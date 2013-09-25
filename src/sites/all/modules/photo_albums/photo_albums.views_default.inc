<?php
/**
 * @file
 * photo_albums.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function photo_albums_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'album_views';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Album Views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '5';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Album Cover */
  $handler->display->display_options['relationships']['field_album_cover_target_id']['id'] = 'field_album_cover_target_id';
  $handler->display->display_options['relationships']['field_album_cover_target_id']['table'] = 'field_data_field_album_cover';
  $handler->display->display_options['relationships']['field_album_cover_target_id']['field'] = 'field_album_cover_target_id';
  $handler->display->display_options['relationships']['field_album_cover_target_id']['ui_name'] = 'Album Cover';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['relationship'] = 'field_album_cover_target_id';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_photo']['alter']['text'] = '<div class="album-info">
<div class="views-field-title">[title]</div>
<div class="views-field-photo"><a href="node/[nid]">[field_photo]</a></div>
</div>';
  $handler->display->display_options['fields']['field_photo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_photo']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => '125_125',
    'image_link' => '',
  );
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'album' => 'album',
  );

  /* Display: Albums pane */
  $handler = $view->new_display('panel_pane', 'Albums pane', 'albums_panel_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'ISTC-Social Photo Albums';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Albums Page */
  $handler = $view->new_display('page', 'Albums Page', 'albums_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'ISTC-Social Photo Albums';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'albums';

  /* Display: Albums Block */
  $handler = $view->new_display('block', 'Albums Block', 'albums_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Photos';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More albums>>';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Promoted to front page */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'node';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
  $handler->display->display_options['sorts']['promote']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $export['album_views'] = $view;

  $view = new view();
  $view->name = 'photo_albums';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Albums';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No photos have been added to this album.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => '150_150',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Contextual filter: Content: Album (field_photo_album) */
  $handler->display->display_options['arguments']['field_photo_album_target_id']['id'] = 'field_photo_album_target_id';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['table'] = 'field_data_field_photo_album';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['field'] = 'field_photo_album_target_id';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_photo_album_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['validate_options']['types'] = array(
    'album' => 'album',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'photo' => 'photo',
  );

  /* Display: Reorder Photos pane */
  $handler = $view->new_display('panel_pane', 'Reorder Photos pane', 'reorder_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Reorder Photos';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => '125_125',
    'image_link' => '',
  );
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_photo_album_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Album (field_photo_album)',
    ),
  );

  /* Display: Edit Captions pane */
  $handler = $view->new_display('panel_pane', 'Edit Captions pane', 'captions_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Edit Captions';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_photo' => 'field_photo',
    'title' => 'field_photo',
    'field_photo_caption' => 'field_photo_caption',
    'field_photo_description' => 'field_photo_caption',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_photo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_photo_caption' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'field_photo_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Save changes by clicking outside of text box.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_photo']['alter']['path'] = 'node/[nid]/edit';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => '125_125',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[Edit]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/edit';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Caption */
  $handler->display->display_options['fields']['field_photo_caption']['id'] = 'field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['table'] = 'field_data_field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['field'] = 'field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['label'] = 'Caption/Description';
  $handler->display->display_options['fields']['field_photo_caption']['type'] = 'editable';
  $handler->display->display_options['fields']['field_photo_caption']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_photo_description']['id'] = 'field_photo_description';
  $handler->display->display_options['fields']['field_photo_description']['table'] = 'field_data_field_photo_description';
  $handler->display->display_options['fields']['field_photo_description']['field'] = 'field_photo_description';
  $handler->display->display_options['fields']['field_photo_description']['type'] = 'editable';
  $handler->display->display_options['fields']['field_photo_description']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'photo_albums:reorder_pane';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_photo_album_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Album (field_photo_album)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Galleriffic pane */
  $handler = $view->new_display('panel_pane', 'Galleriffic pane', 'gallerific_pane');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_galleriffic';
  $handler->display->display_options['style_options']['delay'] = '5000';
  $handler->display->display_options['style_options']['preload'] = '12';
  $handler->display->display_options['style_options']['numbthumbs'] = '12';
  $handler->display->display_options['style_options']['pager_top'] = 'true';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'gallerifficfields';
  $handler->display->display_options['row_options']['slide_field'] = 'field_photo_1';
  $handler->display->display_options['row_options']['thumbnail_field'] = 'field_photo';
  $handler->display->display_options['row_options']['title_field'] = 'field_photo_caption';
  $handler->display->display_options['row_options']['description_field'] = 'field_photo_2';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['label'] = 'Thumbnail';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => '75_75',
    'image_link' => '',
  );
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo_1']['id'] = 'field_photo_1';
  $handler->display->display_options['fields']['field_photo_1']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo_1']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo_1']['label'] = 'Image';
  $handler->display->display_options['fields']['field_photo_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_1']['settings'] = array(
    'image_style' => '750_750',
    'image_link' => '',
  );
  /* Field: Content: Caption */
  $handler->display->display_options['fields']['field_photo_caption']['id'] = 'field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['table'] = 'field_data_field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['field'] = 'field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['label'] = '';
  $handler->display->display_options['fields']['field_photo_caption']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_photo_description']['id'] = 'field_photo_description';
  $handler->display->display_options['fields']['field_photo_description']['table'] = 'field_data_field_photo_description';
  $handler->display->display_options['fields']['field_photo_description']['field'] = 'field_photo_description';
  $handler->display->display_options['fields']['field_photo_description']['label'] = '';
  $handler->display->display_options['fields']['field_photo_description']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo_2']['id'] = 'field_photo_2';
  $handler->display->display_options['fields']['field_photo_2']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo_2']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo_2']['label'] = 'Description and Download - Overridden';
  $handler->display->display_options['fields']['field_photo_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_photo_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_2']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_photo_2']['settings'] = array(
    'text' => 'Download full-size',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'photo_albums:reorder_pane';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_photo_album_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Album (field_photo_album)',
    ),
  );

  /* Display: Cover Selection entity reference */
  $handler = $view->new_display('entityreference', 'Cover Selection entity reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_photo_caption' => 'field_photo_caption',
    'field_photo' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_photo' => 'field_photo',
    'title' => 'title',
    'field_photo_caption' => 'field_photo_caption',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Caption */
  $handler->display->display_options['fields']['field_photo_caption']['id'] = 'field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['table'] = 'field_data_field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['field'] = 'field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['label'] = '';
  $handler->display->display_options['fields']['field_photo_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Album (field_photo_album) */
  $handler->display->display_options['arguments']['field_photo_album_target_id']['id'] = 'field_photo_album_target_id';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['table'] = 'field_data_field_photo_album';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['field'] = 'field_photo_album_target_id';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_photo_album_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_photo_album_target_id']['validate_options']['types'] = array(
    'album' => 'album',
  );
  $export['photo_albums'] = $view;

  return $export;
}
