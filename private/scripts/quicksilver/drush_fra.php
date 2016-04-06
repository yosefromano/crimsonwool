<?php
/**
 * This script is configured to run automatically after code is deployed
 * in Pantheon. It's called by Pantheon's Quicksilver.
 *
 * https://pantheon.io/docs/articles/sites/quicksilver/
 *
 */

// Revert all features
echo "Reverting all features...\n";
passthru('drush fra -y');
echo "Reverting features complete.\n";
