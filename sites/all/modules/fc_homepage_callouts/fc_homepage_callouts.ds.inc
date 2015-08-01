<?php
/**
 * @file
 * fc_homepage_callouts.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fc_homepage_callouts_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|homepage_callout|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'homepage_callout';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_word' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_callout_blurb' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'callout-blurb',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['bean|homepage_callout|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function fc_homepage_callouts_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|homepage_callout|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'homepage_callout';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_callout_main',
        1 => 'field_word',
        2 => 'field_background_image',
        3 => 'field_callout_blurb',
      ),
      'ds_hidden' => array(
        4 => 'title',
        5 => 'field_page_path',
      ),
    ),
    'fields' => array(
      'group_callout_main' => 'ds_content',
      'field_word' => 'ds_content',
      'field_background_image' => 'ds_content',
      'field_callout_blurb' => 'ds_content',
      'title' => 'ds_hidden',
      'field_page_path' => 'ds_hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_sidebars' => 0,
  );
  $export['bean|homepage_callout|default'] = $ds_layout;

  return $export;
}
