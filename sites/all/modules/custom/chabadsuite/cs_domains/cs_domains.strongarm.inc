<?php
/**
 * @file
 * cs_domains.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cs_domains_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_sitename_override';
  $strongarm->value = 0;
  $export['domain_sitename_override'] = $strongarm;

  return $export;
}
