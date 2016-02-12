<?php
/**
 * @file
 * cs_core_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cs_core_roles_user_default_roles() {
  $roles = array();

  // Exported role: CIVI ADMIN.
  $roles['CIVI ADMIN'] = array(
    'name' => 'CIVI ADMIN',
    'weight' => 4,
  );

  // Exported role: CIVI EDITOR.
  $roles['CIVI EDITOR'] = array(
    'name' => 'CIVI EDITOR',
    'weight' => 5,
  );

  // Exported role: CRON.
  $roles['CRON'] = array(
    'name' => 'CRON',
    'weight' => 7,
  );

  // Exported role: DRUPAL ADMIN.
  $roles['DRUPAL ADMIN'] = array(
    'name' => 'DRUPAL ADMIN',
    'weight' => 3,
  );

  // Exported role: SUPER ADMIN.
  $roles['SUPER ADMIN'] = array(
    'name' => 'SUPER ADMIN',
    'weight' => 2,
  );

  // Exported role: VIEW CIVI.
  $roles['VIEW CIVI'] = array(
    'name' => 'VIEW CIVI',
    'weight' => 6,
  );

  return $roles;
}
