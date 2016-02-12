<?php
/**
 * @file
 * CS_VID_EVENT.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function CS_VID_EVENT_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'upcoming_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'civicrm_event';
  $view->human_name = 'Upcoming Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: CiviCRM Events: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'civicrm_event';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_civicrm_event'] = 'page';
  /* Field: CiviCRM Events: Start Date */
  $handler->display->display_options['fields']['start_date']['id'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['table'] = 'civicrm_event';
  $handler->display->display_options['fields']['start_date']['field'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['date_format'] = 'regular';
  $handler->display->display_options['fields']['start_date']['second_date_format'] = 'long';
  /* Field: CiviCRM Events: End Date */
  $handler->display->display_options['fields']['end_date']['id'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['table'] = 'civicrm_event';
  $handler->display->display_options['fields']['end_date']['field'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['date_format'] = 'regular';
  $handler->display->display_options['fields']['end_date']['second_date_format'] = 'long';
  /* Field: CiviCRM Events: Registration Link Text */
  $handler->display->display_options['fields']['registration_link_text']['id'] = 'registration_link_text';
  $handler->display->display_options['fields']['registration_link_text']['table'] = 'civicrm_event';
  $handler->display->display_options['fields']['registration_link_text']['field'] = 'registration_link_text';
  $handler->display->display_options['fields']['registration_link_text']['label'] = 'Register Now';
  $handler->display->display_options['fields']['registration_link_text']['link_to_civicrm_event'] = 'registration';
  /* Sort criterion: CiviCRM Events: Start Date */
  $handler->display->display_options['sorts']['start_date']['id'] = 'start_date';
  $handler->display->display_options['sorts']['start_date']['table'] = 'civicrm_event';
  $handler->display->display_options['sorts']['start_date']['field'] = 'start_date';
  $handler->display->display_options['sorts']['start_date']['granularity'] = 'hour';
  /* Filter criterion: CiviCRM Events: Start Date */
  $handler->display->display_options['filters']['start_date_1']['id'] = 'start_date_1';
  $handler->display->display_options['filters']['start_date_1']['table'] = 'civicrm_event';
  $handler->display->display_options['filters']['start_date_1']['field'] = 'start_date';
  $handler->display->display_options['filters']['start_date_1']['operator'] = '>';
  $handler->display->display_options['filters']['start_date_1']['value']['value'] = '-2 hours';
  $handler->display->display_options['filters']['start_date_1']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['start_date_1']['group'] = 1;
  /* Filter criterion: CiviCRM Events: Is Public */
  $handler->display->display_options['filters']['is_public']['id'] = 'is_public';
  $handler->display->display_options['filters']['is_public']['table'] = 'civicrm_event';
  $handler->display->display_options['filters']['is_public']['field'] = 'is_public';
  $handler->display->display_options['filters']['is_public']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'upcomingevents';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'white-block';
  $export['upcoming_events'] = $view;

  return $export;
}
