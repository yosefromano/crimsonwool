<?php
/**
 * This code is based on code provided in the domain module documentation
 * to ensure that domain works correctly on multiple development and 
 * testing environments. Some values are changed to work correctly with
 * our implementation.
 *
 * https://www.drupal.org/node/1096988
 */

define("DOMAIN_STRING_LOC", "loc.");
define("DOMAIN_STRING_DEV", "dev.");
define("DOMAIN_STRING_TEST", "test.");
define("DOMAIN_STRING_LIVE", "www.");

define("ENV_NAME_LOC", "local");
define("ENV_NAME_DEV", "dev");
define("ENV_NAME_TEST", "test");
define("ENV_NAME_LIVE", "live");

/**
 * Determine the server / hosting environment based on the HTTP REQUEST.
 *
 * @return
 * A server identifier string.
 *
 * @see cs_domains_domain_load()
 */
function cs_domains_get_server() {
  $server = '';
  if (isset($_SERVER['HTTP_HOST'])) {
    if (substr_count($_SERVER['HTTP_HOST'], DOMAIN_STRING_LOC) > 0) {
      $server = ENV_NAME_LOC;
    }
    elseif (substr_count($_SERVER['HTTP_HOST'], DOMAIN_STRING_DEV) > 0) {
      $server = ENV_NAME_DEV;
    }
    elseif (substr_count($_SERVER['HTTP_HOST'], DOMAIN_STRING_TEST) > 0) {
      $server = ENV_NAME_TEST;
    }
    elseif (substr_count($_SERVER['HTTP_HOST'], DOMAIN_STRING_LIVE) > 0) {
      $server = ENV_NAME_LIVE;
    }
  }
  return $server;
}

/**
 * Implements hook_domain_load().
 *
 * Ensure proper URLs on test environments.
 */
function cs_domains_domain_load(&$domain) {
  $server = cs_domains_get_server();
  // If not set, do nothing.
  if (empty($server) || !isset($domain['subdomain'])) {
    return;
  }
  // Take the initial element. Your mileage may vary.
  $subdomain = $domain['subdomain'];
  
  // Separate the subdomain from the domain
  $parts = explode('.', $subdomain, 2);
  $domain_base = $parts[0];
  $domain_main = $parts[1];
  
  // Map parts of the canonical domain to dev aliases.
  // This logic assumes an example.com => dev.example.com structure.
  switch ($server) {
    case ENV_NAME_LOC:
      $domain['subdomain'] = DOMAIN_STRING_LOC . $domain_main;
      break;
    case ENV_NAME_DEV:
      $domain['subdomain'] = DOMAIN_STRING_DEV . $domain_main;
      break;
    case ENV_NAME_TEST:
      $domain['subdomain'] = DOMAIN_STRING_TEST . $domain_main;
      break;
    case ENV_NAME_LIVE:
      $domain['subdomain'] = DOMAIN_STRING_LIVE . $domain_main;
      break;
  }
  $domain['path'] = domain_get_path($domain);
  $domain['canonical'] = $subdomain;
}

/**
 * Alter the domain form to show proper canonical domain information.
 */
function cs_domains_form_domain_form_alter(&$form, &$form_state) {
  if (isset($form['#domain']['canonical'])) {
    $form['subdomain']['#default_value'] = $form['#domain']['canonical'];
    $form['help'] = array(
      '#markup' => '<p>' . t('On this server, the domain URL is !url.', array('!url' => '<strong>' . check_plain($form['#domain']['subdomain']) . '</strong>')) . '</p>',
      '#weight' => -2,
    );
  }
  $new_text = '<strong>' . t('Enter the canonical domain name (e.g. <em>example.com</em>)') . '</strong><br />';
  $form['subdomain']['#description'] = $new_text . $form['subdomain']['#description'];
  if (!isset($form['ignore'])) {
    $form['ignore'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ignore server response warning'),
      '#default_value' => 0,
      '#weight' => 1,
      '#description' => t('<strong>This domain did not respond correctly. It cannot be set as your primary domain unless you select <em>Ignore server response warning</em></strong>.'),
    );
    $form['submit']['#weight'] = 2;
  }
}

/**
 * Alter the domain overview form to show proper canonical domain information.
 */
function cs_domains_form_domain_overview_form_alter(&$form, &$form_state) {
  $active_domain = domain_get_domain();
  $domains = domain_domains();
  foreach ($form['domain'] as $domain_id => $values) {
    if (isset($domains[$domain_id]['canonical'])) {
      $domain = $domains[$domain_id];
      $form['domain'][$domain_id]['subdomain']['#markup'] = ($active_domain['domain_id'] == $domain['domain_id']) ? '<strong>' . l($domain['canonical'], domain_get_uri($domain)) . '</strong>' : l($domain['canonical'], domain_get_uri($domain));
    }
  }
}