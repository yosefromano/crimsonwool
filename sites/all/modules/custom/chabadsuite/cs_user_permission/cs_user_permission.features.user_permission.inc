<?php
/**
 * @file
 * cs_user_permission.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cs_user_permission_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access AJAX API'.
  $permissions['access AJAX API'] = array(
    'name' => 'access AJAX API',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviCRM'.
  $permissions['access CiviCRM'] = array(
    'name' => 'access CiviCRM',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'CRON' => 'CRON',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviCRM activity iCalendar feed'.
  $permissions['access CiviCRM activity iCalendar feed'] = array(
    'name' => 'access CiviCRM activity iCalendar feed',
    'roles' => array(),
    'module' => 'civicrm_activity_ical',
  );

  // Exported permission: 'access CiviContribute'.
  $permissions['access CiviContribute'] = array(
    'name' => 'access CiviContribute',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviEvent'.
  $permissions['access CiviEvent'] = array(
    'name' => 'access CiviEvent',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviMail'.
  $permissions['access CiviMail'] = array(
    'name' => 'access CiviMail',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'CRON' => 'CRON',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviMail subscribe/unsubscribe pages'.
  $permissions['access CiviMail subscribe/unsubscribe pages'] = array(
    'name' => 'access CiviMail subscribe/unsubscribe pages',
    'roles' => array(
      'CRON' => 'CRON',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviPledge'.
  $permissions['access CiviPledge'] = array(
    'name' => 'access CiviPledge',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviReport'.
  $permissions['access CiviReport'] = array(
    'name' => 'access CiviReport',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Contact Dashboard'.
  $permissions['access Contact Dashboard'] = array(
    'name' => 'access Contact Dashboard',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Report Criteria'.
  $permissions['access Report Criteria'] = array(
    'name' => 'access Report Criteria',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all custom data'.
  $permissions['access all custom data'] = array(
    'name' => 'access all custom data',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'access civicrm group role setting'.
  $permissions['access civicrm group role setting'] = array(
    'name' => 'access civicrm group role setting',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm_group_roles',
  );

  // Exported permission: 'access civicrm member role setting'.
  $permissions['access civicrm member role setting'] = array(
    'name' => 'access civicrm member role setting',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm_member_roles',
  );

  // Exported permission: 'access civicrm rules settings'.
  $permissions['access civicrm rules settings'] = array(
    'name' => 'access civicrm rules settings',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm_rules',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access contact reference fields'.
  $permissions['access contact reference fields'] = array(
    'name' => 'access contact reference fields',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(),
    'module' => 'dashboard',
  );

  // Exported permission: 'access deleted contacts'.
  $permissions['access deleted contacts'] = array(
    'name' => 'access deleted contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access uploaded files'.
  $permissions['access uploaded files'] = array(
    'name' => 'access uploaded files',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add JS snippets for google analytics'.
  $permissions['add JS snippets for google analytics'] = array(
    'name' => 'add JS snippets for google analytics',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'add contacts'.
  $permissions['add contacts'] = array(
    'name' => 'add contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer CiviCRM'.
  $permissions['administer CiviCRM'] = array(
    'name' => 'administer CiviCRM',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer CiviCampaign'.
  $permissions['administer CiviCampaign'] = array(
    'name' => 'administer CiviCampaign',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer Reports'.
  $permissions['administer Reports'] = array(
    'name' => 'administer Reports',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer Tagsets'.
  $permissions['administer Tagsets'] = array(
    'name' => 'administer Tagsets',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer custom formatters'.
  $permissions['administer custom formatters'] = array(
    'name' => 'administer custom formatters',
    'roles' => array(),
    'module' => 'custom_formatters',
  );

  // Exported permission: 'administer dedupe rules'.
  $permissions['administer dedupe rules'] = array(
    'name' => 'administer dedupe rules',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer payment processors'.
  $permissions['administer payment processors'] = array(
    'name' => 'administer payment processors',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(),
    'module' => 'redirect',
  );

  // Exported permission: 'administer reserved groups'.
  $permissions['administer reserved groups'] = array(
    'name' => 'administer reserved groups',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer reserved reports'.
  $permissions['administer reserved reports'] = array(
    'name' => 'administer reserved reports',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer reserved tags'.
  $permissions['administer reserved tags'] = array(
    'name' => 'administer reserved tags',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer smtp module'.
  $permissions['administer smtp module'] = array(
    'name' => 'administer smtp module',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'smtp',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'views',
  );

  // Exported permission: 'allow plupload'.
  $permissions['allow plupload'] = array(
    'name' => 'allow plupload',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'plup',
  );

  // Exported permission: 'assign CIVI ADMIN role'.
  $permissions['assign CIVI ADMIN role'] = array(
    'name' => 'assign CIVI ADMIN role',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign CIVI EDITOR role'.
  $permissions['assign CIVI EDITOR role'] = array(
    'name' => 'assign CIVI EDITOR role',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign VIEW CIVI role'.
  $permissions['assign VIEW CIVI role'] = array(
    'name' => 'assign VIEW CIVI role',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'civicrm_entity.rules.administer'.
  $permissions['civicrm_entity.rules.administer'] = array(
    'name' => 'civicrm_entity.rules.administer',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm_entity',
  );

  // Exported permission: 'create all_images content'.
  $permissions['create all_images content'] = array(
    'name' => 'create all_images content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create homepage_slideshow content'.
  $permissions['create homepage_slideshow content'] = array(
    'name' => 'create homepage_slideshow content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create manual batch'.
  $permissions['create manual batch'] = array(
    'name' => 'create manual batch',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create photo_gallery content'.
  $permissions['create photo_gallery content'] = array(
    'name' => 'create photo_gallery content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create team content'.
  $permissions['create team content'] = array(
    'name' => 'create team content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete activities'.
  $permissions['delete activities'] = array(
    'name' => 'delete activities',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete all manual batches'.
  $permissions['delete all manual batches'] = array(
    'name' => 'delete all manual batches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any all_images content'.
  $permissions['delete any all_images content'] = array(
    'name' => 'delete any all_images content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any homepage_slideshow content'.
  $permissions['delete any homepage_slideshow content'] = array(
    'name' => 'delete any homepage_slideshow content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any photo_gallery content'.
  $permissions['delete any photo_gallery content'] = array(
    'name' => 'delete any photo_gallery content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any team content'.
  $permissions['delete any team content'] = array(
    'name' => 'delete any team content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete contacts'.
  $permissions['delete contacts'] = array(
    'name' => 'delete contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete in CiviContribute'.
  $permissions['delete in CiviContribute'] = array(
    'name' => 'delete in CiviContribute',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete in CiviEvent'.
  $permissions['delete in CiviEvent'] = array(
    'name' => 'delete in CiviEvent',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete in CiviMail'.
  $permissions['delete in CiviMail'] = array(
    'name' => 'delete in CiviMail',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'CRON' => 'CRON',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete in CiviPledge'.
  $permissions['delete in CiviPledge'] = array(
    'name' => 'delete in CiviPledge',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete own all_images content'.
  $permissions['delete own all_images content'] = array(
    'name' => 'delete own all_images content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own homepage_slideshow content'.
  $permissions['delete own homepage_slideshow content'] = array(
    'name' => 'delete own homepage_slideshow content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own manual batches'.
  $permissions['delete own manual batches'] = array(
    'name' => 'delete own manual batches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own photo_gallery content'.
  $permissions['delete own photo_gallery content'] = array(
    'name' => 'delete own photo_gallery content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own team content'.
  $permissions['delete own team content'] = array(
    'name' => 'delete own team content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in page_type'.
  $permissions['delete terms in page_type'] = array(
    'name' => 'delete terms in page_type',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all contacts'.
  $permissions['edit all contacts'] = array(
    'name' => 'edit all contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit all events'.
  $permissions['edit all events'] = array(
    'name' => 'edit all events',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit all manual batches'.
  $permissions['edit all manual batches'] = array(
    'name' => 'edit all manual batches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any all_images content'.
  $permissions['edit any all_images content'] = array(
    'name' => 'edit any all_images content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any homepage_slideshow content'.
  $permissions['edit any homepage_slideshow content'] = array(
    'name' => 'edit any homepage_slideshow content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any photo_gallery content'.
  $permissions['edit any photo_gallery content'] = array(
    'name' => 'edit any photo_gallery content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any team content'.
  $permissions['edit any team content'] = array(
    'name' => 'edit any team content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit api keys'.
  $permissions['edit api keys'] = array(
    'name' => 'edit api keys',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit contributions'.
  $permissions['edit contributions'] = array(
    'name' => 'edit contributions',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit event participants'.
  $permissions['edit event participants'] = array(
    'name' => 'edit event participants',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit groups'.
  $permissions['edit groups'] = array(
    'name' => 'edit groups',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit message templates'.
  $permissions['edit message templates'] = array(
    'name' => 'edit message templates',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit my contact'.
  $permissions['edit my contact'] = array(
    'name' => 'edit my contact',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit own all_images content'.
  $permissions['edit own all_images content'] = array(
    'name' => 'edit own all_images content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own api keys'.
  $permissions['edit own api keys'] = array(
    'name' => 'edit own api keys',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own homepage_slideshow content'.
  $permissions['edit own homepage_slideshow content'] = array(
    'name' => 'edit own homepage_slideshow content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own manual batches'.
  $permissions['edit own manual batches'] = array(
    'name' => 'edit own manual batches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own photo_gallery content'.
  $permissions['edit own photo_gallery content'] = array(
    'name' => 'edit own photo_gallery content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own team content'.
  $permissions['edit own team content'] = array(
    'name' => 'edit own team content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit pledges'.
  $permissions['edit pledges'] = array(
    'name' => 'edit pledges',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit terms in page_type'.
  $permissions['edit terms in page_type'] = array(
    'name' => 'edit terms in page_type',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'export all manual batches'.
  $permissions['export all manual batches'] = array(
    'name' => 'export all manual batches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'export own manual batches'.
  $permissions['export own manual batches'] = array(
    'name' => 'export own manual batches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'features',
  );

  // Exported permission: 'gotv campaign contacts'.
  $permissions['gotv campaign contacts'] = array(
    'name' => 'gotv campaign contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'import contacts'.
  $permissions['import contacts'] = array(
    'name' => 'import contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'interview campaign contacts'.
  $permissions['interview campaign contacts'] = array(
    'name' => 'interview campaign contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'make online contributions'.
  $permissions['make online contributions'] = array(
    'name' => 'make online contributions',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'manage campaign'.
  $permissions['manage campaign'] = array(
    'name' => 'manage campaign',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'manage event profiles'.
  $permissions['manage event profiles'] = array(
    'name' => 'manage event profiles',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'features',
  );

  // Exported permission: 'merge duplicate contacts'.
  $permissions['merge duplicate contacts'] = array(
    'name' => 'merge duplicate contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'profile create'.
  $permissions['profile create'] = array(
    'name' => 'profile create',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile edit'.
  $permissions['profile edit'] = array(
    'name' => 'profile edit',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile listings'.
  $permissions['profile listings'] = array(
    'name' => 'profile listings',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile listings and forms'.
  $permissions['profile listings and forms'] = array(
    'name' => 'profile listings and forms',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile view'.
  $permissions['profile view'] = array(
    'name' => 'profile view',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'register for events'.
  $permissions['register for events'] = array(
    'name' => 'register for events',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'release campaign contacts'.
  $permissions['release campaign contacts'] = array(
    'name' => 'release campaign contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'features',
  );

  // Exported permission: 'reserve campaign contacts'.
  $permissions['reserve campaign contacts'] = array(
    'name' => 'reserve campaign contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'user',
  );

  // Exported permission: 'sign CiviCRM Petition'.
  $permissions['sign CiviCRM Petition'] = array(
    'name' => 'sign CiviCRM Petition',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'skip IDS check'.
  $permissions['skip IDS check'] = array(
    'name' => 'skip IDS check',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'translate CiviCRM'.
  $permissions['translate CiviCRM'] = array(
    'name' => 'translate CiviCRM',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(),
    'module' => 'ctools',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format wysiwyg_'.
  $permissions['use text format wysiwyg_'] = array(
    'name' => 'use text format wysiwyg_',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view all activities'.
  $permissions['view all activities'] = array(
    'name' => 'view all activities',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all contacts'.
  $permissions['view all contacts'] = array(
    'name' => 'view all contacts',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'CRON' => 'CRON',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all manual batches'.
  $permissions['view all manual batches'] = array(
    'name' => 'view all manual batches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all notes'.
  $permissions['view all notes'] = array(
    'name' => 'view all notes',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view author on comment'.
  $permissions['view author on comment'] = array(
    'name' => 'view author on comment',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view author on node'.
  $permissions['view author on node'] = array(
    'name' => 'view author on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view changed_date on node'.
  $permissions['view changed_date on node'] = array(
    'name' => 'view changed_date on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view comments on node'.
  $permissions['view comments on node'] = array(
    'name' => 'view comments on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view debug output'.
  $permissions['view debug output'] = array(
    'name' => 'view debug output',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view ds_switch_field on node'.
  $permissions['view ds_switch_field on node'] = array(
    'name' => 'view ds_switch_field on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view ds_user_picture on comment'.
  $permissions['view ds_user_picture on comment'] = array(
    'name' => 'view ds_user_picture on comment',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view ds_user_picture on node'.
  $permissions['view ds_user_picture on node'] = array(
    'name' => 'view ds_user_picture on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view ds_user_picture on user'.
  $permissions['view ds_user_picture on user'] = array(
    'name' => 'view ds_user_picture on user',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view event info'.
  $permissions['view event info'] = array(
    'name' => 'view event info',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view event participants'.
  $permissions['view event participants'] = array(
    'name' => 'view event participants',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view links on comment'.
  $permissions['view links on comment'] = array(
    'name' => 'view links on comment',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view links on node'.
  $permissions['view links on node'] = array(
    'name' => 'view links on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view more_link on taxonomy_term'.
  $permissions['view more_link on taxonomy_term'] = array(
    'name' => 'view more_link on taxonomy_term',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view my contact'.
  $permissions['view my contact'] = array(
    'name' => 'view my contact',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view my invoices'.
  $permissions['view my invoices'] = array(
    'name' => 'view my invoices',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view name on user'.
  $permissions['view name on user'] = array(
    'name' => 'view name on user',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view node_link on node'.
  $permissions['view node_link on node'] = array(
    'name' => 'view node_link on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own manual batches'.
  $permissions['view own manual batches'] = array(
    'name' => 'view own manual batches',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view permalink on comment'.
  $permissions['view permalink on comment'] = array(
    'name' => 'view permalink on comment',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view post_date on comment'.
  $permissions['view post_date on comment'] = array(
    'name' => 'view post_date on comment',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view post_date on node'.
  $permissions['view post_date on node'] = array(
    'name' => 'view post_date on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view public CiviMail content'.
  $permissions['view public CiviMail content'] = array(
    'name' => 'view public CiviMail content',
    'roles' => array(
      'CRON' => 'CRON',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'SUPER ADMIN' => 'SUPER ADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view submitted on comment'.
  $permissions['view submitted on comment'] = array(
    'name' => 'view submitted on comment',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view submitted_by on node'.
  $permissions['view submitted_by on node'] = array(
    'name' => 'view submitted_by on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'CIVI ADMIN' => 'CIVI ADMIN',
      'CIVI EDITOR' => 'CIVI EDITOR',
      'DRUPAL ADMIN' => 'DRUPAL ADMIN',
      'SUPER ADMIN' => 'SUPER ADMIN',
      'VIEW CIVI' => 'VIEW CIVI',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view title on comment'.
  $permissions['view title on comment'] = array(
    'name' => 'view title on comment',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view title on node'.
  $permissions['view title on node'] = array(
    'name' => 'view title on node',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view title on taxonomy_term'.
  $permissions['view title on taxonomy_term'] = array(
    'name' => 'view title on taxonomy_term',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  return $permissions;
}
