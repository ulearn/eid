<?php
/**
 * @file
 * blog_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function blog_content_type_taxonomy_default_vocabularies() {
  return array(
    'tags12_37756' => array(
      'name' => 'Tags',
      'machine_name' => 'tags12_37756',
      'description' => 'Vocabulary created automatically by Taxonomy csv import/export module',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
