<?php
/**
 * @file
 * fc_popout_promo.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function fc_popout_promo_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-meerkat-field_image_link_address'.
  $field_instances['bean-meerkat-field_image_link_address'] = array(
    'bundle' => 'meerkat',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This will link the image to a page within your site OR an external URL. To link to a page within your site, use this format: /node/2  (basically the address after the domain example: yoursite.com/node/1
For an external URL, use this format: http://www.google.com',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_image_link_address',
    'label' => 'Image Link Address',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'bean-meerkat-field_meerkat_image'.
  $field_instances['bean-meerkat-field_meerkat_image'] = array(
    'bundle' => 'meerkat',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'custom_formatters',
        'settings' => array(),
        'type' => 'custom_formatters_popouturl',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_meerkat_image',
    'label' => 'PopOut Image',
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
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
          'youtube' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'bean-meerkat-field_meerkat_verbiage'.
  $field_instances['bean-meerkat-field_meerkat_verbiage'] = array(
    'bundle' => 'meerkat',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_meerkat_verbiage',
    'label' => 'PopOut Verbiage',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image Link Address');
  t('PopOut Image');
  t('PopOut Verbiage');
  t('This will link the image to a page within your site OR an external URL. To link to a page within your site, use this format: /node/2  (basically the address after the domain example: yoursite.com/node/1
For an external URL, use this format: http://www.google.com');

  return $field_instances;
}
