<?php

return array (
  0 =>
    array (
      'name' => 'Civirules:Trigger.IndividualCustomDataChanged',
      'entity' => 'CiviRuleTrigger',
      'params' =>
        array (
          'version' => 3,
          'name' => 'changed_individual_custom_data',
          'label' => 'Custom data on Individual changed',
          'cron' => 0,
          'class_name' => 'CRM_CivirulesPostTrigger_IndividualCustomDataChanged',
          'is_active' => 1
        ),
    ),
);