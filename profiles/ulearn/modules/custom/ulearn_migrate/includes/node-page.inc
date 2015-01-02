<?php

/**
 * @file
 * Migration class defination to migrate nodes of type page.
 */

class ulearnMigratePage extends ulearnMigrate {
  public function __construct() {
    parent::__construct();

    // Human-friendly description of your migration process.
    $this->description = t('Migrate basic pages.');

    // Create a map object for tracking the relationships between source rows
    // and their resulting Drupal objects.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 unique node id',
          'alias' => 'n',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Set up a query for source data.
    $query = Database::getConnection('default', 'ulearn_d6')
      ->select('node', 'n')
      ->fields('n', array('nid', 'vid', 'type', 'language', 'title', 'uid', 'status', 'created', 'changed', 'comment', 'promote', 'moderate', 'sticky', 'tnid', 'translate'));
    $query->join('node_revisions', 'nr', 'n.vid = nr.vid');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->addField('nr', 'format');
    $query->condition('n.type', 'page', '=');
    $query->orderBy('n.nid', 'ASC');
    $query->groupBy('n.nid');

    // Specify additional source fields.
    $source_fields = array(
      'url_alias' => t('URL alias of content.'),
      'page_title' => t('Text to be displayed in title bar of browser.'),
      'attached_images' => t('Attached images'),
    );

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));
    // Set up our destination - node in this case.
    $this->destination = new MigrateDestinationNode('page');

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('nid', 'nid');
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('title_field', 'title');
    $this->addFieldMapping('title_field:language', 'language');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('promote', 'promote');
    $this->addFieldMapping('sticky', 'sticky');
    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('comment', 'comment');
    $this->addFieldMapping('tnid', 'tnid');
    $this->addFieldMapping('translate', 'translate');
    $this->addFieldMapping('revision')->defaultValue(FALSE);

    $this->addFieldMapping('path', 'url_alias');
    $this->addFieldMapping('metatag_title', 'page_title');

    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'teaser');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('body:language', 'language');

    $this->addFieldMapping('field_image', 'attached_images');

    // Unmapped source fields.
    $this->addUnmigratedSources(array('vid', 'type', 'uid', 'moderate', 'format'));
    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array('log', 'revision_uid', 'field_image:file_class', 'field_image:language', 'field_image:destination_dir', 'field_image:destination_file', 'field_image:file_replace', 'field_image:preserve_files', 'field_image:source_dir', 'field_image:alt', 'field_image:title', 'metatag_description', 'metatag_abstract', 'metatag_keywords', 'metatag_robots', 'metatag_news_keywords', 'metatag_standout', 'metatag_generator', 'metatag_copyright', 'metatag_image_src', 'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author', 'metatag_original-source', 'metatag_revisit-after'));
  }

  function prepareRow($current_row) {
    $current_row->url_alias = ulearn_migrate_url_alias($current_row->nid);
    if ($current_row->url_alias == 'accommodation') {
      $current_row->url_alias == 'our-accommodation';
    }
    $current_row->page_title = ulearn_migrate_page_title($current_row->nid);

    // Attached images.
    $current_row->attached_images = ulearn_migrate_attached_images($current_row->nid);
    return TRUE;
  }
}
