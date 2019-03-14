<?php

use Civi\Test\HeadlessInterface;
use Civi\Test\HookInterface;
use Civi\Test\TransactionalInterface;

/**
 * FIXME - Add test description.
 *
 * Tips:
 *  - With HookInterface, you may implement CiviCRM hooks directly in the test class.
 *    Simply create corresponding functions (e.g. "hook_civicrm_post(...)" or similar).
 *  - With TransactionalInterface, any data changes made by setUp() or test****() functions will
 *    rollback automatically -- as long as you don't manipulate schema or truncate tables.
 *    If this test needs to manipulate schema or truncate tables, then either:
 *       a. Do all that using setupHeadless() and Civi\Test.
 *       b. Disable TransactionalInterface, and handle all setup/teardown yourself.
 *
 * @group headless
 */
require ('BaseTest.php');
class CRM_Stripe_IpnTest extends CRM_Stripe_BaseTest {
  protected $_total = '200';
  protected $_contributionRecurID;
  protected $_installments = 5;
  protected $_frequency_unit = 'month';
  protected $_frequency_interval = 1;
  protected $_membershipID;

  // This test is particularly dirty for some reason so we have to 
  // force a reset.
  public function setUpHeadless() {
    $force = TRUE;
    return \Civi\Test::headless()
      ->installMe(__DIR__)
      ->apply($force);
  }

  /**
   * Test creating a membership related recurring contribution and
   * update it after creation. The membership should also be updated.
   */
  public function testIPNRecurMembershipUpdate() {
    $this->setupRecurringTransaction();

    // Create a membership type (this will create the member org too).
    $this->createMembershipType();

    // Create the membership and link to the recurring contribution.
    $params = array(
      'contact_id' => $this->_contactID,
      'membership_type_id' => $this->_membershipTypeID,
      'contribution_recur_id' => $this->_contributionRecurID
    );
    $result = civicrm_api3('membership', 'create', $params);
    $this->_membershipID = $result['id'];
    $status = $result['values'][$this->_membershipID]['status_id'];
    $this->assertEquals(1, $status, 'Membership is in new status');

    // Submit the payment.
    $payment_extra_params = array(
      'is_recur' => 1,
      'contributionRecurID' => $this->_contributionRecurID,
      'frequency_unit' => $this->_frequency_unit,
      'frequency_interval' => $this->_frequency_interval,
      'installments' => $this->_installments,
      'selectMembership' => array(
        0 => $this->_membershipTypeID
      )
    );
    $this->doPayment($payment_extra_params);

    // Now check to see if an event was triggered and if so, process it.
    $payment_object = $this->getEvent('invoice.payment_succeeded'); 
    if ($payment_object) {
      $this->ipn($payment_object);
    }

    // Now that we have a recurring contribution, let's update it. 
    \Stripe\Stripe::setApiKey($this->_sk);
    $sub = \Stripe\Subscription::retrieve($this->_subscriptionID);

    // Create a new plan if it doesn't yet exist.
    $plan_id = 'membertype_1-every-2-month-40000-usd-test';

    // It's possible that this test plan is still in Stripe, so try to
    // retrieve it and catch the error triggered if it doesn't exist.
    try {
      $plan = \Stripe\Plan::retrieve($plan_id);
    }
    catch (Stripe\Error\InvalidRequest $e) {
      // The plan has not been created yet, so create it.
      $product = \Stripe\Product::create(array(
        "name" => "CiviCRM testing product",
        "type" => "service"
      ));

      $plan_details = array(
        'id' => $plan_id,
        'amount' => '40000',
        'interval' => 'month',
        'product' => $product,
        'currency' => 'usd',
        'interval_count' => 2
      );
      $plan = \Stripe\Plan::create($plan_details);

    }
    $sub->plan = $plan_id;
    $sub->save();

    // Now check to see if an event was triggered and if so, process it.
    $payment_object = $this->getEvent('customer.subscription.updated'); 
    if ($payment_object) {
      $this->ipn($payment_object);
    }

    // Check for a new recurring contribution.
    $params = array(
      'contact_id' => $this->_contactID,
      'amount' => '400',
      'contribution_status_id' => "In Progress",
      'return' => array('id'),
    );
    $result = civicrm_api3('ContributionRecur', 'getsingle', $params);
    $newContributionRecurID = $result['id']; 
    
    // Now ensure that the membership record is updated to have this
    // new recurring contribution id.
    $membership_contribution_recur_id = civicrm_api3('Membership', 'getvalue', array(
      'id' => $this->_membershipID,
      'return' => 'contribution_recur_id'
    ));
    $this->assertEquals($newContributionRecurID, $membership_contribution_recur_id, 'Membership is updated to new contribution recur id');

    // Delete the new plan so we can cleanly run the next time.
    $plan->delete();
    
  }

