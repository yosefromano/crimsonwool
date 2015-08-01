<?php
/**
 * @file
 * fc_homepage_image.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function fc_homepage_image_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-homepage_image-field_homepage_image'
  $field_instances['bean-homepage_image-field_homepage_image'] = array(
    'bundle' => 'homepage_image',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_homepage_image',
    'label' => 'Homepage Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Homepage Image');

  return $field_instances;
}
