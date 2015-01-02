<?php
/**
 * User: mike.darke
 * Date: 10/05/13
 * Time: 14:29
 * Description:
 */

include_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'media_wistia') . '/includes/WistiaApi.php';

class DrupalWistiaApi extends WistiaApi {

  protected function __send($url)
  {

    $username = 'api';

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_USERPWD, $username .':'.$this->apiKey);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);

    $proxy_server = variable_get('proxy_server', '');
    if ($proxy_server) {
      $proxy = variable_get('proxy_server', '') . ':' . variable_get('proxy_port', 8080);
      curl_setopt($ch, CURLOPT_PROXY, $proxy);
    } else {
      curl_setopt($ch, CURLOPT_PROXY, null);
    }

    $result = curl_exec($ch);
    $err = curl_errno ( $ch );
    $errmsg = curl_error ( $ch );
    curl_close($ch);
    $this->response = $result;
    return $result;
  }

}