<?php
/**
 * Class to check condition tag is
 *
 * @author Erik Hommel (CiviCooP) <erik.hommel@civicoop.org>
 * @date 15 Nov 2017
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */


class CRM_CivirulesConditions_EntityTag_TagId extends CRM_Civirules_Condition {

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
   * Method to test if the condition is valid
   *
   * @param CRM_Civirules_TriggerData_TriggerData $triggerData
   * @return bool
   */
  public function isConditionValid(CRM_Civirules_TriggerData_TriggerData $triggerData) {
    $entityTag = $triggerData->getEntityData('EntityTag');
    if (in_array($entityTag['tag_id'], $this->conditionParams['tag_id'])) {
      return TRUE;
    }
    return FALSE;
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
    return CRM_Utils_System::url('civicrm/civirule/form/condition/entitytag/tagid/', 'rule_condition_id='.$ruleConditionId);
  }

  /**
   * Returns a user friendly text explaining the condition params
   * e.g. 'Older than 65'
   *
   * @return string
   * @access public
   */
  public function userFriendlyConditionParams() {
    if (!empty($this->conditionParams['tag_id'])) {
      $tagLabels = array();
      foreach ($this->conditionParams['tag_id'] as $tagId) {
        $tagLabels[] = civicrm_api3('Tag', 'getvalue',
          array(
            'return' => 'name',
            'id' => $tagId));
      }
      return ts('Tag for Contact is one of selected: ').implode(', ', $tagLabels);
    }
    return '';
  }

  /**
   * Returns an array with required entity names
   *
   * @return array
   * @access public
   */
  public function requiredEntities() {
    return array('EntityTag');
  }

}