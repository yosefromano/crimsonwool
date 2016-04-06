<?php
/**
 * This script is configured to run automatically after code is deployed
 * in Pantheon. It's called by Pantheon's Quicksilver.
 *
 * https://pantheon.io/docs/articles/sites/quicksilver/
 *
 */

// Run database updates
echo "Running database updates...\n";
passthru('drush updb -y');
echo "Database updates complete.\n";
