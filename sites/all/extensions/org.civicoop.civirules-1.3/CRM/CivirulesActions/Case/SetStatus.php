<?php

class CRM_CivirulesActions_Case_SetStatus extends CRM_CivirulesActions_Generic_Api {

  /**
   * Method to get the api action to process in this CiviRule action
   */
  protected function getApiEntity() {
    return 'Case';
  }


  /**
   * Method to get the api action to process in this CiviRule action
   */
  protected function getApiAction() {
    return 'create';
  }


  /**
   * Returns an array with parameters used for processing an action
   */
  protected function alterApiParameters($parameters, CRM_Civirules_TriggerData_TriggerData $triggerData) {

    $case = $triggerData->getEntityData("Case");
    $parameters['id'] = $case['id'];

    return $parameters;
  }


  /**
   * Returns a redirect url to extra data input from the user after adding a action
   *
   * @param int $ruleActionId
   * @return bool|string
   * @access public
   */
  public function getExtraDataInputUrl($ruleActionId) {
    return CRM_Utils_System::url('civicrm/civirule/form/action/case/setstatus', 'rule_action_id='.$ruleActionId);
  }


  /**
   * Returns a user friendly text explaining the condition params
   * e.g. 'Older than 65'
   *
   * @return string
   * @access public
   */
  public function userFriendlyConditionParams() {
    $params = $this->getActionParameters();
    $status = CRM_Case_PseudoConstant::caseStatus();
    return ts('Set case status to: %1',
              array(1 => $status[$params['status_id']]));
  }


  /**
   * Validates whether this action works with the selected trigger.
   *
   * @param CRM_Civirules_Trigger $trigger
   * @param CRM_Civirules_BAO_Rule $rule
   * @return bool
   */
  public function doesWorkWithTrigger(CRM_Civirules_Trigger $trigger, CRM_Civirules_BAO_Rule $rule) {
    $entities = $trigger->getProvidedEntities();
    return isset($entities['Case']);
  }
}
