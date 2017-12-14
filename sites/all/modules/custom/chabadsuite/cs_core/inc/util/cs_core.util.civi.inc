<?php

/**
 * Install a CiviCRM extension
 */
function cs_util_civicrm_extension_install($key) {
  civicrm_initialize();
  try {
    $result = civicrm_api('extension', 'install', array('key' => $key, 'version' => 3));
    if ($result['values'] && $result['values'] == 1) {
      drupal_set_message(t("Extension !ename installed.", array('!ename' => $key)));
    }
    else {
      drupal_set_message(t('Extension !ename could not be installed.', array('!ename' => $key)), 'error');
    }
  }
  catch (CiviCRM_API3_Exception $e) {
    // handle error here
    $errorMessage = $e->getMessage();
    $errorCode = $e->getErrorCode();
    $errorData = $e->getExtraParams();
    drupal_set_message(t("!error", array('!error' => $errorData), 'error'));
  }
}

/**
 * Delete menu item(s) by path.
 *
 * $delete_if_multiple determins whether to delete all if more than one menu item
 * matches the path
 *
 */
function cs_util_civicrm_menu_item_delete_by_path($path, $delete_if_multiple = FALSE) {
  $items = cs_util_civicrm_menu_item_get_by_path($path);
  $num = count($items);
  if ($num == 1 || ($num > 1 && $delete_if_multiple)) {
    cs_util_civicrm_menu_items_delete($items);
  }
}

/**
 * Delete Civi navigation menu items by id
 */
function cs_util_civicrm_menu_items_delete($ids) {
  if (!is_array($ids)) {
    drupal_set_message('cs_util_civicrm_menu_item_delete_multiple requires an array of ids');
    return;
  }

  civicrm_initialize();

  foreach ($ids as $id) {
    CRM_Core_BAO_Navigation::processDelete($id);
  }
}

/**
 * Get a Civi navigation menu item by path
 */
function cs_util_civicrm_menu_item_get_by_path($path) {
  $query = db_select('civicrm_navigation', 'cn')
    ->fields('cn', array('id'))
    ->condition('url', $path, '=');

  return array_keys($query->execute()->fetchAllKeyed());
}
