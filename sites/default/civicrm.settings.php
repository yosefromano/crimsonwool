<?php
/*
 +--------------------------------------------------------------------+
 | CiviCRM version 4.4                                                |
 +--------------------------------------------------------------------+
 | Copyright CiviCRM LLC (c) 2004-2013                                |
 +--------------------------------------------------------------------+
 | This file is a part of CiviCRM.                                    |
 |                                                                    |
 | CiviCRM is free software; you can copy, modify, and distribute it  |
 | under the terms of the GNU Affero General Public License           |
 | Version 3, 19 November 2007 and the CiviCRM Licensing Exception.   |
 |                                                                    |
 | CiviCRM is distributed in the hope that it will be useful, but     |
 | WITHOUT ANY WARRANTY; without even the implied warranty of         |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.               |
 | See the GNU Affero General Public License for more details.        |
 |                                                                    |
 | You should have received a copy of the GNU Affero General Public   |
 | License and the CiviCRM Licensing Exception along                  |
 | with this program; if not, contact CiviCRM LLC                     |
 | at info[AT]civicrm[DOT]org. If you have questions about the        |
 | GNU Affero General Public License or the licensing of CiviCRM,     |
 | see the CiviCRM license FAQ at http://civicrm.org/licensing        |
 +--------------------------------------------------------------------+
*/

/**
 * CiviCRM Configuration File.
 */

/**
 * Content Management System (CMS) Host:
 *
 * CiviCRM can be hosted in either Drupal 6 or 7, Joomla or WordPress.
 *
 * Settings for Drupal 7.x:
 *      define( 'CIVICRM_UF'        , 'Drupal' );
 *
 * Settings for Drupal 6.x:
 *      define( 'CIVICRM_UF'        , 'Drupal6' );
 *
 * Settings for Joomla 1.7.x - 2.5.x:
 *      define( 'CIVICRM_UF'        , 'Joomla' );
 *
 * Settings for WordPress 3.3.x:
 *      define( 'CIVICRM_UF'        , 'WordPress' );
 *
 * You may have issues with images in CiviCRM. If this is the case, be sure
 * to update the CiviCRM Resource URL field to your CiviCRM root directory
 * (Administer::System Settings::Resource URLs).
 */
define('CIVICRM_UF' , 'Drupal');

 /**
 * Pantheon Systems:
 *
 * Repopulate needed variables based on the Pantheon environment if applicable.
 * http://www.kalamuna.com/news/civicrm-pantheon
 *
 */
