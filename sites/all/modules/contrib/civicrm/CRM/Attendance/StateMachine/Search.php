<?php

require_once 'CRM/Core/StateMachine.php';
require_once 'CRM/Core/Action.php';
require_once 'CRM/Attendance/Task.php';

class CRM_Attendance_StateMachine_Search extends CRM_Core_StateMachine 
{
    /**
     * The task that the wizard is currently processing
     *
     * @var string
     * @protected
     */
    protected $_task;

    /**
     * class constructor
     */
    
	function __construct( $controller, $action = CRM_Core_Action::NONE ) 
    {
        parent::__construct( $controller, $action );

        $this->_pages = array( );
        $this->_pages['CRM_Attendance_Form_Search'] = null;
        list( $task, $result ) = $this->taskName( $controller, 'Search' );
		
        if ( is_array( $task ) ) {
            foreach ( $task as $t ) {
                $this->_pages[$t] = null;
            }
        } else {
            $this->_pages[$task] = null;
        }
		
        $this->addSequentialPages( $this->_pages, $action );
    }

    /**
     * Determine the form name based on the action. This allows us
     * to avoid using  conditional state machine, much more efficient
     * and simpler
     *
     * @param CRM_Core_Controller $controller the controller object
     *
     * @return string the name of the form that will handle the task
     * @access protected
     */
    function taskName( $controller, $formName = 'Search' ) 
    {
	
        // total hack, check POST vars and then session to determine stuff
        // fix value if print button is pressed
        if ( CRM_Utils_Array::value( '_qf_' . $formName . '_next_print', $_POST ) ) {
          $value = CRM_Contribute_Task::PRINT_CONTRIBUTIONS;
        } else {
            $value = CRM_Utils_Array::value( 'task', $_POST );
        }
		
		if ( ! isset( $value ) ) {
            $value = $this->_controller->get( 'task' );
        }
		
        $this->_controller->set( 'task', $value );
        $result = false;
		//echo $value;
		//die();
        switch ( $value ) {
        case CRM_Attendance_Task::DELETE_CONTRIBUTIONS:
            $task   = 'CRM_Attendance_Form_Task_Delete';
            break;

        case CRM_Attendance_Task::EXPORT_CONTRIBUTIONS:
            $task   = array('CRM_Export_Form_Select',
                            'CRM_Export_Form_Map');
            break;

        case CRM_Attendance_Task::EMAIL_CONTACTS:
            $task   = array('CRM_Attendance_Form_Task_Email',
                            'CRM_Attendance_Form_Task_Result');
            break;

        case CRM_Attendance_Task::UPDATE_STATUS:
            //$task   = array('CRM_Attendance_Form_Task_Status',
                           // 'CRM_Attendance_Form_Task_Result');
			$task   = array('CRM_Attendance_Form_Task_Status');				
							
            break;

        case CRM_Attendance_Task::BATCH_CONTRIBUTIONS:
            $task   = array( 'CRM_Attendance_Form_Task_PickProfile',
                             'CRM_Attendance_Form_Task_Batch',
                             'CRM_Attendance_Form_Task_Result');
            break;

        case CRM_Attendance_Task::PDF_RECEIPT:
            $task = 'CRM_Attendance_Form_Task_PDF';
            break;

        default: // the print task is the default and catch=all task
            $task = 'CRM_Attendance_Form_Task_Print';
            break;
        }

        return array( $task, $result );
    }

    /**
     * return the form name of the task
     *
     * @return string
     * @access public
     */
    function getTaskFormName( ) 
    {
        return CRM_Utils_String::getClassName( $this->_task );
    }

}

