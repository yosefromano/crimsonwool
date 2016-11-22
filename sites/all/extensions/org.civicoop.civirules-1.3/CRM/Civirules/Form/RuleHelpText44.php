<?php

require_once 'CRM/Core/Form.php';

/**
 * Form controller class
 *
 * @see http://wiki.civicrm.org/confluence/display/CRMDOC43/QuickForm+Reference
 */
class CRM_Civirules_Form_RuleHelpText44 extends CRM_Core_Form {

  public function buildQuickForm() {
    CRM_Utils_System::setTitle('CiviRule Help');
    $this->add('text', 'help_text', ts('Help For Civirule'));
    parent::buildQuickForm();
  }

  /**
   * Overridden parent method to set default values
   * @return mixed
   */
  public function setDefaultValues() {
    $ruleId = CRM_Utils_Request::retrieve('rid', 'Integer');
    try {
      $helpText = civicrm_api3('CiviRuleRule', 'getvalue', array('id' => $ruleId, 'return' => 'help_text'));
    } catch (CiviCRM_API3_Exception $ex) {
      $helpText = '';
    }
    $defaults['help_text'] = $helpText;
    return $defaults;
  }
}