if (defined('PANTHEON_ENVIRONMENT')) {
  $env = json_decode($_SERVER['PRESSFLOW_SETTINGS'], TRUE);
 	if (!empty($env['conf']['pantheon_binding'])) {
 		$pantheon_db = $env['databases']['default']['default'];
 		$pantheon_conf = $env['conf'];

 		//user name and password
 		$db_string = $pantheon_db['driver'] . '://' . $pantheon_db['username'] . ':' . $pantheon_db['password'] . '@';
 		//host
 		$db_string .= 'dbserver.' . $pantheon_conf['pantheon_environment'] . '.' . $pantheon_conf['pantheon_site_uuid'] . '.drush.in' . ':' . $pantheon_db['port'];
 		// database
 		$db_string .= '/' . $pantheon_db['database'] . '?new_link=true';

 		// define the database strings
 		define('CIVICRM_UF_DSN', $db_string);
 		define('CIVICRM_DSN', $db_string);

 		// define the file paths
 		global $civicrm_root;

 		$civicrm_root = '/srv/bindings/' . $pantheon_conf['pantheon_binding'] . '/code/profiles/civicrm_starterkit/modules/civicrm';
 		define('CIVICRM_TEMPLATE_COMPILEDIR', '/srv/bindings/' . $pantheon_conf['pantheon_binding'] . '/files/private/civicrm/templates_c/');

 		// Use Drupal base url and path
 		global $base_url, $base_path;
 		define( 'CIVICRM_UF_BASEURL', $base_url . '/');
 		define( 'CIVICRM_SITE_KEY', 'a94ef7c7de538900b3e799e2bdba2a88' );

 		if ( $pantheon_conf['pantheon_environment'] == 'dev' || $pantheon_conf['pantheon_environment'] == 'test' ){
 			/**
 			* This setting logs all emails to a file. Useful for debugging any mail (or civimail) issues.
 			* This will not send any email, so ensure this is commented out in production
 			*/
 			define( 'CIVICRM_MAIL_LOG', '/srv/bindings/' . $pantheon_conf['pantheon_binding'] . '/code/sites/default/files/private/civicrm/templates_c/mail.log' );

 		}

 		// Add this line only once above any settings overrides
	  global $civicrm_setting;
	  $civicrm_setting['Directory Preferences']['uploadDir'] = '/srv/bindings/' . $pantheon_conf['pantheon_binding'] . '/code/sites/default/files/private/civicrm/upload/';
	  $civicrm_setting['Directory Preferences']['customFileUploadDir'] = '/srv/bindings/' . $pantheon_conf['pantheon_binding'] . '/code/sites/default/files/private/civicrm/custom/';
	  $civicrm_setting['Directory Preferences']['imageUploadDir'] = '/srv/bindings/' . $pantheon_conf['pantheon_binding'] . '/code/sites/default/files/';
	  $civicrm_setting['Directory Preferences']['extensionsDir'] = '/srv/bindings/' . $pantheon_conf['pantheon_binding'] . '/code/sites/all/extensions/';
		$civicrm_setting['URL Preferences']['userFrameworkResourceURL'] = $base_url . '/profiles/civicrm_starterkit/modules/civicrm/';
		$civicrm_setting['URL Preferences']['imageUploadURL'] = $base_url . '/sites/default/files/';
		$civicrm_setting['URL Preferences']['extensionsURL'] = $base_url . '/sites/all/extensions/';
		$civicrm_setting['CiviCRM Preferences']['communityMessagesUrl'] = false; //disable community msgs
 	}
} else {
  /**
   * If we are not on Pantheon, we assume we're running locally.
   */
  global $conf;

  $db_name = 'cs_' . $conf['site_info']['short_name'];
  $site_root = getcwd();

  define('CIVICRM_UF_DSN', "mysql://root:root@localhost/$db_name?new_link=true");

  define('CIVICRM_DSN', "mysql://root:root@localhost/$db_name?new_link=true");

  global $civicrm_root;
  $civicrm_root = $site_root . '/profiles/civicrm_starterkit/modules/civicrm/';

  define('CIVICRM_TEMPLATE_COMPILEDIR', $site_root . '/sites/default/files/private/civicrm/smarty/' );

  global $base_url, $base_path;
  define('CIVICRM_UF_BASEURL', $base_url . '/');
  define('CIVICRM_SITE_KEY', 'a94ef7c7de538900b3e799e2bdba2a88');

  global $civicrm_setting;
  $civicrm_setting['Directory Preferences']['uploadDir'] = $site_root . '/sites/default/files/private/civicrm/upload/';
  $civicrm_setting['Directory Preferences']['customFileUploadDir'] = $site_root . '/sites/default/files/private/civicrm/custom/';
  $civicrm_setting['Directory Preferences']['imageUploadDir'] = $site_root . '/sites/default/files/private/civicrm/persist/contribute/';
  $civicrm_setting['Directory Preferences']['extensionsDir'] = $site_root . '/sites/all/extensions/';
  $civicrm_setting['URL Preferences']['userFrameworkResourceURL'] = $base_url . '/profiles/civicrm_starterkit/modules/civicrm/';
  $civicrm_setting['URL Preferences']['imageUploadURL'] = $base_url . '/sites/default/files/';
  $civicrm_setting['URL Preferences']['extensionsURL'] = $base_url . '/sites/all/extensions/';
  $civicrm_setting['CiviCRM Preferences']['communityMessagesUrl'] = false; //disable community msgs

  define( 'CIVICRM_DOMAIN_ID'      , 1 );
  define( 'CIVICRM_DB_CACHE_CLASS', 'ArrayCache' );
}

/**
 * Include an optional civicrm.site.settings.php. This file is meant to include
 * settings specific to the site using this upstream.
 */
if (is_file(DRUPAL_ROOT . '/sites/default/civicrm.site.settings.php')) {
  include(DRUPAL_ROOT . '/sites/default/civicrm.site.settings.php');
}


/**
 *
 * Do not change anything below this line. Keep as is
 *
 */

$include_path = '.'           . PATH_SEPARATOR .
                $civicrm_root . PATH_SEPARATOR .
                $civicrm_root . DIRECTORY_SEPARATOR . 'packages' . PATH_SEPARATOR .
                get_include_path( );
if ( set_include_path( $include_path ) === false ) {
   echo "Could not set the include path<p>";
   exit( );
}

if ( function_exists( 'variable_get' ) && variable_get('clean_url', '0') != '0' ) {
    define( 'CIVICRM_CLEANURL', 1 );
} else {
    define( 'CIVICRM_CLEANURL', 0 );
}

// force PHP to auto-detect Mac line endings
ini_set('auto_detect_line_endings', '1');

// make sure the memory_limit is at least 64 MB
$memLimitString = trim(ini_get('memory_limit'));
$memLimitUnit   = strtolower(substr($memLimitString, -1));
$memLimit       = (int) $memLimitString;
switch ($memLimitUnit) {
    case 'g': $memLimit *= 1024;
    case 'm': $memLimit *= 1024;
    case 'k': $memLimit *= 1024;
}
if ($memLimit >= 0 and $memLimit < 134217728) {
    ini_set('memory_limit', '128M');
}

require_once 'CRM/Core/ClassLoader.php';
CRM_Core_ClassLoader::singleton()->register();
