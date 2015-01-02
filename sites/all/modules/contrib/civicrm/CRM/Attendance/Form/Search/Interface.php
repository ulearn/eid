<?php

interface CRM_Attendance_Form_Search_Interface {
    /**
     * The constructor gets the submitted form values
     */
    function __construct( &$formValues );

    /**
     * Builds the quickform for this search
     */
    function buildForm( &$form );

    /**
     * Builds the search query for various cases. We break it down into finer cases
     * since you can optimize each query independently. All the functions below return
     * a sql clause with only SELECT, FROM, WHERE sub-parts. The ORDER BY and LIMIT is
     * added at a later stage
     */

    /**
     * Count of records that match the current input parameters
     * Used by pager
     */
    function count     ( );

    /**
     * Summary information for the query that can be displayed in the template
     * This is useful to pass total / sub total information if needed
     */
    function summary   ( );

    /**
     * List of contact ids that match the current input parameters
     * Used by different tasks. Will be also used to optimize the
     * 'all' query below to avoid excessive LEFT JOIN blowup
     */
    function contactIDs( $offset = 0, $rowcount = 0, $sort = null );

    /**
     * Retrieve all the values that match the current input parameters
     * Used by the selector
     */
    function all       ( $offset = 0, $rowcount = 0, $sort = null,
                         $includeContactIDs = false );

    /**
     * The below two functions (from and where) are ONLY used if you want to
     * expose a custom group as a smart group and be able to send a mailing
     * to them via CiviMail. civicrm_email should be part of the from clause
     * The from clause should be a valid sql from clause including the word FROM
     * CiviMail will pick up the contacts where the email is primary and
     * is not on hold / opt out / do not email
     *
     */

    /**
     * The from clause for the query 
     */
    function from      ( );

    /**
     * The where clause for the query 
     */
    function where     ( $includeContactIDs = false );

    /**
     * The template FileName to use to display the results
     */
    function  templateFile( );

    /**
     * Returns an array of column headers and field names and sort options
     */
    function &columns( );

}


