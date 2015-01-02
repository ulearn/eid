<?php

/**
 * @file
 * Provides OneHourTranslation translation plugin controller.
 */

/**
 * OHT translation plugin controller.
 */
class TMGMTOhtPluginController extends TMGMTDefaultTranslatorPluginController {

  protected $ohtLanguagesMapping = array(
    'sq' => 'sq-al',
    'ar' => 'ar-sa',
    'bn' => 'bn-bd',
    'bs' => 'bs-ba',
    'bg' => 'bg-bg',
    'ca' => 'ca-es',
    // '' => 'zh-cn-yue',
    'zn-hans' => 'zh-cn-cmn-s',
    'zn-hant' => 'zh-cn-cmn-t',
    'hr' => 'hr-hr',
    'cs' => 'cs-cz',
    'da' => 'da-dk',
    'fa' => 'fa-af',
    'nl' => 'nl-nl',
    'en-gb' => 'en-uk',
    'en' => 'en-us',
    'et' => 'et-ee',
    // '' => 'fa-ir',
    'fi' => 'fi-fi',
    'fr' => 'fr-fr',
    // '' => 'fr-ca',
    'ka' => 'ka-ge',
    'de' => 'de-de',
    'el' => 'el-gr',
    'he' => 'he-il',
    'hi' => 'hi-in',
    'hu' => 'hu-hu',
    'id' => 'id-id',
    'it' => 'it-it',
    'jp' => 'jp-jp',
    'kk' => 'kk-kz',
    // '' => 'km-kh',
    'ko' => 'ko-kp',
    'lo' => 'lo-la',
    'lv' => 'lv-lv',
    'lt' => 'lt-lt',
    'mk' => 'mk-mk',
    'ms' => 'ms-my',
    'nb' => 'no-no',
    'ps' => 'ps',
    'pl' => 'pl-pl',
    'pt-br' => 'pt-br',
    'pt-pt' => 'pt-pt',
    'ro' => 'ro-ro',
    'ru' => 'ru-ru',
    'sr' => 'sr-rs',
    'sk' => 'sk-sk',
    'sl' => 'sl-si',
    'es' => 'es-es',
    // '' => 'es-ar',
    'sv' => 'sv-se',
    'tl' => 'tl-ph',
    'ta' => 'ta-in',
    'th' => 'th-th',
    'tr' => 'tr-tr',
    'uk' => 'uk-ua',
    'ur' => 'ur',
    'uz' => 'uz-uz',
    'vi' => 'vi-vn',
  );

  /**
   * Implements TMGMTTranslatorPluginControllerInterface::getDefaultRemoteLanguagesMappings().
   */
  public function getDefaultRemoteLanguagesMappings() {
    return $this->ohtLanguagesMapping;
  }

  /**
   * Implements TMGMTTranslatorPluginControllerInterface::getSupportedLanguages().
   */
  public function getSupportedRemoteLanguages(TMGMTTranslator $translator) {
    return array_values($this->ohtLanguagesMapping);
  }

