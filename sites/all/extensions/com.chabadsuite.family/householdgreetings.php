<?php

require_once 'householdgreetings.civix.php';
use CRM_Householdgreetings_ExtensionUtil as E;

/**
 * Implements hook_civicrm_config().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_config
 */
function householdgreetings_civicrm_config(&$config) {
  _householdgreetings_civix_civicrm_config($config);
}

/**
 * Implements hook_civicrm_xmlMenu().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_xmlMenu
 */
function householdgreetings_civicrm_xmlMenu(&$files) {
  _householdgreetings_civix_civicrm_xmlMenu($files);
}

/**
 * Implements hook_civicrm_install().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_install
 */
function householdgreetings_civicrm_install() {
  $extensionDir = dirname( __FILE__ ) . DIRECTORY_SEPARATOR;
  $customDataXMLFile = $extensionDir . '/xml/auto_install.xml';
  $import = new CRM_Utils_Migrate_Import();
  $import->run($customDataXMLFile);
  _householdgreetings_civix_civicrm_install();
}

/**
 * Implements hook_civicrm_postInstall().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_postInstall
 */
function householdgreetings_civicrm_postInstall() {
  _householdgreetings_civix_civicrm_postInstall();
}

/**
 * Implements hook_civicrm_uninstall().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_uninstall
 */
function householdgreetings_civicrm_uninstall() {
  $queries = [
    "DROP TABLE IF EXISTS civicrm_value_contact_joint_greetings",
    "DELETE cf.*
      FROM civicrm_custom_field cf
        INNER JOIN civicrm_custom_group cg on cf.custom_group_id = cg.id
      WHERE cg.name = 'contact_joint_greetings'",
    "DELETE FROM `civicrm_custom_group`
      WHERE table_name = 'civicrm_value_contact_joint_greetings'
        AND name = 'contact_joint_greetings'",
  ];
  foreach ($queries as $query) {
    CRM_Core_DAO::executeQuery($query);
  }
  _householdgreetings_civix_civicrm_uninstall();
}

/**
 * Implements hook_civicrm_enable().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_enable
 */
function householdgreetings_civicrm_enable() {
  CRM_Core_DAO::executeQuery("
    UPDATE civicrm_custom_group
    SET is_active = 1
    WHERE name = 'contact_joint_greetings'
  ");
  _householdgreetings_civix_civicrm_enable();
}

/**
 * Implements hook_civicrm_disable().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_disable
 */
function householdgreetings_civicrm_disable() {
  CRM_Core_DAO::executeQuery("
    UPDATE civicrm_custom_group
    SET is_active = 0
    WHERE name = 'contact_joint_greetings'
  ");
  _householdgreetings_civix_civicrm_disable();
}

/**
 * Implements hook_civicrm_upgrade().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_upgrade
 */
function householdgreetings_civicrm_upgrade($op, CRM_Queue_Queue $queue = NULL) {
  return _householdgreetings_civix_civicrm_upgrade($op, $queue);
}

/**
 * Implements hook_civicrm_managed().
 *
 * Generate a list of entities to create/deactivate/delete when this module
 * is installed, disabled, uninstalled.
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_managed
 */
function householdgreetings_civicrm_managed(&$entities) {
  $entities[] = array(
    'module' => 'com.chabadsuite.householdgreetings',
    'name' => 'customSearch',
    'update' => 'never',
    'entity' => 'OptionValue',
    'params' => array(
      'label' => 'CRM_Contact_Form_Search_Custom_HouseholdSearch',
      'is_active' => 1,
      'version' => 3,
      'option_group_id' => 'custom_search',
      'description' => ts('Household Search'),
    ),
  );
  _householdgreetings_civix_civicrm_managed($entities);
}

/**
 * Implements hook_civicrm_caseTypes().
 *
 * Generate a list of case-types.
 *
 * Note: This hook only runs in CiviCRM 4.4+.
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_caseTypes
 */
function householdgreetings_civicrm_caseTypes(&$caseTypes) {
  _householdgreetings_civix_civicrm_caseTypes($caseTypes);
}

/**
 * Implements hook_civicrm_angularModules().
 *
 * Generate a list of Angular modules.
 *
 * Note: This hook only runs in CiviCRM 4.5+. It may
 * use features only available in v4.6+.
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_angularModules
 */
function householdgreetings_civicrm_angularModules(&$angularModules) {
  _householdgreetings_civix_civicrm_angularModules($angularModules);
}

/**
 * Implements hook_civicrm_alterSettingsFolders().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_alterSettingsFolders
 */
function householdgreetings_civicrm_alterSettingsFolders(&$metaDataFolders = NULL) {
  _householdgreetings_civix_civicrm_alterSettingsFolders($metaDataFolders);
}

/**
 * Implements hook_civicrm_post().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_post
 */
function householdgreetings_civicrm_post($op, $objectName, $objectId, &$objectRef) {
  if (in_array(strtolower($objectName), ['individual', 'relationship'])
    && in_array($op, ['create', 'edit', 'delete'])
  ) {
    CRM_Utils_GreetingHelper::addUpdateJointGreetings($op, $objectName, $objectId);
  }
}
/**
 * Implements hook_civicrm_post().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_post
 */
function householdgreetings_civicrm_pre($op, $objectName, $id, &$params) {
  if (in_array(strtolower($objectName), ['individual', 'relationship'])
    && in_array($op, ['delete'])
  ) {
    $contactId = $id;
    if ($objectName != 'Individual') {
      $contactId = CRM_Core_DAO::singleValueQuery(
        "SELECT contact_id_a FROM civicrm_relationship WHERE id = {$id}"
      );
    }
    $contactIds = CRM_Utils_GreetingHelper::getContactIds($contactId);
    CRM_Core_Smarty::singleton()->assign("{$objectName}_{$id}", $contactIds);
  }
}

/**
 * Implements hook_civicrm_navigationMenu().
 *
 * @link http://wiki.civicrm.org/confluence/display/CRMDOC/hook_civicrm_navigationMenu
 *
 */
function householdgreetings_civicrm_navigationMenu(&$menu) {
  _householdgreetings_civix_insert_navigation_menu($menu, 'Contacts', array(
    'name' => 'Update Contacts Greetings',
    'url' => CRM_Utils_System::url('civicrm/contact/greetings/update', 'reset=1', TRUE),
    'permission' => 'administer CiviCRM',
  ));
  _householdgreetings_civix_navigationMenu($menu);
}
