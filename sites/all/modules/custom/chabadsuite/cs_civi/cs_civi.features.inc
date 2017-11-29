<?php
/**
 * @file
 * cs_civi.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cs_civi_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
