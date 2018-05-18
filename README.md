CiviCRM Starterkit for Pantheon
===============================

CiviCRM Starterkit is a Drupal 7 distribution that makes it easy to start with the popular open source CRM, CiviCRM.

The [CiviCRM Starterkit](http://civicrmstarterkit.org/) project is not intended to be installed on its own. Instead, you can quickly get started with CiviCRM by [spinning it up on Pantheon](https://dashboard.pantheon.io/products/civicrm_starterkit/spinup). This Pantheon upstream keeps up to date with Pantheon's core Drupal 7 repository, with basic Drupal module security updates, and with updates to the core CiviCRM project.

Support
-------

If you are stuck, confused or run into trouble please [contact us](http://civicrmstarterkit.org/contact) and we'll see how we can help. We provide some basic general support for the public. If you require help with your specific website there will likely be a cost.

Starterkit CHANGELOG
---------------------

See profiles/civicrm_starterkit/CHANGELOG.md.

Installation
------------

After installing by spinning up the site by clicking above, overwrite the automatically included `civicrm.settings.php` with the content from `sites/default/default.civicrm.settings.php`.

Upgrades
--------

Consult the [guide on upgrading CiviCRM on Drupal 7](https://wiki.civicrm.org/confluence/display/CRMDOC/Upgrading+CiviCRM+for+Drupal+7).

On Pantheon you can accept the updates from the dashboard. Once the code has merged without conflicts on dev, you can test the upgrade of the database with the following steps:

1. Backup the database, files and code using Pantheon's backup tool first.
2. Upgrade the database. Two options: go to `http://<your_drupal_home>/civicrm/upgrade?reset=1` or use `terminus drush site.env civicrm-upgrade-db` where "env" is dev, test, live or the name of the Multidev.
3. If you've got extensions switch to SFTP mode and go to `civicrm/admin/extensions?reset=1` to check and download any extension updates.
4. If there are extension database updates, make another backup of the database and click the update link in the Extension dashboard.
5. Commit any extension code updates and switch back to git mode.
6. Verify Drupal role-based permissions which were added in recent releases. You can review and update these at `admin/people/permissions`.
7. If you were using Views integration prior to this upgrade, you will need to go to `admin/structure/views/settings/advanced` and press "Clear Views cache" for Views to capture changes in the CiviCRM Views integration code.
8. Clear CiviCRM caches by clicking "Cleanup Caches" at `civicrm/admin/setting/updateConfigBackend?reset=1`
9. Rebuild CiviCRM templates by first enabling debugging at `civicrm/admin/setting/debug?reset=1` and then pasting `&directoryCleanup=1` to the end of the URL so it looks like `civicrm/admin/setting/debug?reset=1&directoryCleanup=1` and hitting Enter. Once that's done loading disable debugging again if on live.

When you are ready to deploy the upgrade to live, put the live site into maintenance mode. You then have two options: one, you can copy the live database to dev or test and rerun the upgrade and then copy the database to live. Or two, rerun the relevant steps above on live (backup the database and files; disable extensions and CiviCRM integration modules; push the code update to live and run the database upgrade).
