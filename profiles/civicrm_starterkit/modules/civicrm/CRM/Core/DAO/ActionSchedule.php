<?php

/**
 * @package CRM
 * @copyright CiviCRM LLC (c) 2004-2018
 *
 * Generated from xml/schema/CRM/Core/ActionSchedule.xml
 * DO NOT EDIT.  Generated by CRM_Core_CodeGen
 * (GenCodeChecksum:d158b2da297ca83e4210a3fa0da8d5eb)
 */

/**
 * Database access object for the ActionSchedule entity.
 */
class CRM_Core_DAO_ActionSchedule extends CRM_Core_DAO {

  /**
   * Static instance to hold the table name.
   *
   * @var string
   */
  static $_tableName = 'civicrm_action_schedule';

  /**
   * Should CiviCRM log any modifications to this table in the civicrm_log table.
   *
   * @var bool
   */
  static $_log = FALSE;

  /**
   * @var int unsigned
   */
  public $id;

  /**
   * Name of the action(reminder)
   *
   * @var string
   */
  public $name;

  /**
   * Title of the action(reminder)
   *
   * @var string
   */
  public $title;

  /**
   * Recipient
   *
   * @var string
   */
  public $recipient;

  /**
   * Is this the recipient criteria limited to OR in addition to?
   *
   * @var boolean
   */
  public $limit_to;

  /**
   * Entity value
   *
   * @var string
   */
  public $entity_value;

  /**
   * Entity status
   *
   * @var string
   */
  public $entity_status;

  /**
   * Reminder Interval.
   *
   * @var int unsigned
   */
  public $start_action_offset;

  /**
   * Time units for reminder.
   *
   * @var string
   */
  public $start_action_unit;

  /**
   * Reminder Action
   *
   * @var string
   */
  public $start_action_condition;

  /**
   * Entity date
   *
   * @var string
   */
  public $start_action_date;

  /**
   * @var boolean
   */
  public $is_repeat;

  /**
   * Time units for repetition of reminder.
   *
   * @var string
   */
  public $repetition_frequency_unit;

  /**
   * Time interval for repeating the reminder.
   *
   * @var int unsigned
   */
  public $repetition_frequency_interval;

  /**
   * Time units till repetition of reminder.
   *
   * @var string
   */
  public $end_frequency_unit;

  /**
   * Time interval till repeating the reminder.
   *
   * @var int unsigned
   */
  public $end_frequency_interval;

  /**
   * Reminder Action till repeating the reminder.
   *
   * @var string
   */
  public $end_action;

  /**
   * Entity end date
   *
   * @var string
   */
  public $end_date;

  /**
   * Is this option active?
   *
   * @var boolean
   */
  public $is_active;

  /**
   * Contact IDs to which reminder should be sent.
   *
   * @var string
   */
  public $recipient_manual;

  /**
   * listing based on recipient field.
   *
   * @var string
   */
  public $recipient_listing;

  /**
   * Body of the mailing in text format.
   *
   * @var longtext
   */
  public $body_text;

  /**
   * Body of the mailing in html format.
   *
   * @var longtext
   */
  public $body_html;

  /**
   * Content of the SMS text.
   *
   * @var longtext
   */
  public $sms_body_text;

  /**
   * Subject of mailing
   *
   * @var string
   */
  public $subject;

  /**
   * Record Activity for this reminder?
   *
   * @var boolean
   */
  public $record_activity;

  /**
   * Name/ID of the mapping to use on this table
   *
   * @var string
   */
  public $mapping_id;

  /**
   * FK to Group
   *
   * @var int unsigned
   */
  public $group_id;

  /**
   * FK to the message template.
   *
   * @var int unsigned
   */
  public $msg_template_id;

  /**
   * FK to the message template.
   *
   * @var int unsigned
   */
  public $sms_template_id;

  /**
   * Date on which the reminder be sent.
   *
   * @var date
   */
  public $absolute_date;

  /**
   * Name in "from" field
   *
   * @var string
   */
  public $from_name;

