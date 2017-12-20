<?php
/**
 * @file
 * cs_civi.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cs_civi_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'civicrm_entity_admin_enabled_entities';
  $strongarm->value = array(
    'civicrm_activity' => 'civicrm_activity',
    'civicrm_action_schedule' => 0,
    'civicrm_address' => 0,
    'civicrm_campaign' => 0,
    'civicrm_case' => 0,
    'civicrm_contact' => 'civicrm_contact',
    'civicrm_contribution' => 0,
    'civicrm_contribution_recur' => 0,
    'civicrm_contribution_page' => 0,
    'civicrm_country' => 0,
    'civicrm_email' => 0,
    'civicrm_entity_tag' => 'civicrm_entity_tag',
    'civicrm_entity_financial_trxn' => 0,
    'civicrm_financial_account' => 0,
    'civicrm_financial_trxn' => 0,
    'civicrm_financial_type' => 0,
    'civicrm_event' => 0,
    'civicrm_group' => 0,
    'civicrm_grant' => 0,
    'civicrm_im' => 0,
    'civicrm_line_item' => 0,
    'civicrm_loc_block' => 0,
    'civicrm_membership' => 0,
    'civicrm_membership_payment' => 0,
    'civicrm_membership_type' => 0,
    'civicrm_note' => 0,
    'civicrm_participant' => 0,
    'civicrm_participant_status_type' => 0,
    'civicrm_participant_payment' => 0,
    'civicrm_payment_processor' => 0,
    'civicrm_payment_processor_type' => 0,
    'civicrm_phone' => 0,
    'civicrm_pledge' => 0,
    'civicrm_pledge_payment' => 0,
    'civicrm_price_set' => 0,
    'civicrm_price_field' => 0,
    'civicrm_price_field_value' => 0,
    'civicrm_recurring_entity' => 0,
    'civicrm_relationship' => 0,
    'civicrm_relationship_type' => 0,
    'civicrm_survey' => 0,
    'civicrm_tag' => 'civicrm_tag',
    'civicrm_custom_field' => 0,
    'civicrm_custom_group' => 0,
    'civicrm_website' => 0,
  );
  $export['civicrm_entity_admin_enabled_entities'] = $strongarm;

  return $export;
}
