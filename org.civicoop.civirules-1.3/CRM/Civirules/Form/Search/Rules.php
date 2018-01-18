<?php

/**
 * Custom Search class to find CiviRules Rules
 *
 * @see https://wiki.civicrm.org/confluence/display/CRMDOC46/Create+a+Custom-Search+Extension
 *
 * @author Erik Hommel (CiviCooP) <erik.hommel@civicoop.org>
 * @license http://www.gnu.org/licenses/agpl-3.0.html
 */
class CRM_Civirules_Form_Search_Rules extends CRM_Contact_Form_Search_Custom_Base implements CRM_Contact_Form_Search_Interface {

  private $_domainVersion = NULL;

  function __construct(&$formValues) {
    // keep track of version so we can do ugly backwards compatibility hack in function alterRow
    $domainVersion = civicrm_api3('Domain', 'getvalue', array('current_domain' => "TRUE", 'return' => 'version'));
    $this->_domainVersion = round((float) $domainVersion, 2);

    parent::__construct($formValues);
  }

  /**
   * Prepare a set of search fields
   *
   * @param CRM_Core_Form $form modifiable
   * @return void
   */
  function buildForm(&$form) {
    CRM_Utils_System::setTitle(ts('Find CiviRules Rules'));
    $form->add('text', 'rule_label', ts('Rule Label contains'), TRUE);
    $form->add('select', 'rule_tag_id', ts('Rule Tag(s)'), CRM_Civirules_BAO_RuleTag::getRuleTagsList(), FALSE,
      array('id' => 'rule_tag_id', 'multiple' => 'multiple', 'class' => 'crm-select2'));
    $form->add('select', 'rule_trigger_id', ts('Rule Trigger(s)'), $this->getRuleTriggers(), FALSE,
      array('id' => 'rule_trigger_id', 'multiple' => 'multiple', 'class' => 'crm-select2'));
    $onlyActive = array(
      '1' => ts('Only active Rules)'),
      '0' => ts('All Rules'),
    );
    $form->addRadio('only_active_rules', ts('Find only active Rules?'), $onlyActive, NULL, '<br />', TRUE);
    $defaults['only_active_rules'] = 1;
    $form->setDefaults($defaults);
    $form->assign('elements', array('rule_label', 'rule_tag_id', 'rule_trigger_id', 'only_active_rules'));
  }

  /**
   * Method to build select list of all active triggers
   * @return array
   */
  private function getRuleTriggers() {
    $result = array();
    $triggers = CRM_Civirules_BAO_Trigger::getValues(array('is_active' => 1));
    foreach ($triggers as $trigger) {
      $result[$trigger['id']] = $trigger['label'];
    }
    return $result;
  }

  /**
   * Get a list of displayable columns
   *
   * @return array, keys are printable column headers and values are SQL column names
   */
  function &columns() {
    // return by reference
    $columns = array(
      ts('Rule Label') => 'rule_label',
      ts('Trigger') => 'rule_trigger_label',
      ts('Tag(s)') => 'rule_tags',
      ts('Description') => 'rule_description',
      ts('Active?') => 'is_active',
      ts('Date Created') => 'rule_created_date',
      ts('Created By') => 'rule_created_by',
      // hidden row elements
      ts('RuleID') => 'rule_id',
      ts('Help Text') => 'rule_help_text',
      ts('Hidden Active') => 'rule_is_active'
    );
    return $columns;
  }

  /**
   * Construct a full SQL query which returns one page worth of results
   *
   * @param int $offset
   * @param int $rowcount
   * @param null $sort
   * @param bool $includeContactIDs
   * @param bool $justIDs
   * @return string, sql
   */
  function all($offset = 0, $rowcount = 0, $sort = NULL, $includeContactIDs = FALSE, $justIDs = FALSE) {
    // delegate to $this->sql(), $this->select(), $this->from(), $this->where(), etc.
    return $this->sql($this->select(), $offset, $rowcount, $sort, FALSE, NULL);
  }

  /**
   * Construct a SQL SELECT clause
   *
   * @return string, sql fragment with SELECT arguments
   */
  function select() {
    return "DISTINCT(crr.id) AS rule_id, crr.name AS rule_name, crr.label AS rule_label, crr.is_active AS rule_is_active,
	'' AS rule_tags, crtrigger.label AS rule_trigger_label, crr.description AS rule_description, '' AS is_active,
	crr.help_text AS rule_help_text, crr.created_date AS rule_created_date, contact.display_name AS rule_created_by";
  }

