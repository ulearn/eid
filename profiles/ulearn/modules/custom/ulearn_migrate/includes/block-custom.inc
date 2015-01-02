<?php

/**
 * @file
 * Migration class defination to migrate custom blocks.
 */

class ulearnMigrateBlockCustom extends ulearnMigrate {
  public function __construct() {
    parent::__construct();

    // Human-friendly description of your migration process.
    $this->description = t('Migrate custom blocks.');

    // Create a map object for tracking the relationships between source rows
    // and their resulting Drupal objects.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'bid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 unique block id',
          'alias' => 'b',
        )
      ),
      MigrateDestinationTable::getKeySchema('block')
    );

    // Get default theme..
    $default_theme = variable_get('theme_default', 'goodnex_sub');

    // We are not migrating all blocks.
    // Get the 'bid's of blocks that will not be migrated.
    $bids = array(53, 54, 55, 56, 57);

    // Set up a query for source data.
    $query = Database::getConnection('default', 'ulearn_d6')
      ->select('blocks', 'b')
      ->fields('b', array('bid', 'module', 'delta', 'status', 'weight', 'region', 'custom', 'visibility', 'pages', 'title', 'cache'));
    $query->join('boxes', 'bx', 'b.delta = bx.bid');
    $query->addField('bx', 'body');
    $query->addField('bx', 'info');
    $query->addField('bx', 'format');
    $query->condition('b.bid', $bids, 'NOT IN'); // These custom blocks will not be migrated.
    $query->orderBy('b.bid', 'ASC');
    $query->groupBy('b.delta');

    // Specify additional source fields.
    $source_fields = array();

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));
    // Set up our destination table - block_custom in this case.
    $this->destination = new MigrateDestinationTable('block');

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('module')->defaultValue('block');
    $this->addFieldMapping('theme')->defaultValue($default_theme);
    $this->addFieldMapping('delta', 'delta');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('weight', 'weight');
    $this->addFieldMapping('region', 'region');
    $this->addFieldMapping('custom', 'custom');
    $this->addFieldMapping('visibility', 'visibility');
    $this->addFieldMapping('pages', 'pages');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('cache', 'cache');

    // Unmapped source fields.
    $this->addUnmigratedSources(array('module', 'body', 'info', 'format'));
    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array('bid'));
  }

  public function prepareRow($current_row) {
    // Map regions.
    $current_row->region = ulearn_migrate_theme_region($current_row->region);
    return TRUE;
  }

  public function prepare($block, $row) {
    // Migrate images within content.
    $content = $row->body;
    $matches = array();
    preg_match('|<img [^>]*>|i', $content, $matches);
    foreach ($matches as $match) {
      $src_matches = array();
      if (preg_match('|src=[\'"]([^\'"]+)[\'"]|i', $match, $src_matches)) {
        $src = $src_matches[1];
        // Fetch the image from source.
        ulearn_migrate_fetch_image($src, $content);
      }
    }
    $row->body = $content;

    // Add the entries in block custom table and use
    // its primary key as 'delta' for 'block' table.
    $delta = db_insert('block_custom')
    ->fields(array(
      'body' => $row->body,
      'info' => $row->info,
      'format' => 'full_html',
    ))
    ->execute();
    $block->delta = $delta;
  }

  public function preRollback() {
    foreach ($this->map as $destination_key) {
      // Get the delta of this block.
      $delta = db_select('block', 'b')
        ->fields('b', array('delta'))
        ->condition('bid', $destination_key->destid1, '=')
        ->execute()
        ->fetchField();

      // Remove the entry from 'block_custom' table.
      $delete = db_delete('block_custom');
      $delete->condition('bid', $delta);
      $delete->execute();
    }
  }
}
