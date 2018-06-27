; This version of the .make will build a local copy of the distribution
; using the versions of modules and patches listed.
; Modules and libraries will be in sites/all
; This is used to test the packaging BEFORE committing
; drush make --no-core civicrm_starterkit.make

core = 7.51
api = 2

; Drupal Core
projects[drupal][version] = "7.51"

; ====== CIVICRM RELATED =========

libraries[civicrm][download][type] = get
libraries[civicrm][download][url] = "https://download.civicrm.org/civicrm-5.0.2-drupal.tar.gz"
libraries[civicrm][destination] = modules
libraries[civicrm][directory_name] = civicrm

;PANTHEON RELATED PATCHES
; Settings for Pantheon (d.o/node/2082713 originally)
; Private folders: https://civicrm.org/advisory/civi-sa-2014-001-risk-information-disclosure
; Define [civicrm.files] and [civicrm.private] paths since there is no htaccess file
; to set public/private folders.
libraries[civicrm][patch][pantheonsettings] = ./patches/pantheon-settings-starterkit-50.patch
libraries[civicrm][patch][publicfiledir] = ./patches/public_files_config.patch

; Set session for cron.
; Matches settings in CiviCRM core for extern/*.
libraries[civicrm][patch][cron] = ./patches/cron.patch

; IPN: bootstrap Drupal
libraries[civicrm][patch][externbootstrap] = ./patches/extern-cms-bootstrap.patch

; IPN: Separate Paypal Pro and Standard into separate calls [deprecated]
libraries[civicrm][patch][ipn] = ./patches/ipn.patch
libraries[civicrm][patch][ipnstd] = ./patches/ipnStd.patch

; May be necessary where extension, etc paths are cached but Pantheon changes binding
; https://www.drupal.org/node/2347897
libraries[civicrm][patch][2347897] = ./patches/binding-extension-47-2347897.patch

; === Installer ===

; Ensure the baseURL is correct in the installer in Pantheon.
libraries[civicrm][patch][installerbaseurl] = ./patches/installer-baseurl.patch

; Related to https://issues.civicrm.org/jira/browse/CRM-9683
libraries[civicrm][patch][2130213] = ./patches/ignore-timezone-on-install-47-2130213.patch

; Necessary if CiviCRM in profiles/*/modules/civicrm
; Define the path to the civicrm.settings.php file because CiviCRM is not in the expected location.
; https://www.drupal.org/node/1844558
libraries[civicrm][patch][1844558] = ./patches/settings_location-for-profiles.patch
; https://www.drupal.org/node/2063371
libraries[civicrm][patch][2063371] = ./patches/2063371-add-modulePath-var-4-4.patch

; Populate with Pantheon environment settings on install
; https://www.drupal.org/node/1978838
libraries[civicrm][patch][pre-populate-installer] = ./patches/pre-populate-installer.patch
; https://www.drupal.org/node/1849424
libraries[civicrm][patch][1849424-pass] = ./patches/pass-vars-in-install-link.patch

; Cached Symfony container
; This is a potential issue but not clear at the moment--like it will just rebuild the php file.
; If concerned can set it to skip caching the container. In civicrm.settings.php set:
; define('CIVICRM_CONTAINER_CACHE', 'never');

; [OPTIONAL] SMTP patch for PHP 5.6+
; https://civicrm.stackexchange.com/questions/16628/outgoing-mail-settings-civismtp-php-5-6-x-problem
libraries[civicrm][patch][smtpverify] = ./patches/smtp-disable-peer-verification.patch

; ====== POPULAR CONTRIB MODULES =========

projects[backup_migrate][subdir] = "contrib"
projects[backup_migrate][version] = "3.4"

projects[civicrm_clear_all_caches][subdir] = "contrib"
projects[civicrm_clear_all_caches][version] = "1.0-beta2"

projects[civicrm_cron][subdir] = "contrib"
projects[civicrm_cron][version] = "2.0-beta2"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.12"

projects[captcha][subdir] = "contrib"
projects[captcha][version] = "1.5"

projects[features][subdir] = "contrib"
projects[features][version] = "2.10"

projects[fontyourface][subdir] = "contrib"
projects[fontyourface][version] = "2.8"

projects[imce][subdir] = "contrib"
projects[imce][version] = "1.11"

projects[imce_wysiwyg][subdir] = "contrib"
projects[imce_wysiwyg][version] = "1.0"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.3"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.1"

projects[options_element][subdir] = "contrib"
projects[options_element][version] = "1.12"

projects[profile_status_check][subdir] = "contrib"
projects[profile_status_check][version] = "1.0-beta2"

projects[profile_switcher][subdir] = "contrib"
projects[profile_switcher][version] = "1.0-beta1"

projects[recaptcha][subdir] = "contrib"
projects[recaptcha][version] = "2.2"

projects[views][subdir] = "contrib"
projects[views][version] = "3.18"

projects[webform][subdir] = "contrib"
projects[webform][version] = "4.16"

projects[webform_civicrm][subdir] = "contrib"
projects[webform_civicrm][version] = "4.19"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.4"


; ====== DRUPAL LIBRARIES =========

libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.6.2/ckeditor_4.6.2_standard.tar.gz"
libraries[ckeditor][destination] = libraries
libraries[ckeditor][directory_name] = ckeditor

libraries[tinymce][download][type] = get
libraries[tinymce][download][url] = "http://download.ephox.com/tinymce/community/tinymce_4.5.7.zip"
libraries[tinymce][destination] = libraries
libraries[tinymce][directory_name] = tinymce
