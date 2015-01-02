<?php

require_once 'CRM/Core/Component/Info.php';

class CRM_Attendance_Info extends CRM_Core_Component_Info
{


    // docs inherited from interface
    protected $keyword = 'attendance';

    // docs inherited from interface
    public function getInfo()
    {
        return  array( 'name'	              => 'CiviAttendance',
                       'translatedName'       => ts('CiviAttendance'),
                       'title'                => ts('CiviCRM Attendance Engine'),
                       'search'               => 1,
                       'showActivitiesInCore' => 1 
                       );
    }

    // docs inherited from interface
    public function getPermissions($getAllUnconditionally = FALSE)
    {
        return array( 'access CiviAttendance',
                      'edit attendance',
                      'make online attendance',
                      'delete in CiviAttendance' );
    }


    // docs inherited from interface
    public function getUserDashboardElement()
    {
        return array( 'name'    => ts( 'Attendance' ),
                      'title'   => ts( 'Your Attendance(s)' ),
                      'perm'    => array( 'make online attendance' ),
                      'weight'  => 10 );
    }

    // docs inherited from interface
    public function registerTab()
    {
        return array( 'title'   => ts( 'Attendance' ),
                      'url'     => 'attendance',
                      'weight'  => 20 );
    }

    // docs inherited from interface
    public function registerAdvancedSearchPane()
    {
        return array( 'title'   => ts( 'Attendance' ),
                      'weight'  => 20 );
    }

    // docs inherited from interface    
    public function getActivityTypes()
    {
        return null;
    }

   // Add new shortcut for civicrm
   public function creatNewShortcut(&$shortCuts) {

   }
    
}

