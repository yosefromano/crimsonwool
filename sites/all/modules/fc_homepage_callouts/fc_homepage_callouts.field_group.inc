<?php
/**
 * @file
 * fc_homepage_callouts.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fc_homepage_callouts_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_callout_main|bean|homepage_callout|default';
  $field_group->group_name = 'group_callout_main';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'homepage_callout';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_background_image',
      1 => 'field_word',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'group-callout-main field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_callout_main|bean|homepage_callout|default'] = $field_group;

  return $export;
}
