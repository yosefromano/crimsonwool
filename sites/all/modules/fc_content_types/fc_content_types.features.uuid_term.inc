<?php
/**
 * @file
 * fc_content_types.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function fc_content_types_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Programs',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'df88574c-7bd1-443b-9747-f0fa255c9080',
    'vocabulary_machine_name' => 'page_type',
    'url_alias' => array(),
  );
  return $terms;
}
