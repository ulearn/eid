
	<div id="wrap">
		<!-- Header -->
		<header id="header" class="clearfix">
			<div class="container clearfix">
				<div id="top-bar" class="clearfix">
					<div class="info clearfix">
					    
						<?php print render($page['header_top_left']); ?>
					</div>

					<div class="flags clearfix">
					
					<?php print render($page['header_top_right']); ?>
					</div>
				</div>
             
				<div id="logo">
					 <?php if ($logo): ?>
						<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
							<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
						</a>
					<?php endif; ?>
				</div>

				<nav id="nav">
				  <?php print render($page['header_menu']); ?>
				</nav>
			</div>
		</header>
		<!-- End Header -->

		<!-- Slider -->
	    <section id="slider-home">
	        <div class="fullwidthbanner-container">
	           <?php print render($page['slideshow']); ?>
	       </div>
	    </section>
	    <!-- End Slider -->


		<!-- Content -->
		<section id="content">
			<div class="container clearfix">
				<!-- Services -->
				<div class="row services mb10">
					 <?php print render($page['highlighted']); ?>
				</div>
				<!-- End Services -->

				<!-- Recent Works -->
				
			        <?php print render($page['featured']); ?>
				
				<!-- End Recent Works -->

				<div class="row">
					<!-- Recent Posts -->
					<div class="four column">
						 <?php print render($page['triptych_first']); ?>
					</div>
					<!-- End Recent Posts -->

					<!-- Our Clients -->
					<div class="four column">

                              <?php print render($page['triptych_middle']); ?>
						
					</div>
					<!-- End Our Clients -->

					<!-- Client Testimonials -->
					<div class="four column">
					   
						<?php print render($page['triptych_last']); ?>
			            
					</div>
					<!-- End Client Testimonials -->
				</div>
			</div>
		</section>
		<!-- End Content -->

	  	<!-- Footer -->
		<footer id="footer">
			<div class="container clearfix">
				<ul class="no-bullet clearfix p0 row">
					<li class="widget subscribe three column">
					
					   <?php print render($page['footer_firstcolumn']); ?>
					  
					</li>

					<li class="widget flickr three column">
						
						<?php print render($page['footer_secondcolumn']); ?>
					</li>

					<li class="widget about-us three column">
						<?php print render($page['footer_thirdcolumn']); ?>
					</li>

					<li class="widget contact-us three column">
					<?php print render($page['footer_fourthcolumn']); ?>
					</li>
				</ul>

				<div id="back-to-top">
					<a href="#top">Top</a>
				</div>

				<div class="copyright"><?php print render($page['footer']); ?></div>

				<div class="social-icons clearfix">
					<?php print render($page['footer_social']); ?>
				</div>
			</div>
		</footer>
		<!-- End Footer -->
	</div>
	<!-- End Wrap -->

