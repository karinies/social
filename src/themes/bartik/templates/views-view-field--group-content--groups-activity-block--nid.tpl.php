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
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php 
  $nid = $row->nid;
//firep($nid, "nid");
  $node = node_load($nid);
  $format = 'm-d-Y H:i';
  $created = $node->created;
    //print ("created ". date($format, $created).'</br>');
  $updated = $node->changed;
    //print ("updated ". date($format, $updated).'</br>');
  $lastcomment = $node->last_comment_timestamp;
    //print ("commented ". date($format, $lastcomment).'</br>');
  if ($updated > $created) {
      if ($updated > $lastcomment) {
          print("UDPATED");
      } else {
          print ("NEW COMMENT");
      }
  } else {
      if ($lastcomment > $created) {
          print("NEW COMMENT");
      } else {
          print ("NEW CONTENT");
      }
  }
?>