  /**
   * Construct a SQL FROM clause
   *
   * @return string, sql fragment with FROM and JOIN clauses
   */
  function from() {
    return "
      FROM civirule_rule crr
LEFT JOIN civirule_trigger crtrigger ON crr.trigger_id = crtrigger.id
LEFT JOIN civirule_rule_tag crtag ON crr.id = crtag.rule_id
LEFT JOIN civicrm_contact contact ON crr.created_user_id = contact.id";
  }

  /**
   * Construct a SQL WHERE clause
   *
   * @param bool $includeContactIDs
   * @return string, sql fragment with conditional expressions
   */
  function where($includeContactIDs = FALSE) {
    $params = array();
    $index  = 1;
    $clauses = array();

    $onlyActiveRules = CRM_Utils_Array::value('only_active_rules', $this->_formValues);
    if ($onlyActiveRules == 1) {
      $clauses[] = "crr.is_active = %{$index}";
      $params[$index] = array(1, 'Integer');
      $index++;
    }

    $label   = CRM_Utils_Array::value('rule_label', $this->_formValues);
    if ($label != NULL) {
      if (strpos($label, '%') === FALSE) {
        $label = "%{$label}%";
      }
      $params[$index] = array($label, 'String');
      $clauses[] = "crr.label LIKE %{$index}";
      $index++;
    }

    $ruleTagIds = CRM_Utils_Array::value('rule_tag_id', $this->_formValues);
    $tagClauses = array();
    foreach ($ruleTagIds as $ruleTagId) {
      $params[$index] = array($ruleTagId, 'Integer');
      $tagClauses[] = "crtag.rule_tag_id = %".$index;
      $index++;
    }

    $ruleTriggerIds = CRM_Utils_Array::value('rule_trigger_id', $this->_formValues);
    $triggerClauses = array();
    foreach ($ruleTriggerIds as $ruleTriggerId) {
      $params[$index] = array($ruleTriggerId, 'Integer');
      $triggerClauses[] = "crr.trigger_id = %".$index;
      $index++;
    }

    $where = implode(' AND ', $clauses);
    if (!empty($tagClauses)) {
      $where .= ' AND ('.implode(' OR ', $tagClauses).")";
    }
    if (!empty($triggerClauses)) {
      $where .= ' AND ('.implode(' OR ', $triggerClauses).")";
    }

    return $this->whereClause($where, $params);
  }

  /**
   * Determine the Smarty template for the search screen
   *
   * @return string, template path (findable through Smarty template path)
   */
  function templateFile() {
    return 'CRM/Civirules/Form/Search/Rules.tpl';
  }

  /**
   * Modify the content of each row
   *
   * @param array $row modifiable SQL result row
   * @return void
   */
  function alterRow(&$row) {
    // get all tag labels for rule
    $ruleTagLabels = CRM_Civirules_BAO_RuleTag::getTagLabelsForRule($row['rule_id']);
    $row['rule_tags'] = implode ('; ', $ruleTagLabels);

    if ($row['rule_is_active'] == 1) {
      $row['is_active'] = ts("Yes");
    } else {
      $row['is_active'] = ts("No");
    }
    if (!empty($row['rule_help_text'])) {
      $row['rule_help_text'] = trim($row['rule_help_text']);
      $helpParts = explode(' ', $row['rule_help_text']);
      foreach ($helpParts as $key => $value) {
        $helpParts[$key] = htmlentities(htmlspecialchars(stripslashes($value)));
      }
      $row['rule_help_text'] = json_encode($helpParts);
    }
    // ugly hack to allow backwards compatibility with CiviCRM versions earlier than 4.6
    if ($this->_domainVersion < 4.6) {
      $row['earlier_than_46'] = 1;
    } else {
      $row['earlier_than_46'] = 0;
    }

  }
  /**
   * Method to count selected rules
   *
   * @return string
   */
  function count() {
    return CRM_Core_DAO::singleValueQuery($this->sql('COUNT(DISTINCT(crr.id)) AS total'), array(), 0, NULL, FALSE, NULL);
  }

  /**
   * @param $sql
   * @param bool $onlyWhere
   *
   * @throws Exception
   */
  public function validateUserSQL(&$sql, $onlyWhere = FALSE) {
    $excludeStrings = array('insert', 'delete', 'update');
    foreach ($excludeStrings as $string) {
      if (preg_match('/(\s' . $string . ')|(' . $string . '\s)/i', $sql)) {
        CRM_Core_Error::fatal(ts('Found illegal \'%1\' string in SQL clause.',
          array(1 => $string)
        ));
      }
    }
  }
  /**
   * Builds the list of tasks or actions that a searcher can perform on a result set.
   *
   * The returned array completely replaces the task list, so a child class that
   * wants to modify the existing list should manipulate the result of this method.
   *
   * @param CRM_Core_Form_Search $form
   * @return array
   */
  public function buildTaskList(CRM_Core_Form_Search $form) {
    return array();
  }
}
