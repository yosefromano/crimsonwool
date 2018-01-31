<?php
/**
 * @author Jaap Jansma (CiviCooP) <jaap.jansma@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */

return array (
  0 =>
    array (
      'name' => 'Civirules:Condition.RelationshipIsContactA',
      'entity' => 'CiviRuleCondition',
      'params' =>
        array (
          'version' => 3,
          'name' => 'relationship_is_contact_a',
          'label' => 'Relationship is contact a',
          'class_name' => 'CRM_CivirulesConditions_Relationship_IsContactA',
          'is_active' => 1
        ),
    ),
  1 =>
    array (
      'name' => 'Civirules:Condition.RelationshipIsContactB',
      'entity' => 'CiviRuleCondition',
      'params' =>
        array (
          'version' => 3,
          'name' => 'relationship_is_contact_b',
          'label' => 'Relationship is contact b',
          'class_name' => 'CRM_CivirulesConditions_Relationship_IsContactB',
          'is_active' => 1
        ),
    ),
);