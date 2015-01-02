<?php
/**
 * @file
 * new_nodes.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function new_nodes_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'221\',
      \'uid\' => \'1\',
      \'title\' => \'Cursos en ULearn\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'f480060d-2217-4333-a180-6d627c582e0f\',
      \'nid\' => \'2360\',
      \'type\' => \'ajax_navigation\',
      \'language\' => \'es\',
      \'created\' => \'1400017628\',
      \'changed\' => \'1400730388\',
      \'tnid\' => \'2360\',
      \'translate\' => \'0\',
      \'uuid\' => \'2cddcbed-fc04-4808-a887-4a5a7e088dd9\',
      \'revision_timestamp\' => \'1400730388\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h4 class=\\"content-title\\">Cursos en ULearn</h4>\\r\\n\\r\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/stock-students-lying.jpg\\" />\\r\\n\\r\\n\\r\\n\\r\\n<p>ULearn cuenta con estudiantes de todas partes del mundo, y ofrece una amplia variedad de cursos de inglés que cubren las necesidades del alumno en todos los niveles; comenzando desde el nivel elemental (o básico) hasta el nivel avanzado. Nuestros cursos de inglés en Dublín, Irlanda, están basados en un enfoque comunicativo. Nuestras lecciones están diseñadas para capacitar al estudiante en las 5 habilidades fundamentales, específicamente: escuchar, pronunciar, hablar, leer y escribir. Nuestros cursos de inglés son impartidos por profesores altamente capacitados y experimentados que además garantizan que cada sesión de clases se desarrolle en un ambiente alegre y dinámico. Nuestro director académico se encarga de que el ingreso y avance de cada estudiante sea debidamente controlado y evaluado de manera sistemática. Nuestros alumnos suelen progresar de forma rápida y consistente.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h4 class=\\"content-title\\">Cursos en ULearn</h4>\\n\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/stock-students-lying.jpg\\" />\\n\\n\\n\\n<p>ULearn cuenta con estudiantes de todas partes del mundo, y ofrece una amplia variedad de cursos de inglés que cubren las necesidades del alumno en todos los niveles; comenzando desde el nivel elemental (o básico) hasta el nivel avanzado. Nuestros cursos de inglés en Dublín, Irlanda, están basados en un enfoque comunicativo. Nuestras lecciones están diseñadas para capacitar al estudiante en las 5 habilidades fundamentales, específicamente: escuchar, pronunciar, hablar, leer y escribir. Nuestros cursos de inglés son impartidos por profesores altamente capacitados y experimentados que además garantizan que cada sesión de clases se desarrolle en un ambiente alegre y dinámico. Nuestro director académico se encarga de que el ingreso y avance de cada estudiante sea debidamente controlado y evaluado de manera sistemática. Nuestros alumnos suelen progresar de forma rápida y consistente.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'field_order\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017628\',
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
        \'pid\' => \'508\',
        \'source\' => \'node/2360\',
        \'alias\' => \'summary/cursos-en-ulearn\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'222\',
      \'uid\' => \'1\',
      \'title\' => \'Exámenes\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'a1657148-fd22-44cb-ba88-ff19b075a2d0\',
      \'nid\' => \'2361\',
      \'type\' => \'ajax_navigation\',
      \'language\' => \'es\',
      \'created\' => \'1400017628\',
      \'changed\' => \'1400730462\',
      \'tnid\' => \'2361\',
      \'translate\' => \'0\',
      \'uuid\' => \'556f81ff-cfbd-4109-93c8-838be47cb1a0\',
      \'revision_timestamp\' => \'1400730462\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h4 class=\\"content-title\\">Exámenes</h4>\\r\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/flickr-dee-students.jpg\\" />\\r\\n\\r\\n<p>Muchos de los estudiantes que se acercan a ULearn lo hacen con el objetivo de prepararse para un examen reconocido internacionalmente. Los cursos de preparaci&oacute;n para ex&aacute;menes m&aacute;s populares que ofrecemos son para los ex&aacute;menes de Cambridge: FCE (Primer Certificado de Ingl&eacute;s), CAE (Certificado de Ingl&eacute;s Avanzado); y IELTS (Capacitaci&oacute;n Acad&eacute;mica y General). Nuestros cursos de preparaci&oacute;n para ex&aacute;menes han sido desarrollados para que el estudiante reciba la mejor preparaci&oacute;n posible antes de someterse a dichos ex&aacute;menes. El estudiante perfecciona las habilidades claves requeridas para cada examen a la vez que se familiariza con las t&eacute;cnicas y estrategias necesarias para alcanzar los mejores resultados. ULearn proporciona asesoramiento a fin de que el estudiante pueda determinar cu&aacute;l es el tipo de examen m&aacute;s apropiado en su caso.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h4 class=\\"content-title\\">Exámenes</h4>\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/flickr-dee-students.jpg\\" />\\n\\n<p>Muchos de los estudiantes que se acercan a ULearn lo hacen con el objetivo de prepararse para un examen reconocido internacionalmente. Los cursos de preparaci&oacute;n para ex&aacute;menes m&aacute;s populares que ofrecemos son para los ex&aacute;menes de Cambridge: FCE (Primer Certificado de Ingl&eacute;s), CAE (Certificado de Ingl&eacute;s Avanzado); y IELTS (Capacitaci&oacute;n Acad&eacute;mica y General). Nuestros cursos de preparaci&oacute;n para ex&aacute;menes han sido desarrollados para que el estudiante reciba la mejor preparaci&oacute;n posible antes de someterse a dichos ex&aacute;menes. El estudiante perfecciona las habilidades claves requeridas para cada examen a la vez que se familiariza con las t&eacute;cnicas y estrategias necesarias para alcanzar los mejores resultados. ULearn proporciona asesoramiento a fin de que el estudiante pueda determinar cu&aacute;l es el tipo de examen m&aacute;s apropiado en su caso.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'field_order\' => array(
        \'und\' => array(
          array(
            \'value\' => \'4\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017628\',
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
        \'pid\' => \'509\',
        \'source\' => \'node/2361\',
        \'alias\' => \'summary/exámenes\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'223\',
      \'uid\' => \'1\',
      \'title\' => \'CAE Advanced Exam\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'6c4cbb30-89cb-4a20-8018-ae7994ecb00f\',
      \'nid\' => \'2362\',
      \'type\' => \'ajax_navigation\',
      \'language\' => \'es\',
      \'created\' => \'1400017628\',
      \'changed\' => \'1400730374\',
      \'tnid\' => \'2362\',
      \'translate\' => \'0\',
      \'uuid\' => \'5eb7f6cd-b61a-4101-b56d-7697ec56be60\',
      \'revision_timestamp\' => \'1400730374\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h4 class=\\"content-title\\">Cambridge Advanced - CAE</h4>\\r\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/flickr-steve-compu.jpg\\" />\\r\\n\\r\\n<div>\\r\\n\\tEl CAE demuestra que el estudiante posee un nivel de ingl&eacute;s avanzado y por tanto puede desenvolverse con confianza y fluidez en situaciones o tareas profesionales y acad&eacute;micas complejas.</div>\\r\\n<div>\\r\\n\\tEste certificado (CAE) se sit&uacute;a en el nivel C1 del Marco Com&uacute;n Europeo de Referencia para las Lenguas y al igual que el FCE es ideal para personas que requieren demostrar su nivel de dominio del idioma ingl&eacute;s para prop&oacute;sitos profesionales.</div>\\r\\n<div>\\r\\n\\t&nbsp;</div>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h4 class=\\"content-title\\">Cambridge Advanced - CAE</h4>\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/flickr-steve-compu.jpg\\" />\\n\\n<div>\\n\\tEl CAE demuestra que el estudiante posee un nivel de ingl&eacute;s avanzado y por tanto puede desenvolverse con confianza y fluidez en situaciones o tareas profesionales y acad&eacute;micas complejas.</div>\\n<div>\\n\\tEste certificado (CAE) se sit&uacute;a en el nivel C1 del Marco Com&uacute;n Europeo de Referencia para las Lenguas y al igual que el FCE es ideal para personas que requieren demostrar su nivel de dominio del idioma ingl&eacute;s para prop&oacute;sitos profesionales.</div>\\n<div>\\n\\t&nbsp;</div>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'field_order\' => array(
        \'und\' => array(
          array(
            \'value\' => \'7\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017628\',
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
        \'pid\' => \'510\',
        \'source\' => \'node/2362\',
        \'alias\' => \'cambridge-advanced-cae\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'224\',
      \'uid\' => \'1\',
      \'title\' => \'FCE First Certificate\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'ab8928b2-12c1-4502-9c0c-01193c5ca530\',
      \'nid\' => \'2363\',
      \'type\' => \'ajax_navigation\',
      \'language\' => \'es\',
      \'created\' => \'1400017628\',
      \'changed\' => \'1400730472\',
      \'tnid\' => \'2363\',
      \'translate\' => \'0\',
      \'uuid\' => \'6e582c75-7064-4e9d-b48e-573a0500d331\',
      \'revision_timestamp\' => \'1400730472\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h4 class=\\"content-title\\">First Certificate - FCE</h4>\\r\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/flickr-stairs.jpg\'\\" />\\r\\n\\r\\n<p>El FCE se recomienda a personas que deseen demostrar que poseen un nivel intermedio en el dominio del idioma inglés (Nivel B2 en el Marco Común Europeo de Referencia para las Lenguas). Este certificado normalmente se necesita para propósitos laborales o profesionales, aunque puede ser útil o requerido también para la obtención de visados o para propósitos académicos.&nbsp;</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h4 class=\\"content-title\\">First Certificate - FCE</h4>\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/flickr-stairs.jpg\'\\" />\\n\\n<p>El FCE se recomienda a personas que deseen demostrar que poseen un nivel intermedio en el dominio del idioma inglés (Nivel B2 en el Marco Común Europeo de Referencia para las Lenguas). Este certificado normalmente se necesita para propósitos laborales o profesionales, aunque puede ser útil o requerido también para la obtención de visados o para propósitos académicos.&nbsp;</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'field_order\' => array(
        \'und\' => array(
          array(
            \'value\' => \'6\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017628\',
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
        \'pid\' => \'511\',
        \'source\' => \'node/2363\',
        \'alias\' => \'summary/fce-first-certificate\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'225\',
      \'uid\' => \'1\',
      \'title\' => \'Ingles de Negocios\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'30e2a0be-764a-4f86-84dc-e060d0ac16c0\',
      \'nid\' => \'2364\',
      \'type\' => \'ajax_navigation\',
      \'language\' => \'es\',
      \'created\' => \'1400017628\',
      \'changed\' => \'1400730407\',
      \'tnid\' => \'2364\',
      \'translate\' => \'0\',
      \'uuid\' => \'ae696a16-5f9c-4000-816c-905093d3fb28\',
      \'revision_timestamp\' => \'1400730407\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h4 class=\\"content-title\\">Ingles de Negocios</h4>\\r\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/sites/default/files/images/stock/flickr-comput.jpg\\" />\\r\\n\\r\\n<p>Ulearn reconoce la importancia del idioma ingl&eacute;s en la industria y el comercio a nivel global. Algunas de las empresas m&aacute;s importantes de Irlanda han contratado los servicios de ULearn con el prop&oacute;sito de mejorar el nivel de ingl&eacute;s de sus empleados. Fundamentados en la experiencia internacional de nuestros directores y maestros, ULearn ha dise&ntilde;ado cursos especiales dirigidos espec&iacute;ficamente a cubrir las necesidades y expectativas de nuestros clientes. Nos complace compartir testimonios y referencias de empresas con las que hemos trabajado y para las cuales que hemos desarrollado diversos cursos de entrenamiento.</p>",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h4 class=\\"content-title\\">Ingles de Negocios</h4>\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/sites/default/files/images/stock/flickr-comput.jpg\\" />\\n\\n<p>Ulearn reconoce la importancia del idioma ingl&eacute;s en la industria y el comercio a nivel global. Algunas de las empresas m&aacute;s importantes de Irlanda han contratado los servicios de ULearn con el prop&oacute;sito de mejorar el nivel de ingl&eacute;s de sus empleados. Fundamentados en la experiencia internacional de nuestros directores y maestros, ULearn ha dise&ntilde;ado cursos especiales dirigidos espec&iacute;ficamente a cubrir las necesidades y expectativas de nuestros clientes. Nos complace compartir testimonios y referencias de empresas con las que hemos trabajado y para las cuales que hemos desarrollado diversos cursos de entrenamiento.</p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'field_order\' => array(
        \'und\' => array(
          array(
            \'value\' => \'8\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017628\',
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
        \'pid\' => \'512\',
        \'source\' => \'node/2364\',
        \'alias\' => \'summary/ingles-de-negocios\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'226\',
      \'uid\' => \'1\',
      \'title\' => \'IELTS Examen\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'0d7e23b3-f87b-41e0-a928-45c2b550fde7\',
      \'nid\' => \'2365\',
      \'type\' => \'ajax_navigation\',
      \'language\' => \'es\',
      \'created\' => \'1400017628\',
      \'changed\' => \'1400730454\',
      \'tnid\' => \'2365\',
      \'translate\' => \'0\',
      \'uuid\' => \'bc0b4f84-6d7c-4cef-86f0-41fc9b3213ce\',
      \'revision_timestamp\' => \'1400730454\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h4 class=\\"content-title\\">IELTS</h4>\\r\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/world-speaks-ielts.jpg\\" />\\r\\n<p>El IELTS es un examen mundialmente reconocido a trav&eacute;s del cual se eval&uacute;an alrededor de 2 millones de estudiantes cada a&ntilde;o. Este certificado se utiliza principalmente para prop&oacute;sitos acad&eacute;micos dado que muchas universidades requieren que el estudiante obtenga una determinada calificaci&oacute;n de IELTS como requisito de admisi&oacute;n. Las autoridades consulares y migratorias de Pa&iacute;ses como Australia, Nueva Zelandia y Canad&aacute; utilizan el IELTS para determinar el nivel de ingl&eacute;s de los solicitantes de visa.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h4 class=\\"content-title\\">IELTS</h4>\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/world-speaks-ielts.jpg\\" />\\n<p>El IELTS es un examen mundialmente reconocido a trav&eacute;s del cual se eval&uacute;an alrededor de 2 millones de estudiantes cada a&ntilde;o. Este certificado se utiliza principalmente para prop&oacute;sitos acad&eacute;micos dado que muchas universidades requieren que el estudiante obtenga una determinada calificaci&oacute;n de IELTS como requisito de admisi&oacute;n. Las autoridades consulares y migratorias de Pa&iacute;ses como Australia, Nueva Zelandia y Canad&aacute; utilizan el IELTS para determinar el nivel de ingl&eacute;s de los solicitantes de visa.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'field_order\' => array(
        \'und\' => array(
          array(
            \'value\' => \'5\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017628\',
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
        \'pid\' => \'513\',
        \'source\' => \'node/2365\',
        \'alias\' => \'summary/ielts-examen\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'227\',
      \'uid\' => \'1\',
      \'title\' => \'Inglés General\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'3fdb7935-17aa-4b61-bf5d-b3c85e63ed46\',
      \'nid\' => \'2366\',
      \'type\' => \'ajax_navigation\',
      \'language\' => \'es\',
      \'created\' => \'1400017628\',
      \'changed\' => \'1400730399\',
      \'tnid\' => \'2366\',
      \'translate\' => \'0\',
      \'uuid\' => \'ee9aa5fd-a722-49b6-9865-fc8104bcac8b\',
      \'revision_timestamp\' => \'1400730399\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h4 class=\\"content-title\\">Inglés General</h4>\\r\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/students-stairs-laughing.jpg\\" />\\r\\n\\r\\n<div>Ofrecemos al estudiante interesado en aprender inglés general una serie de opciones flexibles a fin de que estos puedan elegir el curso que mejor se adapte a sus necesidades. Nuestro curso más popular es el curso matutino general de inglés que tiene lugar de lunes a viernes de 9.30 AM a 12.45 PM (por la mañana). Ofrecemos además un curso vespertino de 2.00 PM a 5.15 PM (por la tarde). Los estudiantes que deseen recibir un curso intensivo pueden tomar clases en ambos horarios (en la mañana y en la tarde). Este curso de 30 horas se recomienda a estudiantes que desean mejorar su &nbsp;inglés al máximo en un breve periodo de tiempo.</div>\\r\\n\\r\\n<div>Adicionalmente ofrecemos un curso general de inglés &nbsp;a tiempo parcial que se imparte los lunes y miércoles de 7.00 PM a 9.00PM.</div>\\r\\n\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h4 class=\\"content-title\\">Inglés General</h4>\\n<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/students-stairs-laughing.jpg\\" />\\n\\n<div>Ofrecemos al estudiante interesado en aprender inglés general una serie de opciones flexibles a fin de que estos puedan elegir el curso que mejor se adapte a sus necesidades. Nuestro curso más popular es el curso matutino general de inglés que tiene lugar de lunes a viernes de 9.30 AM a 12.45 PM (por la mañana). Ofrecemos además un curso vespertino de 2.00 PM a 5.15 PM (por la tarde). Los estudiantes que deseen recibir un curso intensivo pueden tomar clases en ambos horarios (en la mañana y en la tarde). Este curso de 30 horas se recomienda a estudiantes que desean mejorar su &nbsp;inglés al máximo en un breve periodo de tiempo.</div>\\n\\n<div>Adicionalmente ofrecemos un curso general de inglés &nbsp;a tiempo parcial que se imparte los lunes y miércoles de 7.00 PM a 9.00PM.</div>\\n\\n",
            \'safe_summary\' => \'\',
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
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017628\',
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
        \'pid\' => \'514\',
        \'source\' => \'node/2366\',
        \'alias\' => \'summary/inglés-general\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'228\',
      \'uid\' => \'1\',
      \'title\' => \'Estudio y Trabajo\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'89cc2529-7597-46b7-b6c8-eaf01d37d85c\',
      \'nid\' => \'2367\',
      \'type\' => \'ajax_navigation\',
      \'language\' => \'es\',
      \'created\' => \'1400017628\',
      \'changed\' => \'1400730379\',
      \'tnid\' => \'2367\',
      \'translate\' => \'0\',
      \'uuid\' => \'f79c6243-e779-4344-9146-ff3d4c837945\',
      \'revision_timestamp\' => \'1400730379\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h4 class=\\"content-title\\">Programa de Estudio y Trabajo</h4>\\r\\n\\r\\n\\t<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/stock-tractor.jpg\\" />\\r\\n<div>\\r\\n\\tULearn ofrece un curso de ingl&eacute;s en la modalidad de estudio y trabajo en Irlanda por solo &euro;2500. El programa incluye 25 semanas de clase y 25 semanas de vacaciones. Durante las 25 semanas de vacaciones el estudiante puede trabajar a tiempo completo o parcial en Irlanda. Muchos estudiantes suelen conseguir empleo en Dubl&iacute;n mientras que otros simplemente usan sus vacaciones para recorrer Irlanda y Europa. ULearn proporciona todos los documentos requeridos para entrar a Irlanda. El proceso para recibir una Visa de Estudio y Trabajo es bien sencillo. Los estudiantes no-residentes, o no-nacionales de de la Uni&oacute;n Europea, deben completar los siguientes requisitos a fin de estudiar ingl&eacute;s en Irlanda:</div>\\r\\n<div>\\r\\n\\t&nbsp;</div>\\r\\n<div>\\r\\n\\t1.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Pago de los honorarios (tarifa) del curso.</div>\\r\\n<div>\\r\\n\\t&nbsp;</div>\\r\\n<div>\\r\\n\\t2.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Carta de invitaci&oacute;n de ULearn especificando los detalles del curso. ULearn le enviara una carta original de la escuela tras haber completado el pago de los honorarios correspondientes. Dicho documento debe ser presentado ante las autoridades de inmigraci&oacute;n en el momento de su arribo a Irlanda.</div>\\r\\n<div>\\r\\n\\t&nbsp;</div>\\r\\n<div>\\r\\n\\t3.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Pasaporte v&aacute;lido por al menos 6 meses a partir de la fecha en que finaliza el curso.</div>\\r\\n<div>\\r\\n\\t&nbsp;</div>\\r\\n<div>\\r\\n\\t4.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Seguro medico valido por 1 a&ntilde;o. ULearn puede asistirle con el seguro m&eacute;dico en caso de ser requerido. Los estudiantes no-residentes, o no-nacionales de de la Uni&oacute;n Europea necesitan un seguro m&eacute;dico para estudiar ingl&eacute;s en Irlanda.</div>\\r\\n<div>\\r\\n\\t&nbsp;</div>\\r\\n<div>\\r\\n\\t5.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Estado de cuenta bancaria a fin de acreditar medios financieros suficientes para cubrir su estancia en Irlanda.</div>\\r\\n<div>\\r\\n\\t&nbsp;</div>\\r\\n<div>\\r\\n\\t6.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Documentaci&oacute;n de su historia laboral y educativa.</div>\\r\\n<div>\\r\\n\\tSi su solicitud de visado de Estudio y Trabajo es denegada usted recibir&aacute; un reembolso completo, menos &euro; 150 por cargos de administraci&oacute;n.</div>\\r\\n<div>\\r\\n\\tPara mayor informaci&oacute;n sobre el visado irland&eacute;s, visite los siguientes sitios web oficiales: Departamento de Relaciones Exteriores y Departamento de Justicia, Igualdad y Reforma Legal.</div>\\r\\n<div>\\r\\n\\t&nbsp;</div>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h4 class=\\"content-title\\">Programa de Estudio y Trabajo</h4>\\n\\n\\t<img src=\\"http://ulearnschool.com/sites/default/files/images/stock/stock-tractor.jpg\\" />\\n<div>\\n\\tULearn ofrece un curso de ingl&eacute;s en la modalidad de estudio y trabajo en Irlanda por solo &euro;2500. El programa incluye 25 semanas de clase y 25 semanas de vacaciones. Durante las 25 semanas de vacaciones el estudiante puede trabajar a tiempo completo o parcial en Irlanda. Muchos estudiantes suelen conseguir empleo en Dubl&iacute;n mientras que otros simplemente usan sus vacaciones para recorrer Irlanda y Europa. ULearn proporciona todos los documentos requeridos para entrar a Irlanda. El proceso para recibir una Visa de Estudio y Trabajo es bien sencillo. Los estudiantes no-residentes, o no-nacionales de de la Uni&oacute;n Europea, deben completar los siguientes requisitos a fin de estudiar ingl&eacute;s en Irlanda:</div>\\n<div>\\n\\t&nbsp;</div>\\n<div>\\n\\t1.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Pago de los honorarios (tarifa) del curso.</div>\\n<div>\\n\\t&nbsp;</div>\\n<div>\\n\\t2.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Carta de invitaci&oacute;n de ULearn especificando los detalles del curso. ULearn le enviara una carta original de la escuela tras haber completado el pago de los honorarios correspondientes. Dicho documento debe ser presentado ante las autoridades de inmigraci&oacute;n en el momento de su arribo a Irlanda.</div>\\n<div>\\n\\t&nbsp;</div>\\n<div>\\n\\t3.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Pasaporte v&aacute;lido por al menos 6 meses a partir de la fecha en que finaliza el curso.</div>\\n<div>\\n\\t&nbsp;</div>\\n<div>\\n\\t4.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Seguro medico valido por 1 a&ntilde;o. ULearn puede asistirle con el seguro m&eacute;dico en caso de ser requerido. Los estudiantes no-residentes, o no-nacionales de de la Uni&oacute;n Europea necesitan un seguro m&eacute;dico para estudiar ingl&eacute;s en Irlanda.</div>\\n<div>\\n\\t&nbsp;</div>\\n<div>\\n\\t5.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Estado de cuenta bancaria a fin de acreditar medios financieros suficientes para cubrir su estancia en Irlanda.</div>\\n<div>\\n\\t&nbsp;</div>\\n<div>\\n\\t6.<span class=\\"Apple-tab-span\\" style=\\"white-space:pre\\"> </span>Documentaci&oacute;n de su historia laboral y educativa.</div>\\n<div>\\n\\tSi su solicitud de visado de Estudio y Trabajo es denegada usted recibir&aacute; un reembolso completo, menos &euro; 150 por cargos de administraci&oacute;n.</div>\\n<div>\\n\\tPara mayor informaci&oacute;n sobre el visado irland&eacute;s, visite los siguientes sitios web oficiales: Departamento de Relaciones Exteriores y Departamento de Justicia, Igualdad y Reforma Legal.</div>\\n<div>\\n\\t&nbsp;</div>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'field_order\' => array(
        \'und\' => array(
          array(
            \'value\' => \'3\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'translations\' => (object) array(
          \'original\' => NULL,
          \'data\' => array(),
        ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017628\',
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
        \'pid\' => \'515\',
        \'source\' => \'node/2367\',
        \'alias\' => \'summary/estudio-y-trabajo\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
