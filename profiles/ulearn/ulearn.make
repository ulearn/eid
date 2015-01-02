; This file describes the core project requirements for Ulearn 7.x. Several
; patches against Drupal core and their associated issue numbers have been
; included here for reference.
;
;
;     $ drush make ulearn.make [directory]

core = 7.x
api = 2

projects[drupal][type] = core
projects[drupal][version] = 7.25
projects[drupal][download][type] = get
projects[drupal][download][url] = http://ftp.drupal.org/files/projects/drupal-7.25.tar.gz


; BASE COMPONENTS ------------------------------------------------------------

projects[addressfield][version] = 1.0-beta5
projects[addressfield][subdir] = contrib



; COMMERCE -------------------------------------------------------------------

;--------------------------------- WYSIWYG ---------------------------------- ;


; DEVELOPMENT ----------------------------------------------------------------

projects[devel][subdir] = contrib
projects[devel][version] = 1.3

projects[diff][subdir] = contrib
projects[diff][version] = 3.2



; LIBRARIES ------------------------------------------------------------------

projects[backbone_lib][type] = library
projects[backbone_lib][download][type] = get
projects[backbone_lib][download][url] = https://github.com/documentcloud/backbone/archive/1.0.0.zip
projects[backbone_lib][directory_name] = backbone

projects[imgareaselect_lib][type] = library
projects[imgareaselect_lib][download][type] = get
projects[imgareaselect_lib][download][url] = http://odyniec.net/projects/imgareaselect/jquery.imgareaselect-0.9.10.zip
projects[imgareaselect_lib][directory_name] = jquery.imgareaselect

projects[imagesloaded_lib][type] = library
projects[imagesloaded_lib][download][type] = file
projects[imagesloaded_lib][download][url] = http://desandro.github.io/imagesloaded/imagesloaded.pkgd.min.js
projects[imagesloaded_lib][download][filename] = jquery.imagesloaded.min.js
projects[imagesloaded_lib][directory_name] = jquery.imagesloaded

projects[underscore_lib][type] = library
projects[underscore_lib][download][type] = get
projects[underscore_lib][download][url] = https://github.com/documentcloud/underscore/archive/1.4.4.zip
projects[underscore_lib][directory_name] = underscore

projects[jsmin_lib][type] = library
projects[jsmin_lib][download][type] = git
projects[jsmin_lib][download][url] = git://github.com/rgrove/jsmin-php.git
projects[jsmin_lib][download][branch] = master

projects[headjs_lib][type] = library
projects[headjs_lib][download][type] = get
projects[headjs_lib][download][url] = https://github.com/headjs/headjs/raw/v0.96/dist/head.load.min.js
projects[headjs_lib][directory_name] = headjs/head.min.js

; projects[labjs_lib][type] = library
; projects[labjs_lib][download][type] = get
; projects[labjs_lib][download][url] = http://labjs.com/releases/LABjs-2.0.3.tar.gz
; projects[labjs_lib][directory_name] = labjs

projects[labjs_lib][type] = library
projects[labjs_lib][download][type] = git
projects[labjs_lib][download][url] = git://github.com/getify/LABjs.git
projects[labjs_lib][download][branch] = master
projects[labjs_lib][directory_name] = labjs

projects[colorbox_lib][type] = library
projects[colorbox_lib][download][type] = get
projects[colorbox_lib][download][url] = https://github.com/jackmoore/colorbox/archive/1.4.15.zip
projects[colorbox_lib][directory_name] = colorbox

projects[cycle_lib][type] = library
projects[cycle_lib][download][type] = get
projects[cycle_lib][download][url] = https://raw.github.com/malsup/cycle/master/jquery.cycle.all.js
projects[cycle_lib][directory_name] = jquery.cycle

projects[fitvids_lib][type] = library
projects[fitvids_lib][download][type] = get
projects[fitvids_lib][download][url] = https://raw.github.com/davatron5000/FitVids.js/master/jquery.fitvids.js
projects[fitvids_lib][directory_name] = fitvids

projects[markitup_lib][type] = library
projects[markitup_lib][download][type] = get
projects[markitup_lib][download][url] = https://github.com/markitup/1.x/tarball/master
projects[markitup_lib][directory_name] = markitup
projects[markitup_lib][patch][1715642] = http://drupal.org/files/1715642-adding-html-set-markitup-editor.patch

projects[PIE_lib][type] = library
projects[PIE_lib][download][type] = get
projects[PIE_lib][download][url] = http://css3pie.com/download-latest
projects[PIE_lib][directory_name] = PIE

projects[plupload_lib][type] = library
projects[plupload_lib][download][type] = get
projects[plupload_lib][download][url] = http://plupload.com/downloads/plupload_1_5_6.zip
projects[plupload_lib][directory_name] = plupload
projects[plupload_lib][patch][] = http://drupal.org/files/plupload-1_5_6-rm_examples-1903850-5.patch

projects[querypath_lib][type] = library
projects[querypath_lib][download][type] = get
projects[querypath_lib][download][url] = https://github.com/downloads/technosophos/querypath/QueryPath-2.1-minimal.tgz
projects[querypath_lib][directory_name] = querypath

