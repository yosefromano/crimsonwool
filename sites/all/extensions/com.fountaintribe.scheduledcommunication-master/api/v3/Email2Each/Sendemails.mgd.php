<?php
// This file declares a managed database record of type "Job".
// The record will be automatically inserted, updated, or deleted from the
// database as appropriate. For more details, see "hook_civicrm_managed" at:
// http://wiki.civicrm.org/confluence/display/CRMDOC42/Hook+Reference
return array (
  0 => 
  array (
    'name' => 'Cron:Email2Each.Sendemails',
    'entity' => 'Job',
    'params' => 
    array (
      'version' => 3,
      'name' => 'Call Email2Each.Sendemails API',
      'description' => 'Sends an email to each contact in the group',
      'run_frequency' => 'Daily',
      'api_entity' => 'Email2Each',
      'api_action' => 'Sendemails',
      'parameters' => '',
    ),
  ),
);
