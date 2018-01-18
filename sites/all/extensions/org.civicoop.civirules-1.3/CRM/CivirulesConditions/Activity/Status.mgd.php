<?php
/**
 * @author Jaap Jansma (CiviCooP) <jaap.jansma@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */
return array (
  0 =>
    array (
      'name' => 'Civirules:Condition.ActivityStatus',
      'entity' => 'CiviRuleCondition',
      'params' =>
        array (
          'version' => 3,
          'name' => 'contact_has_activity_of_status',
          'label' => 'Activity status is (not)',
          'class_name' => 'CRM_CivirulesConditions_Activity_Status',
          'is_active' => 1
        ),
    ),
);