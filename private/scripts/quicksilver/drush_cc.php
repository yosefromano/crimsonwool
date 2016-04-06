<?php
/**
 * This script is configured to run automatically after code is deployed
 * in Pantheon. It's called by Pantheon's Quicksilver.
 *
 * https://pantheon.io/docs/articles/sites/quicksilver/
 *
 */

// Clear all caches
echo "Clearing all caches.\n";
passthru('drush cc all');
echo "Clearing caches complete.\n";
