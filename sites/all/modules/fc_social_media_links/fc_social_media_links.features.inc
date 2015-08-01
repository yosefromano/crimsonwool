<?php
/**
 * @file
 * fc_social_media_links.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fc_social_media_links_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
}
