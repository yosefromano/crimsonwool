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
