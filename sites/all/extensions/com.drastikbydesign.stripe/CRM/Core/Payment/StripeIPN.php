<?php
/*
 * @file
 * Handle Stripe Webhooks for recurring payments.
 */

class CRM_Core_Payment_StripeIPN extends CRM_Core_Payment_BaseIPN {

  use CRM_Core_Payment_StripeIPNTrait;

  /**
   * Transaction ID is the contribution in the redirect flow and a random number in the on-site->POST flow
   * Ideally the contribution id would always be created at this point in either flow for greater consistency
   * @var
   */
  protected $transaction_id;

  // By default, always retrieve the event from stripe to ensure we are
  // not being fed garbage. However, allow an override so when we are 
  // testing, we can properly test a failed recurring contribution.
  protected $verify_event = TRUE;

  /**
   * Do we send an email receipt for each contribution?
   *
   * @var int
   */
  protected $is_email_receipt = NULL;

  // Properties of the event.
  protected $event_type = NULL;
  protected $subscription_id = NULL;
  protected $customer_id = NULL;
  protected $charge_id = NULL;
  protected $previous_plan_id = NULL;
  protected $plan_id = NULL;
  protected $plan_amount = NULL;
  protected $frequency_interval = NULL;
  protected $frequency_unit = NULL;
  protected $plan_name = NULL;
  protected $plan_start = NULL;
       
  // Derived properties.
  protected $contribution_recur_id = NULL;
  protected $event_id = NULL;
  protected $invoice_id = NULL;
  protected $receive_date = NULL;
  protected $amount = NULL;
  protected $fee = NULL;
  protected $net_amount = NULL;
  protected $previous_contribution = [];

  /**
   * CRM_Core_Payment_StripeIPN constructor.
   *
   * @param $ipnData
   * @param bool $verify
   *
   * @throws \CRM_Core_Exception
   */
  public function __construct($ipnData, $verify = TRUE) {
    $this->verify_event = $verify;
    $this->setInputParameters($ipnData);
    parent::__construct();
  }

  /**
   * Set the value of is_email_receipt to use when a new contribution is received for a recurring contribution
   * This is used for the API Stripe.Ipn function.  If not set, we respect the value set on the ContributionRecur entity.
   *
   * @param int $sendReceipt The value of is_email_receipt
   */
  public function setSendEmailReceipt($sendReceipt) {
    switch ($sendReceipt) {
      case 0:
        $this->is_email_receipt = 0;
        break;

      case 1:
        $this->is_email_receipt = 1;
        break;

      default:
        $this->is_email_receipt = 0;
    }
  }

  /**
   * Get the value of is_email_receipt to use when a new contribution is received for a recurring contribution
   * This is used for the API Stripe.Ipn function.  If not set, we respect the value set on the ContributionRecur entity.
   *
   * @return int
   * @throws \CiviCRM_API3_Exception
   */
  public function getSendEmailReceipt() {
    if (isset($this->is_email_receipt)) {
      return (int) $this->is_email_receipt;
    }
    if (!empty($this->contribution_recur_id)) {
      $this->is_email_receipt = civicrm_api3('ContributionRecur', 'getvalue', [
        'return' => "is_email_receipt",
        'id' => $this->contribution_recur_id,
      ]);
    }
    return (int) $this->is_email_receipt;
  }

  /**
   * Store input array on the class.
   * We override base because our input parameter is an object
   *
   * @param array $parameters
  */
  public function setInputParameters($parameters) {
    if (!is_object($parameters)) {
      $this->exception('Invalid input parameters');
    }

    // Determine the proper Stripe Processor ID so we can get the secret key
    // and initialize Stripe.
    $this->getPaymentProcessor();

    // Now re-retrieve the data from Stripe to ensure it's legit.
    \Stripe\Stripe::setApiKey($this->_paymentProcessor['user_name']);

    // Special case if this is the test webhook
    if (substr($parameters->id, -15, 15) === '_00000000000000') {
      http_response_code(200);
      $test = (boolean) $this->_paymentProcessor['is_test'] ? '(Test processor)' : '(Live processor)';
      echo "Test webhook from Stripe ({$parameters->id}) received successfully by CiviCRM {$test}.";
      exit();
    }

    if ($this->verify_event) {
      $this->_inputParameters = \Stripe\Event::retrieve($parameters->id);
    }
    else {
      $this->_inputParameters = $parameters;
    }
    http_response_code(200);
  }

