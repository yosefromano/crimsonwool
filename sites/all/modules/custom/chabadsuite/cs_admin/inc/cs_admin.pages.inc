<?php

/**
 * Page callback for the CS admin page
 */
function cs_admin_main_page($form, &$form_state) {
  $form = array();

  $form['row-open'] = array(
    '#markup' => '<div class="row">',
  );

  // Content
  if (user_access('access content overview')) {
    $form['content'] = array(
      '#type' => 'fieldset',
      '#title' => t('Content'),
      '#description' => t("Manage your site's content"),
    );

    $form['content']['manage'] = array(
      '#markup' => l(t('Manage Content'), 'admin/content', array(
        'attributes' => array(
          'class' => array('button-blue', 'waves-button', 'waves-effect', 'waves-float', 'waves-classic'),
        )
      )),
    );
  }

  // Users
  if (user_access('access users overview')) {
    $form['users'] = array(
      '#type' => 'fieldset',
      '#title' => t('People'),
      '#description' => t("Manage your site's users"),
    );

    $form['users']['manage'] = array(
      '#markup' => l(t('Manage Users'), 'admin/people', array(
        'attributes' => array(
          'class' => array('button-blue', 'waves-button', 'waves-effect', 'waves-float', 'waves-classic'),
        )
      )),
    );
  }

  // Menus
  if (user_access('administer main-menu menu items')) {
    $form['menus'] = array(
      '#type' => 'fieldset',
      '#title' => t('Menus'),
      '#description' => t("Manage your site's menus"),
    );

    $form['menus']['manage'] = array(
      '#markup' => l(t('Manage Menus'), 'admin/people', array(
        'attributes' => array(
          'class' => array('button-blue', 'waves-button', 'waves-effect', 'waves-float', 'waves-classic'),
        )
      )),
      '#suffix' => '</div>',
    );
  }

  $form['row-close'] = array(
    '#markup' => '</div>',
  );

  // Clear caches
  $form['cache'] = array(
    '#type' => 'fieldset',
    '#title' => t('Clear caches'),
    '#description' => t("If something appears to not be working correctly, clearing the caches can sometimes help"),
  );

  $form['cache']['clear'] = array(
    '#type' => 'button',
    '#value' => 'Clear caches',
    '#prefix' => '<div id="admin-cache-wrapper">',
    '#suffix' => '</div>',
    '#ajax' => array(
      'callback' => 'cs_admin_clear_caches',
      'wrapper' => 'admin-cache-wrapper',
    ),
  );

  return $form;
}

function cs_admin_clear_caches($form, $form_state) {
  drupal_flush_all_caches();
  return '<div class="messages status">Cleared caches</div>';
}
