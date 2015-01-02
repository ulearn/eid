<?php

require_once 'CRM/Core/Controller.php';
require_once 'CRM/Core/Session.php';

/**
 * This class is used by the Search functionality.
 *
 *  - the search controller is used for building/processing multiform
 *    searches.
 *
 * Typically the first form will display the search criteria and it's results
 *
 * The second form is used to process search results with the asscociated actions
 *
 */
class CRM_Attendance_Controller_Search extends CRM_Core_Controller {

  /**
   * class constructor
   */
  function __construct( $title = null, $action = CRM_Core_Action::NONE, $modal = true ) {
		
    require_once 'CRM/Attendance/StateMachine/Search.php';
    parent::__construct( $title, $modal );
    $this->_stateMachine =& new CRM_Attendance_StateMachine_Search( $this, $action );
    // create and instantiate the pages
    $this->addPages( $this->_stateMachine, $action );
    // add all the actions
    $config =& CRM_Core_Config::singleton( );
    $this->addActions( );
  }
}