  /**
   * Implements TMGMTTranslatorPluginControllerInterface::isAvailable().
   */
  public function isAvailable(TMGMTTranslator $translator) {
    if ($translator->getSetting('api_public_key') && $translator->getSetting('api_secret_key')) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Implements TMGMTTranslatorPluginControllerInterface::canTranslation().
   *
   * We will check are source and target language supported.
   */
  public function canTranslate(TMGMTTranslator $translator, TMGMTJob $job) {
    // If we use sandbox we can translate anyway.
    if ($translator->getSetting('use_sandbox')) {
      return TRUE;
    }
    // If Translator is configured - check if the source and
    // target language are supported.
    if ($this->isAvailable($translator)) {
        $targets = $this->getSupportedRemoteLanguages($translator);
        return in_array($this->mapToRemoteLanguage($translator, $job->source_language), $targets) &&
            in_array($this->mapToRemoteLanguage($translator, $job->target_language), $targets);
    }
    return FALSE;
  }

  /**
   * Implements TMGMTTranslatorPluginControllerInterface::requestTranslation().
   *
   * Here we will acutally query source and get translations.
   */
  public function requestTranslation(TMGMTJob $job) {

    $translator = $job->getTranslator();

    /**
     * @var TMGMTJobItem $job_item
     */
    $job_item = NULL;
    $oht_uuid = NULL;

    try {

      foreach ($job->getItems() as $job_item) {
        $oht_uuid = $this->getConnector($translator)->uploadTextResource($this->prepareDataForSending($job_item));
        $oht_uuid = array_shift($oht_uuid);

        $result = $this->getConnector($translator)->newTranslationProject(
          $job_item->tjiid,
          $this->mapToRemoteLanguage($translator, $job->source_language),
          $this->mapToRemoteLanguage($translator, $job->target_language),
          $oht_uuid,
          $job->settings['notes'],
          $job->settings['expertise']
        );

        $job_item->addRemoteMapping(NULL, $result['project_id'], array(
          'remote_identifier_2' => $oht_uuid,
          'word_count' => $result['wordcount'],
          'remote_data' => array(
            'credits' => $result['credits'],
          ),
        ));

        $job_item->addMessage('OHT Project ID %project_id created. @credits credits reduced from your account.',
          array('%project_id' => $result['project_id'], '@credits' => $result['credits']));
      }

      $job->submitted('Job has been successfully submitted for translation.');
    }
    catch (TMGMTOHTException $e) {
      $job->rejected($e->getMessage());
    }
  }

  /**
   * Receives and stores a translation returned by OHT.
   */
  public function retrieveTranslation(array $resource_uuids, TMGMTJobItem $job_item, $oht_project_id = NULL) {
    try {
      foreach ($resource_uuids as $resource_uuid) {
        $resource = $this->getConnector($job_item->getTranslator())->getResourceDownload($resource_uuid, $oht_project_id);
        // On sandbox we get some non existing resource_uuids which do not
        // really exist and return some forbidden error in json format. So we
        // filter these out.
        if (strpos($resource, '<?xml') !== FALSE) {
          $data = $this->parseTranslationData($resource);
          $job_item->addTranslatedData($data);

          if ($job_item->isState(TMGMT_JOB_ITEM_STATE_ACTIVE)) {
            $job_item->addMessage('The translation has been received.');
          }
          else {
            $job_item->addMessage('The translation has been updated.');
          }
        }
        // @todo we should log errors here for the failing resources.
      }
    }
    catch (TMGMTOHTException $e) {
      $job_item->addMessage('Could not get translation from OHT. Message error: @error',
        array('@error' => $e->getMessage()), 'error');
    }
  }

  /**
   * Prepares data to be send to OHT service and returns XML string.
   *
   * @param TMGMTJobItem $job_item
   *   Job object.
   *
   * @return string
   *   Data for sending to the translator service.
   */
  protected function prepareDataForSending(TMGMTJobItem $job_item) {
    $data = array_filter(tmgmt_flatten_data($job_item->getData()), '_tmgmt_filter_data');
    $items = '';
    foreach ($data as $key => $value) {
      $items .= str_replace(array('@key', '@text'), array($key, $value['#text']), '<item key="@key"><text type="text/html"><![CDATA[@text]]></text></item>');
    }

    return '<?xml version="1.0" encoding="UTF-8" ?>
    <items>' . $items . '</items>';
  }

  /**
   * Parses received translation from OHT and returns unflatted data.
   *
   * @param string $data
   *   Base64 encode data, received from OHT.
   *
   * @return array
   *   Unflatted data.
   */
  protected function parseTranslationData($data) {
    $items = simplexml_load_string($data);
    $data = array();
    foreach ($items->item as $item) {
      $key = (string) $item['key'];
      $data[$key]['#text'] = (string) $item->text;
    }

    return tmgmt_unflatten_data($data);
  }

  /**
   * Gets OHT service connector.
   *
   * @param TMGMTTranslator $translator
   *   Current job translator.
   *
   * @return OHTConnector
   *   OHT connector instance.
   */
  public function getConnector(TMGMTTranslator $translator) {
    return new OHTConnector(
      $translator->getSetting('api_public_key'),
      $translator->getSetting('api_secret_key'),
      $translator->getSetting('use_sandbox')
    );
  }
}
