<?php
/**
 * @author Jaap Jansma (CiviCooP) <jaap.jansma@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */

class CRM_CivirulesActions_Activity_UpdateStatus extends CRM_CivirulesActions_Generic_Api {

  /**
   * Method to get the api entity to process in this CiviRule action
   *
   * @access protected
   * @abstract
   */
  protected function getApiEntity() {
    return 'Activity';
  }

  /**
   * Method to get the api action to process in this CiviRule action
   *
   * @access protected
   * @abstract
   */
  protected function getApiAction() {
    return 'Create';
  }

  /**
   * Returns an array with parameters used for processing an action
   *
   * @param array $parameters
   * @param CRM_Civirules_TriggerData_TriggerData $triggerData
   * @return array
   * @access protected
   */
  protected function alterApiParameters($parameters, CRM_Civirules_TriggerData_TriggerData $triggerData) {
    $action_params = $this->getActionParameters();
    $activityData = $triggerData->getEntityData('Activity');
    $parameters['id'] = $activityData['id'];
    $parameters['status_id'] = $action_params['status_id'];
    return $parameters;
  }

  /**
   * Returns a redirect url to extra data input from the user after adding a action
   *
   * Return false if you do not need extra data input
   *
   * @param int $ruleActionId
   * @return bool|string
   * @access public
   */
  public function getExtraDataInputUrl($ruleActionId) {
    return CRM_Utils_System::url('civicrm/civirule/form/action/activity_update_status', 'rule_action_id='.$ruleActionId);
  }

  /**
   * Returns a user friendly text explaining the condition params
   * e.g. 'Older than 65'
   *
   * @return string
   * @access public
   */
  public function userFriendlyConditionParams() {
    $return = '';
    $params = $this->getActionParameters();
    $status = CRM_Core_OptionGroup::getLabel('activity_status', $params['status_id']);
    $return .= ts("Status: %1", array(1 => $status));

    return $return;
  }

  /**
   * This function validates whether this action works with the selected trigger.
   *
   * This function could be overriden in child classes to provide additional validation
   * whether an action is possible in the current setup.
   *
   * @param CRM_Civirules_Trigger $trigger
   * @param CRM_Civirules_BAO_Rule $rule
   * @return bool
   */
  public function doesWorkWithTrigger(CRM_Civirules_Trigger $trigger, CRM_Civirules_BAO_Rule $rule) {
    $entities = $trigger->getProvidedEntities();
    if (isset($entities['Activity'])) {
      return true;
    }
    return false;
  }

}