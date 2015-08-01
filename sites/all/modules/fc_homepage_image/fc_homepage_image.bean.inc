<?php
/**
 * @file
 * fc_homepage_image.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function fc_homepage_image_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'homepage_image';
  $bean_type->label = 'Homepage Image';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['homepage_image'] = $bean_type;

  return $export;
}
