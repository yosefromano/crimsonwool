<?php drupal_add_js('sites/all/themes/friendship-circle/js/jquery.meerkat.1.3.js', 'file');
drupal_add_js("jQuery(document).ready(function($) {
$('.meerkat').meerkat({
    background: 'url(images/meerkat-bot-bg.png) repeat-x left top',
    height: '300px',
    width: '400px',
    position: 'right',
    close: '.close-meerkat',
    dontShowAgain: '.dont-show',
    animationIn: 'slide',
    animationSpeed: 500
});

});", array('type' => 'inline', 'scope' => 'footer', 'weight' => 16));

function myfctheme_theme() {
  $items = array();
    
  
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'myfctheme') . '/templates',
    'template' => 'user-login',
    'preprocess functions' => array(
       'myfctheme_preprocess_user_login'
    ),
	
  );

  $items['user_pass'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'myfctheme') . '/templates',
    'template' => 'user-pass',
    'preprocess functions' => array(
      'myfctheme_preprocess_user_pass'
    ),
	 
  );
  return $items;
  
}

/*function myfctheme_preprocess_user_login(&$vars) {
  $vars['intro_text'] = t('This is my awesome login form');
}

function myfctheme_preprocess_user_register_form(&$vars) {
  $vars['intro_text'] = t('This is my super awesome reg form');
}

function myfctheme_preprocess_user_pass(&$vars) {
  $vars['intro_text'] = t('This is my super awesome request new password form');
}
*/

?>
