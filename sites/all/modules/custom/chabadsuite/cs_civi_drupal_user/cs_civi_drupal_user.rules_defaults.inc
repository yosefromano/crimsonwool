<?php
/**
 * @file
 * cs_civi_drupal_user.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function cs_civi_drupal_user_default_rules_configuration() {
  $items = array();
  $items['rules_new_parent'] = entity_import('rules_config', '{ "rules_new_parent" : {
      "LABEL" : "Linked User-Civi contact",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "REQUIRES" : [ "civicrm", "rules" ],
      "ON" : { "civicrm_entity_tag_create" : [] },
      "IF" : [
        { "NOT civicrm_entity_user_exists" : { "civicrm_contact" : [ "civicrm-entity-tag:entity-id-contact" ] } },
        { "data_is" : { "data" : [ "civicrm-entity-tag:tag-id" ], "value" : "1" } }
      ],
      "DO" : [
        { "civicrm_entity_action_create_user" : {
            "USING" : {
              "civicrm_contact" : [ "civicrm-entity-tag:entity-id-contact" ],
              "is_active" : 1,
              "notify" : 1,
              "signin" : 0,
              "username_format" : "firstlast"
            },
            "PROVIDE" : { "civicrm_user" : { "civicrm_user" : "Created Drupal User" } }
          }
        }
      ]
    }
  }');
  return $items;
}
