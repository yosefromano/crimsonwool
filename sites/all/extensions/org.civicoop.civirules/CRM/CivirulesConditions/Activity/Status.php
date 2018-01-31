<?php
/**
 * @author Jaap Jansma (CiviCooP) <jaap.jansma@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */

class CRM_CivirulesConditions_Activity_Status extends CRM_Civirules_Condition {

  private $conditionParams = array();

  public function getExtraDataInputUrl($ruleConditionId) {
    return CRM_Utils_System::url('civicrm/civirule/form/condition/activity_status/',
      'rule_condition_id='.$ruleConditionId);
  }

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
   * Method to check if the condition is valid, will check if the contact
   * has an activity of the selected type
   *
   * @param object CRM_Civirules_TriggerData_TriggerData $triggerData
   * @return bool
   * @access public
   */
  public function isConditionValid(CRM_Civirules_TriggerData_TriggerData $triggerData) {
    $isConditionValid = FALSE;
    $activity = $triggerData->getEntityData('Activity');
    switch ($this->conditionParams['operator']) {
      case 0:
        if (in_array($activity['status_id'], $this->conditionParams['status_id'])) {
          $isConditionValid = TRUE;
        }
        break;
      case 1:
        if (!in_array($activity['status_id'], $this->conditionParams['status_id'])) {
          $isConditionValid = TRUE;
        }
        break;
    }
    return $isConditionValid;
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
      $friendlyText = 'Activity Status is one of: ';
    }
    if ($this->conditionParams['operator'] == 1) {
      $friendlyText = 'Activity Status is NOT one of: ';
    }
    $actText = array();
    foreach ($this->conditionParams['status_id'] as $actStatusId) {
      $actText[] = civicrm_api3('OptionValue', 'getvalue', array(
        'option_group_id' => 'activity_status',
        'value' => $actStatusId,
        'return' => 'label'
      ));
    }
    if (!empty($actText)) {
      $friendlyText .= implode(", ", $actText);
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
    return array(
      'Activity',
    );
  }

}