<?php

require_once 'CRM/Core/Form.php';

/**
 * Form controller class
 *
 * @see http://wiki.civicrm.org/confluence/display/CRMDOC43/QuickForm+Reference
 */
class CRM_CivirulesConditions_Form_Activity_Date extends CRM_CivirulesConditions_Form_Form {

  /**
   * Overridden parent method to build the form
   *
   * @access public
   */
  public function buildQuickForm() {
    $this->add('hidden', 'rule_condition_id');
    $this->add('select', 'operator', ts('Operator'), CRM_Civirules_Utils::getActivityDateOperatorOptions(), TRUE, array('onclick' => "checkOperator()"));
    $this->add('datepicker', 'activity_compare_date', ts('Comparison Date'), array('placeholder' => ts('Compare with')),FALSE, array('time' => FALSE));
    $this->add('datepicker', 'activity_from_date', ts('From date'), array('placeholder' => ts('From')),FALSE, array('time' => FALSE));
    $this->add('datepicker', 'activity_to_date', ts('To date'), array('placeholder' => ts('To')),FALSE, array('time' => FALSE));

    $this->addButtons(array(
      array('type' => 'next', 'name' => ts('Save'), 'isDefault' => TRUE,),
      array('type' => 'cancel', 'name' => ts('Cancel'))));

    parent::buildQuickForm();
  }

  /**
   * Function to add validation condition rules (overrides parent function)
   *
   * @access public
   */
  public function addRules() {
    $this->addFormRule(array('CRM_CivirulesConditions_Form_Activity_Date', 'validateDates'));
  }

  /**
   * Method to validate if from and to date cover a valid period
   *
   * @param $fields
   * @return array|bool
   */
  public static function validateDates($fields) {
    // if operator is between
    if (isset($fields['operator']) && $fields['operator'] == 6) {
      // from and to date can not be empty
      if (!isset($fields['activity_from_date']) || !isset($fields['activity_to_date']) || empty($fields['activity_from_date']) || empty($fields['activity_to_date'])) {
        $errors['operator'] = ts('From and To Date are required  and can not be empty when using Between');
        return $errors;
      }
      // to date can not be earlier than from date
      try {
        $fromDate = new DateTime($fields['activity_from_date']);
        $toDate = new DateTime($fields['activity_to_date']);
        if ($toDate < $fromDate) {
          $errors['from_date'] = ts('From Date should be earlier than or the same as To Date');
          return $errors;
        }
      }
      catch (Exception $ex) {
        Civi::log()->error('Could not parse either from date or to date into DateTime in ' . __METHOD__);
      }
    }
    // if not between, compare date can not be empty
    else {
      if (!isset($fields['activity_compare_date']) || empty($fields['activity_compare_date'])) {
        $errors['activity_compare_date'] = ts('Date to compare with can not be empty');
        return $errors;
      }
    }
    return TRUE;
  }

  /**
   * Overridden parent method to set default values
   *
   * @return array $defaultValues
   * @access public
   */
  public function setDefaultValues() {
    $defaultValues = parent::setDefaultValues();
    $data = unserialize($this->ruleCondition->condition_params);
    if (!empty($data['operator'])) {
      $defaultValues['operator'] = $data['operator'];
    }
    if (!empty($data['activity_compare_date'])) {
      $defaultValues['activity_compare_date'] = $data['activity_compare_date'];
    }
    if (!empty($data['activity_from_date'])) {
      $defaultValues['activity_from_date'] = $data['activity_from_date'];
    }
    if (!empty($data['activity_to_date'])) {
      $defaultValues['activity_to_date'] = $data['activity_to_date'];
    }
    if ($data['operator'] == 6) {
      $this->assign('between', 1);
    }
    else {
      $this->assign('between', 0);
    }
    return $defaultValues;
  }

  /**
   * Overridden parent method to perform data processing once form is submitted
   *
   * @access public
   */
  public function postProcess() {
    $data['operator'] = $this->_submitValues['operator'];
    if ($this->_submitValues['operator'] == 6) {
      $data['activity_compare_date'] = "";
      $data['activity_from_date'] = $this->_submitValues['activity_from_date'];
      $data['activity_to_date'] = $this->_submitValues['activity_to_date'];
    }
    else {
      $data['activity_compare_date'] = $this->_submitValues['activity_compare_date'];
      $data['activity_from_date'] = "";
      $data['activity_to_date'] = "";

    }
    $this->ruleCondition->condition_params = serialize($data);
    $this->ruleCondition->save();
    parent::postProcess();
  }

}