  /**
   * Test making a failed recurring contribution.
   */
  public function testIPNRecurFail() {
    $this->setupRecurringTransaction();
    $payment_extra_params = array(
      'is_recur' => 1,
      'contributionRecurID' => $this->_contributionRecurID,
      'frequency_unit' => $this->_frequency_unit,
      'frequency_interval' => $this->_frequency_interval,
      'installments' => $this->_installments
    );
    // Note - this will succeed. It is very hard to test a failed transaction.
    // We will manipulate the event to make it a failed transaction below.
    $this->doPayment($payment_extra_params);

    // Now check to see if an event was triggered and if so, process it.
    $payment_object = $this->getEvent('invoice.payment_succeeded'); 
    if ($payment_object) {
      // Now manipulate the transaction so it appears to be a failed one.
      $payment_object->type = 'invoice.payment_failed';
      // Tell Ipn not to verify it - because we manipulated it.
      $verify = FALSE;
      $this->ipn($payment_object, $verify);
    }

    $contribution = civicrm_api3('contribution', 'getsingle', array('id' => $this->_contributionID));
    $contribution_status_id = $contribution['contribution_status_id'];

    $status = CRM_Contribute_PseudoConstant::contributionStatus($contribution_status_id, 'name');
    $this->assertEquals('Failed', $status, "Failed contribution was properly marked as failed via a stripe event.");
    $failure_count = civicrm_api3('ContributionRecur', 'getvalue', array(
      'sequential' => 1,
      'id' => $this->_contributionRecurID,
      'return' => 'failure_count',
    ));
    $this->assertEquals(1, $failure_count, "Failed contribution count is correct..");

  }
  /**
   * Test making a recurring contribution.
   */
  public function testIPNRecurSuccess() {
    $this->setupRecurringTransaction();
    $payment_extra_params = array(
      'is_recur' => 1,
      'contributionRecurID' => $this->_contributionRecurID,
      'frequency_unit' => $this->_frequency_unit,
      'frequency_interval' => $this->_frequency_interval,
      'installments' => $this->_installments
    );
    $this->doPayment($payment_extra_params);

    // Now check to see if an event was triggered and if so, process it.
    $payment_object = $this->getEvent('invoice.payment_succeeded'); 
    if ($payment_object) {
      $this->ipn($payment_object);
    }
    $contribution = civicrm_api3('contribution', 'getsingle', array('id' => $this->_contributionID));
    $contribution_status_id = $contribution['contribution_status_id'];
    $this->assertEquals(1, $contribution_status_id, "Recurring payment was properly processed via a stripe event.");

    // Now, cancel the subscription and ensure it is properly cancelled.
    \Stripe\Stripe::setApiKey($this->_sk);
    $sub = \Stripe\Subscription::retrieve($this->_subscriptionID);
    $sub->cancel();

    $sub_object = $this->getEvent('customer.subscription.deleted'); 
    if ($sub_object) {
      $this->ipn($sub_object);
    }
    $this->assertContributionRecurIsCancelled();  
  }

  public function assertContributionRecurIsCancelled() {
    $contribution_recur = civicrm_api3('contributionrecur', 'getsingle', array('id' => $this->_contributionRecurID));
    $contribution_recur_status_id = $contribution_recur['contribution_status_id'];
    $status = CRM_Contribute_PseudoConstant::contributionStatus($contribution_recur_status_id, 'name');
    $this->assertEquals('Cancelled', $status, "Recurring payment was properly cancelled via a stripe event.");
  }

  /**
   * Retrieve the event with a matching subscription id
   */
  public function getEvent($type) {
    // If the type has subscription in it, then the id is the subscription id
    if (preg_match('/\.subscription\./', $type)) {
      $property = 'id';
    }
    else {
      // Otherwise, we'll find the subscription id in the subscription property.
      $property = 'subscription';
    }
    // Gather all events since this class was instantiated.
    $params['sk'] = $this->_sk;
    $params['created'] = array('gte' => $this->_created_ts);
    $params['type'] = $type;
    $params['ppid'] = $this->_paymentProcessorID;
    $params['output'] = 'raw';

    // Now try to retrieve this transaction.
    $transactions = civicrm_api3('Stripe', 'listevents', $params );    
    foreach($transactions['values']['data'] as $transaction) {
      if ($transaction->data->object->$property == $this->_subscriptionID) {
        return $transaction;
      }
    }
    return NULL;

  }

  /**
   * Run the webhook/ipn
   *
   */
  public function ipn($data, $verify = TRUE) {
    // The $_GET['processor_id'] value is normally set by 
    // CRM_Core_Payment::handlePaymentMethod
    $_GET['processor_id'] = $this->_paymentProcessorID;
    $ipnClass = new CRM_Core_Payment_StripeIPN($data, $verify);
    $ipnClass->main();
  }

  /**
   * Create recurring contribition
   */
  public function setupRecurringTransaction($params = array()) {
    $contributionRecur = civicrm_api3('contribution_recur', 'create', array_merge(array(
      'financial_type_id' => $this->_financialTypeID,
      'payment_instrument_id' => CRM_Core_PseudoConstant::getKey('CRM_Contribute_BAO_ContributionRecur', 'payment_instrument_id', 'Credit Card'),
      'contact_id' => $this->_contactID,
      'amount' => $this->_total,
      'sequential' => 1,
      'installments' => $this->_installments,
      'frequency_unit' => $this->_frequency_unit, 
      'frequency_interval' => $this->_frequency_interval,
      'invoice_id' => $this->_invoiceID,
      'contribution_status_id' => 2,
      'payment_processor_id' => $this->_paymentProcessorID,
      // processor provided ID - use contact ID as proxy.
      'processor_id' => $this->_contactID,
      'api.contribution.create' => array(
        'total_amount' => $this->_total,
        'invoice_id' => $this->_invoiceID,
        'financial_type_id' => $this->_financialTypeID,
        'contribution_status_id' => 'Pending',
        'contact_id' => $this->_contactID,
        'contribution_page_id' => $this->_contributionPageID,
        'payment_processor_id' => $this->_paymentProcessorID,
        'is_test' => 1,
      ),
    ), $params));
    $this->assertEquals(0, $contributionRecur['is_error']);
    $this->_contributionRecurID = $contributionRecur['id'];
    $this->_contributionID = $contributionRecur['values']['0']['api.contribution.create']['id'];
  } 
}
