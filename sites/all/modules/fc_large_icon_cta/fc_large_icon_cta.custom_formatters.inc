<?php
/**
 * @file
 * fc_large_icon_cta.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function fc_large_icon_cta_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'large_icon_cta_link';
  $formatter->label = 'Large Icon CTA Link';
  $formatter->description = '';
  $formatter->mode = 'token';
  $formatter->field_types = 'image';
  $formatter->code = '<a href="[bean:field_icon_link_path]"><div class="cta-label">[bean:label]</div><img src="[bean:field_icon_image]" ></a>';
  $formatter->fapi = '';
  $export['large_icon_cta_link'] = $formatter;

  return $export;
}