projects[superfish_lib][type] = library
projects[superfish_lib][download][type] = get
projects[superfish_lib][download][url] = https://github.com/mehrpadin/Superfish-for-Drupal/archive/1.x.zip
projects[superfish_lib][directory_name] = superfish

projects[tinymce_lib][type] = library
projects[tinymce_lib][download][type] = get
projects[tinymce_lib][download][url] = http://github.com/downloads/tinymce/tinymce/tinymce_3.5.8.zip
projects[tinymce_lib][directory_name] = tinymce
projects[tinymce_lib][patch][1561882] = http://drupal.org/files/1561882-cirkuit-theme-tinymce-3.5.8.patch

projects[twitter_api_php_lib][type] = library
projects[twitter_api_php_lib][download][type] = get
projects[twitter_api_php_lib][download][url] = https://github.com/J7mbo/twitter-api-php/archive/master.zip
projects[twitter_api_php_lib][directory_name] = twitter-api-php

projects[glip_lib][type] = library
projects[glip_lib][download][type] = get
projects[glip_lib][download][url] = https://github.com/halstead/glip/archive/1.1.zip
projects[glip_lib][directory_name] = glip

projects[spyc_lib][type] = library
projects[spyc_lib][download][type] = get
projects[spyc_lib][download][url] = https://raw.github.com/mustangostang/spyc/master/Spyc.php
projects[spyc_lib][filename] = ../spyc.php
projects[spyc_lib][directory_name] = lib
projects[spyc_lib][destination] = modules/contrib/services/servers/rest_server

projects[openlayers_lib][type] = library
projects[openlayers_lib][download][type] = get
projects[openlayers_lib][download][url] = http://openlayers.org/api/2.12/OpenLayers.js
projects[openlayers_lib][directory_name] = OpenLayers

projects[youtubechannel][subdir] = contrib
projects[youtubechannel][version] = 2.0
projects[youtubechannel][patch][] = http://drupal.org/files/2032839-youtubechannel-access.patch
projects[youtubechannel][patch][] = http://drupal.org/files/2032853-youtubechannel-variable.patch

projects[iCalcreator_lib][type] = library
projects[iCalcreator_lib][download][type] = git
projects[iCalcreator_lib][download][url] = https://github.com/iCalcreator/iCalcreator.git
projects[iCalcreator_lib][directory_name] = iCalcreator

projects[kissmetrics_lib][type] = library
projects[kissmetrics_lib][download][type] = git
projects[kissmetrics_lib][download][url] = https://github.com/kissmetrics/KISSmetrics.git
projects[kissmetrics_lib][directory_name] = kissmetrics

; TESTING - THESE MODULES NEED REVIEW
; WE MAY NOT END UP USING THEM

projects[core_library][version] = 2.0-beta1
projects[core_library][subdir] = contrib

projects[agrcache][version] = 1.0
projects[agrcache][subdir] = contrib

projects[http_client][version] = 2.4
projects[http_client][subdir] = contrib


; ----------
; WEBFORM ALTERNATE UI - versions based on a Drupal Gardens export.
; @see https://drupal.org/node/1033462 for reasoning.

; projects[form_builder][subdir] = contrib
; projects[form_builder][version] = 0.9
; projects[form_builder][patch][] = http://drupal.org/files/1033462-webform_alt_ui-form_builder-drupal-gardens.patch

; projects[options_element][subdir] = contrib
; projects[options_element][download][type] = git
; projects[options_element][download][url] = http://git.drupal.org/project/options_element.git
; projects[options_element][download][branch] = 7.x-1.x
; projects[options_element][download][tag] = 7.x-1.4
; projects[options_element][patch][] = http://drupal.org/files/1033462-webform_alt_ui-options_element-drupal-gardens.patch

; projects[webform_alt_ui][subdir] = contrib
; projects[webform_alt_ui][version] = 1.0-alpha4
; projects[webform_alt_ui][patch][] = http://drupal.org/files/1033462-webform_alt_ui-webform_alt_ui-drupal-gardens.patch

; projects[ux_elements][version] = 1.0-beta1
; projects[ux_elements][subdir] = contrib
; projects[ux_elements][patch][] = http://drupal.org/files/issues/1224568-ux_elements_redeclare.patch

; ----------

projects[form_builder][subdir] = contrib
projects[form_builder][download][type] = git
projects[form_builder][download][url] = http://git.drupal.org/project/form_builder.git
projects[form_builder][download][branch] = 7.x-1.x
projects[form_builder][download][revision] = 61e7da4b969c72b91c295f6d134305c4ff23831f
projects[form_builder][patch][] = http://drupal.org/files/2032489-form_builder-sanitize-list.patch

projects[options_element][subdir] = contrib
projects[options_element][version] = 1.9

projects[conditional_fields][subdir] = contrib
projects[conditional_fields][download][type] = git
projects[conditional_fields][download][url] = http://git.drupal.org/project/conditional_fields.git
projects[conditional_fields][download][branch] = 7.x-3.x
projects[conditional_fields][download][revision] = cd29b003a592d375f3fdb4c46f5639d0f26ed0be

