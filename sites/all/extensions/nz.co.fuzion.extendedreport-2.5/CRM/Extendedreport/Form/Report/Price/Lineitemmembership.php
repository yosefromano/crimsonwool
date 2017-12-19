<?php
/**
 * Class CRM_Extendedreport_Form_Report_Price_Lineitemmembership
 */
class CRM_Extendedreport_Form_Report_Price_Lineitemmembership extends CRM_Extendedreport_Form_Report_ExtendedReport {
  protected $_addressField = FALSE;

  protected $_emailField = FALSE;

  protected $_summary = NULL;

  protected $_customGroupExtends = array('Membership', 'Individual', 'Contact');

  protected $_baseTable = 'civicrm_line_item';

  protected $_aclTable = 'civicrm_contact';

  /**
   * Class constructor.
   */
  public function __construct() {
    $this->_columns = $this->getColumns('Contact') +
    $this->getColumns('Membership') +
    $this->getColumns('Contribution') +
    $this->getColumns('PriceField') +
    $this->getColumns('PriceFieldValue') +
    $this->getColumns('LineItem') +
    $this->getColumns('Address');

    parent::__construct();
  }

  /**
   * Select from clauses to use.
   *
   * (from those advertised using $this->getAvailableJoins())
   *
   * @return array
   */
  public function fromClauses() {
    return array(
      'priceFieldValue_from_lineItem',
      'priceField_from_lineItem',
      'membership_from_lineItem',
      'contact_from_contribution',
      'address_from_contact',
    );
  }

}
