<?php
/**
 * @file
 * fc_popout_promo.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function fc_popout_promo_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'meerkat';
  $bean_type->label = 'PopOut Box';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['meerkat'] = $bean_type;

  return $export;
}