projects[geocoder][subdir] = contrib
projects[geocoder][version] = 1.2

projects[geofield][subdir] = contrib
projects[geofield][download][type] = git
projects[geofield][download][url] = http://git.drupal.org/project/geofield.git
projects[geofield][download][branch] = 7.x-2.x
projects[geofield][download][revision] = 27de4c92bb84e1a977ee5c2b131fb47218008dc9

projects[geonames][subdir] = contrib
projects[geonames][download][type] = git
projects[geonames][download][url] = http://git.drupal.org/project/geonames.git
projects[geonames][download][branch] = 7.x-1.x
projects[geonames][download][revision] = f93c989428e7b1f86b54765e0dbe4b6be121fe3d

projects[geophp][subdir] = contrib
projects[geophp][version] = 1.7

projects[sliderfield][subdir] = contrib
projects[sliderfield][download][type] = git
projects[sliderfield][download][url] = http://git.drupal.org/project/sliderfield.git
projects[sliderfield][download][branch] = 7.x-1.x

projects[tinymce_extended][subdir] = contrib
projects[tinymce_extended][type] = module
projects[tinymce_extended][download][type] = git
projects[tinymce_extended][download][url] = http://git.drupal.org/sandbox/ldweeks/1141230.git
projects[tinymce_extended][download][branch] = master

projects[ie6update][subdir] = contrib
projects[ie6update][type] = module
projects[ie6update][download][type] = git
projects[ie6update][download][url] = http://git.drupal.org/project/ie6update.git
projects[ie6update][download][branch] = 7.x-1.x

projects[readmore][subdir] = contrib
projects[readmore][version] = 1.0-alpha1
projects[readmore][patch][] = http://drupal.org/files/add_read_more_if_is_need.patch

projects[tac_lite][subdir] = contrib
projects[tac_lite][version] = 1.0-rc2
projects[tac_lite][patch][] = http://drupal.org/files/id_to_machine_name_d7-1446926.patch

projects[content_access][subdir] = contrib
projects[content_access][type] = module
projects[content_access][download][type] = git
projects[content_access][download][url] = http://git.drupal.org/project/content_access.git
projects[content_access][download][branch] = 7.x-1.x
projects[content_access][download][revision] = d57beda87f6c80d521fad961a8f7cd1b552319bd

projects[sitecatalyst][subdir] = contrib
projects[sitecatalyst][type] = module
projects[sitecatalyst][download][type] = git
projects[sitecatalyst][download][url] = http://git.drupal.org/project/sitecatalyst.git
projects[sitecatalyst][download][branch] = 7.x-1.x
projects[sitecatalyst][download][revision] = b2b855fb7b27a65546753d5ed95896bb9a983e9a

projects[geocoder_autocomplete][subdir] = contrib
projects[geocoder_autocomplete][type] = module
projects[geocoder_autocomplete][download][type] = git
projects[geocoder_autocomplete][download][url] = http://git.drupal.org/project/geocoder_autocomplete.git
projects[geocoder_autocomplete][download][branch] = 7.x-1.x
projects[geocoder_autocomplete][download][revision] = b9207f2e423a163af8a17091c3977c6e67917ef9
projects[geocoder_autocomplete][patch][] = http://drupal.org/files/1839204-6-geocoder_autocomplete-integration_geocoder_views.patch

projects[getdirections][subdir] = contrib
projects[getdirections][type] = module
projects[getdirections][download][type] = git
projects[getdirections][download][url] = http://git.drupal.org/project/getdirections.git
projects[getdirections][download][branch] = 7.x-3.x
projects[getdirections][download][revision] = 44562afd79faf2d9a2f258d74c81ea65113916e2
projects[getdirections][patch][] = http://drupal.org/files/getdirections-problem-multiple-addressfield.patch
projects[getdirections][patch][] = http://drupal.org/files/getdirections-problem-not-show-field.patch

projects[rpx][subdir] = contrib
projects[rpx][type] = module
projects[rpx][download][type] = git
projects[rpx][download][url] = http://git.drupal.org/project/rpx.git
projects[rpx][download][branch] = 7.x-2.x
projects[rpx][download][revision] = 4a516e53fbd11650c5f5468580fe8d94c1998e96
projects[rpx][patch][] = http://drupal.org/files/issues/2118437.3-rpx-problem-old-users.patch
; projects[rpx][patch][] = http://drupal.org/files/issues/rpx-field-mapping-disabled-2121027-1_0.patch
projects[rpx][patch][] = http://drupal.org/files/issues/rpx-integration_with_address_field-1240194-3_0.patch

projects[rpx_sso][subdir] = contrib
projects[rpx_sso][type] = module
projects[rpx_sso][download][type] = git
projects[rpx_sso][download][url] = http://git.drupal.org/sandbox/jacintocapote/2119445.git

; INSTALLATION PROFILES ------------------------------------------------------

projects[sac_members][type] = profile
projects[sac_members][download][type] = git
projects[sac_members][download][url] = git@github.com:stoneacre/sac_profile_members.git
projects[sac_members][download][branch] = 7.x-3.x

