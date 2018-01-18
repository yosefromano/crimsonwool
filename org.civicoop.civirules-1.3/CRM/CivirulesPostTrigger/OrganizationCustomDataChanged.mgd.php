<?php

return array (
  0 =>
    array (
      'name' => 'Civirules:Trigger.OrganizationCustomDataChanged',
      'entity' => 'CiviRuleTrigger',
      'params' =>
        array (
          'version' => 3,
          'name' => 'changed_organization_custom_data',
          'label' => 'Custom data on Organization changed',
          'cron' => 0,
          'class_name' => 'CRM_CivirulesPostTrigger_OrganizationCustomDataChanged',
          'is_active' => 1
        ),
    ),
);