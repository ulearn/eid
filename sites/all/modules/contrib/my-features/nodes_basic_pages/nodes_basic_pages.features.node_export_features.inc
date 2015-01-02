<?php
/**
 * @file
 * nodes_basic_pages.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function nodes_basic_pages_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'298\',
      \'uid\' => \'1\',
      \'title\' => \'Ciaran Mc Mahon\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'a38597fc-6ce0-4a0b-bc4d-7a11bc6072cc\',
      \'nid\' => \'2437\',
      \'type\' => \'page\',
      \'language\' => \'es\',
      \'created\' => \'1400206275\',
      \'changed\' => \'1400214236\',
      \'tnid\' => \'2437\',
      \'translate\' => \'0\',
      \'uuid\' => \'d43eee06-5542-4b4a-98ae-9bb3f7f1542c\',
      \'revision_timestamp\' => \'1400214236\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<div class=\\"team-member four columns\\">\\r\\n<div class=\\"team-entry\\">\\r\\n\\r\\n<div class=\\"team-member\\">\\r\\n   <img src=\\"http://stage.ulearnschool.com/sites/default/files/images/team/ciaran-mc.jpg\\" />  <!-- Image of Team Member -->\\r\\n   <h5>Ciaran Mc Mahon</h5><span>Director</span>   <!-- Name Team Member --> <!-- Designation Team Member -->\\r\\n  </div>\\r\\n\\r\\n<p>Ciaran es uno de los y directores de ULearn. Experto en comunicaciones, se graduó como Master en Comunicación Pública en 2005. Desempeñó diversas funciones relativas a las comunicaciones en el Senado Irlandés, así como en el sector privado. Ciaran posee además un Master en Historia y Política.  A Ciaran le apasionan todos los deportes.</p>\\r\\n\\r\\n<ul class=\\"social-icons\\">\\r\\n\\t<li class=\\"twitter\\"><a href=\\"https://twitter.com/ulearn\\">Twitter</a></li>\\r\\n\\t<li class=\\"facebook\\"><a href=\\"https://www.facebook.com/ULearnDublinEnglishSchool\\">Facebook</a></li>\\r\\n         <li class=\\"linkedin\\"><a href=\\"http://www.linkedin.com/profile/view?id=230588788&trk=nav_responsive_tab_profile_pic\\">Linkdin</a></li>\\r\\n        <li class=\\"gplus\\"><a href=\\"https://plus.google.com/u/2/b/112298331569691583207/112298331569691583207/posts\\">Google+</a></li>\\r\\n\\t<li class=\\"rss\\"><a href=\\"http://www.ulearn.ie/blog\\">Rss</a></li>\\r\\n</ul>\\r\\n<!--/ .social-icons--></div>\\r\\n<!--/ .team-entry--></div>\\r\\n<!--/ .team-member-->",
            \'summary\' => \'\',
            \'format\' => \'php_code\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'field_order\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2\',
          ),
        ),
      ),
      \'field_tags\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'48\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400206275\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'print_display\' => 1,
      \'print_display_comment\' => 0,
      \'print_display_urllist\' => 1,
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'a:3:{s:18:"contact_entityform";i:0;s:18:"htmlmail_plaintext";i:0;s:7:"contact";i:0;}\',
      \'print_pdf_display\' => 1,
      \'print_pdf_display_comment\' => 0,
      \'print_pdf_display_urllist\' => 1,
      \'path\' => array(
        \'pid\' => \'489\',
        \'source\' => \'node/2437\',
        \'alias\' => \'ciaran-mc-mahon\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
