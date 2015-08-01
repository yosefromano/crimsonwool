<?php
/**
 * @file
 * fc_popout_promo.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function fc_popout_promo_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'popouturl';
  $formatter->label = 'PopOutURL';
  $formatter->description = '';
  $formatter->mode = 'token';
  $formatter->field_types = 'image';
  $formatter->code = '<a href="[bean:field_image_link_address]"><img src="[bean:field_meerkat_image]"></a>';
  $formatter->fapi = '';
  $export['popouturl'] = $formatter;

  return $export;
}
