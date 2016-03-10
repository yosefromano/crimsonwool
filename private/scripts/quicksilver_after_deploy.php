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

echo "\n";

// Revert all features
echo "Reverting all features...\n";
passthru('drush fra -y');
echo "Reverting features complete.\n";

echo "\n";

// Clear all caches
echo "Clearing all caches.\n";
passthru('drush cc all');
echo "Clearing caches complete.\n";
