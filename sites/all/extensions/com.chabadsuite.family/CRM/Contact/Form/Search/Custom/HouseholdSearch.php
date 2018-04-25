<?php
class CRM_Contact_Form_Search_Custom_HouseholdSearch extends CRM_Contact_Form_Search_Custom_Base implements CRM_Contact_Form_Search_Interface {
  protected $_aclFrom = NULL;
  protected $_aclWhere = NULL;
  /**
   * Class constructor.
   *
   * @param array $formValues
   */
  public function __construct(&$formValues) {
    parent::__construct($formValues);

    // FIXME
    $this->_columns = array(
      ts('Contact-A Prefix') => 'a_prefix',
      ts('Contact-A First Name') => 'a_first_name',
      ts('Contact-A Last Name') => 'a_last_name',
      ts('Contact-B Prefix') => 'b_prefix',
      ts('Contact-B First Name') => 'b_first_name',
      ts('Contact-B Last Name') => 'b_last_name',
      ts('Joint Casual') => 'joint_casual',
      ts('Solo Casual') => 'solo_casual',
      ts('Joint Casual FirstName LastName') => 'joint_casual_firstname_lastname',
      ts('Joint Casual FirstName Only') => 'joint_casual_firstname_only',
      ts('Solo Casual Nickname Only') => 'solo_casual_nickname_only',
      ts('Joint Casual Nickname Only') => 'joint_casual_nickname_only',
      ts('Joint Formal') => 'joint_formal',
      ts('Joint Formal FirstName') => 'joint_formal_firstname',
      ts('Street Address') => 'street_address',
      ts('Supplemental Address 1') => 'supplemental_address_1',
      ts('Supplemental Address 2') => 'supplemental_address_2',
      ts('City') => 'city',
      ts('State') => 'state_province_id',
      ts('Postal Code') => 'postal_code',
      ts('Country') => 'country_id',
    );
  }

  /**
   * Build form.
   *
   * @param CRM_Core_Form $form
   */
  public function buildForm(&$form) {
    $form->_group = CRM_Core_PseudoConstant::group();
    $groupHierarchy = CRM_Contact_BAO_Group::getGroupsHierarchy($form->_group, NULL, '&nbsp;&nbsp;', TRUE);

    $form->add('select', 'include_group', ts('Include Group'), $groupHierarchy, FALSE,
      ['id' => 'group', 'multiple' => 'multiple', 'class' => 'crm-select2']
    );
    $form->add('select', 'exclude_group', ts('Exclude Group'), $groupHierarchy, FALSE,
      ['id' => 'group', 'multiple' => 'multiple', 'class' => 'crm-select2']
    );
    $this->setTitle(ts('Household Search'));
    $form->add('checkbox', 'do_not_mail', ts('exclude contacts with "Do Not Mail" privacy option checked'));
    /**
     * if you are using the standard template, this array tells the template what elements
     * are part of the search criteria
     */
    $form->assign('elements', ['include_group', 'exclude_group', 'do_not_mail']);
  }

  /**
   * @param int $offset
   * @param int $rowcount
   * @param null $sort
   * @param bool $returnSQL
   *
   * @return string
   */
  public function contactIDs($offset = 0, $rowcount = 0, $sort = NULL, $returnSQL = FALSE) {
    return $this->all($offset, $rowcount, $sort, FALSE, TRUE);
  }

  /**
   * @param int $offset
   * @param int $rowcount
   * @param null $sort
   * @param bool $includeContactIDs
   * @param bool $justIDs
   *
   * @return string
   */
  public function all($offset = 0, $rowcount = 0, $sort = NULL, $includeContactIDs = FALSE, $justIDs = FALSE) {
    if ($justIDs) {
      $selectClause = "contact_a.id as contact_id";
      $sort = 'contact_a.id';
    }
    else {
      //FIXME
      $selectClause = "
        contact_a.id contact_id,
        contact_a.prefix_id a_prefix,
        contact_a.first_name a_first_name,
        contact_a.last_name a_last_name,
        contact_b.prefix_id b_prefix,
        contact_b.first_name b_first_name,
        contact_b.last_name b_last_name,
        joint_casual,
        solo_casual,
        joint_casual_firstname_lastname,
        joint_casual_firstname_only,
        solo_casual_nickname_only,
        joint_casual_nickname_only,
        joint_formal,
        joint_formal_firstname,
        street_address,
        supplemental_address_1,
        supplemental_address_2,
        city,
        state_province_id,
        postal_code,
        country_id
      ";
    }

    return $this->sql($selectClause,
      $offset, $rowcount, $sort,
      $includeContactIDs, NULL
    );
  }

