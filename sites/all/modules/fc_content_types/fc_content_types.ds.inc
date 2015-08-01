<?php
/**
 * @file
 * fc_content_types.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fc_content_types_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_slide_content|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_slide_content';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_slideshow_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'flex-video',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_slideshow_header_text' => array(
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
    'field_big_header' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h1',
          'fi-cl' => 'homepage',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['field_collection_item|field_slide_content|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|homepage_slideshow|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'homepage_slideshow';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_slide_content' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'node-slide',
          'fis-at' => 'data-orbit',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|homepage_slideshow|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_right_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'left-with-margin',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_media' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'flex-video',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|page|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo_gallery|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo_gallery';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_photo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'left-with-margin',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|photo_gallery|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|team|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'team';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_member_photo' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|team|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|team|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'team';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_member_photo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'left',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|team|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function fc_content_types_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_slide_content|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_slide_content';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slideshow_image',
        1 => 'field_big_header',
        2 => 'field_slideshow_header_text',
        3 => 'group_shpiel',
        4 => 'field_slideshow_shpiel',
        5 => 'field_call_to_action',
      ),
    ),
    'fields' => array(
      'field_slideshow_image' => 'ds_content',
      'field_big_header' => 'ds_content',
      'field_slideshow_header_text' => 'ds_content',
      'group_shpiel' => 'ds_content',
      'field_slideshow_shpiel' => 'ds_content',
      'field_call_to_action' => 'ds_content',
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
  $export['field_collection_item|field_slide_content|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|homepage_slideshow|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'homepage_slideshow';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slide_content',
      ),
    ),
    'fields' => array(
      'field_slide_content' => 'ds_content',
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
  $export['node|homepage_slideshow|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_right_image',
        1 => 'field_media',
        2 => 'body',
        3 => 'field_photo_gallery_reference',
      ),
    ),
    'fields' => array(
      'field_right_image' => 'ds_content',
      'field_media' => 'ds_content',
      'body' => 'ds_content',
      'field_photo_gallery_reference' => 'ds_content',
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
  $export['node|page|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo_gallery|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo_gallery';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_photo',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'field_photo' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_sidebars' => 0,
  );
  $export['node|photo_gallery|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo_gallery|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo_gallery';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_photo_gallery',
        1 => 'title',
        2 => 'field_photo',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'group_photo_gallery' => 'ds_content',
      'title' => 'ds_content',
      'field_photo' => 'ds_content',
      'body' => 'ds_content',
    ),
    'limit' => array(
      'field_photo' => '1',
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
  $export['node|photo_gallery|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|team|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'team';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_member_photo',
        1 => 'body',
        2 => 'field_email_adress',
        3 => 'field_phone_number',
      ),
    ),
    'fields' => array(
      'field_member_photo' => 'ds_content',
      'body' => 'ds_content',
      'field_email_adress' => 'ds_content',
      'field_phone_number' => 'ds_content',
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
  $export['node|team|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|team|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'team';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'group_team_photo',
        3 => 'field_member_photo',
        4 => 'group_team_info',
        5 => 'field_phone_number',
        6 => 'field_email_adress',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'group_team_photo' => 'ds_content',
      'field_member_photo' => 'ds_content',
      'group_team_info' => 'ds_content',
      'field_phone_number' => 'ds_content',
      'field_email_adress' => 'ds_content',
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
  $export['node|team|teaser'] = $ds_layout;

  return $export;
}
