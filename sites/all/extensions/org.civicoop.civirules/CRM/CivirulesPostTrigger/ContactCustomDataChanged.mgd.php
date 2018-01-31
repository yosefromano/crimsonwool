<?php

return array (
  0 =>
    array (
      'name' => 'Civirules:Trigger.ContactCustomDataChanged',
      'entity' => 'CiviRuleTrigger',
      'params' =>
        array (
          'version' => 3,
          'name' => 'changed_contact_custom_data',
          'label' => 'Custom data on Contact (of any type) changed',
//          'object_name' => 'Contact',
//          'op' => 'edit',
          'cron' => 0,
          'class_name' => 'CRM_CivirulesPostTrigger_ContactCustomDataChanged',
          'is_active' => 1
        ),
    ),
);