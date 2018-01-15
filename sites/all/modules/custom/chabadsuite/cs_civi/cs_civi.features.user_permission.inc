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

  // Exported permission: 'administer restricted CiviCRM features'.
  $permissions['administer restricted CiviCRM features'] = array(
    'name' => 'administer restricted CiviCRM features',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  return $permissions;
}
