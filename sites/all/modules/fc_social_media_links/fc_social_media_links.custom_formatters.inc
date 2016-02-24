<?php
/**
 * @file
 * fc_social_media_links.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function fc_social_media_links_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'social_media_links';
  $formatter->label = 'Social Media Links';
  $formatter->description = '';
  $formatter->mode = 'token';
  $formatter->field_types = 'image';
  $formatter->code = '<a href="http://[bean:field_link_url]" target="_blank"><img src="[bean:field_link_image]"></a>';
  $formatter->fapi = '';
  $export['social_media_links'] = $formatter;

  return $export;
}
