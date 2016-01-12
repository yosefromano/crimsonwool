<?php
/**
 * @file
 * cs_domains.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cs_domains_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access domain navigation'.
  $permissions['access domain navigation'] = array(
    'name' => 'access domain navigation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain_nav',
  );

  // Exported permission: 'access domain settings form'.
  $permissions['access domain settings form'] = array(
    'name' => 'access domain settings form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain_settings',
  );

  // Exported permission: 'access inactive domains'.
  $permissions['access inactive domains'] = array(
    'name' => 'access inactive domains',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'access the domain content page'.
  $permissions['access the domain content page'] = array(
    'name' => 'access the domain content page',
    'roles' => array(
      'CS Domain Admin' => 'CS Domain Admin',
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'domain_content',
  );

  // Exported permission: 'administer domains'.
  $permissions['administer domains'] = array(
    'name' => 'administer domains',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'assign domain editors'.
  $permissions['assign domain editors'] = array(
    'name' => 'assign domain editors',
    'roles' => array(
      'CS Domain Admin' => 'CS Domain Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete domain content'.
  $permissions['delete domain content'] = array(
    'name' => 'delete domain content',
    'roles' => array(
      'CS Domain Admin' => 'CS Domain Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'edit domain content'.
  $permissions['edit domain content'] = array(
    'name' => 'edit domain content',
    'roles' => array(
      'CS Domain Admin' => 'CS Domain Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'publish from assigned domain'.
  $permissions['publish from assigned domain'] = array(
    'name' => 'publish from assigned domain',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'publish from default domain'.
  $permissions['publish from default domain'] = array(
    'name' => 'publish from default domain',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'publish to any assigned domain'.
  $permissions['publish to any assigned domain'] = array(
    'name' => 'publish to any assigned domain',
    'roles' => array(
      'CS Domain Admin' => 'CS Domain Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'review content for all domains'.
  $permissions['review content for all domains'] = array(
    'name' => 'review content for all domains',
    'roles' => array(
      'CS Domain Admin' => 'CS Domain Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain_content',
  );

  // Exported permission: 'set domain access'.
  $permissions['set domain access'] = array(
    'name' => 'set domain access',
    'roles' => array(
      'CS Domain Admin' => 'CS Domain Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'view unpublished domain content'.
  $permissions['view unpublished domain content'] = array(
    'name' => 'view unpublished domain content',
    'roles' => array(
      'CS Domain Admin' => 'CS Domain Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  return $permissions;
}
