<?php

class CRM_CivirulesConditions_Contribution_FinancialType extends CRM_Civirules_Condition {

  private $conditionParams = array();

  /**
   * Method to set the Rule Condition data
   *
   * @param array $ruleCondition
   * @access public
   */
  public function setRuleConditionData($ruleCondition) {
    parent::setRuleConditionData($ruleCondition);
    $this->conditionParams = array();
    if (!empty($this->ruleCondition['condition_params'])) {
      $this->conditionParams = unserialize($this->ruleCondition['condition_params']);
    }
  }

  /**
   * Method to determine if the condition is valid
   *
   * @param CRM_Civirules_TriggerData_TriggerData $triggerData
   * @return bool
   */

  public function isConditionValid(CRM_Civirules_TriggerData_TriggerData $triggerData) {
    $isConditionValid = FALSE;
    $contribution = $triggerData->getEntityData('Contribution');
    switch ($this->conditionParams['operator']) {
      case 0:
        if (in_array($contribution['financial_type_id'], $this->conditionParams['financial_type_id'])) {
          $isConditionValid = TRUE;
        }
      break;
      case 1:
        if (!in_array($contribution['financial_type_id'], $this->conditionParams['financial_type_id'])) {
          $isConditionValid = TRUE;
        }
      break;
    }
    return $isConditionValid;
  }

  /**
   * Returns a redirect url to extra data input from the user after adding a condition
   *
   * Return false if you do not need extra data input
   *
   * @param int $ruleConditionId
   * @return bool|string
   * @access public
   * @abstract
   */
  public function getExtraDataInputUrl($ruleConditionId) {
    return CRM_Utils_System::url('civicrm/civirule/form/condition/contribution_financialtype/', 'rule_condition_id='.$ruleConditionId);
  }

  /**
   * Returns a user friendly text explaining the condition params
   * e.g. 'Older than 65'
   *
   * @return string
   * @access public
   */
  public function userFriendlyConditionParams() {
    $friendlyText = "";
    if ($this->conditionParams['operator'] == 0) {
      $friendlyText = 'Financial Type is one of: ';
    }
    if ($this->conditionParams['operator'] == 1) {
      $friendlyText = 'Financial Type is NOT one of: ';
    }
    $finText = array();
    foreach ($this->conditionParams['financial_type_id'] as $finTypeId) {
      $financialType = new CRM_Financial_BAO_FinancialType();
      $financialType->id = $finTypeId;
      if ($financialType->find(true)) {
        $finText[] = $financialType->name;
      }
    }
    if (!empty($finText)) {
      $friendlyText .= implode(", ", $finText);
    }
    return $friendlyText;
  }

  /**
   * Returns an array with required entity names
   *
   * @return array
   * @access public
   */
  public function requiredEntities() {
    return array('Contribution');
  }

}