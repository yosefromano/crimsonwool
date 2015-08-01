<?php
/**
 * @file
 * fc_homepage_callouts.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function fc_homepage_callouts_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'callout_image';
  $formatter->label = 'Callout Image';
  $formatter->description = '';
  $formatter->mode = 'token';
  $formatter->field_types = 'image';
  $formatter->code = '<a href="[bean:field-page-path]"><img src="[bean:field_background_image]" /></a>';
  $formatter->fapi = '';
  $export['callout_image'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'image_link';
  $formatter->label = 'Image Link';
  $formatter->description = '';
  $formatter->mode = 'token';
  $formatter->field_types = 'text';
  $formatter->code = '<a href="[bean:field-page-path]"><img src="[bean:field_page_path]" /></a>';
  $formatter->fapi = '';
  $export['image_link'] = $formatter;

  return $export;
}
