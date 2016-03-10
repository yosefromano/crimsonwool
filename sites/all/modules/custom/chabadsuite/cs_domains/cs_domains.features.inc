<?php
/**
 * @file
 * cs_domains.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cs_domains_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
