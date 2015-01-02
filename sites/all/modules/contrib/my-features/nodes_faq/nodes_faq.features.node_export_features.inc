<?php
/**
 * @file
 * nodes_faq.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function nodes_faq_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'229\',
      \'uid\' => \'1\',
      \'title\' => \'¿Tu escuela de inglés ofrece visitas guiadas por Irlanda? Si sí ¿cuál es el coste adicional?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'6f9a518c-e2fd-4c1c-8d50-e6ca0f17d4cf\',
      \'nid\' => \'2368\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'0a22b4f8-a2b8-4317-940c-29ff46005773\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí, así es. No hay ningún coste adicional en nuestros tours culturales en Dublín, pero puede tener que pagar la entrada a las galerías de arte, museos y lugares de interés local. Los viajes fuera de Dublín tendrán un coste para el transporte, comida y alojamiento. De momento la escuela no cobra ningún cargo adicional.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí, así es. No hay ningún coste adicional en nuestros tours culturales en Dublín, pero puede tener que pagar la entrada a las galerías de arte, museos y lugares de interés local. Los viajes fuera de Dublín tendrán un coste para el transporte, comida y alojamiento. De momento la escuela no cobra ningún cargo adicional.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'516\',
        \'source\' => \'node/2368\',
        \'alias\' => \'¿tu-escuela-de-inglés-ofrece-visitas-guiadas-por-irlanda-si-sí-¿cuál-es-el-coste-adicional\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'230\',
      \'uid\' => \'1\',
      \'title\' => \'¿Qué calificaciones tienen los profesores?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'6b07fdfb-7872-43ac-beac-65fe966363f7\',
      \'nid\' => \'2369\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'0aeaad6a-183f-4b52-9b92-cbe9ea3ec87e\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Como toda escuela reconocida por el Departamento de Educación y por ACELS, todos nuestros profesores tienen grado universitario y un mínimo de 120 horas del certificado de entrenamiento TEFL. Actualmente todos los profesores tienen un mínimo de cuatro años de experiencia.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Como toda escuela reconocida por el Departamento de Educación y por ACELS, todos nuestros profesores tienen grado universitario y un mínimo de 120 horas del certificado de entrenamiento TEFL. Actualmente todos los profesores tienen un mínimo de cuatro años de experiencia.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'517\',
        \'source\' => \'node/2369\',
        \'alias\' => \'¿qué-calificaciones-tienen-los-profesores\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'231\',
      \'uid\' => \'1\',
      \'title\' => \'¿La escuela puede organizar excursiones por Irlanda a los estudiantes?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'f637b51a-7be7-4a95-ac81-ee692353b175\',
      \'nid\' => \'2370\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'0e15fd60-95cc-4166-ab67-d404683cb4dc\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí. Si los estudiantes simplemente requieren asistencia (con reserva de alojamiento, &nbsp;localización de destinos interesantes, alquiler de coche, etc.), nuestro personal de soporte está siempre dispuesto a ayudar sin ningún cargo adicional.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí. Si los estudiantes simplemente requieren asistencia (con reserva de alojamiento, &amp;nbsp;localización de destinos interesantes, alquiler de coche, etc.), nuestro personal de soporte está siempre dispuesto a ayudar sin ningún cargo adicional.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'518\',
        \'source\' => \'node/2370\',
        \'alias\' => \'¿la-escuela-puede-organizar-excursiones-por-irlanda-los-estudiantes\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'233\',
      \'uid\' => \'1\',
      \'title\' => \'¿Tu escuela de inglés ofrece a los estudiantes la posibilidad de tomar algún examen de inglés?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'773a9f33-9177-4847-97df-b29c2499d275\',
      \'nid\' => \'2372\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'2ec84970-244c-4c73-a158-a17c59c92139\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí. Ofrecemos enseñanza y preparación para todos los exámenes de inglés para extranjeros (ESOL), incluyendo Preliminary English Test, First Certificate, Advanced Certificate. También ofrecemos preparación para todos los niveles de estudiantes de TOEFL e IELTS, y ULearn es un centro reconocido por el TIE, que é o test irlandés equivalente. También preparamos alumnos para cualquier nivel para el BEC exam, para esos alumnos que buscan un Business English Certification.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí. Ofrecemos enseñanza y preparación para todos los exámenes de inglés para extranjeros (ESOL), incluyendo Preliminary English Test, First Certificate, Advanced Certificate. También ofrecemos preparación para todos los niveles de estudiantes de TOEFL e IELTS, y ULearn es un centro reconocido por el TIE, que é o test irlandés equivalente. También preparamos alumnos para cualquier nivel para el BEC exam, para esos alumnos que buscan un Business English Certification.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'520\',
        \'source\' => \'node/2372\',
        \'alias\' => \'¿tu-escuela-de-inglés-ofrece-los-estudiantes-la-posibilidad-de-tomar-algún-examen-de-inglés\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'234\',
      \'uid\' => \'1\',
      \'title\' => \'¿Cómo tu escuela de inglés monitora la performance de los estudiantes? \',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'423c3242-3272-451f-a94d-0d67f271365c\',
      \'nid\' => \'2373\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'343fbcf6-6235-4dc4-bd30-cb377574a4be\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Al entrar a la escuela el nivel del estudiante se evalúa mediante la prueba de nivel 1 y 2 de Oxford, además de la sección Aural y una entrevista personal. Sobre una base diaria (o en cada clase) cada aula tiene la corrección de errores. Esto permite a los estudiantes ver sus propios errores en una base continua.</p>\\r\\n\\r\\n<p>Además, en una forma más estructurada, ULearn organiza pruebas <strong>semanales</strong> y <strong>sesiones de charlas</strong>, por lo general el viernes. Se cotejan las puntuaciones y se actualiza la cuenta de los estudiantes. Esto nos ayuda a monitorear el progreso semanalmente. El Director de Estudios organiza reuniones semanales con los profesores para discutir el progreso, las dificultades y los problemas de los estudiantes, y también es la plataforma para la discusión de nivel o cambio de aula para el estudiante.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Al entrar a la escuela el nivel del estudiante se evalúa mediante la prueba de nivel 1 y 2 de Oxford, además de la sección Aural y una entrevista personal. Sobre una base diaria (o en cada clase) cada aula tiene la corrección de errores. Esto permite a los estudiantes ver sus propios errores en una base continua.&lt;/p&gt;</p>\\n<p>&lt;p&gt;Además, en una forma más estructurada, ULearn organiza pruebas &lt;strong&gt;semanales&lt;/strong&gt; y &lt;strong&gt;sesiones de charlas&lt;/strong&gt;, por lo general el viernes. Se cotejan las puntuaciones y se actualiza la cuenta de los estudiantes. Esto nos ayuda a monitorear el progreso semanalmente. El Director de Estudios organiza reuniones semanales con los profesores para discutir el progreso, las dificultades y los problemas de los estudiantes, y también es la plataforma para la discusión de nivel o cambio de aula para el estudiante.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'521\',
        \'source\' => \'node/2373\',
        \'alias\' => \'¿cómo-tu-escuela-de-inglés-monitora-la-performance-de-los-estudiantes\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'235\',
      \'uid\' => \'1\',
      \'title\' => \'¿Cuándo la escuela se ha establecido?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'98ce7382-44fc-42d2-8a17-929ff08fb83e\',
      \'nid\' => \'2374\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'440f7032-6a90-4b14-b27a-f6df6c4bb565\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>ULearn se estableció en 1988.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;ULearn se estableció en 1988.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'522\',
        \'source\' => \'node/2374\',
        \'alias\' => \'¿cuándo-la-escuela-se-ha-establecido\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'236\',
      \'uid\' => \'1\',
      \'title\' => \'¿Algún miembro de la escuela va al aeropuerto a recibir a los alumnos?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'f0863267-2cc3-4db6-b36d-83498555ccf1\',
      \'nid\' => \'2375\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'4c278d81-a5e7-44c0-bcf4-bffc41a02f96\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí, si se pide. Hay un servicio de \\"Airport Transfer\\" - mandamos a un coche / autobus al aeropuerto a recoger el estudiante.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí, si se pide. Hay un servicio de &quot;Airport Transfer&quot; - mandamos a un coche / autobus al aeropuerto a recoger el estudiante.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'523\',
        \'source\' => \'node/2375\',
        \'alias\' => \'¿algún-miembro-de-la-escuela-va-al-aeropuerto-recibir-los-alumnos\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'237\',
      \'uid\' => \'1\',
      \'title\' => \'¿Las aulas son separadas dependiendo de las capacidades de los alumnos?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'e77ce00d-ab23-4a9c-9597-ad8b5445cb15\',
      \'nid\' => \'2376\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'4cdf10c8-a7bf-4f70-9664-3a2a4d6e1b31\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí. Siguiendo Parte 1, 2, y 3 de la prueba de acceso los alumnos son asignados a un aula de acuerdo a su nivel. Solicitamos comentarios de los alumnos para asegurarnos de que están en su nivel adecuado y también para mantener la homogeneidad de cada grupo.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí. Siguiendo Parte 1, 2, y 3 de la prueba de acceso los alumnos son asignados a un aula de acuerdo a su nivel. Solicitamos comentarios de los alumnos para asegurarnos de que están en su nivel adecuado y también para mantener la homogeneidad de cada grupo.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'524\',
        \'source\' => \'node/2376\',
        \'alias\' => \'¿las-aulas-son-separadas-dependiendo-de-las-capacidades-de-los-alumnos\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'238\',
      \'uid\' => \'1\',
      \'title\' => \'¿Tu escuela de inglés tiene algún requisito de inglés para algún curso específico?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'046f7f4c-916c-4167-a473-7f75cdca6e6d\',
      \'nid\' => \'2377\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'56a6f063-4e71-49ff-ae5f-e7318a0cacaf\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Pedimos una prueba de acceso para todos los estudiantes para saber su nivel, pero no existe un nivel mínimo porque enseñamos a alumnos de todos los niveles de aprendizaje de inglés.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Pedimos una prueba de acceso para todos los estudiantes para saber su nivel, pero no existe un nivel mínimo porque enseñamos a alumnos de todos los niveles de aprendizaje de inglés.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'525\',
        \'source\' => \'node/2377\',
        \'alias\' => \'¿tu-escuela-de-inglés-tiene-algún-requisito-de-inglés-para-algún-curso-específico\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'239\',
      \'uid\' => \'1\',
      \'title\' => \'¿Tu escuela tiene una prueba de acceso para determinar la capacidad del estudiante?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'28625187-7467-46ad-adb1-d067eab19a56\',
      \'nid\' => \'2378\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'5801905c-3e70-452a-8465-8fb2af902729\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí (ver pregunta 17).&nbsp; Al entrar a la escuela los alumnos son evaluados a través de las variaciones del test estandarizado de Oxford 1 y 2 y secciones Aural. Una entrevista personal también se da para evaluar la fluidez oral y la precisión. Los resultados se comparan y el estudiante entra en el aula de su nivel adecuado.&nbsp;&nbsp;</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí (ver pregunta 17).&amp;nbsp; Al entrar a la escuela los alumnos son evaluados a través de las variaciones del test estandarizado de Oxford 1 y 2 y secciones Aural. Una entrevista personal también se da para evaluar la fluidez oral y la precisión. Los resultados se comparan y el estudiante entra en el aula de su nivel adecuado.&amp;nbsp;&amp;nbsp;&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'526\',
        \'source\' => \'node/2378\',
        \'alias\' => \'¿tu-escuela-tiene-una-prueba-de-acceso-para-determinar-la-capacidad-del-estudiante\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'240\',
      \'uid\' => \'1\',
      \'title\' => \'¿Cuál la distancia de los alojamientos a la escuela?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'467f7a32-d24f-4374-a5f4-12902836c8c9\',
      \'nid\' => \'2379\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'5ecabc09-8530-419e-a515-2249512a94fc\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<ol>\\r\\n\\t<li>Casa de Familia – fuera del centro de la ciudad. Es necesario transporte público para llegar a la escuela, que está en el centro de Dublín. Todas las casas tienen ruta de transporte público como requerimiento para el proceso selectivo.</li>\\r\\n\\t<li>Apartamentos – situado en el centro de la ciudad y sus alrededores. Normalmente, a poca distancia de ULearn del centro de Dublín (ULearn está situada justo al lado de O\'Connell Street, la calle principal de la ciudad)</li>\\r\\n\\t<li>Residencia de Estudiantes – Está a menos de 5 minutos caminando a ULearn en el centro.</li>\\r\\n</ol>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;ol&gt;<br />\\n\\t&lt;li&gt;Casa de Familia – fuera del centro de la ciudad. Es necesario transporte público para llegar a la escuela, que está en el centro de Dublín. Todas las casas tienen ruta de transporte público como requerimiento para el proceso selectivo.&lt;/li&gt;<br />\\n\\t&lt;li&gt;Apartamentos – situado en el centro de la ciudad y sus alrededores. Normalmente, a poca distancia de ULearn del centro de Dublín (ULearn está situada justo al lado de O&#039;Connell Street, la calle principal de la ciudad)&lt;/li&gt;<br />\\n\\t&lt;li&gt;Residencia de Estudiantes – Está a menos de 5 minutos caminando a ULearn en el centro.&lt;/li&gt;<br />\\n&lt;/ol&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'527\',
        \'source\' => \'node/2379\',
        \'alias\' => \'¿cuál-la-distancia-de-los-alojamientos-la-escuela\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'241\',
      \'uid\' => \'1\',
      \'title\' => \'¿Cuántos alumnos internacionales han pasado por tu escuela? \',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'6301e672-7526-4a5e-9895-121b7ebe9c6a\',
      \'nid\' => \'2380\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'72ffd6eb-59e4-4914-83e2-e035ea7de8a3\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>ULearn tiene una reputación fuerte en el extranjero con alumnos de todas las nacionalidades. Como base anual, recibimos una media de 1000 alumnos.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;ULearn tiene una reputación fuerte en el extranjero con alumnos de todas las nacionalidades. Como base anual, recibimos una media de 1000 alumnos.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'528\',
        \'source\' => \'node/2380\',
        \'alias\' => \'¿cuántos-alumnos-internacionales-han-pasado-por-tu-escuela\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'242\',
      \'uid\' => \'1\',
      \'title\' => \'¿Cuál es la política actual de tu escuela de inglés?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'b516b0fe-eb60-41b7-8129-f562b2844dae\',
      \'nid\' => \'2381\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'82659e21-87f7-4f76-bb79-80703c3c63bd\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Hay un anexo con el documento completo en Terms and Condtions.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Hay un anexo con el documento completo en Terms and Condtions.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'529\',
        \'source\' => \'node/2381\',
        \'alias\' => \'¿cuál-es-la-política-actual-de-tu-escuela-de-inglés\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'243\',
      \'uid\' => \'1\',
      \'title\' => \'¿Cuál es el coste de vida aproximado en tu área local?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'5bc359c0-93cb-4336-bc39-e6b35e62bc53\',
      \'nid\' => \'2382\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'8b38c5cf-bcef-4f43-9601-c4fc4003cc76\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Con alquiler de unos €400 por mes más comida y otros gastos, puedes vivir con aproximadamente &nbsp;€1200 por mes.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Con alquiler de unos €400 por mes más comida y otros gastos, puedes vivir con aproximadamente &amp;nbsp;€1200 por mes.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'530\',
        \'source\' => \'node/2382\',
        \'alias\' => \'¿cuál-es-el-coste-de-vida-aproximado-en-tu-área-local\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'244\',
      \'uid\' => \'1\',
      \'title\' => \'¿Tu escuela de inglés tiene vínculos con empleadores con el fin de facilitar al alumno un trabajo informal?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'949dc7d1-6aa2-4f36-980d-a1ea5254afb2\',
      \'nid\' => \'2383\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'909bbd27-c92f-4e29-b131-b76ca804273d\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí. También tenemos contacto con las agencias de contratación. Esta es un área muy importante para nuestros estudiantes y nos enfocamos en brindarles toda la ayuda que podamos.&nbsp;</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí. También tenemos contacto con las agencias de contratación. Esta es un área muy importante para nuestros estudiantes y nos enfocamos en brindarles toda la ayuda que podamos.&amp;nbsp;&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'531\',
        \'source\' => \'node/2383\',
        \'alias\' => \'¿tu-escuela-de-inglés-tiene-vínculos-con-empleadores-con-el-fin-de-facilitar-al-alumno-un-trabajo\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'245\',
      \'uid\' => \'1\',
      \'title\' => \'7.	¿Cuánto personal administrativo tiene tu escuela de inglés?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'6f98e42b-da4a-4e95-b5d1-7f513e546bff\',
      \'nid\' => \'2384\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'9cb3e824-2796-4168-bdfc-762c22d00176\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Tenemos 3 administrativos en tiempo integral y además un asistente que es un intermediario entre alumnos y administración. ULearn también cuenta con otro intermediario, si necesario, que habla varios idiomas incluyendo portugués, español, coreano e alemán.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Tenemos 3 administrativos en tiempo integral y además un asistente que es un intermediario entre alumnos y administración. ULearn también cuenta con otro intermediario, si necesario, que habla varios idiomas incluyendo portugués, español, coreano e alemán.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'532\',
        \'source\' => \'node/2384\',
        \'alias\' => \'7-¿cuánto-personal-administrativo-tiene-tu-escuela-de-inglés\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'246\',
      \'uid\' => \'1\',
      \'title\' => \'ALOJAMIENTO - 14.	Describa los tipos de alojamiento ofrecidos a los posibles alumnos.\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'47870bd0-8f7d-4583-be14-eea13534dcf9\',
      \'nid\' => \'2385\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'ac0c2980-e82a-4aaf-b6ca-455293a13b0e\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Ofrecemos 3 principales tipos de alojamiento:</p>\\r\\n\\r\\n<ol>\\r\\n\\t<li><strong>En Casa de Familia</strong> – Desayuno y cena están incluidos. Esta es una gran oportunidad para el alumno, una auténtica experiencia de vida con una familia irlandesa. La oportunidad de practicar inglés con la familia anfitriona siempre hace esta la opción más popular entre los alumnos que quieren aprender inglés.</li>\\r\\n\\t<li><strong>&nbsp;Apartamentos</strong> – En el corazón de la ciudad, les da a los alumnos la libertad de disfrutar la vida cultural y nocturna de Dublín. Desde todos los apartamentos se puede ir caminando para la escuela, al distrito de tiendas y restaurantes de Dublín. Esta opción es para alumnos mayores de 18 años (si no van acompañados por mayores). Puedes elegir una habitación individual o compartida. Generalmente tienen WiFi, así que, por favor, si esta es una exigencia, déjanos saber.</li>\\r\\n\\t<li><strong>Residencia de Estudiantes</strong> – A 5 minutos caminando da escuela, la residencia de estudiantes tiene cuartos compartidos con otros estudiantes da ULearn en el centro de Dublín, con WiFi.</li>\\r\\n</ol>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Ofrecemos 3 principales tipos de alojamiento:&lt;/p&gt;</p>\\n<p>&lt;ol&gt;<br />\\n\\t&lt;li&gt;&lt;strong&gt;En Casa de Familia&lt;/strong&gt; – Desayuno y cena están incluidos. Esta es una gran oportunidad para el alumno, una auténtica experiencia de vida con una familia irlandesa. La oportunidad de practicar inglés con la familia anfitriona siempre hace esta la opción más popular entre los alumnos que quieren aprender inglés.&lt;/li&gt;<br />\\n\\t&lt;li&gt;&lt;strong&gt;&amp;nbsp;Apartamentos&lt;/strong&gt; – En el corazón de la ciudad, les da a los alumnos la libertad de disfrutar la vida cultural y nocturna de Dublín. Desde todos los apartamentos se puede ir caminando para la escuela, al distrito de tiendas y restaurantes de Dublín. Esta opción es para alumnos mayores de 18 años (si no van acompañados por mayores). Puedes elegir una habitación individual o compartida. Generalmente tienen WiFi, así que, por favor, si esta es una exigencia, déjanos saber.&lt;/li&gt;<br />\\n\\t&lt;li&gt;&lt;strong&gt;Residencia de Estudiantes&lt;/strong&gt; – A 5 minutos caminando da escuela, la residencia de estudiantes tiene cuartos compartidos con otros estudiantes da ULearn en el centro de Dublín, con WiFi.&lt;/li&gt;<br />\\n&lt;/ol&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'533\',
        \'source\' => \'node/2385\',
        \'alias\' => \'alojamiento-14-describa-los-tipos-de-alojamiento-ofrecidos-los-posibles-alumnos\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'247\',
      \'uid\' => \'1\',
      \'title\' => \'¿Existe un número máximo de alumnos que tu escuela de inglés puede atender?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'f91b05c7-555d-4856-9218-716caacbdf5e\',
      \'nid\' => \'2386\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'c3a49095-5312-4f5f-832b-debbb5a4743a\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>No. ULearn está bem preparada para qualquer ampliação estacional no número de alunos. Temos acesso a muitos espaços de ensino e de recreação.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;No. ULearn está bem preparada para qualquer ampliação estacional no número de alunos. Temos acesso a muitos espaços de ensino e de recreação.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'534\',
        \'source\' => \'node/2386\',
        \'alias\' => \'¿existe-un-número-máximo-de-alumnos-que-tu-escuela-de-inglés-puede-atender\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'248\',
      \'uid\' => \'1\',
      \'title\' => \'¿Si la escuela ofrece alojamiento con una familia irlandesa, como es la selección de la familia para garantizar que son los anfitriones adecuados?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'72c7d2a0-33b4-496c-8d2a-082476ef7e9b\',
      \'nid\' => \'2387\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'c44f1067-d6c6-4756-bfd1-1f8f2a96dc3d\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Existe un proceso de selección riguroso de todas las familias. En cuanto la familia rellena y nos entrega el formulario de candidatura de hospedaje y el acuerdo de familia de acogida, organizamos una visita a la casa. También existe un continuo proceso de comentarios y supervisión entre la oficina de alojamiento aquí de la escuela y la casa anfitriona. Eso nos permite mantener los patrones de calidad. También contamos con el hecho de que ULearn ha construido una relación con esas familias por los últimos 20 años. Conocemos a todas las familias personal y profesionalmente. Esta confianza es clave en la gestión de éxito en la experiencia entre alumno y familia anfitriona, con la escuela como intermediario.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Existe un proceso de selección riguroso de todas las familias. En cuanto la familia rellena y nos entrega el formulario de candidatura de hospedaje y el acuerdo de familia de acogida, organizamos una visita a la casa. También existe un continuo proceso de comentarios y supervisión entre la oficina de alojamiento aquí de la escuela y la casa anfitriona. Eso nos permite mantener los patrones de calidad. También contamos con el hecho de que ULearn ha construido una relación con esas familias por los últimos 20 años. Conocemos a todas las familias personal y profesionalmente. Esta confianza es clave en la gestión de éxito en la experiencia entre alumno y familia anfitriona, con la escuela como intermediario.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'535\',
        \'source\' => \'node/2387\',
        \'alias\' => \'¿si-la-escuela-ofrece-alojamiento-con-una-familia-irlandesa-como-es-la-selección-de-la-familia-para\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'250\',
      \'uid\' => \'1\',
      \'title\' => \'¿Tu escuela puede enviar fotos de los alojamientos de estudiantes?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'64a18bc2-254c-471b-a88d-2603ad033998\',
      \'nid\' => \'2389\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'d27fe230-0a93-4083-9557-c93afac4b0ba\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí, sin problema. Las fotos están disponibles para que se bajen desde nuestra página web y también en nuestra cuenta de Flickr. También encontrarás buenas fotos de la escuela, los parques alrededor, las atracciones culturales y las actividades con los estudiantes.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí, sin problema. Las fotos están disponibles para que se bajen desde nuestra página web y también en nuestra cuenta de Flickr. También encontrarás buenas fotos de la escuela, los parques alrededor, las atracciones culturales y las actividades con los estudiantes.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'537\',
        \'source\' => \'node/2389\',
        \'alias\' => \'¿tu-escuela-puede-enviar-fotos-de-los-alojamientos-de-estudiantes\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'251\',
      \'uid\' => \'1\',
      \'title\' => \'¿Tu escuela de inglés tiene su propio formulario de aplicación?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'b83fb625-6441-45f0-b5ad-f62ec9947b75\',
      \'nid\' => \'2390\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'d8c0c993-2684-413d-aa7e-6378cd2e842d\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí. Puedes ver lo <a href=\\"/booking\\">aqui</a>.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí. Puedes ver lo &lt;a href=&quot;/booking&quot;&gt;aqui&lt;/a&gt;.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'538\',
        \'source\' => \'node/2390\',
        \'alias\' => \'¿tu-escuela-de-inglés-tiene-su-propio-formulario-de-aplicación\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'253\',
      \'uid\' => \'1\',
      \'title\' => \'INFORMACIÓN ADICIONAL\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'575c2026-70f9-45c5-974f-85254de073a2\',
      \'nid\' => \'2392\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'e1adbbc7-b1c6-4bd3-be7e-ca9c98e5059a\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p><span style=\\"line-height:1.6em\\">Por favor baja <a href=\\"/docs/brochure.pdf\\">nuestro catálogo</a> para más información. :)</span></p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;&lt;span style=&quot;line-height:1.6em&quot;&gt;Por favor baja &lt;a href=&quot;/docs/brochure.pdf&quot;&gt;nuestro catálogo&lt;/a&gt; para más información. :)&lt;/span&gt;&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'540\',
        \'source\' => \'node/2392\',
        \'alias\' => \'información-adicional\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'254\',
      \'uid\' => \'1\',
      \'title\' => \'¿Qué comodidades tu escuela de inglés proporciona?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'a769d3e4-46af-4cfe-9950-c7bd8414fafa\',
      \'nid\' => \'2393\',
      \'type\' => \'faq\',
      \'language\' => \'und\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'e7daac13-0456-4bb4-9a00-10d44245bb8f\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>ULearn es un excelente ambiente de aprendizaje, en nuestro espacioso edificio Georgiano. Ofrecemos WiFi gratis de las 09:30 a las 21:00 para todos los alumnos, salón de estudio y lectura siempre abierto y también ofrecemos programas de vida social:</p>\\r\\n\\r\\n<p><strong style=\\"line-height:1.6em\\">Miércoles:</strong><span style=\\"line-height:1.6em\\"> Noche de Cine en la sala Audio Visual de la escuela (pelis con subtítulos).</span></p>\\r\\n\\r\\n<p><strong>Jueves:</strong> Noche de Pub ofrece a los alumnos la oportunidad de conocer a los profesores y el personal de apoyo de la escuela y practicar inglés fuera del tradicional escenario del aula.</p>\\r\\n\\r\\n<p><strong>Viernes:</strong> Excursión cultural en Dublín. Normalmente vamos a alguna galería, museo o lugar de interés local, como Kilmainham Gaol.</p>\\r\\n\\r\\n<p><strong>Viernes noche:</strong> Deporte.&nbsp; Futbol sala para todos los alumnos. También jugamos tag rugby y ultimate Frisbee.</p>\\r\\n\\r\\n<p><strong>Fines de semana:</strong> Excursiones fuera de Dublín, como por ejemplo: Galway, Cliffs of Moher, the Ring of Kerry and the Aran Islands.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;ULearn es un excelente ambiente de aprendizaje, en nuestro espacioso edificio Georgiano. Ofrecemos WiFi gratis de las 09:30 a las 21:00 para todos los alumnos, salón de estudio y lectura siempre abierto y también ofrecemos programas de vida social:&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong style=&quot;line-height:1.6em&quot;&gt;Miércoles:&lt;/strong&gt;&lt;span style=&quot;line-height:1.6em&quot;&gt; Noche de Cine en la sala Audio Visual de la escuela (pelis con subtítulos).&lt;/span&gt;&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong&gt;Jueves:&lt;/strong&gt; Noche de Pub ofrece a los alumnos la oportunidad de conocer a los profesores y el personal de apoyo de la escuela y practicar inglés fuera del tradicional escenario del aula.&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong&gt;Viernes:&lt;/strong&gt; Excursión cultural en Dublín. Normalmente vamos a alguna galería, museo o lugar de interés local, como Kilmainham Gaol.&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong&gt;Viernes noche:&lt;/strong&gt; Deporte.&amp;nbsp; Futbol sala para todos los alumnos. También jugamos tag rugby y ultimate Frisbee.&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong&gt;Fines de semana:&lt;/strong&gt; Excursiones fuera de Dublín, como por ejemplo: Galway, Cliffs of Moher, the Ring of Kerry and the Aran Islands.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'541\',
        \'source\' => \'node/2393\',
        \'alias\' => \'¿qué-comodidades-tu-escuela-de-inglés-proporciona\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'255\',
      \'uid\' => \'1\',
      \'title\' => \'¿En tu escuela de inglés hay algún programa de orientación para los alumnos?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'f9e3f1bc-1b95-42b3-a891-3055897c3b57\',
      \'nid\' => \'2394\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'eb6f9bc5-b24a-410d-838d-6104cc5e40b1\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Sí. El 1º día hacemos una inducción y continuamente hacemos reuniones cara a cara con café y mañanas de charla para darles a los estudiantes la oportunidad de discutir problemas y soluciones similares.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;Sí. El 1º día hacemos una inducción y continuamente hacemos reuniones cara a cara con café y mañanas de charla para darles a los estudiantes la oportunidad de discutir problemas y soluciones similares.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'542\',
        \'source\' => \'node/2394\',
        \'alias\' => \'¿en-tu-escuela-de-inglés-hay-algún-programa-de-orientación-para-los-alumnos\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'257\',
      \'uid\' => \'1\',
      \'title\' => \'SERVICIO DE APOYO - ¿Qué tipos de servicios de apoyo son ofrecidos a los estudiantes?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'8e7c898a-baf4-43b6-875a-fae2c3776440\',
      \'nid\' => \'2396\',
      \'type\' => \'faq\',
      \'language\' => \'es\',
      \'created\' => \'1400017823\',
      \'changed\' => \'1400017823\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'fc6bdfe1-ad78-4b77-b886-efe302a73b12\',
      \'revision_timestamp\' => \'1400017823\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p><strong style=\\"line-height:1.6em\\">Académico</strong></p>\\r\\n\\r\\n<p>El Director de Estudios está disponible a los estudiantes a todo momento en las horas de oficina para algún comentario u otro asunto académico.</p>\\r\\n\\r\\n<p><strong>Trabajo&nbsp;</strong></p>\\r\\n\\r\\n<p>Ofrecemos un servicio gratuito aquí en la escuela de asistencia en la búsqueda de trabajo. Ayudamos en la modificación y corrección del currículo, consejos en la búsqueda de trabajo y también, si se pide, se puede llevar a cabo una consulta con nuestros socios de contratación y talleres de entrevistas que permite a los estudiantes la oportunidad de practicar con su profesor EFL preguntas y respuestas de la entrevista de trabajo.</p>\\r\\n\\r\\n<p><strong>Social</strong></p>\\r\\n\\r\\n<p>Organizamos noches sociales para que todos los alumnos de la escuela se conozcan. También organizamos e participamos de eventos sociales y deportivos de la escuela.</p>\\r\\n\\r\\n<p><strong>Deportes</strong></p>\\r\\n\\r\\n<p>Jugamos futbol sala, Tag Rugby (en verano) y hay un moderno gimnasio disponible para los estudiantes de ULearn que esta situado cerca a la escuela</p>\\r\\n\\r\\n<p>.<strong>Soporte de Alojamiento&nbsp;</strong></p>\\r\\n\\r\\n<p>Si los estudiantes necesitan ayuda para encontrar su propio alojamiento en Dublín, ULearn les ayuda sin cobro adicional. La escuela también puede proporcionar una lista de los agentes inmobiliarios y los propietarios de buena reputación en la zona.&nbsp;</p>\\r\\n\\r\\n<p><strong>Apoyo de Bienestar&nbsp;</strong></p>\\r\\n\\r\\n<p>Es muy gratificante estudiar, vivir y trabajar en un país extranjero, pero también a veces puede ser una experiencia cargada de emociones. ULearn cree importante que todos los estudiantes deban tener acceso a la asistencia en todos los aspectos de su vida en Dublín, y no sólo en el aprendizaje, sino también en cuestiones relacionadas con el bienestar. Es por eso que ULearn también ofrece un servicio de asesoramiento a los estudiantes. Está disponible con cita una vez por semana en la escuela.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>&lt;p&gt;&lt;strong style=&quot;line-height:1.6em&quot;&gt;Académico&lt;/strong&gt;&lt;/p&gt;</p>\\n<p>&lt;p&gt;El Director de Estudios está disponible a los estudiantes a todo momento en las horas de oficina para algún comentario u otro asunto académico.&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong&gt;Trabajo&amp;nbsp;&lt;/strong&gt;&lt;/p&gt;</p>\\n<p>&lt;p&gt;Ofrecemos un servicio gratuito aquí en la escuela de asistencia en la búsqueda de trabajo. Ayudamos en la modificación y corrección del currículo, consejos en la búsqueda de trabajo y también, si se pide, se puede llevar a cabo una consulta con nuestros socios de contratación y talleres de entrevistas que permite a los estudiantes la oportunidad de practicar con su profesor EFL preguntas y respuestas de la entrevista de trabajo.&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong&gt;Social&lt;/strong&gt;&lt;/p&gt;</p>\\n<p>&lt;p&gt;Organizamos noches sociales para que todos los alumnos de la escuela se conozcan. También organizamos e participamos de eventos sociales y deportivos de la escuela.&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong&gt;Deportes&lt;/strong&gt;&lt;/p&gt;</p>\\n<p>&lt;p&gt;Jugamos futbol sala, Tag Rugby (en verano) y hay un moderno gimnasio disponible para los estudiantes de ULearn que esta situado cerca a la escuela&lt;/p&gt;</p>\\n<p>&lt;p&gt;.&lt;strong&gt;Soporte de Alojamiento&amp;nbsp;&lt;/strong&gt;&lt;/p&gt;</p>\\n<p>&lt;p&gt;Si los estudiantes necesitan ayuda para encontrar su propio alojamiento en Dublín, ULearn les ayuda sin cobro adicional. La escuela también puede proporcionar una lista de los agentes inmobiliarios y los propietarios de buena reputación en la zona.&amp;nbsp;&lt;/p&gt;</p>\\n<p>&lt;p&gt;&lt;strong&gt;Apoyo de Bienestar&amp;nbsp;&lt;/strong&gt;&lt;/p&gt;</p>\\n<p>&lt;p&gt;Es muy gratificante estudiar, vivir y trabajar en un país extranjero, pero también a veces puede ser una experiencia cargada de emociones. ULearn cree importante que todos los estudiantes deban tener acceso a la asistencia en todos los aspectos de su vida en Dublín, y no sólo en el aprendizaje, sino también en cuestiones relacionadas con el bienestar. Es por eso que ULearn también ofrece un servicio de asesoramiento a los estudiantes. Está disponible con cita una vez por semana en la escuela.&lt;/p&gt;</p>\\n",
            \'safe_summary\' => \'\',
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1400017823\',
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
        \'pid\' => \'544\',
        \'source\' => \'node/2396\',
        \'alias\' => \'servicio-de-apoyo-¿qué-tipos-de-servicios-de-apoyo-son-ofrecidos-los-estudiantes\',
        \'language\' => \'es\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
