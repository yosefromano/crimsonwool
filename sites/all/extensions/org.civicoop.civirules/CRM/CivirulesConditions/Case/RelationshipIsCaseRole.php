<?php
/**
 * @author Jaap Jansma (CiviCooP) <jaap.jansma@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */

class CRM_CivirulesConditions_Case_RelationshipIsCaseRole extends CRM_Civirules_Condition {

  public function isConditionValid(CRM_Civirules_TriggerData_TriggerData $triggerData) {
    $relationship = $triggerData->getEntityData('Relationship');
    if (!empty($relationship['case_id'])) {
      return true;
    }
    return false;
  }

  public function getExtraDataInputUrl($ruleConditionId) {
    return false;
  }

  /**
   * Returns an array with required entity names
   *
   * @return array
   * @access public
   */
  public function requiredEntities() {
    return array('Relationship');
  }

}