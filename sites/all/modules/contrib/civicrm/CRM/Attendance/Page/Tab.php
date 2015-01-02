<?php

require_once 'CRM/Core/Page.php';

class CRM_Attendance_Page_Tab extends CRM_Core_Page {


  public $_permission = NULL;
  public $_contactId = NULL;

  /**
   * This function is called when action is browse
   *
   * return null
   * @access public
   */
  function browse() {
    $controller = new CRM_Core_Controller_Simple(
      'CRM_Attendance_Form_Search',
      ts('Attendance'),
      $this->_action
    );
    $controller->setEmbedded(TRUE);
    $controller->reset();
    $controller->set('cid', $this->_contactId);
    $controller->set('context', 'attendance');
    $controller->process();
    $controller->run();

    if ($this->_contactId) {
      $displayName = CRM_Contact_BAO_Contact::displayName($this->_contactId);
      $this->assign('displayName', $displayName);
    }
    $partial_result = array(); 
    $select_query_partial = "SELECT contact_id,sort_name, total_class_days, total_attended_days, persentage, civicrm_course_attendance.id, contact_id  FROM  civicrm_course_attendance join civicrm_contact on (civicrm_contact.id = civicrm_course_attendance.contact_id) where civicrm_course_attendance.contact_id = '$this->_contactId'";
     $query_result = CRM_Core_DAO::executeQuery($select_query_partial);
     $partial_count = 1;
     while($query_result->fetch()) {
      $partial_result[$partial_count]['id'] = $query_result->contact_id;
       $partial_result[$partial_count]['sort_name'] = $query_result->sort_name;
      $partial_result[$partial_count]['total_class_days'] = $query_result->total_class_days;
      $partial_result[$partial_count]['total_attended_days'] = $query_result->total_attended_days;
      $partial_result[$partial_count]['persentage'] = $query_result->persentage;
      $partial_count++;
     }
    $this->assign('associatedAttendance', $partial_result);
  }


  /**
   * This function is called when action is view
   *
   * return null
   * @access public
   */
  function view() {

   
  }

  /**
   * This function is called when action is edit or delete
   *
   * return null
   * @access public
   */
  function edit() {

  
  }


  /**
   * This function is called when action is cancel
   *
   * return null
   * @access public
   */
  function cancel() {

    
  }



  function preProcess() {
    $context       = CRM_Utils_Request::retrieve('context', 'String', $this);
    $this->_action = CRM_Utils_Request::retrieve('action', 'String', $this, FALSE, 'browse');
    $this->_id     = CRM_Utils_Request::retrieve('id', 'Positive', $this);

    if ($context == 'standalone') {
      $this->_action = CRM_Core_Action::ADD;
    }
    else {
      $this->_contactId = CRM_Utils_Request::retrieve('cid', 'Positive', $this, TRUE);
      $this->assign('contactId', $this->_contactId);

      // check logged in url permission
      CRM_Contact_Page_View::checkUserPermission($this);

      // set page title
      CRM_Contact_Page_View::setTitle($this->_contactId);
    }

    $this->assign('action', $this->_action);

    if ($this->_permission == CRM_Core_Permission::EDIT && !CRM_Core_Permission::check('edit attendance')) {
      // demote to view since user does not have edit booking rights
      $this->_permission = CRM_Core_Permission::VIEW;
      $this->assign('permission', 'view');
    }
  }

  /**
   * This function is the main function that is called when the page loads, it decides the which action has to be taken for the page.
   *
   * return null
   * @access public
   */
  function run() {
    $this->preProcess();

    $this->setContext();

    if ($this->_action & (CRM_Core_Action::UPDATE | CRM_Core_Action::DELETE)) {
      $this->edit();
    }elseif ($this->_action & CRM_Core_Action::VIEW){
      $this->view();
    }elseif ($this->_action & CRM_Core_Action::CLOSE){
      $this->cancel();
    }else {
      $this->browse();
    }

    return parent::run();
  }


  function setContext() {
    $context = CRM_Utils_Request::retrieve('context',
      'String', $this, FALSE, 'search'
    );
    $compContext = CRM_Utils_Request::retrieve('compContext',
      'String', $this
    );

    $qfKey = CRM_Utils_Request::retrieve('key', 'String', $this);

    //validate the qfKey
    if (!CRM_Utils_Rule::qfKey($qfKey)) {
      $qfKey = NULL;
    }

    switch ($context) {
      case 'dashboard':
        //TODO:: Implement dashboard for booking
        $url = CRM_Utils_System::url('civicrm/attendance', 'reset=1');
        break;

      case 'search':
        $urlParams = 'force=1';
        if ($qfKey) {
          $urlParams .= "&qfKey=$qfKey";
        }
        $this->assign('searchKey', $qfKey);

        if ($compContext == 'advanced') {
          $url = CRM_Utils_System::url('civicrm/contact/search/advanced', $urlParams);
        }
        else {
          $url = CRM_Utils_System::url('civicrm/booking/search', $urlParams);
        }
        break;

      case 'user':
        $url = CRM_Utils_System::url('civicrm/user', 'reset=1');
        break;

      case 'participant':
        $url = CRM_Utils_System::url('civicrm/contact/view',
          "reset=1&force=1&cid={$this->_contactId}&selectedChild=participant"
        );
        break;

      case 'home':
        $url = CRM_Utils_System::url('civicrm/dashboard', 'force=1');
        break;

      case 'activity':
        $url = CRM_Utils_System::url('civicrm/contact/view',
          "reset=1&force=1&cid={$this->_contactId}&selectedChild=activity"
        );
        break;

      case 'attendance':
        $url = CRM_Utils_System::url('civicrm/contact/view',
          "reset=1&force=1&cid={$this->_contactId}&selectedChild=attendance"
        );
        break;

      case 'standalone':
        $url = CRM_Utils_System::url('civicrm/dashboard', 'reset=1');
        break;

      case 'fulltext':
        $keyName   = '&qfKey';
        $urlParams = 'force=1';
        $urlString = 'civicrm/contact/search/custom';
        if ($this->_action == CRM_Core_Action::UPDATE) {
          if ($this->_contactId) {
            $urlParams .= '&cid=' . $this->_contactId;
          }
          $keyName = '&key';
          $urlParams .= '&context=fulltext&action=view';
          $urlString = 'civicrm/contact/view/participant';
        }
        if ($qfKey) {
          $urlParams .= "$keyName=$qfKey";
        }
        $this->assign('searchKey', $qfKey);
        $url = CRM_Utils_System::url($urlString, $urlParams);
        break;

      default:
        $cid = NULL;
        if ($this->_contactId) {
          $cid = '&cid=' . $this->_contactId;
        }
        $url = CRM_Utils_System::url('civicrm/attendance/search',
          'force=1' . $cid
        );
        break;
    }
    $session = CRM_Core_Session::singleton();
    $session->pushUserContext($url);
  }

}
