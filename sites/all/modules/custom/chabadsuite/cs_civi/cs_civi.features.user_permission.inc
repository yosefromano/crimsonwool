<?php
/**
 * @file
 * cs_civi.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cs_civi_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer advanced CiviCRM features'.
  $permissions['administer advanced CiviCRM features'] = array(
    'name' => 'administer advanced CiviCRM features',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  return $permissions;
}