  /**
   * Get a parameter given to us by Stripe.
   *
   * @param string $name
   * @param $type
   * @param bool $abort
   *
   * @return false|int|null|string
   * @throws \CRM_Core_Exception
   */
  public function retrieve($name, $type, $abort = TRUE) {
    $className = get_class($this->_inputParameters->data->object);
    $value = NULL;
    switch ($className) {
      case 'Stripe\Charge':
        switch ($name) {
          case 'charge_id':
            $value = $this->_inputParameters->data->object->id;
            break;

          case 'failure_code':
            $value = $this->_inputParameters->data->object->failure_code;
            break;

          case 'failure_message':
            $value = $this->_inputParameters->data->object->failure_message;
            break;

          case 'refunded':
            $value = $this->_inputParameters->data->object->refunded;
            break;

          case 'amount_refunded':
            $value = $this->_inputParameters->data->object->amount_refunded;
            break;
        }
        break;

      case 'Stripe\Invoice':
        switch ($name) {
          case 'charge_id':
            $value = $this->_inputParameters->data->object->charge;
            break;

          case 'invoice_id':
            $value = $this->_inputParameters->data->object->id;
            break;

          case 'receive_date':
            $value = date("Y-m-d H:i:s", $this->_inputParameters->data->object->date);
            break;

          case 'subscription_id':
            $value = $this->_inputParameters->data->object->subscription;
            break;
        }
        break;

      case 'Stripe\Subscription':
        switch ($name) {
          case 'frequency_interval':
            $value = $this->_inputParameters->data->object->plan->interval_count;
            break;

          case 'frequency_unit':
            $value = $this->_inputParameters->data->object->plan->interval;
            break;

          case 'plan_amount':
            $value = $this->_inputParameters->data->object->plan->amount / 100;
            break;

          case 'plan_id':
            $value = $this->_inputParameters->data->object->plan->id;
            break;

          case 'plan_name':
            $value = $this->_inputParameters->data->object->plan->name;
            break;

          case 'plan_start':
            $value = date("Y-m-d H:i:s", $this->_inputParameters->data->object->start);
            break;

          case 'subscription_id':
            $value = $this->_inputParameters->data->object->id;
            break;
        }
        break;
    }

    // Common parameters
    switch ($name) {
      case 'customer_id':
        $value = $this->_inputParameters->data->object->customer;
        break;

      case 'event_type':
        $value = $this->_inputParameters->type;
        break;

      case 'previous_plan_id':
        if (preg_match('/\.updated$/', $this->_inputParameters->type)) {
          $value = $this->_inputParameters->data->previous_attributes->plan->id;
        }
        break;
    }

    $value = CRM_Utils_Type::validate($value, $type, FALSE);
    if ($abort && $value === NULL) {
      echo "Failure: Missing Parameter<p>" . CRM_Utils_Type::escape($name, 'String');
      $this->exception("Could not find an entry for $name");
    }
    return $value;
  }

