<?php
/**
 * @file
 * cs_mobileapp.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cs_mobileapp_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'app_activity';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'civicrm_activity';
  $view->human_name = 'App Activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'activity_type' => 'activity_type',
    'display_name_1' => 'display_name_1',
    'activity_date_time' => 'activity_date_time',
    'details' => 'details',
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = 'activity_date_time';
  $handler->display->display_options['style_options']['info'] = array(
    'activity_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'display_name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'activity_date_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'details' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<style>
.logo, .fcrm-footer, .main-nav, .l-footer, .l-triptych, .top-bar, .block-views-menubar-block-2 {
    display:none;
}
#admin-menu, #admin-menu .dropdown {
    display: none;
}
table.views-table {
    width: 100%;
}
</style>

<br /><div class="large-12" style="background:#888; text-align:center; font-color:#fff;"><a href= "/mobileapp" style="font-size=1.2em; color:#fff; font-weight:bold;"><i class="fa fa-arrow-left" aria-hidden="true"></i> APP HOME</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<style>
.logo, .fcrm-footer, .main-nav, .l-footer, .l-triptych, .top-bar {
    display:none;
}
#admin-menu, #admin-menu .dropdown {
    display: none;
}
table.views-table {
    width: 100%;
}

h1{
color: #21A367;
text-align:center;
}

</style>
<div>
<h1> No Data To Display </h1>
</div>

<br /><div class="large-12" style="background:#888; text-align:center; font-color:#fff;"><a href= "/mobileapp" style="font-size=1.2em; color:#fff; font-weight:bold;"><i class="fa fa-arrow-left" aria-hidden="true"></i> APP HOME</a></div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
  $handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['relationships']['contact_id']['table'] = 'civicrm_activity_contact';
  $handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['relationships']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['relationships']['contact_id']['record_type'] = '1';
  /* Relationship: CiviCRM Contacts: Drupal ID */
  $handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
  $handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
  $handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
  $handler->display->display_options['relationships']['drupal_id']['relationship'] = 'contact_id';
  /* Relationship: CiviCRM Activity Contacts: Activity Contact ID */
  $handler->display->display_options['relationships']['contact_id_1']['id'] = 'contact_id_1';
  $handler->display->display_options['relationships']['contact_id_1']['table'] = 'civicrm_activity_contact';
  $handler->display->display_options['relationships']['contact_id_1']['field'] = 'contact_id';
  $handler->display->display_options['relationships']['contact_id_1']['label'] = 'Activity target ID';
  $handler->display->display_options['relationships']['contact_id_1']['record_type'] = '3';
  /* Field: CiviCRM Email: Email Address */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['email']['label'] = '';
  $handler->display->display_options['fields']['email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['email']['alter']['text'] = '<a href="mailto:[email]" target="_top"><i class="fa fa-envelope" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['email']['location_type'] = '0';
  $handler->display->display_options['fields']['email']['location_op'] = '0';
  $handler->display->display_options['fields']['email']['is_primary'] = 0;
  $handler->display->display_options['fields']['email']['link_to_user'] = '0';
  /* Field: CiviCRM Phone Details: Phone Number */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['phone']['label'] = '';
  $handler->display->display_options['fields']['phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['phone']['alter']['text'] = '<a href="tel:[phone]"><i class="fa fa-phone" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['phone']['location_type'] = '0';
  $handler->display->display_options['fields']['phone']['location_op'] = '0';
  $handler->display->display_options['fields']['phone']['is_primary'] = 1;
  $handler->display->display_options['fields']['phone']['phone_type'] = '0';
  /* Field: CiviCRM Activities: Activity Type */
  $handler->display->display_options['fields']['activity_type']['id'] = 'activity_type';
  $handler->display->display_options['fields']['activity_type']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['activity_type']['field'] = 'activity_type';
  $handler->display->display_options['fields']['activity_type']['label'] = '';
  $handler->display->display_options['fields']['activity_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_type']['element_label_colon'] = FALSE;
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name_1']['id'] = 'display_name_1';
  $handler->display->display_options['fields']['display_name_1']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name_1']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name_1']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['display_name_1']['label'] = 'To Do';
  $handler->display->display_options['fields']['display_name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['display_name_1']['alter']['text'] = '[activity_type] with [display_name_1] <br /> [phone]  [email]';
  $handler->display->display_options['fields']['display_name_1']['link_to_civicrm_contact'] = 1;
  /* Field: CiviCRM Activities: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  /* Field: CiviCRM Activities: Scheduled Activity Date */
  $handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
  $handler->display->display_options['fields']['activity_date_time']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
  $handler->display->display_options['fields']['activity_date_time']['date_format'] = 'short';
  $handler->display->display_options['fields']['activity_date_time']['second_date_format'] = 'long';
  /* Field: CiviCRM Activities: Activity ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'drupal_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: CiviCRM Activities: Activity Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'civicrm_activity';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: CiviCRM Activities: Scheduled Activity Date */
  $handler->display->display_options['filters']['activity_date_time']['id'] = 'activity_date_time';
  $handler->display->display_options['filters']['activity_date_time']['table'] = 'civicrm_activity';
  $handler->display->display_options['filters']['activity_date_time']['field'] = 'activity_date_time';
  $handler->display->display_options['filters']['activity_date_time']['operator'] = '>';
  $handler->display->display_options['filters']['activity_date_time']['value']['value'] = '-3 months';
  $handler->display->display_options['filters']['activity_date_time']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['activity_date_time']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CiviCRM Email: Email Address */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['email']['label'] = '';
  $handler->display->display_options['fields']['email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['email']['alter']['text'] = '<a href="mailto:[email]" target="_top"><i class="fa fa-envelope" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['email']['location_type'] = '0';
  $handler->display->display_options['fields']['email']['location_op'] = '0';
  $handler->display->display_options['fields']['email']['is_primary'] = 0;
  $handler->display->display_options['fields']['email']['link_to_user'] = '0';
  /* Field: CiviCRM Phone Details: Phone Number */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['phone']['label'] = '';
  $handler->display->display_options['fields']['phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['phone']['alter']['text'] = '<a href="tel:[phone]"><i class="fa fa-phone" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['phone']['location_type'] = '0';
  $handler->display->display_options['fields']['phone']['location_op'] = '0';
  $handler->display->display_options['fields']['phone']['is_primary'] = 1;
  $handler->display->display_options['fields']['phone']['phone_type'] = '0';
  /* Field: CiviCRM Activities: Activity Type */
  $handler->display->display_options['fields']['activity_type']['id'] = 'activity_type';
  $handler->display->display_options['fields']['activity_type']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['activity_type']['field'] = 'activity_type';
  $handler->display->display_options['fields']['activity_type']['label'] = '';
  $handler->display->display_options['fields']['activity_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_type']['element_label_colon'] = FALSE;
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name_1']['id'] = 'display_name_1';
  $handler->display->display_options['fields']['display_name_1']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name_1']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name_1']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['display_name_1']['label'] = 'To Do';
  $handler->display->display_options['fields']['display_name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['display_name_1']['alter']['text'] = '[activity_type] with [display_name_1] <br /> [phone]  [email]';
  $handler->display->display_options['fields']['display_name_1']['link_to_civicrm_contact'] = 1;
  /* Field: CiviCRM Activities: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  /* Field: CiviCRM Activities: Scheduled Activity Date */
  $handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
  $handler->display->display_options['fields']['activity_date_time']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
  $handler->display->display_options['fields']['activity_date_time']['date_format'] = 'short';
  $handler->display->display_options['fields']['activity_date_time']['second_date_format'] = 'long';
  /* Field: CiviCRM Activities: Activity ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/mobileapp/activities/details/[id]">Details</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'mobileapp/activities';

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<style>
.logo, .fcrm-footer, .main-nav, .l-footer, .l-triptych, .top-bar, .block-views-menubar-block-2 {
    display:none;
}
#admin-menu, #admin-menu .dropdown {
    display: none;
}
table.views-table {
    width: 100%;
}

table {
    margin: 0 auto;
}
h2{
text-align:center;
color:#22B573 !important
}
</style>

<br /><div class="large-12" style="background:#888; text-align:center; font-color:#fff;"><a href= "/mobileapp/activities" style="font-size=1.2em; color:#fff; font-weight:bold;"><i class="fa fa-arrow-left" aria-hidden="true"></i> All My Activities</a></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CiviCRM Email: Email Address */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['email']['label'] = '';
  $handler->display->display_options['fields']['email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['email']['alter']['text'] = '<a href="mailto:[email]" target="_top"><i class="fa fa-envelope" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['email']['location_type'] = '0';
  $handler->display->display_options['fields']['email']['location_op'] = '0';
  $handler->display->display_options['fields']['email']['is_primary'] = 0;
  $handler->display->display_options['fields']['email']['link_to_user'] = '0';
  /* Field: CiviCRM Phone Details: Phone Number */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['phone']['label'] = '';
  $handler->display->display_options['fields']['phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['phone']['alter']['text'] = '<a href="tel:[phone]"><i class="fa fa-phone" aria-hidden="true"></i></a>';
  $handler->display->display_options['fields']['phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['phone']['location_type'] = '0';
  $handler->display->display_options['fields']['phone']['location_op'] = '0';
  $handler->display->display_options['fields']['phone']['is_primary'] = 1;
  $handler->display->display_options['fields']['phone']['phone_type'] = '0';
  /* Field: CiviCRM Activities: Activity Type */
  $handler->display->display_options['fields']['activity_type']['id'] = 'activity_type';
  $handler->display->display_options['fields']['activity_type']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['activity_type']['field'] = 'activity_type';
  $handler->display->display_options['fields']['activity_type']['label'] = '';
  $handler->display->display_options['fields']['activity_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_type']['element_label_colon'] = FALSE;
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name_1']['id'] = 'display_name_1';
  $handler->display->display_options['fields']['display_name_1']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name_1']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name_1']['relationship'] = 'contact_id_1';
  $handler->display->display_options['fields']['display_name_1']['label'] = '';
  $handler->display->display_options['fields']['display_name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['display_name_1']['alter']['text'] = '<center><h2>[activity_type] with [display_name_1] <br /></h2></center>
<div class="center"> [phone]  [email]</div';
  $handler->display->display_options['fields']['display_name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['display_name_1']['link_to_civicrm_contact'] = 1;
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['relationship'] = 'drupal_id';
  $handler->display->display_options['fields']['display_name']['label'] = '';
  $handler->display->display_options['fields']['display_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['display_name']['empty'] = 'N/A';
  $handler->display->display_options['fields']['display_name']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
  /* Field: CiviCRM Activities: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  $handler->display->display_options['fields']['subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['subject']['empty'] = 'N/A';
  $handler->display->display_options['fields']['subject']['hide_alter_empty'] = FALSE;
  /* Field: CiviCRM Activities: Scheduled Activity Date */
  $handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
  $handler->display->display_options['fields']['activity_date_time']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
  $handler->display->display_options['fields']['activity_date_time']['label'] = '';
  $handler->display->display_options['fields']['activity_date_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_date_time']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['activity_date_time']['date_format'] = 'short';
  $handler->display->display_options['fields']['activity_date_time']['second_date_format'] = 'long';
  /* Field: CiviCRM Activities: Activity ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: CiviCRM Activities: Activity Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = FALSE;
  /* Field: CiviCRM Activities: Duration (min) */
  $handler->display->display_options['fields']['duration']['id'] = 'duration';
  $handler->display->display_options['fields']['duration']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['duration']['field'] = 'duration';
  $handler->display->display_options['fields']['duration']['label'] = '';
  $handler->display->display_options['fields']['duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['duration']['alter']['text'] = '[duration] Minutes';
  $handler->display->display_options['fields']['duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['duration']['hide_alter_empty'] = FALSE;
  /* Field: CiviCRM Activities: Priority */
  $handler->display->display_options['fields']['priority']['id'] = 'priority';
  $handler->display->display_options['fields']['priority']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['priority']['field'] = 'priority';
  $handler->display->display_options['fields']['priority']['label'] = '';
  $handler->display->display_options['fields']['priority']['exclude'] = TRUE;
  $handler->display->display_options['fields']['priority']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['priority']['empty'] = 'N/A';
  $handler->display->display_options['fields']['priority']['hide_alter_empty'] = FALSE;
  /* Field: CiviCRM Activities: Details */
  $handler->display->display_options['fields']['details']['id'] = 'details';
  $handler->display->display_options['fields']['details']['table'] = 'civicrm_activity';
  $handler->display->display_options['fields']['details']['field'] = 'details';
  $handler->display->display_options['fields']['details']['label'] = '';
  $handler->display->display_options['fields']['details']['exclude'] = TRUE;
  $handler->display->display_options['fields']['details']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['details']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['details']['empty'] = 'N/A';
  $handler->display->display_options['fields']['details']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['details']['text_format'] = 'full_html';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<table>
<tbody>
<tr>
<td><label>Assigned to</label></td>
<td>[display_name]</td>
</tr>
<tr>
<td><label>Subject</label></td>
<td>[subject]</td>
</tr>
<tr>
<td><label>Date/Time</label></td>
<td>[activity_date_time]</td>
</tr>
<tr>
<td><label>Status</label></td>
<td>[status]</td>
</tr>
<tr>
<td><label>Duration</label></td>
<td>[duration]</td>
</tr>
<tr>
<td><label>Priority</label></td>
<td>[priority]</td>
</tr>
<tr>
<td><label>Details</label></td>
<td>[details]</td>
</tr>
</tbody>
</table>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CiviCRM Activities: Activity ID */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'civicrm_activity';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['id']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'mobileapp/activities/details/%';
  $export['app_activity'] = $view;

  $view = new view();
  $view->name = 'contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'civicrm_contact';
  $view->human_name = 'MOBILEAPP CONTACTS';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all contacts';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'display_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'large-12 columns app-table';
  $handler->display->display_options['style_options']['columns'] = array(
    'display_name' => 'display_name',
    'street_address' => 'street_address',
    'postal_code' => 'postal_code',
    'state_province' => 'state_province',
    'phone' => 'phone',
    'email' => 'email',
  );
  $handler->display->display_options['style_options']['default'] = 'display_name';
  $handler->display->display_options['style_options']['info'] = array(
    'display_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'street_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'postal_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'state_province' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<style>
.logo, .fcrm-footer, .main-nav, .l-footer, .l-triptych, .top-bar {
    display:none;
}
#admin-menu, #admin-menu .dropdown {
    display: none;
}
table.views-table {
    width: 100%;
}
</style>

<br /><div class="large-12" style="background:#888; text-align:center; font-color:#fff;"><a href= "/mobileapp" style="font-size=1.2em; color:#fff; font-weight:bold;"><i class="fa fa-arrow-left" aria-hidden="true"></i> APP HOME</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<style>
.logo, .fcrm-footer, .main-nav, .l-footer, .l-triptych, .top-bar {
    display:none;
}
#admin-menu, #admin-menu .dropdown {
    display: none;
}
table.views-table {
    width: 100%;
}

h1{
color: #21A367;
text-align:center;
}

</style>
<div>
<h1> No Data To Display </h1>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['label'] = '';
  $handler->display->display_options['fields']['display_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['display_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['display_name']['alter']['text'] = '<br />
[display_name]';
  $handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 1;
  /* Field: CiviCRM Address: Full Street Address */
  $handler->display->display_options['fields']['street_address']['id'] = 'street_address';
  $handler->display->display_options['fields']['street_address']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['street_address']['field'] = 'street_address';
  $handler->display->display_options['fields']['street_address']['label'] = '';
  $handler->display->display_options['fields']['street_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['street_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['street_address']['alter']['text'] = '[street_address],';
  $handler->display->display_options['fields']['street_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['street_address']['location_type'] = '0';
  $handler->display->display_options['fields']['street_address']['location_op'] = '0';
  $handler->display->display_options['fields']['street_address']['is_primary'] = 0;
  $handler->display->display_options['fields']['street_address']['is_billing'] = 0;
  /* Field: CiviCRM Address: ZIP / Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['label'] = '';
  $handler->display->display_options['fields']['postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['postal_code']['location_type'] = '0';
  $handler->display->display_options['fields']['postal_code']['location_op'] = '0';
  $handler->display->display_options['fields']['postal_code']['is_primary'] = 0;
  $handler->display->display_options['fields']['postal_code']['is_billing'] = 0;
  /* Field: CiviCRM Address: State/Province */
  $handler->display->display_options['fields']['state_province']['id'] = 'state_province';
  $handler->display->display_options['fields']['state_province']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['state_province']['field'] = 'state_province';
  $handler->display->display_options['fields']['state_province']['label'] = '';
  $handler->display->display_options['fields']['state_province']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['state_province']['alter']['text'] = '<a href="http://maps.google.com/?q=[street_address] [state_province] [postal_code]"><i class="fa fa-map-marker" aria-hidden="true" style="color:#6d6a6a;"></i> [street_address] [state_province] [postal_code]</a>';
  $handler->display->display_options['fields']['state_province']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['state_province']['empty'] = '<i class="fa fa-map-marker" aria-hidden="true"></i> <em>No Address Found</em>';
  $handler->display->display_options['fields']['state_province']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['state_province']['location_type'] = '0';
  $handler->display->display_options['fields']['state_province']['location_op'] = '0';
  $handler->display->display_options['fields']['state_province']['is_primary'] = 0;
  $handler->display->display_options['fields']['state_province']['is_billing'] = 0;
  $handler->display->display_options['fields']['state_province']['prov_display'] = '1';
  /* Field: CiviCRM Phone Details: Phone Number */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['label'] = '';
  $handler->display->display_options['fields']['phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['phone']['alter']['text'] = '<a href="tel:[phone]" style="color:#6d6a6a;"><i class="fa fa-phone" aria-hidden="true" style="color:#6d6a6a;"></i> [phone]</a>';
  $handler->display->display_options['fields']['phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['phone']['empty'] = '<i class="fa fa-phone" aria-hidden="true"></i><em> No Phone Number</em>';
  $handler->display->display_options['fields']['phone']['location_type'] = '0';
  $handler->display->display_options['fields']['phone']['location_op'] = '0';
  $handler->display->display_options['fields']['phone']['is_primary'] = 0;
  $handler->display->display_options['fields']['phone']['phone_type'] = '0';
  /* Field: CiviCRM Email: Email Address */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['label'] = '';
  $handler->display->display_options['fields']['email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['email']['alter']['text'] = '<a href="mailto:[email]" target="_top" style="color:#6d6a6a;"><i class="fa fa-envelope" aria-hidden="true" style="color:#6d6a6a;"></i></a>';
  $handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['email']['location_type'] = '0';
  $handler->display->display_options['fields']['email']['location_op'] = '0';
  $handler->display->display_options['fields']['email']['is_primary'] = 1;
  $handler->display->display_options['fields']['email']['link_to_user'] = '0';
  /* Filter criterion: CiviCRM Contacts: Display Name */
  $handler->display->display_options['filters']['display_name']['id'] = 'display_name';
  $handler->display->display_options['filters']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['filters']['display_name']['field'] = 'display_name';
  $handler->display->display_options['filters']['display_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['display_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['display_name']['expose']['operator_id'] = 'display_name_op';
  $handler->display->display_options['filters']['display_name']['expose']['label'] = 'Search Contact List';
  $handler->display->display_options['filters']['display_name']['expose']['operator'] = 'display_name_op';
  $handler->display->display_options['filters']['display_name']['expose']['identifier'] = 'display_name';
  $handler->display->display_options['filters']['display_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<style>
.logo, .fcrm-footer, .main-nav, .l-footer, .l-triptych, .top-bar, .block-views-menubar-block-2 {
    display:none;
}
#admin-menu, #admin-menu .dropdown {
    display: none;
}
table.views-table {
    width: 100%;
}

.views-exposed-form .views-exposed-widget .form-submit {
    margin-top: 1em;
}

</style>

<br /><div class="large-12" style="background:#888; text-align:center; font-color:#fff;"><a href= "/mobileapp" style="font-size=1.2em; color:#fff; font-weight:bold;"><i class="fa fa-arrow-left" aria-hidden="true"></i> APP HOME</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<style>
.logo, .fcrm-footer, .main-nav, .l-footer, .l-triptych, .top-bar {
    display:none;
}
#admin-menu, #admin-menu .dropdown {
    display: none;
}
table.views-table {
    width: 100%;
}

h1{
color: #21A367;
text-align:center;
}

</style>
<div>
<h1> No Data To Display </h1>
</div>

<br /><div class="large-12" style="background:#888; text-align:center; font-color:#fff;"><a href= "/mobileapp" style="font-size=1.2em; color:#fff; font-weight:bold;"><i class="fa fa-arrow-left" aria-hidden="true"></i> APP HOME</a></div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'mobileapp/contacts';

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'contact_id',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<style>
.logo, .fcrm-footer, .main-nav, .l-footer, .l-triptych, .top-bar, .block-views-menubar-block-2 {
    display:none;
}
#admin-menu, #admin-menu .dropdown {
    display: none;
}
i {color:#fff;}
</style>

<div class="cloud-logo">
		
	</div>


<div class="large-12">
<div class="large-6 columns" style="height:100px">
<div class="large-12" style="background:#21A367; text-align:center; color:#fff;">
<div class="small-4 small-centered columns" style="text-align:center">
<a href="/mobileapp/contacts"><i class="fa fa-user" aria-hidden="true" style="font-size:4em; text-align:center"></i><h6 style="text-align:center; font-size:20px; color:#fff;">CONTACTS</h6></a>
</div></div></div>
<div class="large-6 columns" style="height:100px">
<div class="large-12" style="background:#21A367; text-align:center color:#fff;">
<div class="small-4 small-centered columns" style="text-align:center">
<a href="/mobileapp/activities"><i class="fa fa-list-alt" aria-hidden="true" style="font-size:4em; text-align:center;"></i>
<h6 style="text-align:center; font-size:20px; color:#fff;">Activities</h6></a>
</div></div></div>

</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CiviCRM Address: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['alter']['text'] = '<p> </p>';
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: CiviCRM Address: Contact ID */
  $handler->display->display_options['filters']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['table'] = 'civicrm_address';
  $handler->display->display_options['filters']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['value']['value'] = '2';
  $handler->display->display_options['path'] = 'mobileapp';
  $export['contacts'] = $view;

  return $export;
}