  /**
   * @return string
   */
  public function from() {
    $this->buildACLClause('contact_a');
    $from = '';
    if (!empty($this->_formValues['include_group'])
      || !empty($this->_formValues['exclude_group'])
    ) {
      $from = "LEFT JOIN civicrm_group_contact group_contact
        ON group_contact.contact_id = contact_a.id AND group_contact.status = 'Added'
      LEFT JOIN civicrm_group_contact_cache group_contact_cache
        ON group_contact_cache.contact_id = contact_a.id";
    }
    $from = "
      FROM civicrm_contact contact_a
      INNER JOIN (
        SELECT c1.id as contact_id_a, c2.id contact_id_b
        FROM civicrm_contact c1
          INNER JOIN civicrm_relationship cr ON (cr.contact_id_a = c1.id)
          INNER JOIN civicrm_relationship_type crt
            ON cr.relationship_type_id = crt.id AND (lower(name_a_b) LIKE '%spouse%' OR lower(name_a_b) LIKE '%partner%')
              AND cr.is_active = 1
          INNER JOIN civicrm_contact c2 ON (cr.contact_id_b = c2.id)
        WHERE c1.contact_type = 'Individual' AND c1.id <> c2.id
        UNION
        SELECT c2.id, c1.id
        FROM civicrm_contact c1
          INNER JOIN civicrm_relationship cr ON (cr.contact_id_b = c1.id)
          INNER JOIN civicrm_relationship_type crt
            ON cr.relationship_type_id = crt.id AND (lower(name_a_b) LIKE '%spouse%' OR lower(name_a_b) LIKE '%partner%')
              AND cr.is_active = 1
          INNER JOIN civicrm_contact c2 ON (cr.contact_id_a = c2.id)
        WHERE c1.contact_type = 'Individual' AND c1.id <> c2.id
        UNION
        SELECT c1.id, crt.id
        FROM civicrm_contact c1
          LEFT JOIN civicrm_relationship cr ON (cr.contact_id_a = c1.id or cr.contact_id_b = c1.id)
          LEFT JOIN civicrm_relationship_type crt
            ON cr.relationship_type_id = crt.id AND (lower(name_a_b) LIKE '%spouse%' OR lower(name_a_b) LIKE '%partner%')
              AND cr.is_active = 1
        WHERE c1.contact_type = 'Individual' AND crt.id IS NULL AND c1.id NOT IN (
          SELECT c2.id
          FROM civicrm_contact c1
            INNER JOIN civicrm_relationship cr ON (cr.contact_id_a = c1.id)
            INNER JOIN civicrm_relationship_type crt
              ON cr.relationship_type_id = crt.id AND (lower(name_a_b) LIKE '%spouse%' OR lower(name_a_b) LIKE '%partner%')
                AND cr.is_active = 1
            INNER JOIN civicrm_contact c2 ON (cr.contact_id_b = c2.id)
          WHERE c1.contact_type = 'Individual' AND c1.id <> c2.id
        )
        AND c1.id NOT IN (
          SELECT c1.id
          FROM civicrm_contact c1
            INNER JOIN civicrm_relationship cr ON (cr.contact_id_a = c1.id)
            INNER JOIN civicrm_relationship_type crt
              ON cr.relationship_type_id = crt.id AND (lower(name_a_b) LIKE '%spouse%' OR lower(name_a_b) LIKE '%partner%')
                AND cr.is_active = 1
            INNER JOIN civicrm_contact c2 ON (cr.contact_id_b = c2.id)
          WHERE c1.contact_type = 'Individual'  AND c1.id <> c2.id
        )
      ) AS temp ON temp.contact_id_a = contact_a.id
      LEFT JOIN civicrm_contact contact_b ON contact_b.id = temp.contact_id_b
      LEFT JOIN civicrm_value_contact_joint_greetings cv ON cv.entity_id = contact_a.id
      LEFT JOIN civicrm_address ca ON ca.contact_id = contact_a.id AND ca.is_primary = 1
      {$from}
      {$this->_aclFrom}
    ";
    return $from;
  }

  /**
   * @param bool $includeContactIDs
   *
   * @return string
   */
  public function where($includeContactIDs = FALSE) {
    $params = $clause = [];
    $where = "";
    if (CRM_Utils_Array::value('do_not_mail', $this->_formValues)) {
      $clause[] = "contact_a.do_not_mail = 1";
    }
    if (!empty($this->_formValues['include_group'])) {
      $clause[] = '(group_contact_cache.group_id IN ('
        . implode (',', $this->_formValues['include_group'])
        . ') OR (group_contact.group_id IN ('
        . implode (',', $this->_formValues['include_group'])
        . ')))';
    }
    if (!empty($this->_formValues['exclude_group'])) {
      $clause[] = 'contact_a.id NOT IN (
          SELECT c.id FROM civicrm_contact c
            LEFT JOIN civicrm_group_contact group_contact
              ON group_contact.contact_id = c.id
                AND group_contact.status = "Added"
            LEFT JOIN civicrm_group_contact_cache group_contact_cache
              ON group_contact_cache.contact_id = c.id
          WHERE (group_contact_cache.group_id IN ('
            . implode (',', $this->_formValues['exclude_group'])
            . ') OR (group_contact.group_id IN ('
            . implode (',', $this->_formValues['exclude_group'])
            . '))))';
    }
    if ($this->_aclWhere) {
      $clause[] = " {$this->_aclWhere} ";
    }

    if (!empty($clause)) {
      $where = implode(' AND ', $clause);
    }

    return $this->whereClause($where, $params);
  }

  /**
   * @return string
   */
  public function templateFile() {
    return 'CRM/Contact/Form/Search/Custom.tpl';
  }

  /**
   * @param string $tableAlias
   */
  public function buildACLClause($tableAlias = 'contact') {
    list($this->_aclFrom, $this->_aclWhere) = CRM_Contact_BAO_Contact_Permission::cacheClause($tableAlias);
  }

  /**
   * @param $row
   */
  public function alterRow(&$row) {
    if (!empty($row['a_prefix'])) {
      $row['a_prefix'] = CRM_Core_PseudoConstant::getLabel('CRM_Contact_DAO_Contact', 'prefix_id', $row['a_prefix']);
    }
    if (!empty($row['b_prefix'])) {
      $row['b_prefix'] = CRM_Core_PseudoConstant::getLabel('CRM_Contact_DAO_Contact', 'prefix_id', $row['b_prefix']);
    }
    if (!empty($row['state_province_id'])) {
      $row['state_province_id'] = CRM_Core_PseudoConstant::stateProvince($row['state_province_id']);
    }
    if (!empty($row['country_id'])) {
      $row['country_id'] = CRM_Core_PseudoConstant::country($row['country_id']);
    }
  }
}
