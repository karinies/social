<?php
/**
 * @file
 * photo_albums.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function photo_albums_user_default_permissions() {
  $permissions = array();

  // Exported permission: bulk upload media.
  $permissions['bulk upload media'] = array(
    'name' => 'bulk upload media',
    'roles' => array(
      0 => 'Admin',
      1 => 'Super Admin',
      2 => 'authenticated user',
    ),
    'module' => 'bulk_media_upload',
  );

  // Exported permission: create album content.
  $permissions['create album content'] = array(
    'name' => 'create album content',
    'roles' => array(
      0 => 'Super Admin',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create photo content.
  $permissions['create photo content'] = array(
    'name' => 'create photo content',
    'roles' => array(
      0 => 'Admin',
      1 => 'Super Admin',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any album content.
  $permissions['delete any album content'] = array(
    'name' => 'delete any album content',
    'roles' => array(
      0 => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any photo content.
  $permissions['delete any photo content'] = array(
    'name' => 'delete any photo content',
    'roles' => array(
      0 => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own album content.
  $permissions['delete own album content'] = array(
    'name' => 'delete own album content',
    'roles' => array(
      0 => 'Super Admin',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own photo content.
  $permissions['delete own photo content'] = array(
    'name' => 'delete own photo content',
    'roles' => array(
      0 => 'Super Admin',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any album content.
  $permissions['edit any album content'] = array(
    'name' => 'edit any album content',
    'roles' => array(
      0 => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any photo content.
  $permissions['edit any photo content'] = array(
    'name' => 'edit any photo content',
    'roles' => array(
      0 => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own album content.
  $permissions['edit own album content'] = array(
    'name' => 'edit own album content',
    'roles' => array(
      0 => 'Super Admin',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own photo content.
  $permissions['edit own photo content'] = array(
    'name' => 'edit own photo content',
    'roles' => array(
      0 => 'Super Admin',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
