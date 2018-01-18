<?php
/**
 * Class for condition only once that operates on case.
 * The goals is to make sure that the rule is not executed for each
 * case contact, but only once for the case
 *
 *
 * @author Erik Hommel (CiviCooP) <erik.hommel@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */

class CRM_CivirulesConditions_Case_OnlyOnce extends CRM_Civirules_Condition {

  public function getExtraDataInputUrl($ruleConditionId) {
    return FALSE;
  }

  /**
   * Method to check if the condition is valid. Goal of this condition is to make sure that
   * the action is only done once for a case. This will prevent the action happening for each
   * of the contacts involved in the case!
   *
   * @param object CRM_Civirules_TriggerData_TriggerData $triggerData
   * @return bool
   * @access public
   */
  public function isConditionValid(CRM_Civirules_TriggerData_TriggerData $triggerData) {
    $isConditionValid = FALSE;
    try {
      $sourceRecordTypeId = civicrm_api3('OptionValue', 'getvalue', array(
        'option_group' => 'activity_contacts',
        'name' => 'Activity Source',
        'return' => 'value'
      ));
      // if triggered from case activity we will have activity contact data
      $activityContactData = $triggerData->getEntityData('ActivityContact');
      if (!empty($activityContactData)) {
        if ($activityContactData['record_type_id'] == $sourceRecordTypeId) {
          $isConditionValid = TRUE;
        }
      } else {
        // if no activity contact check case data (based on fact that relationship exists
        // for all case roles apart from client)
        $caseData = $triggerData->getEntityData('Case');
        if (empty($caseData)) {
          $isConditionValid = TRUE;
        } else {
          $relationship = $triggerData->getEntityData('Relationship');
          if (empty($relationship)) {
            $isConditionValid = TRUE;
          }
        }
      }
    } catch (CiviCRM_API3_Exception $ex) {}
    return $isConditionValid;
  }

  /**
   * Returns an array with required entity names
   *
   * @return array
   * @access public
   */
  public function requiredEntities() {
    return array(
      'Case',
    );
  }
}