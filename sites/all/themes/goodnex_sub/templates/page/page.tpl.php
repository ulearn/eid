<?php ?>
<head>
<!-- Put Scripts Here -->
<link rel="publisher" href=" https://plus.google.com/u/0/112298331569691583207/about"/>
<script type="text/javascript" async defer
src="http://www.ulearnschool.com/blog/?ai1ec_super_widget"></script>

<script type="text/javascript" async defer
  src="https://apis.google.com/js/platform.js?publisherid=112298331569691583207">
</script>

</head>

<div id="wrapper">
<header id="header">
<div class="container">
<div id="top-bar">
<div class="eight columns">
<?php if (isset($page['header_top_left'])) : ?>
<?php print render($page['header_top_left']); ?>
<?php endif; ?>
</div>
<div class="eight columns">
<?php print render($page['header_top_right']); ?>
</div>
</div>
<div class="eight columns">
<?php if (isset($page['header_left'])) : ?>
<?php print render($page['header_left']); ?>
<?php endif; ?>
<?php if ($logo): ?>
<h1 class="logo">
<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
</a>
</h1>
<?php endif; ?>
<?php if ($site_name || $site_slogan): ?>
<div id="name-and-slogan"<?php if ($disable_site_name && $disable_site_slogan) { print ' class="hidden"'; } ?>>
<?php if ($site_name): ?>
<h1 id="site-name"<?php if ($disable_site_name) { print ' class="hidden"'; } ?>>
<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
</h1>
<?php endif; ?>
<?php if ($site_slogan): ?>
<div id="site-slogan"<?php if ($disable_site_slogan) { print ' class="hidden"'; } ?>>
<?php print $site_slogan; ?>
</div>
<?php endif; ?>
</div> <!-- /#name-and-slogan -->
<?php endif; ?>
</div>
<div class="eight columns">
<?php print render($page['header_right']); ?>  
</div>  
<div class="clear"></div>
<div class="sixteen columns">
<div class="menu-container clearfix">
<nav id="navigation" class="navigation">
<div class="menu">
<?php print render($page['header_menu']); ?>
</div>  
</nav>
<?php if ( ($page['header_search']) ): ?>
<div class="search-wrapper">
<?php print render($page['header_search']); ?>
</div><!--/ .search-wrapper--> 
<?php endif; ?>
</div>
</div>
</div>  				
</header>
<!-- Slider -->
<section id="slider-home">
<div class="fullwidthbanner-container">
<?php print render($page['slider-home']); ?>
</div>
</section>
<!-- End Slider -->
<?php print render($page['before_content_no_wrap']); ?>
<section id="content">
<div class="container">
<?php if ($title) : ?>
<div class="page-header clearfix">
<?php if ( ($breadcrumb) AND (theme_get_setting('breadcrumbs') == '1') ): ?>
<div id="breadcrumbs"><?php print $breadcrumb; ?> </div>	
<?php endif; ?>
<h1 class="alignleft"><?php print $title; ?></h1>
</div><!--/ .page-header-->
<?php endif; ?>
<?php print render($page['before_content']); ?>
<?php if ( ($page['sidebar_left']) ) : ?>
<aside id="sidebar" class="four columns">
<?php print render($page['sidebar_left']); ?>
</aside>
<?php endif; ?>
<?php if ( ($page['sidebar_right']) AND ($page['sidebar_left']) ): ?>
<section id="main" class="eight columns">
<?php endif; ?>
<?php if ( (($page['sidebar_right']) AND (!$page['sidebar_left'])) OR ($page['sidebar_left']) AND (!$page['sidebar_right']) ): ?>
<section id="main" class="eleven columns">
<?php endif; ?>
<?php print $messages; ?>
<?php if ($tabs = render($tabs)): ?>
<div id="drupal_tabs" class="tabs">
<?php print render($tabs); ?>
</div>
<?php endif; ?>
<?php print render($page['help']); ?>
<?php if ($action_links): ?>
<ul class="action-links">
<?php print render($action_links); ?>
</ul>
<?php endif; ?>
<?php if (isset($page['content'])) { print render($page['content']); } ?>
<div id="after-content">  <?php print render($page['after_content']); ?>
</div> 
<?php if ( ($page['sidebar_right']) OR ($page['sidebar_left']) ): ?>
</section>
<?php endif; ?>
<?php if ( ($page['sidebar_right']) ) : ?>
<aside id="sidebar" class="five columns">
<?php print render($page['sidebar_right']); ?>
</aside>
<?php endif; ?>
</div>
</section> 
<?php print render($page['after_content_no_wrap']); ?>
<!-- Combined Footer -->
<footer id="footer">
<div class="container">
<div class="four columns">
<?php if (isset($page['footer_1'])) : ?>
<?php print render($page['footer_1']); ?>
<?php endif; ?>
</div>
<div class="four columns">
<?php if (isset($page['footer_2'])) : ?>
<?php print render($page['footer_2']); ?>
<?php endif; ?>
</div>
<div class="four columns">
<?php if (isset($page['footer_3'])) : ?>
<?php print render($page['footer_3']); ?>
<?php endif; ?>
</div>
<div class="four columns">
<?php if (isset($page['footer_4'])) : ?>
<?php print render($page['footer_4']); ?>
<?php endif; ?>
</div>
<div class="clear"></div>
<div class="sixteen columns">
<div class="adjective clearfix">
<div id="back-to-top">
<a href="#top">Top</a>
</div>
<div class="copyright"><?php print render($page['footer_bottom']); ?></div>
<div class="social-icons clearfix">
<?php print render($page['footer_social']); ?>
</div>
</div>
</div>
</div>  
</footer>
</div>
<div style="display:none">
<!-- Google Code for Remarketing Tag -->
<!--------------------------------------------------
Remarketing tags may not be associated with personally identifiable information or placed on pages related to sensitive categories. See more information and instructions on how to setup the tag on: http://google.com/ads/remarketingsetup
--------------------------------------------------->
<script type="text/javascript">
/* <![CDATA[ */
var google_conversion_id = 1040131113;
var google_custom_params = window.google_tag_params;
var google_remarketing_only = true;
/* ]]> */
</script>
<script type="text/javascript" src="//www.googleadservices.com/pagead/conversion.js">
</script>
<noscript>
<div style="display:inline;">
<img height="1" width="1" style="border-style:none;" alt="" src="//googleads.g.doubleclick.net/pagead/viewthroughconversion/1040131113/?value=0&amp;guid=ON&amp;script=0"/>
</div>
</noscript>
</div>