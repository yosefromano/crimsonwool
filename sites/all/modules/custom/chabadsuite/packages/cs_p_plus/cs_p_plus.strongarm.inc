<?php
/**
 * @file
 * cs_p_plus.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cs_p_plus_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cs_active_package';
  $strongarm->value = 'plus';
  $export['cs_active_package'] = $strongarm;

  return $export;
}
