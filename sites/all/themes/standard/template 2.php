<?php

function myfctheme_preprocess_block(&$variables)
{

  // For bean blocks.

  if ($variables['block']->module == 'bean')
{

    // Get the bean elements.

    $beans =
$variables['elements']['bean'];

    // There is only 1 bean per
block.

    $bean_keys =
element_children($beans);

    $bean =
$beans[reset($bean_keys)];

    // Add bean type classes to the
block.

    $variables['classes_array'][] =
drupal_html_class('block-bean-' .
$bean['#bundle']);

    // Add template suggestions for bean
types.

    $variables['theme_hook_suggestions'][] =
'block__bean__' . $bean['#bundle'];

  }

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
