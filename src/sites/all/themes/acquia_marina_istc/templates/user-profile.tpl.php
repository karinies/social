<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 */
?>
<div class="profile"<?php print $attributes; ?>>
  <?php
    $uid = arg(1);
    $user = user_load($uid);    
    $myprofile = 'profile_info';
    $profile = profile2_load_by_user($uid, $myprofile);
  ?>
  <?php 
  if ($user->picture) { 
  ?>
  <div class="profile-picture">
    <?php echo theme('image_style', array('style_name' => 'large', 'path' => $user->picture->uri)); ?>
  </div>
  <?php } ?> 
    
  <?php 
  if ($profile->field_affiliation) { 
    $affiliation =  $profile->field_affiliation['und'][0]['title'];
    $affiliation_url =  $profile->field_affiliation['und'][0]['url']; 
  ?>
  <div class="profile-affiliation"><h2>
    <?php print l(t($affiliation), $affiliation_url, array('attributes' => array('target'=>'_blank'))); ?>
  </div></h2>
  <?php } ?>

  <?php 
    if ($profile->field_website) { 
      $website =  $profile->field_website['und'][0]['url'];
  ?>
  <div class="profile-website">
    <?php print l(t($website), $website, array('attributes' => array('target'=>'_blank'))); ?>
  </div>
  <?php } ?>
    
  <?php 
    if ($profile->field_bio) { 
      $bio =  $profile->field_bio['und'][0]['value'];
  ?>   
  <div class="profile-bio">
    <?php print $bio;?>
  </div>
  <?php } ?>
      
  <?php if (user_authenticated()) {?>  
    <div class="profile-blog">
      <?php print render($user_profile['summary']['blog']['#markup']); ?>
    </div>
  
    <div class="profile-groups">
      <div class="groups-label">Groups:</div>
      <div class="groups-content">
        <?php {print render($user_profile['og_group_ref']);} ?>
      </div>
    </div>
  <?php } ?>
      


  <?php /*print '<PRE>'; print_r($user_profile); print '</PRE>';*/?>

</div>