  /**
   * @throws \CRM_Core_Exception
   * @throws \CiviCRM_API3_Exception
   */
  public function main() {
    // Collect and determine all data about this event.
    $this->event_type = $this->retrieve('event_type', 'String');

    $pendingStatusId = CRM_Core_PseudoConstant::getKey('CRM_Contribute_BAO_Contribution', 'contribution_status_id', 'Pending');

    switch($this->event_type) {
      // Successful recurring payment.
      case 'invoice.payment_succeeded':
        $this->setInfo();
        if ($this->previous_contribution['contribution_status_id'] == $pendingStatusId) {
          $this->completeContribution();
        }
        elseif ($this->previous_contribution['trxn_id'] != $this->charge_id) {
          // The first contribution was completed, so create a new one.
          // api contribution repeattransaction repeats the appropriate contribution if it is given
          // simply the recurring contribution id. It also updates the membership for us.
          civicrm_api3('Contribution', 'repeattransaction', array(
            'contribution_recur_id' => $this->contribution_recur_id,
            'contribution_status_id' => 'Completed',
            'receive_date' => $this->receive_date,
            'trxn_id' => $this->charge_id,
            'total_amount' => $this->amount,
            'fee_amount' => $this->fee,
            'is_email_receipt' => $this->getSendEmailReceipt(),
          ));
        }

        // Successful charge & more to come. 
        civicrm_api3('ContributionRecur', 'create', array(
          'id' => $this->contribution_recur_id,
          'failure_count' => 0,
          'contribution_status_id' => 'In Progress'
        ));
        return TRUE;

      // Failed recurring payment.
      case 'invoice.payment_failed':
        $this->setInfo();
        $failDate = date('YmdHis');

        if ($this->previous_contribution['contribution_status_id'] == $pendingStatusId) {
          // If this contribution is Pending, set it to Failed.
          civicrm_api3('Contribution', 'create', array(
            'id' => $this->previous_contribution['id'],
            'contribution_status_id' => "Failed",
            'receive_date' => $failDate,
            'is_email_receipt' => 0,
          ));
        }
        else {
          $contributionParams = [
            'contribution_recur_id' => $this->contribution_recur_id,
            'contribution_status_id' => 'Failed',
            'receive_date' => $failDate,
            'total_amount' => $this->amount,
            'is_email_receipt' => 0,
          ];
          civicrm_api3('Contribution', 'repeattransaction', $contributionParams);
        }

        $failureCount = civicrm_api3('ContributionRecur', 'getvalue', array(
         'id' => $this->contribution_recur_id,
         'return' => 'failure_count',
        ));
        $failureCount++;

        // Change the status of the Recurring and update failed attempts.
        civicrm_api3('ContributionRecur', 'create', array(
          'id' => $this->contribution_recur_id,
          'contribution_status_id' => "Failed",
          'failure_count' => $failureCount,
          'modified_date' => $failDate,
        ));
        return TRUE;

      // Subscription is cancelled
      case 'customer.subscription.deleted':
        $this->setInfo();
        // Cancel the recurring contribution
        civicrm_api3('ContributionRecur', 'cancel', array(
          'id' => $this->contribution_recur_id,
        ));
        return TRUE;

      // One-time donation and per invoice payment.
      case 'charge.failed':
        $chargeId = $this->retrieve('charge_id', 'String');
        $failureCode = $this->retrieve('failure_code', 'String');
        $failureMessage = $this->retrieve('failure_message', 'String');
        $contribution = civicrm_api3('Contribution', 'getsingle', ['trxn_id' => $chargeId]);
        $failedStatusId = CRM_Core_PseudoConstant::getKey('CRM_Contribute_BAO_Contribution', 'contribution_status_id', 'Failed');
        if ($contribution['contribution_status_id'] != $failedStatusId) {
          $note = $failureCode . ' : ' . $failureMessage;
          civicrm_api3('Contribution', 'create', ['id' => $contribution['id'], 'contribution_status_id' => $failedStatusId, 'note' => $note]);
        }
        return TRUE;

      case 'charge.refunded':
        $chargeId = $this->retrieve('charge_id', 'String');
        $refunded = $this->retrieve('refunded', 'Boolean');
        $refundAmount = $this->retrieve('amount_refunded', 'Integer');
        $contribution = civicrm_api3('Contribution', 'getsingle', ['trxn_id' => $chargeId]);
        if ($refunded) {
          $refundedStatusId = CRM_Core_PseudoConstant::getKey('CRM_Contribute_BAO_Contribution', 'contribution_status_id', 'Refunded');
          if ($contribution['contribution_status_id'] != $refundedStatusId) {
            civicrm_api3('Contribution', 'create', [
              'id' => $contribution['id'],
              'contribution_status_id' => $refundedStatusId
            ]);
          }
          elseif ($refundAmount > 0) {
            $partiallyRefundedStatusId = CRM_Core_PseudoConstant::getKey('CRM_Contribute_BAO_Contribution', 'contribution_status_id', 'Partially Refunded');
            if ($contribution['contribution_status_id'] != $partiallyRefundedStatusId) {
              civicrm_api3('Contribution', 'create', [
                'id' => $contribution['id'],
                'contribution_status_id' => $refundedStatusId
              ]);
            }
          }
        }
        return TRUE;

      case 'charge.succeeded':
        $this->setInfo();
        if ($this->previous_contribution['contribution_status_id'] == $pendingStatusId) {
          $this->completeContribution();
        }
        return TRUE;

      case 'customer.subscription.updated':
       $this->setInfo();
       if (empty($this->previous_plan_id)) {
         // Not a plan change...don't care.
         return TRUE;
       }

       civicrm_api3('ContributionRecur', 'create', [
         'id' => $this->contribution_recur_id,
          'amount' => $this->plan_amount,
          'auto_renew' => 1,
          'created_date' => $this->plan_start,
          'frequency_unit' => $this->frequency_unit,
          'frequency_interval' => $this->frequency_interval,
       ]);

       civicrm_api3('Contribution', 'create', [
          'id' => $this->previous_contribution['id'],
          'total_amount' => $this->plan_amount,
          'contribution_recur_id' => $this->contribution_recur_id,
       ]);
        return TRUE;
    }
    // Unhandled event type.
    return TRUE;
  }

