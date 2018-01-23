<?php
/**
 * @file
 * cs_p_plus.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cs_p_plus_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