  /**
   * Email address in "from" field
   *
   * @var string
   */
  public $from_email;

  /**
   * Send the message as email or sms or both.
   *
   * @var string
   */
  public $mode;

  /**
   * @var int unsigned
   */
  public $sms_provider_id;

  /**
   * Used for repeating entity
   *
   * @var string
   */
  public $used_for;

  /**
   * Used for multilingual installation
   *
   * @var string
   */
  public $filter_contact_language;

  /**
   * Used for multilingual installation
   *
   * @var string
   */
  public $communication_language;

  /**
   * Class constructor.
   */
  public function __construct() {
    $this->__table = 'civicrm_action_schedule';
    parent::__construct();
  }

  /**
   * Returns foreign keys and entity references.
   *
   * @return array
   *   [CRM_Core_Reference_Interface]
   */
  public static function getReferenceColumns() {
    if (!isset(Civi::$statics[__CLASS__]['links'])) {
      Civi::$statics[__CLASS__]['links'] = static ::createReferenceColumns(__CLASS__);
      Civi::$statics[__CLASS__]['links'][] = new CRM_Core_Reference_Basic(self::getTableName(), 'group_id', 'civicrm_group', 'id');
      Civi::$statics[__CLASS__]['links'][] = new CRM_Core_Reference_Basic(self::getTableName(), 'msg_template_id', 'civicrm_msg_template', 'id');
      Civi::$statics[__CLASS__]['links'][] = new CRM_Core_Reference_Basic(self::getTableName(), 'sms_template_id', 'civicrm_msg_template', 'id');
      Civi::$statics[__CLASS__]['links'][] = new CRM_Core_Reference_Basic(self::getTableName(), 'sms_provider_id', 'civicrm_sms_provider', 'id');
      CRM_Core_DAO_AllCoreTables::invoke(__CLASS__, 'links_callback', Civi::$statics[__CLASS__]['links']);
    }
    return Civi::$statics[__CLASS__]['links'];
  }

