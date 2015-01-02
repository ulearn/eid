<?php
/**
 * @file
 * ulearn_locale.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function ulearn_locale_locale_default_languages() {
  $languages = array();

  // Exported language: es.
  $languages['es'] = array(
    'language' => 'es',
    'name' => 'Spanish',
    'native' => 'Español',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'es',
    'weight' => 1,
  );
  // Exported language: it.
  $languages['it'] = array(
    'language' => 'it',
    'name' => 'Italian',
    'native' => 'Italiano',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'it',
    'weight' => 2,
  );
  // Exported language: ja.
  $languages['ja'] = array(
    'language' => 'ja',
    'name' => 'Japanese',
    'native' => '日本語',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'ja',
    'weight' => 5,
  );
  // Exported language: ko.
  $languages['ko'] = array(
    'language' => 'ko',
    'name' => 'Korean',
    'native' => '한국어',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'ko',
    'weight' => 4,
  );
  // Exported language: pt.
  $languages['pt'] = array(
    'language' => 'pt',
    'name' => 'Portuguese',
    'native' => 'Portugués',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'pt',
    'weight' => 3,
  );
  return $languages;
}
