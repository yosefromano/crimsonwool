<?php
/**
 * @file
 * fc_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fc_content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery|node|photo_gallery|teaser';
  $field_group->group_name = 'group_photo_gallery';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'photo_gallery';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_photo',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'classes' => 'group-photo-gallery field-group-div views-row',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_photo_gallery|node|photo_gallery|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shpiel|field_collection_item|field_slide_content|default';
  $field_group->group_name = 'group_shpiel';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slide_content';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shpiel',
    'weight' => '2',
    'children' => array(
      0 => 'field_slideshow_header_text',
      1 => 'field_slideshow_shpiel',
      2 => 'field_call_to_action',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Shpiel',
      'instance_settings' => array(
        'classes' => 'group-shpiel field-group-div ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_shpiel|field_collection_item|field_slide_content|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_info|node|team|teaser';
  $field_group->group_name = 'group_team_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Team Info',
    'weight' => '2',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Team Info',
      'instance_settings' => array(
        'classes' => 'group-team-info field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_team_info|node|team|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_photo|node|team|teaser';
  $field_group->group_name = 'group_team_photo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Team Photo',
    'weight' => '1',
    'children' => array(
      0 => 'field_member_photo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Team Photo',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_team_photo|node|team|teaser'] = $field_group;

  return $export;
}
