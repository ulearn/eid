<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $caption : The caption of this table.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<table <?php if ($classes) : print 'class="'. $classes . '" '; endif; ?><?php print $attributes; ?>>
  <?php if (!empty($caption)) : ?>
    <caption><?php print $caption; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        <?php if (!isset($header_columns[$field])): ?>
        <th <?php ($header_classes[$field]) ? print 'class="'. $header_classes[$field] . '" ' : "";?>>
          <?php print $label; ?>
        </th>
        <?php else: ?>
        <td></td>
        <?php endif; ?>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?>">
        <?php foreach ($row as $field => $content): ?>
          <?php if (isset($header_columns[$field])) {
            $row_element = 'th';
          }
          else {
            $row_element = 'td';
          }
          ?><<?php print $row_element;?> <?php if ($field_classes[$field][$count]) : print 'class="'. $field_classes[$field][$count] . '" '; endif; ?><?php print drupal_attributes($field_attributes[$field][$count]); ?>>
            <?php print $content; ?>
          </<?php print $row_element;?>>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
  <?php // @todo add tfoot ?>
</table>
