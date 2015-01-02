<?php

/**
 * @file
 * Please supply a file description.
 */

/**
 * @file
 * Provides myGengo translation plugin controller.
 */
class TMGMTOhtTranslatorUIController extends TMGMTDefaultTranslatorUIController {

  protected $expertiseCodes = array(
    'automotive-aerospace' => 'Automotive/Aerospace',
    'business-finance' => 'Business/Forex/Finance',
    'software-it' => 'Software/IT',
    'legal-certificate' => 'Legal/Certificates',
    'marketing-consumer-media' => 'Marketing/Consumer/Media',
    'cv' => 'CV',
    'medical' => 'Medical',
    'patents' => 'Patents',
    'scientific' => 'Scientific',
    'technical-engineering' => 'Technical/Engineering',
    'gaming-video-games' => 'Gaming/Video Games',
    'ad-words-banners' => 'Ad-Words/Banners',
    'mobile-applications' => 'Mobile Applications',
  );

  /**
   * Implements TMGMTTranslatorUIControllerInterface::reviewForm().
   */
  public function reviewForm($form, &$form_state, TMGMTJobItem $job_item) {
    /* @var TMGMTOhtPluginController $controller */
    $controller = $job_item->getTranslatorController();
    $connector = $controller->getConnector($job_item->getTranslator());
    $mappings = $job_item->getRemoteMappings();
    /* @var TMGMTRemote $mapping */
    $mapping = array_shift($mappings);

    $comments = $connector->getProjectComments($mapping->remote_identifier_1);
    $rows = array();
    $new_comment_link = '';

    if (is_array($comments) && count($comments) > 0) {
      foreach ($comments as $comment) {
        $rows[] = array(
          array(
            'data' => t('By %name (%role) at %time', array(
              '%name' => $comment['commenter_name'],
              '%role' => $comment['commenter_role'],
              '%time' => format_date(strtotime($comment['date']))
            )),
            'class' => 'meta',
          ),
          check_plain($comment['comment_content']),
        );
      }

      $new_comment_link = '<a href="#new-comment">' . t('Add new comment') . '</a>';
    }

    $form['#attached']['css'][] = drupal_get_path('module', 'tmgmt_oht') . '/css/tmgmt_oht_comments.css';
    $form['#attached']['js'][] = drupal_get_path('module', 'tmgmt_oht') . '/js/tmgmt_oht_comments.js';

    $form['oht_comments'] = array(
      '#type' => 'fieldset',
      '#title' => t('OHT Comments'),
      '#collapsible' => TRUE,
    );
    $form['oht_comments']['container'] = array(
      '#prefix' => '<div id="tmgmt-oht-comments-wrapper">',
      '#suffix' => '</div>',
    );
    $form['oht_comments']['container']['comments'] = array(
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => array(),
      '#empty' => t('No comments'),
      '#prefix' => $new_comment_link,
    );
    $form['oht_comments']['container']['comment'] = array(
      '#type' => 'textarea',
      '#title' => t('Comment text'),
      '#prefix' => '<a name="new-comment"></a>'
    );
    $form['oht_comments']['container']['comment_submitted'] = array(
      '#type' => 'hidden',
      '#value' => isset($form_state['comment_submitted']) ? $form_state['comment_submitted'] : 0,
    );
    $form['oht_comments']['add_comment'] = array(
      '#type' => 'submit',
      '#value' => t('Add new comment'),
      '#submit' => array('tmgmt_oht_add_comment_form_submit'),
      '#ajax' => array(
        'callback' => 'tmgmt_oht_review_form_ajax',
        'wrapper' => 'tmgmt-oht-comments-wrapper',
      ),
    );

    return $form;
  }

  /**
   * Overrides TMGMTDefaultTranslatorUIController::pluginSettingsForm().
   */
  public function pluginSettingsForm($form, &$form_state, TMGMTTranslator $translator, $busy = FALSE) {
    $form['api_public_key'] = array(
      '#type' => 'textfield',
      '#title' => t('OHT API Public Key'),
      '#default_value' => $translator->getSetting('api_public_key'),
      '#description' => t('Please enter your public API key for OneHourTranslation service.'),
    );
    $form['api_secret_key'] = array(
      '#type' => 'textfield',
      '#title' => t('OHT API Secret key'),
      '#default_value' => $translator->getSetting('api_secret_key'),
      '#description' => t('Please enter your secret API key for OneHourTranslation service.'),
    );
    $form['use_sandbox'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use the sandbox'),
      '#default_value' => $translator->getSetting('use_sandbox'),
      '#description' => t('Check to use the testing environment.'),
    );
    return parent::pluginSettingsForm($form, $form_state, $translator, $busy);
  }

  /**
   * Overrides TMGMTDefaultTranslatorUIController::checkoutSettingsForm().
   */
  public function checkoutSettingsForm($form, &$form_state, TMGMTJob $job) {
    $settings['expertise'] = array(
      '#type' => 'select',
      '#title' => t('Expertise'),
      '#description' => t('Select an expertise to identify the area of the text you will request to translate.'),
      '#empty_option' => ' - ',
      '#options' => $this->expertiseCodes,
      '#default_value' => isset($job->settings['expertise']) ? $job->settings['expertise'] : '',
    );
    $settings['notes'] = array(
      '#type' => 'textarea',
      '#title' => t('Instructions'),
      '#description' => t('You can provide a set of instructions so that the translator will better understand your requirements.'),
      '#default_value' => isset($job->settings['notes']) ? $job->settings['notes'] : '',
    );

    return $settings;
  }
}
