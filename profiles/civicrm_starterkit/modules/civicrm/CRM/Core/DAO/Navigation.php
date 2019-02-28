<?php

/**
 * @package CRM
 * @copyright CiviCRM LLC (c) 2004-2019
 *
 * Generated from xml/schema/CRM/Core/Navigation.xml
 * DO NOT EDIT.  Generated by CRM_Core_CodeGen
 * (GenCodeChecksum:f168de98d6c4d46c63abfd789f6fdf24)
 */

/**
 * Database access object for the Navigation entity.
 */
class CRM_Core_DAO_Navigation extends CRM_Core_DAO {

  /**
   * Static instance to hold the table name.
   *
   * @var string
   */
  static $_tableName = 'civicrm_navigation';

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
   * Which Domain is this navigation item for
   *
   * @var int unsigned
   */
  public $domain_id;

  /**
   * Navigation Title
   *
   * @var string
   */
  public $label;

  /**
   * Internal Name
   *
   * @var string
   */
  public $name;

  /**
   * url in case of custom navigation link
   *
   * @var string
   */
  public $url;

  /**
   * CSS class name for an icon
   *
   * @var string
   */
  public $icon;

  /**
   * Permission for menu item
   *
   * @var string
   */
  public $permission;

  /**
   * Permission Operator
   *
   * @var string
   */
  public $permission_operator;

  /**
   * Parent navigation item, used for grouping
   *
   * @var int unsigned
   */
  public $parent_id;

  /**
   * Is this navigation item active?
   *
   * @var boolean
   */
  public $is_active;

  /**
   * If separator needs to be added after this menu item
   *
   * @var boolean
   */
  public $has_separator;

  /**
   * Ordering of the navigation items in various blocks.
   *
   * @var int
   */
  public $weight;

  /**
   * Class constructor.
   */
  public function __construct() {
    $this->__table = 'civicrm_navigation';
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
      Civi::$statics[__CLASS__]['links'][] = new CRM_Core_Reference_Basic(self::getTableName(), 'domain_id', 'civicrm_domain', 'id');
      Civi::$statics[__CLASS__]['links'][] = new CRM_Core_Reference_Basic(self::getTableName(), 'parent_id', 'civicrm_navigation', 'id');
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
          'title' => ts('Navigation ID'),
          'required' => TRUE,
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'domain_id' => [
          'name' => 'domain_id',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Navigation Domain'),
          'description' => ts('Which Domain is this navigation item for'),
          'required' => TRUE,
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
          'FKClassName' => 'CRM_Core_DAO_Domain',
          'pseudoconstant' => [
            'table' => 'civicrm_domain',
            'keyColumn' => 'id',
            'labelColumn' => 'name',
          ]
        ],
        'label' => [
          'name' => 'label',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Navigation Item Label'),
          'description' => ts('Navigation Title'),
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'name' => [
          'name' => 'name',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Navigation Item Machine Name'),
          'description' => ts('Internal Name'),
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'url' => [
          'name' => 'url',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Url'),
          'description' => ts('url in case of custom navigation link'),
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'icon' => [
          'name' => 'icon',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Icon'),
          'description' => ts('CSS class name for an icon'),
          'required' => FALSE,
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
          'default' => 'NULL',
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'permission' => [
          'name' => 'permission',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Required Permission'),
          'description' => ts('Permission for menu item'),
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'permission_operator' => [
          'name' => 'permission_operator',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Permission Operator'),
          'description' => ts('Permission Operator'),
          'maxlength' => 3,
          'size' => CRM_Utils_Type::FOUR,
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'parent_id' => [
          'name' => 'parent_id',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Navigation parent ID'),
          'description' => ts('Parent navigation item, used for grouping'),
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
          'FKClassName' => 'CRM_Core_DAO_Navigation',
          'pseudoconstant' => [
            'table' => 'civicrm_navigation',
            'keyColumn' => 'id',
            'labelColumn' => 'label',
            'nameColumn' => 'name',
          ]
        ],
        'is_active' => [
          'name' => 'is_active',
          'type' => CRM_Utils_Type::T_BOOLEAN,
          'title' => ts('Is Active'),
          'description' => ts('Is this navigation item active?'),
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'has_separator' => [
          'name' => 'has_separator',
          'type' => CRM_Utils_Type::T_BOOLEAN,
          'title' => ts('Use separator'),
          'description' => ts('If separator needs to be added after this menu item'),
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
          'localizable' => 0,
        ],
        'weight' => [
          'name' => 'weight',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Order'),
          'description' => ts('Ordering of the navigation items in various blocks.'),
          'table_name' => 'civicrm_navigation',
          'entity' => 'Navigation',
          'bao' => 'CRM_Core_BAO_Navigation',
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
    $r = CRM_Core_DAO_AllCoreTables::getImports(__CLASS__, 'navigation', $prefix, []);
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
    $r = CRM_Core_DAO_AllCoreTables::getExports(__CLASS__, 'navigation', $prefix, []);
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
