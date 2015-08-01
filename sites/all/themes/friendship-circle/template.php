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

?>