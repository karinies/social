<?php
/**
 * @file
 * photo_albums.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function photo_albums_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function photo_albums_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function photo_albums_image_default_styles() {
  $styles = array();

  // Exported image style: 125_125.
  $styles['125_125'] = array(
    'name' => '125_125',
    'effects' => array(
      24 => array(
        'label' => 'Crop and scale manually',
        'help' => 'Crop and scale a user-selected area, respecting the ratio of the destination width and height.',
        'effect callback' => 'manualcrop_crop_and_scale_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_and_scale_form',
        'summary theme' => 'manualcrop_crop_and_scale_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => '125',
          'height' => '125',
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => '125_125',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: 750_750.
  $styles['750_750'] = array(
    'name' => '750_750',
    'effects' => array(
      20 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '750',
          'height' => '750',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: 75_75.
  $styles['75_75'] = array(
    'name' => '75_75',
    'effects' => array(
      25 => array(
        'label' => 'Crop and scale manually',
        'help' => 'Crop and scale a user-selected area, respecting the ratio of the destination width and height.',
        'effect callback' => 'manualcrop_crop_and_scale_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_and_scale_form',
        'summary theme' => 'manualcrop_crop_and_scale_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => '75',
          'height' => '75',
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => '75_75',
        ),
        'weight' => '-11',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function photo_albums_node_info() {
  $items = array(
    'album' => array(
      'name' => t('Album'),
      'base' => 'node_content',
      'description' => t('Collection of Photos'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'photo' => array(
      'name' => t('Photo'),
      'base' => 'node_content',
      'description' => t('Photo for ISTC photo albums'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
