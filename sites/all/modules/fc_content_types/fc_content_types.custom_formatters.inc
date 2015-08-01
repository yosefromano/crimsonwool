<?php
/**
 * @file
 * fc_content_types.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function fc_content_types_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'call_to_action';
  $formatter->label = 'Call To Action';
  $formatter->description = '';
  $formatter->mode = 'token';
  $formatter->field_types = 'text';
  $formatter->code = '<a href="[field_collection_item:field-button-path]" class="button success">[field_collection_item:field_text_in_button]</a>';
  $formatter->fapi = '';
  $export['call_to_action'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'team_email';
  $formatter->label = 'Team Email';
  $formatter->description = '';
  $formatter->mode = 'token';
  $formatter->field_types = 'text';
  $formatter->code = '<a href="mailto:[node:field-email-adress]">[node:field-email-adress]</a>';
  $formatter->fapi = '';
  $export['team_email'] = $formatter;

  return $export;
}
