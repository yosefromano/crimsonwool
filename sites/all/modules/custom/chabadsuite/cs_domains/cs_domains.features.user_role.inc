<?php
/**
 * @file
 * cs_domains.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cs_domains_user_default_roles() {
  $roles = array();

  // Exported role: CS Domain Admin.
  $roles['CS Domain Admin'] = array(
    'name' => 'CS Domain Admin',
    'weight' => 6,
  );

  return $roles;
}
