<?php
/**
 * @file
 * fc_social_media_links.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function fc_social_media_links_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'social_media_links';
  $bean_type->label = 'Social Media Links';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['social_media_links'] = $bean_type;

  return $export;
}
