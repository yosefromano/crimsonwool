<?php
/**
 * @author Erik Hommel (CiviCooP) <erik.hommel@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */
return array (
  0 =>
    array (
      'name' => 'Civirules:Condition.Activity.OnlyOnce',
      'entity' => 'CiviRuleCondition',
      'params' =>
        array (
          'version' => 3,
          'name' => 'once_for_activity',
          'label' => 'Execute action only once for activity',
          'class_name' => 'CRM_CivirulesConditions_Activity_OnlyOnce',
          'is_active' => 1
        ),
    ),
);