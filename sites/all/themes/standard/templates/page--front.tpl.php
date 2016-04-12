<!--.page -->
<div role="document" class="page"> 
  <!--.l-header region -->
  <header role="banner" class="l-header">
    <?php if ($top_bar): ?>
    <!--.top-bar -->
    <?php if ($top_bar_classes): ?>
    <div class="<?php print $top_bar_classes; ?>">
      <?php endif; ?>
 
     

	<nav class="top-bar" <?php print $top_bar_options; ?>>
		 <div class="bh">ב"ה</div>	  
         <ul class="title-area">
		  <li class="name">
			  <?php if ($linked_logo):?> <div class="thelogo"><?php  print $linked_logo; endif; ?></div>
		  </li>	  
		  <li class="toggle-topbar menu-icon"><a href="#"><span><?php print $top_bar_menu_text; ?></span></a></li>
        </ul>
        <section class="top-bar-section">
          <?php if ($top_bar_main_menu) :?>
          <?php print $top_bar_main_menu; ?>
          <?php endif; ?>
          <?php if ($top_bar_secondary_menu) :?>
          <?php print $top_bar_secondary_menu; ?>
          <?php endif; ?>
        </section>
      </nav>

      <?php if ($top_bar_classes): ?>
   </div>
   
    <?php endif; ?>
    <!--/.top-bar -->
    <?php endif; ?>
    
    <!-- Title, slogan and menu -->
    <?php if ($alt_header): ?>
    <section class="row <?php print $alt_header_classes; ?>">
      <?php if ($linked_logo): print $linked_logo; endif; ?>
      <?php if ($site_name): ?>
      <?php if ($title): ?>
      <div id="site-name" class="element-invisible"> <strong> <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a> </strong> </div>
      <?php else: /* Use h1 when the content title is empty */ ?>
      <h1 id="site-name"> <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a> </h1>
      <?php endif; ?>
      <?php endif; ?>
      <?php if ($site_slogan): ?>
      <h2 title="<?php print $site_slogan; ?>" class="site-slogan"><?php print $site_slogan; ?></h2>
      <?php endif; ?>
      <?php if ($alt_main_menu): ?>
      <nav id="main-menu" class="navigation" role="navigation"> <?php print ($alt_main_menu); ?> </nav>
      <!-- /#main-menu -->
      <?php endif; ?>
      <?php if ($alt_secondary_menu): ?>
      <nav id="secondary-menu" class="navigation" role="navigation"> <?php print $alt_secondary_menu; ?> </nav>
      <!-- /#secondary-menu -->
      <?php endif; ?>
    </section>
    <?php endif; ?>
    <!-- End title, slogan and menu -->
    
    <?php if (!empty($page['header'])): ?>
    <!--.l-header-region -->
    <section class="l-header-region row">
      <div class="large-12 columns"> <?php print render($page['header']); ?></div>
    </section>
    <!--/.l-header-region -->
    <?php endif; ?>
  </header>
  <?php if (!empty($page['meerkat'])): ?>
    <div class="meerkat"> <?php print render($page['meerkat']); ?> <a href="#" class="close-meerkat">X</a></div>
    <?php endif; ?>
  <?php if (!empty($page['homepage_image'])): ?>
  <div class="homepage-image">
   
    <?php print render($page['homepage_image']); ?></div>
  <?php endif; ?>
  <div class="columns hpslideshow">

    <?php if (!empty($page['slideshow'])): ?>
    <?php print render($page['slideshow']); ?>
    <?php endif; ?>
  </div>
  <!--/.l-header -->
  
  <?php if (!empty($page['featured'])): ?>
  <!--/.featured -->
  <section class="l-featured row">
    <div class="large-12 columns"> <?php print render($page['featured']); ?> </div>
  </section>
  <!--/.l-featured -->
  <?php endif; ?>
  <?php if ($messages && !$zurb_foundation_messages_modal): ?>
  <!--/.l-messages -->
  <section class="l-messages row">
    <div class="large-12 columns">
      <?php if ($messages): print $messages; endif; ?>
    </div>
  </section>
  <!--/.l-messages -->
  <?php endif; ?>
  <div class="white-bg">
    <?php if (!empty($page['help'])): ?>
    <!--/.l-help -->
    <section class="l-help row">
      <div class="large-12 columns"> <?php print render($page['help']); ?> </div>
    </section>
  </div>
  <!--/.l-help -->
  <?php endif; ?>
  <main role="main" class="row l-main maincontent">
    <div class="<?php print $main_grid; ?> main columns">
      <?php if (!empty($page['highlighted'])): ?>
      <div class="highlight panel callout"> <?php print render($page['highlighted']); ?> </div>
      <?php endif; ?>
      <a id="main-content"></a>
      <?php if ($breadcrumb): print $breadcrumb; endif; ?>
      <?php if ($title && !$is_front): ?>
      <?php print render($title_prefix); ?>
      <h1 id="page-title" class="title"><?php print $title; ?></h1>
      <?php print render($title_suffix); ?>
      <?php endif; ?>
      <?php if (!empty($tabs)): ?>
      <?php print render($tabs); ?>
      <?php if (!empty($tabs2)): print render($tabs2); endif; ?>
      <?php endif; ?>
      <?php if ($action_links): ?>
      <ul class="action-links">
        <?php print render($action_links); ?>
      </ul>
      <?php endif; ?>
      <?php print render($page['content']); ?> </div>
    <!--/.main region -->
    <?php if (!empty($page['under_content'])): ?>
    <div class="row undercontent"> <?php print render($page['under_content']); ?> </div>
    <?php endif; ?>
    <?php if (!empty($page['sidebar_first'])): ?>
    <aside role="complementary" class="<?php print $sidebar_first_grid; ?> sidebar-first columns sidebar"> <?php print render($page['sidebar_first']); ?> </aside>
    <?php endif; ?>
    <?php if (!empty($page['sidebar_second'])): ?>
    <aside role="complementary" class="<?php print $sidebar_sec_grid; ?> sidebar-second columns sidebar"> <?php print render($page['sidebar_second']); ?> </aside>
    <?php endif; ?>
  </main>
  <!--/.main-->
  
  <?php if (!empty($page['triptych_first']) || !empty($page['triptych_middle']) || !empty($page['triptych_last'] ) || !empty($page['single_one'])  || !empty($page['double_one'])): ?>
  <!--.triptych-->
  <div class="light-blue-bg">
      <div class="social">
        <div class="newsletter-signup">
          <div class="signup-blurb"></div>
          <a href="#" data-reveal-id="myModal2" class="emaillink">
          <i class="fa fa-envelope"></i>
          </a>
        <?php if (!empty($page['social'])): ?>
  	  <div class="socialicons">
        <?php print render($page['social']); ?>
        </div>
        <?php endif; ?>
      </div></div>
    <div class="row">
		    <h1 class="hp-sitename">
		      <?php
		$site_name = variable_get('site_name');
		echo $site_name;
		?>
		    </h1>
		    <h1 class="hp-slogan large-12">
		      <?php
		$site_slogan = variable_get('site_slogan');
		echo $site_slogan;
		?>
		    </h1>
			<hr>
			</div>
      <div class="triptych-first_header-1 large-12 "> <?php print render($page['triptych_header_1']); ?> </div>
    <section class="l-triptych row">
      <div class="triptych-first large-4 columns"> <?php print render($page['triptych_first']); ?> </div>
      <div class="triptych-middle large-4 columns"> <?php print render($page['triptych_middle']); ?> </div>
      <div class="triptych-last large-4 columns"> <?php print render($page['triptych_last']); ?> </div>
	  </section>
	  <section class="l-triptych2 row">
      <div class="single large-4 columns"> <?php print render($page['single_one']); ?> </div>
      <div class="double large-8 columns"> <?php print render($page['double_one']); ?> </div>
	  </section>
  </div>
    <?php endif; ?>

    <?php if (!empty($page['triptych_icon1']) || !empty($page['triptych_icon2']) || !empty($page['triptych_icon3'] )): ?>

  <div class="icon_ctas">
    <section class="l-triptych row">
      <div class="triptych-first large-4 columns small-4"> <?php print render($page['triptych_icon1']); ?> </div>
      <div class="triptych-middle large-4 columns small-4"> <?php print render($page['triptych_icon2']); ?> </div>
      <div class="triptych-last large-4 columns small-4"> <?php print render($page['triptych_icon3']); ?> </div>
    </section>
  </div>
    <?php endif; ?>
  <!--/.triptych -->
  
