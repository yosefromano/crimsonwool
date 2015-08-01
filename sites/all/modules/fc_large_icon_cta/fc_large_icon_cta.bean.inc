<?php
/**
 * @file
 * fc_large_icon_cta.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function fc_large_icon_cta_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'large_icon_cta';
  $bean_type->label = 'Large Icon Calls to Action';
  $bean_type->options = '';
  $bean_type->description = 'Large icons on homepage that are links to wherever you want them to go.';
  $export['large_icon_cta'] = $bean_type;

  return $export;
}
