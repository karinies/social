<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *-
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php 
  $album_title = $row->node_title;
  $album_nid = $row->nid;
  $photo_output = $output;
  
  // pick an album cover if none was set
  if (!$row->node_field_data_field_album_cover_nid) {
      // find one image in this album
      $sql = "SELECT  entity.entity_id AS entity_id, entity.field_photo_album_target_id AS field_album_cover_target_id
              FROM {field_data_field_photo_album} entity 
              WHERE (field_photo_album_target_id=$album_nid)
              LIMIT 1
              ";
      $photo_nid = 0;
      $results = db_query($sql);
      foreach ($results as $result) {
          $photo_nid = $result->entity_id;
      } 
      if ($photo_nid != 0) {  // album was not empty
          $photo = node_load($photo_nid);
          $photo_output = ( theme('image_style', array('style_name' => '125_125', 'path' => $photo->field_photo['und']['0']['uri'])) );
      }
  }
?>
<div class="album-info">
<div class="views-field-title"><a href="node/<?php print $album_nid?>"><?php print $album_title?></div>
<div class="views-field-photo"><a href="node/<?php print $album_nid?>"><?php print $photo_output?></a></div>
</div>
