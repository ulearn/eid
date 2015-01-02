<?php

require_once 'CRM/Attendance/Form/Task.php';
require_once 'CRM/Attendance/Selector/Search.php';
require_once 'CRM/Core/Selector/Controller.php';

/**
 * This class provides the functionality to print members
 */
class CRM_Attendance_Form_Task_Print extends CRM_Attendance_Form_Task 
{
    /**
     * build all the data structures needed to build the form
     *
     * @return void
     * @access public
     */
    function preProcess()
    {
        parent::preprocess( );

        // set print view, so that print templates are called
        $this->controller->setPrint( 1 );

        // get the formatted params
        $queryParams = $this->get( 'queryParams' );

        $sortID = null;
        if ( $this->get( CRM_Utils_Sort::SORT_ID  ) ) {
            $sortID = CRM_Utils_Sort::sortIDValue( $this->get( CRM_Utils_Sort::SORT_ID  ),
                                                   $this->get( CRM_Utils_Sort::SORT_DIRECTION ) );
        }
		
        $selector   =& new CRM_Attendance_Selector_Search($queryParams, $this->_action, $this->_componentClause );
        $controller =& new CRM_Core_Selector_Controller($selector , null, $sortID, CRM_Core_Action::VIEW, $this, CRM_Core_Selector_Controller::SCREEN);
        $controller->setEmbedded( true );
        $controller->run();
    }

    /**
     * Build the form - it consists of
     *    - displaying the QILL (query in local language)
     *    - displaying elements for saving the search
     *
     * @access public
     * @return void
     */
    function buildQuickForm()
    {
        //
        // just need to add a javacript to popup the window for printing
        // 
        $this->addButtons( array(
                                 array ( 'type'      => 'next',
                                         'name'      => ts('Print Members'),
                                         'js'        => array( 'onclick' => 'window.print()' ),
                                         'isDefault' => true   ),
                                 array ( 'type'      => 'back',
                                         'name'      => ts('Done') ),
                                 )
                           );
    }

    /**
     * process the form after the input has been submitted and validated
     *
     * @access public
     * @return void
     */
    public function postProcess()
    {
        // redirect to the main search page after printing is over
    }
}


