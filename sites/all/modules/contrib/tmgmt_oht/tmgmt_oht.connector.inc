<?php
/**
 * @file
 * Connector to OHT Service.
 */

/**
 * OHT connector class.
 */
class OHTConnector {

  private $sandbox;
  private $publicKey;
  private $secretKey;

  private $responseCode;
  private $responseStatus;

  const SANDBOX_URL = 'https://sandbox.onehourtranslation.com/api/2/';
  const PRODUCTION_URL = 'https://api.onehourtranslation.com/api/2/';

  public $debug;

  /**
   * @param string $public_key
   *   OHT public key.
   * @param $secret_key
   *   OHT secret key.
   * @param bool $sandbox
   *   Flag to determine if to connect to sandbox.
   */
  function __construct($public_key, $secret_key, $sandbox = FALSE) {
    $this->publicKey = $public_key;
    $this->secretKey = $secret_key;
    $this->sandbox = $sandbox;

    $this->debug = variable_get('tmgmt_oht_debug', FALSE);
  }

  /**
   * Creates a text resource at OHT.
   *
   * @param string $text
   *   Text to be translated.
   *
   * @return array
   *   OHT uuid of the resource.
   */
  public function uploadTextResource($text) {
    $params['text'] = $text;
    return $this->getRequest('resources/text', 'POST', $params);
  }

  /**
   * Downloads resource.
   *
   * @param string $oht_uuid
   *
   * @return array
   *   Resource xml.
   */
  public function getResourceDownload($oht_uuid, $project_id = NULL) {
    return $this->getRequest('resources/' . $oht_uuid . '/download', 'GET', ($project_id) ? array('project_id' => $project_id) : array(), TRUE);
  }

  /**
   * Creates new translation project at OHT.
   *
   * @param int $tjiid
   *   Translation job item id.
   * @param string $source_language
   *   Source language.
   * @param string $target_language
   *   Target language.
   * @param string $oht_uuid
   *   OHT uuid.
   * @param string $notes
   *   Notes to be sent with the job.
   * @param string $expertise
   *   Expertise code.
   * @param array $params
   *   Additional params.
   *
   * @return array
   *   OHT project data.
   */
  public function newTranslationProject($tjiid, $source_language, $target_language, $oht_uuid, $notes = '', $expertise = '', $params = array()) {
    $params['source_language'] = $source_language;
    $params['target_language'] = $target_language;
    $params['sources'] = $oht_uuid;
    $params['notes'] = $notes;
    $params['callback_url'] = url('tmgmt_oht_callback', array('absolute' => TRUE));
    $params['custom0'] = $tjiid;
    $params['custom1'] = tmgmt_oht_hash($tjiid);

    if (!empty($expertise)) {
      $params['expertise'] = $expertise;
    }

    return $this->getRequest('projects/translation', 'POST', $params);
  }

  /**
   * Gets OHT project data.
   *
   * @param int $project_id
   *   OHT project id.
   *
   * @return array
   *   Project info.
   */
  public function getProjectDetails($project_id) {
    return $this->getRequest('project/' . $project_id, 'GET');
  }

  /**
   * Create new comment to project.
   *
   * @param int $project_id
   * @param string $content (optional)
   *
   * @return array
   *   Response.
   */
  public function addProjectComment($project_id, $content = '') {
    $params['content'] = $content;
    return $this->getRequest('projects/' . $project_id . '/comments', 'POST', $params);
  }

  /**
   * Fetch comments by project id
   *
   * @param integer $project_id
   *
   * @return array
   *   Project comments.
   */
  public function getProjectComments($project_id) {
    return $this->getRequest('projects/' . $project_id . '/comments', 'GET');
  }

  /**
   * Gets wordcount.
   *
   * @param string $oht_uuid
   *   OHT resource uuid.
   *
   * @return array
   *   Wordcount info.
   */
  public function getWordcount($oht_uuid) {
    $params['resources'] = $oht_uuid;
    return $this->getRequest('tools/wordcount', 'GET', $params);
  }

  /**
   * Gets quotation.
   *
   * @param string $oht_uuid
   *   OHT resource uuid.
   * @param string $currency
   *   Currency code.
   * @param string $proofreading
   *   If to provide proofreading.
   * @param string $expertise
   *   Expertise code.
   *
   * @return array
   *   Quotation info
   */
  public function getQuotations($oht_uuid, $currency = '', $proofreading = '', $expertise = '') {
    $params['resources'] = $oht_uuid;
    $params['currency'] = $currency;
    $params['proofreading'] = $proofreading;
    $params['expertise'] = $expertise;

    return $this->getRequest('tools/quote', 'GET', $params);
  }

  /**
   * Processes request to OHT service.
   *
   * @param string $path
   *   Path to request.
   * @param string $method
   *   Method to use.
   * @param array $query
   *   Additional data sent with request.
   * @param bool $download
   *   If we expect resource to be downloaded.
   *
   * @return mixed
   *
   * @throws TMGMTOHTException
   */
  protected function getRequest($path, $method = 'GET', $query = array(), $download = FALSE) {
    $options = array();

    if ($this->sandbox) {
      $url = self::SANDBOX_URL . $path;
    }
    else {
      $url = self::PRODUCTION_URL . $path;
    }

    $query['public_key'] = $this->publicKey;
    $query['secret_key'] = $this->secretKey;

    // If we will send GET request - add params to the URL.
    if ($method == 'GET') {
      $url = url($url, array('query' => $query));
    }
    // Otherwise - configure $options array.
    elseif ($method == 'POST') {
      $options += array(
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
        'method' => 'POST',
        'data' => drupal_http_build_query($query),
      );
    }

    $response = drupal_http_request($url, $options);

    if ($this->debug) {
      watchdog('tmgmt oht debug', "Received response at @url <pre>@params\n\n@response</pre>",
        array('@url' => $url, '@params' => var_export($query, TRUE), '@response' => var_export($response, TRUE)));
    }

    $this->responseCode = $response->code;

    if ($response->code != 200) {
      throw new TMGMTOHTException('Unable to connect to the OHT service due to following error: @error at @url',
        array('@error' => $response->error, '@url' => $url));
    }

    // If we are expecting a download, just return received data.
    if ($download) {
      return $response->data;
    }

    $response = drupal_json_decode($response->data);

    $this->responseStatus = $response['status'];

    if ($response['status']['code'] != 0) {
      throw new TMGMTOHTException('OHT service returned validation error: #%code %error',
        array('%code' => $response['status']['code'], '%error' => $response['status']['msg']));
    }

    if (!empty($response['errors'])) {
      watchdog('tmgmt_oht', 'OHT error: @error', array('@error' => implode('; ', $response['errors'])));
      throw new TMGMTOHTException('OHT service returned following error: %error',
        array('%error' => $response['status']['msg']));
    }

    return $response['results'];
  }
}