  /**
   * Complete a pending contribution and update associated entities (recur/membership)
   *
   * @throws \CiviCRM_API3_Exception
   */
  public function completeContribution() {
    // Update the contribution to include the fee.
    civicrm_api3('Contribution', 'create', array(
      'id' => $this->previous_contribution['id'],
      'total_amount' => $this->amount,
      'fee_amount' => $this->fee,
      'net_amount' => $this->net_amount,
    ));
    // The last one was not completed, so complete it.
    civicrm_api3('Contribution', 'completetransaction', array(
      'id' => $this->previous_contribution['id'],
      'trxn_date' => $this->receive_date,
      'trxn_id' => $this->charge_id,
      'total_amount' => $this->amount,
      'net_amount' => $this->net_amount,
      'fee_amount' => $this->fee,
      'payment_processor_id' => $this->_paymentProcessor['id'],
      'is_email_receipt' => $this->getSendEmailReceipt(),
    ));
  }

    /**
   * Gather and set info as class properties.
   *
   * Given the data passed to us via the Stripe Event, try to determine
   * as much as we can about this event and set that information as 
   * properties to be used later.
   *
   * @throws \CRM_Core_Exception
   */
  public function setInfo() {
    $abort = FALSE;
    $this->customer_id = $this->retrieve('customer_id', 'String');
    $this->subscription_id = $this->retrieve('subscription_id', 'String', $abort);
    $this->invoice_id = $this->retrieve('invoice_id', 'String', $abort);
    $this->receive_date = $this->retrieve('receive_date', 'String', $abort);
    $this->charge_id = $this->retrieve('charge_id', 'String', $abort);
    $this->plan_id = $this->retrieve('plan_id', 'String', $abort);
    $this->previous_plan_id = $this->retrieve('previous_plan_id', 'String', $abort);
    $this->plan_amount = $this->retrieve('plan_amount', 'String', $abort);
    $this->frequency_interval = $this->retrieve('frequency_interval', 'String', $abort);
    $this->frequency_unit = $this->retrieve('frequency_unit', 'String', $abort);
    $this->plan_name = $this->retrieve('plan_name', 'String', $abort);
    $this->plan_start = $this->retrieve('plan_start', 'String', $abort);

    // Gather info about the amount and fee.
    // Get the Stripe charge object if one exists. Null charge still needs processing.
    if ($this->charge_id !== null) {
      try {
        $charge = \Stripe\Charge::retrieve($this->charge_id);
        $balance_transaction_id = $charge->balance_transaction;
        // If the transaction is declined, there won't be a balance_transaction_id.
        if ($balance_transaction_id) {
          $balance_transaction = \Stripe\BalanceTransaction::retrieve($balance_transaction_id);
          $this->amount = $charge->amount / 100;
          $this->fee = $balance_transaction->fee / 100;
        }
        else {
          $this->amount = 0;
          $this->fee = 0;
        }
      }
      catch(Exception $e) {
        $this->exception('Cannot get contribution amounts');
      }
    } else {
      // The customer had a credit on their subscription from a downgrade or gift card.
      $this->amount = 0;
      $this->fee = 0;
    }

    $this->net_amount = $this->amount - $this->fee;

    // Additional processing of values is only relevant if there is a subscription id.
    if ($this->subscription_id) {
      // Get the recurring contribution record associated with the Stripe subscription.
      try {
        $contributionRecur = civicrm_api3('ContributionRecur', 'getsingle', ['trxn_id' => $this->subscription_id]);
        $this->contribution_recur_id = $contributionRecur['id'];
      }
      catch (Exception $e) {
        $this->exception('Cannot find recurring contribution for subscription ID: ' . $this->subscription_id . '. ' . $e->getMessage());
      }
    }
    // If a recurring contribution has been found, get the most recent contribution belonging to it.
    if ($this->contribution_recur_id) {
      try {
        // Same approach as api repeattransaction.
        $contribution = civicrm_api3('contribution', 'getsingle', array(
          'return' => array('id', 'contribution_status_id', 'total_amount', 'trxn_id'),
          'contribution_recur_id' => $this->contribution_recur_id,
          'contribution_test' => isset($this->_paymentProcessor['is_test']) && $this->_paymentProcessor['is_test'] ? 1 : 0,
          'options' => array('limit' => 1, 'sort' => 'id DESC'),
        ));
        $this->previous_contribution = $contribution;
      }
      catch (Exception $e) {
        $this->exception('Cannot find any contributions with recurring contribution ID: ' . $this->contribution_recur_id . '. ' . $e->getMessage());
      }
    }
  }

  public function exception($message) {
    $errorMessage = 'StripeIPN Exception: Event: ' . $this->event_type . ' Error: ' . $message;
    Civi::log()->debug($errorMessage);
    http_response_code(400);
    exit(1);
  }
}
