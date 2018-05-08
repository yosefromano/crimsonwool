<?php
/**
 * @file
 * This provides the Sync Pull into CiviCRM from Constant Contact form.
 */

class CRM_Householdgreetings_Form_Update extends CRM_Core_Form {

  const QUEUE_NAME = 'cc-pull';
  const END_URL    = 'civicrm/contact/greetings/update';
  const END_PARAMS = 'state=done';
  /**
   * Function to pre processing
   *
   * @return None
   * @access public
   */
  function preProcess() {
    parent::preProcess();
  }

  /**
   * Function to actually build the form
   *
   * @return None
   * @access public
   */
  public function buildQuickForm() {
    $this->addButtons(array(
      array(
        'type' => 'submit',
        'name' => ts('Update Contact(s) greetings'),
        'isDefault' => TRUE,
      ),
      array(
        'type' => 'cancel',
        'name' => ts('Cancel'),
      ),
    ));
  }

  /**
   * Function to process the form
   *
   * @access public
   *
   * @return None
   */
  public function postProcess() {
    $submitValues = $this->_submitValues;
    $runner = self::getRunner($submitValues);
    if ($runner) {
      // Run Everything in the Queue via the Web.
      $runner->runAllViaWeb();
    } else {
      CRM_Core_Session::setStatus(ts('Nothing to pull.'));
    }
  }

  /**
   * Set up the queue.
   */
  public static function getRunner($submitValues) {
    // Setup the Queue
    $queue = CRM_Queue_Service::singleton()->create(array(
      'name'  => self::QUEUE_NAME,
      'type'  => 'Sql',
      'reset' => TRUE,
    ));
    $contactCount = CRM_Core_DAO::singleValueQuery('SELECT count(id) FROM civicrm_contact WHERE contact_type = "Individual"');
    $batchSize = 100;
    for ($startId = 0; $startId <= $contactCount; $startId += $batchSize) {
      $endId = $startId + $batchSize;
      $queue->createItem( new CRM_Queue_Task(
        ['CRM_Householdgreetings_Form_Update', 'updateGreetings'],
        [$startId, $batchSize],
        "Update reetings($startId => $endId): Update greetings for contact... "
      ));
    }

    // Setup the Runner
    $runnerParams = [
      'title' => ts('Update Greetings for contacts'),
      'queue' => $queue,
      'errorMode'=> CRM_Queue_Runner::ERROR_ABORT,
      'onEndUrl' => CRM_Utils_System::url(self::END_URL, self::END_PARAMS, TRUE, NULL, FALSE),
    ];

    $runner = new CRM_Queue_Runner($runnerParams);
    return $runner;
  }

  public static function updateGreetings(CRM_Queue_TaskContext $ctx, $startId, $endId) {
    $sql = "SELECT id FROM civicrm_contact WHERE contact_type = 'Individual' LIMIT $startId, $endId";
    $result = CRM_Core_DAO::executeQuery($sql);
    while ($result->fetch()) {
      civicrm_api3('Contact', 'create', ['id' => $result->id]);
    }
    return CRM_Queue_Task::TASK_SUCCESS;
  }
}