<?php if (!empty($page['triptych_first_2']) || !empty($page['triptych_middle_2']) || !empty($page['triptych_last_2'])): ?>
		
  <div class="third-row-ctas">
    <div class="row">
      <div class="triptych-first_header large-12 "> <?php print render($page['triptych_header']); ?> </div>
    </div>
    <section class="l-triptych row">
      <div class="triptych-first large-4 columns"> <?php print render($page['triptych_first_2']); ?> </div>
      <div class="triptych-middle large-4 columns"> <?php print render($page['triptych_middle_2']); ?> </div>
      <div class="triptych-last large-4 columns"> <?php print render($page['triptych_last_2']); ?> </div>
    </section>
  </div>
  
  <?php endif; ?>
  
  <!--.l-footer-->
  <footer class="l-footer panel " role="contentinfo">
    <?php if (!empty($page['footer'])): ?>
    <div class="footer large-12 columns"> <?php print render($page['footer']); ?> </div>
    <?php endif; ?>

    <?php if (!empty($page['footer_firstcolumn']) || !empty($page['footer_secondcolumn']) || !empty($page['footer_thirdcolumn']) || !empty($page['footer_fourthcolumn'])): ?>
      <!--.footer-columns -->
      <section class="row l-footer-columns">
        <?php if (!empty($page['footer_firstcolumn'])): ?>
          <div class="footer-first large-3 columns">
            <?php print render($page['footer_firstcolumn']); ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($page['footer_secondcolumn'])): ?>
          <div class="footer-second large-3 columns">
            <?php print render($page['footer_secondcolumn']); ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($page['footer_thirdcolumn'])): ?>
          <div class="footer-third large-3 columns">
            <?php print render($page['footer_thirdcolumn']); ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($page['footer_fourthcolumn'])): ?>
          <div class="footer-fourth large-3 columns">
            <?php print render($page['footer_fourthcolumn']); ?>
          </div>
        <?php endif; ?>
      </section>
      <!--/.footer-columns-->
    <?php endif; ?>
	
    <?php if ($site_name) :?>
    <div class="copyright row"> &copy; <?php print date('Y') . ' ' . check_plain($site_name) . ' ' . t('All rights reserved.'); ?> </div>
    <?php endif; ?>
  </footer>
  <!--/.footer-->
  
  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>
</div>

<div id="myModal2" class="reveal-modal tiny">
  <?php
$node_webform = node_load(8);
// Get form.
$form = drupal_get_form(
  'webform_client_form_' . $node_webform->nid,
  $node_webform,
  array(),
  TRUE,
  FALSE
);
// Render form.
print render($form);
?>
</div>
<!--/.page --> 