  /**
   * Returns all the column names of this table
   *
   * @return array
   */
  public static function &fields() {
    if (!isset(Civi::$statics[__CLASS__]['fields'])) {
      Civi::$statics[__CLASS__]['fields'] = [
        'id' => [
          'name' => 'id',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Action Schedule ID'),
          'required' => TRUE,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'name' => [
          'name' => 'name',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Name'),
          'description' => 'Name of the action(reminder)',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'title' => [
          'name' => 'title',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Title'),
          'description' => 'Title of the action(reminder)',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'recipient' => [
          'name' => 'recipient',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Recipient'),
          'description' => 'Recipient',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'limit_to' => [
          'name' => 'limit_to',
          'type' => CRM_Utils_Type::T_BOOLEAN,
          'title' => ts('Limit To'),
          'description' => 'Is this the recipient criteria limited to OR in addition to?',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'entity_value' => [
          'name' => 'entity_value',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Entity Value'),
          'description' => 'Entity value',
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'entity_status' => [
          'name' => 'entity_status',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Entity Status'),
          'description' => 'Entity status',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'start_action_offset' => [
          'name' => 'start_action_offset',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Start Action Offset'),
          'description' => 'Reminder Interval.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'start_action_unit' => [
          'name' => 'start_action_unit',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Start Action Unit'),
          'description' => 'Time units for reminder.',
          'maxlength' => 8,
          'size' => CRM_Utils_Type::EIGHT,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
          'html' => [
            'type' => 'Select',
          ],
          'pseudoconstant' => [
            'callback' => 'CRM_Core_SelectValues::getRecurringFrequencyUnits',
          ]
        ],
        'start_action_condition' => [
          'name' => 'start_action_condition',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Start Action Condition'),
          'description' => 'Reminder Action',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'start_action_date' => [
          'name' => 'start_action_date',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Start Action Date'),
          'description' => 'Entity date',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'is_repeat' => [
          'name' => 'is_repeat',
          'type' => CRM_Utils_Type::T_BOOLEAN,
          'title' => ts('Repeat?'),
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'repetition_frequency_unit' => [
          'name' => 'repetition_frequency_unit',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Repetition Frequency Unit'),
          'description' => 'Time units for repetition of reminder.',
          'maxlength' => 8,
          'size' => CRM_Utils_Type::EIGHT,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
          'html' => [
            'type' => 'Select',
          ],
          'pseudoconstant' => [
            'callback' => 'CRM_Core_SelectValues::getRecurringFrequencyUnits',
          ]
        ],
        'repetition_frequency_interval' => [
          'name' => 'repetition_frequency_interval',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Repetition Frequency Interval'),
          'description' => 'Time interval for repeating the reminder.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'end_frequency_unit' => [
          'name' => 'end_frequency_unit',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('End Frequency Unit'),
          'description' => 'Time units till repetition of reminder.',
          'maxlength' => 8,
          'size' => CRM_Utils_Type::EIGHT,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
          'html' => [
            'type' => 'Select',
          ],
          'pseudoconstant' => [
            'callback' => 'CRM_Core_SelectValues::getRecurringFrequencyUnits',
          ]
        ],
        'end_frequency_interval' => [
          'name' => 'end_frequency_interval',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('End Frequency Interval'),
          'description' => 'Time interval till repeating the reminder.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'end_action' => [
          'name' => 'end_action',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('End Action'),
          'description' => 'Reminder Action till repeating the reminder.',
          'maxlength' => 32,
          'size' => CRM_Utils_Type::MEDIUM,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'end_date' => [
          'name' => 'end_date',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('End Date'),
          'description' => 'Entity end date',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'is_active' => [
          'name' => 'is_active',
          'type' => CRM_Utils_Type::T_BOOLEAN,
          'title' => ts('Schedule is Active?'),
          'description' => 'Is this option active?',
          'default' => '1',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'recipient_manual' => [
          'name' => 'recipient_manual',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Recipient Manual'),
          'description' => 'Contact IDs to which reminder should be sent.',
          'maxlength' => 128,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'recipient_listing' => [
          'name' => 'recipient_listing',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Recipient Listing'),
          'description' => 'listing based on recipient field.',
          'maxlength' => 128,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'body_text' => [
          'name' => 'body_text',
          'type' => CRM_Utils_Type::T_LONGTEXT,
          'title' => ts('Reminder Text'),
          'description' => 'Body of the mailing in text format.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'body_html' => [
          'name' => 'body_html',
          'type' => CRM_Utils_Type::T_LONGTEXT,
          'title' => ts('Reminder HTML'),
          'description' => 'Body of the mailing in html format.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'sms_body_text' => [
          'name' => 'sms_body_text',
          'type' => CRM_Utils_Type::T_LONGTEXT,
          'title' => ts('SMS Reminder Text'),
          'description' => 'Content of the SMS text.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'subject' => [
          'name' => 'subject',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Reminder Subject'),
          'description' => 'Subject of mailing',
          'maxlength' => 128,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'record_activity' => [
          'name' => 'record_activity',
          'type' => CRM_Utils_Type::T_BOOLEAN,
          'title' => ts('Record Activity for Reminder?'),
          'description' => 'Record Activity for this reminder?',
          'default' => 'NULL',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'mapping_id' => [
          'name' => 'mapping_id',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Reminder Mapping'),
          'description' => 'Name/ID of the mapping to use on this table',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'group_id' => [
          'name' => 'group_id',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Reminder Group'),
          'description' => 'FK to Group',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
          'FKClassName' => 'CRM_Contact_DAO_Group',
          'html' => [
            'type' => 'Select',
          ],
          'pseudoconstant' => [
            'table' => 'civicrm_group',
            'keyColumn' => 'id',
            'labelColumn' => 'title',
          ]
        ],
        'msg_template_id' => [
          'name' => 'msg_template_id',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Reminder Template'),
          'description' => 'FK to the message template.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
          'FKClassName' => 'CRM_Core_DAO_MessageTemplate',
        ],
        'sms_template_id' => [
          'name' => 'sms_template_id',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('SMS Reminder Template'),
          'description' => 'FK to the message template.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
          'FKClassName' => 'CRM_Core_DAO_MessageTemplate',
        ],
        'absolute_date' => [
          'name' => 'absolute_date',
          'type' => CRM_Utils_Type::T_DATE,
          'title' => ts('Fixed Date for Reminder'),
          'description' => 'Date on which the reminder be sent.',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'from_name' => [
          'name' => 'from_name',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Reminder from Name'),
          'description' => 'Name in "from" field',
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'from_email' => [
          'name' => 'from_email',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Reminder From Email'),
          'description' => 'Email address in "from" field',
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'mode' => [
          'name' => 'mode',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Message Mode'),
          'description' => 'Send the message as email or sms or both.',
          'maxlength' => 128,
          'size' => CRM_Utils_Type::HUGE,
          'default' => 'Email',
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
          'html' => [
            'type' => 'Select',
          ],
          'pseudoconstant' => [
            'optionGroupName' => 'msg_mode',
            'optionEditPath' => 'civicrm/admin/options/msg_mode',
          ]
        ],
        'sms_provider_id' => [
          'name' => 'sms_provider_id',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('SMS Provider'),
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
          'FKClassName' => 'CRM_SMS_DAO_Provider',
          'html' => [
            'type' => 'Select',
          ],
        ],
        'used_for' => [
          'name' => 'used_for',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Used For'),
          'description' => 'Used for repeating entity',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'filter_contact_language' => [
          'name' => 'filter_contact_language',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Filter Contact Language'),
          'description' => 'Used for multilingual installation',
          'maxlength' => 128,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
        'communication_language' => [
          'name' => 'communication_language',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Communication Language'),
          'description' => 'Used for multilingual installation',
          'maxlength' => 8,
          'size' => CRM_Utils_Type::EIGHT,
          'table_name' => 'civicrm_action_schedule',
          'entity' => 'ActionSchedule',
          'bao' => 'CRM_Core_BAO_ActionSchedule',
          'localizable' => 0,
        ],
      ];
      CRM_Core_DAO_AllCoreTables::invoke(__CLASS__, 'fields_callback', Civi::$statics[__CLASS__]['fields']);
    }
    return Civi::$statics[__CLASS__]['fields'];
  }

  /**
   * Return a mapping from field-name to the corresponding key (as used in fields()).
   *
   * @return array
   *   Array(string $name => string $uniqueName).
   */
  public static function &fieldKeys() {
    if (!isset(Civi::$statics[__CLASS__]['fieldKeys'])) {
      Civi::$statics[__CLASS__]['fieldKeys'] = array_flip(CRM_Utils_Array::collect('name', self::fields()));
    }
    return Civi::$statics[__CLASS__]['fieldKeys'];
  }

  /**
   * Returns the names of this table
   *
   * @return string
   */
  public static function getTableName() {
    return self::$_tableName;
  }

  /**
   * Returns if this table needs to be logged
   *
   * @return bool
   */
  public function getLog() {
    return self::$_log;
  }

  /**
   * Returns the list of fields that can be imported
   *
   * @param bool $prefix
   *
   * @return array
   */
  public static function &import($prefix = FALSE) {
    $r = CRM_Core_DAO_AllCoreTables::getImports(__CLASS__, 'action_schedule', $prefix, []);
    return $r;
  }

  /**
   * Returns the list of fields that can be exported
   *
   * @param bool $prefix
   *
   * @return array
   */
  public static function &export($prefix = FALSE) {
    $r = CRM_Core_DAO_AllCoreTables::getExports(__CLASS__, 'action_schedule', $prefix, []);
    return $r;
  }

  /**
   * Returns the list of indices
   *
   * @param bool $localize
   *
   * @return array
   */
  public static function indices($localize = TRUE) {
    $indices = [];
    return ($localize && !empty($indices)) ? CRM_Core_DAO_AllCoreTables::multilingualize(__CLASS__, $indices) : $indices;
  }

}
