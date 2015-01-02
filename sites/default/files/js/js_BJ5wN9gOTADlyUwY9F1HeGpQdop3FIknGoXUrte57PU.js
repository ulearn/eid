(function ($) {

/**
 * Attaches double-click behavior to toggle full path of Krumo elements.
 */
Drupal.behaviors.devel = {
  attach: function (context, settings) {

    // Add hint to footnote
    $('.krumo-footnote .krumo-call').before('<img style="vertical-align: middle;" title="Click to expand. Double-click to show path." src="' + Drupal.settings.basePath + 'misc/help.png"/>');

    var krumo_name = [];
    var krumo_type = [];

    function krumo_traverse(el) {
      krumo_name.push($(el).html());
      krumo_type.push($(el).siblings('em').html().match(/\w*/)[0]);

      if ($(el).closest('.krumo-nest').length > 0) {
        krumo_traverse($(el).closest('.krumo-nest').prev().find('.krumo-name'));
      }
    }

    $('.krumo-child > div:first-child', context).dblclick(
      function(e) {
        if ($(this).find('> .krumo-php-path').length > 0) {
          // Remove path if shown.
          $(this).find('> .krumo-php-path').remove();
        }
        else {
          // Get elements.
          krumo_traverse($(this).find('> a.krumo-name'));

          // Create path.
          var krumo_path_string = '';
          for (var i = krumo_name.length - 1; i >= 0; --i) {
            // Start element.
            if ((krumo_name.length - 1) == i)
              krumo_path_string += '$' + krumo_name[i];

            if (typeof krumo_name[(i-1)] !== 'undefined') {
              if (krumo_type[i] == 'Array') {
                krumo_path_string += "[";
                if (!/^\d*$/.test(krumo_name[(i-1)]))
                  krumo_path_string += "'";
                krumo_path_string += krumo_name[(i-1)];
                if (!/^\d*$/.test(krumo_name[(i-1)]))
                  krumo_path_string += "'";
                krumo_path_string += "]";
              }
              if (krumo_type[i] == 'Object')
                krumo_path_string += '->' + krumo_name[(i-1)];
            }
          }
          $(this).append('<div class="krumo-php-path" style="font-family: Courier, monospace; font-weight: bold;">' + krumo_path_string + '</div>');

          // Reset arrays.
          krumo_name = [];
          krumo_type = [];
        }
      }
    );
  }
};

})(jQuery);
;
(function($) {

Drupal.admin = Drupal.admin || {};
Drupal.admin.behaviors = Drupal.admin.behaviors || {};

/**
 * @ingroup admin_behaviors
 * @{
 */

/**
 * Apply active trail highlighting based on current path.
 *
 * @todo Not limited to toolbar; move into core?
 */
Drupal.admin.behaviors.toolbarActiveTrail = function (context, settings, $adminMenu) {
  if (settings.admin_menu.toolbar && settings.admin_menu.toolbar.activeTrail) {
    $adminMenu.find('> div > ul > li > a[href="' + settings.admin_menu.toolbar.activeTrail + '"]').addClass('active-trail');
  }
};

/**
 * @} End of "ingroup admin_behaviors".
 */

Drupal.admin.behaviors.shorcutcollapsed = function (context, settings, $adminMenu) {

  // Create the dropdown base 
  $("<li class=\"label\"><a>"+Drupal.t('Shortcuts')+"</a></li>").prependTo("body.menu-render-collapsed div.toolbar-shortcuts ul"); 

}

Drupal.admin.behaviors.shorcutselect = function (context, settings, $adminMenu) {

  // Create the dropdown base
  $("<select id='shortcut-menu'/>").appendTo("body.menu-render-dropdown div.toolbar-shortcuts");
    
  // Create default option "Select"
  $("<option />", {
    "selected"  :  "selected",
    "value"     :  "",
    "text"      :  Drupal.t('Shortcuts')
  }).appendTo("body.menu-render-dropdown div.toolbar-shortcuts select");
    
  // Populate dropdown with menu items
  $("body.menu-render-dropdown div.toolbar-shortcuts a").each(function() {
    var el = $(this);
    $("<option />", {
      "value"   :  el.attr("href"),
      "text"    :  el.text()
    }).appendTo("body.menu-render-dropdown div.toolbar-shortcuts select");
    });
    
  $("body.menu-render-dropdown div.toolbar-shortcuts select").change(function() {
    window.location = $(this).find("option:selected").val();
  });
  
  $('body.menu-render-dropdown div.toolbar-shortcuts ul').remove();

};

})(jQuery);
;
(function ($) {

/**
 * Toggle the visibility of a fieldset using smooth animations.
 */
Drupal.toggleFieldset = function (fieldset) {
  var $fieldset = $(fieldset);
  if ($fieldset.is('.collapsed')) {
    var $content = $('> .fieldset-wrapper', fieldset).hide();
    $fieldset
      .removeClass('collapsed')
      .trigger({ type: 'collapsed', value: false })
      .find('> legend span.fieldset-legend-prefix').html(Drupal.t('Hide'));
    $content.slideDown({
      duration: 'fast',
      easing: 'linear',
      complete: function () {
        Drupal.collapseScrollIntoView(fieldset);
        fieldset.animating = false;
      },
      step: function () {
        // Scroll the fieldset into view.
        Drupal.collapseScrollIntoView(fieldset);
      }
    });
  }
  else {
    $fieldset.trigger({ type: 'collapsed', value: true });
    $('> .fieldset-wrapper', fieldset).slideUp('fast', function () {
      $fieldset
        .addClass('collapsed')
        .find('> legend span.fieldset-legend-prefix').html(Drupal.t('Show'));
      fieldset.animating = false;
    });
  }
};

/**
 * Scroll a given fieldset into view as much as possible.
 */
Drupal.collapseScrollIntoView = function (node) {
  var h = document.documentElement.clientHeight || document.body.clientHeight || 0;
  var offset = document.documentElement.scrollTop || document.body.scrollTop || 0;
  var posY = $(node).offset().top;
  var fudge = 55;
  if (posY + node.offsetHeight + fudge > h + offset) {
    if (node.offsetHeight > h) {
      window.scrollTo(0, posY);
    }
    else {
      window.scrollTo(0, posY + node.offsetHeight - h + fudge);
    }
  }
};

Drupal.behaviors.collapse = {
  attach: function (context, settings) {
    $('fieldset.collapsible', context).once('collapse', function () {
      var $fieldset = $(this);
      // Expand fieldset if there are errors inside, or if it contains an
      // element that is targeted by the URI fragment identifier.
      var anchor = location.hash && location.hash != '#' ? ', ' + location.hash : '';
      if ($fieldset.find('.error' + anchor).length) {
        $fieldset.removeClass('collapsed');
      }

      var summary = $('<span class="summary"></span>');
      $fieldset.
        bind('summaryUpdated', function () {
          var text = $.trim($fieldset.drupalGetSummary());
          summary.html(text ? ' (' + text + ')' : '');
        })
        .trigger('summaryUpdated');

      // Turn the legend into a clickable link, but retain span.fieldset-legend
      // for CSS positioning.
      var $legend = $('> legend .fieldset-legend', this);

      $('<span class="fieldset-legend-prefix element-invisible"></span>')
        .append($fieldset.hasClass('collapsed') ? Drupal.t('Show') : Drupal.t('Hide'))
        .prependTo($legend)
        .after(' ');

      // .wrapInner() does not retain bound events.
      var $link = $('<a class="fieldset-title" href="#"></a>')
        .prepend($legend.contents())
        .appendTo($legend)
        .click(function () {
          var fieldset = $fieldset.get(0);
          // Don't animate multiple times.
          if (!fieldset.animating) {
            fieldset.animating = true;
            Drupal.toggleFieldset(fieldset);
          }
          return false;
        });

      $legend.append(summary);
    });
  }
};

})(jQuery);
;
/**
 * @file
 * Add jCarousel behaviors to the page and provide Views-support.
 */

(function($) {

Drupal.behaviors.jcarousel = {};
Drupal.behaviors.jcarousel.attach = function(context, settings) {
  settings = settings || Drupal.settings;

  // If no carousels exist on this part of the page, work no further. 
  if (!settings.jcarousel || !settings.jcarousel.carousels) {
    return;
  }

  $.each(settings.jcarousel.carousels, function(key, options) {
    var $carousel = $(options.selector + ':not(.jcarousel-processed)', context);

    // If this carousel has already been processed or doesn't exist, move on.
    if (!$carousel.length) {
      return;
    }

    // Callbacks need to be converted from a string to an actual function.
    $.each(options, function(optionKey) {
      if (optionKey.match(/Callback$/) && typeof options[optionKey] == 'string') {
        var callbackFunction = window;
        var callbackParents = options[optionKey].split('.');
        $.each(callbackParents, function(objectParent) {
          callbackFunction = callbackFunction[callbackParents[objectParent]];
        });
        options[optionKey] = callbackFunction;
      }
    });

    // Add standard options required for AJAX functionality.
    if (options.ajax && !options.itemLoadCallback) {
      options.itemLoadCallback = Drupal.jcarousel.ajaxLoadCallback;
    }

    // If auto-scrolling, pause animation when hoving over the carousel.
    if (options.auto && options.autoPause && !options.initCallback) {
      options.initCallback = function(carousel, state) {
        Drupal.jcarousel.autoPauseCallback(carousel, state);
      };
    }

    // Add navigation to the carousel if enabled.
    if (!options.setupCallback) {
      options.setupCallback = function(carousel) {
        Drupal.jcarousel.setupCarousel(carousel);
        if (options.navigation) {
          Drupal.jcarousel.addNavigation(carousel, options.navigation);
        }
      };
      if (options.navigation && !options.itemVisibleInCallback) {
        options.itemLastInCallback = {
          onAfterAnimation: Drupal.jcarousel.updateNavigationActive
        };
      }
    }

    if (!options.hasOwnProperty('buttonNextHTML') && !options.hasOwnProperty('buttonPrevHTML')) {
      options.buttonNextHTML = Drupal.theme('jCarouselButton', 'next');
      options.buttonPrevHTML = Drupal.theme('jCarouselButton', 'previous');
    }

    // Initialize the jcarousel.
    $carousel.addClass('jcarousel-processed').jcarousel(options);
  });
};

Drupal.jcarousel = {};
Drupal.jcarousel.ajaxLoadCallback = function(jcarousel, state) {
  // Check if the requested items already exist.
  if (state == 'init' || jcarousel.has(jcarousel.first, jcarousel.last)) {
    return;
  }

  var $list = jcarousel.list;
  var $view = $list.parents('.view:first');
  var ajaxPath = Drupal.settings.jcarousel.ajaxPath;
  var target = $view.get(0);

  // Find this view's settings in the Views AJAX settings.
  var settings;
  $.each(Drupal.settings.jcarousel.carousels, function(domID, carouselSettings) {
    if ($list.is('.' + domID)) {
      settings = carouselSettings['view_options'];
    }
  });

  // Copied from ajax_view.js:
  var viewData = { 'js': 1, 'first': jcarousel.first - 1, 'last': jcarousel.last };
  // Construct an object using the settings defaults and then overriding
  // with data specific to the link.
  $.extend(
    viewData,
    settings
  );

  $.ajax({
    url: ajaxPath,
    type: 'GET',
    data: viewData,
    success: function(response) {
      Drupal.jcarousel.ajaxResponseCallback(jcarousel, target, response);
    },
    error: function(xhr) {
      Drupal.jcarousel.ajaxErrorCallback(xhr, ajaxPath);
    },
    dataType: 'json'
  });

};

/**
 * Init callback for jCarousel. Pauses the carousel when hovering over.
 */
Drupal.jcarousel.autoPauseCallback = function(carousel, state) {
  function pauseAuto() {
    carousel.stopAuto();
  }
  function resumeAuto() {
    carousel.startAuto();
  }
  carousel.clip.hover(pauseAuto, resumeAuto);
  carousel.buttonNext.hover(pauseAuto, resumeAuto);
  carousel.buttonPrev.hover(pauseAuto, resumeAuto);
};

/**
 * Setup callback for jCarousel. Calculates number of pages.
 */
Drupal.jcarousel.setupCarousel = function(carousel) {
  // Determine the number of pages this carousel includes.
  // This only works for a positive starting point. Also, .first is 1-based
  // while .last is a count, so we need to reset the .first number to be
  // 0-based to make the math work.
  carousel.pageSize = carousel.last - (carousel.first - 1);

  // jCarousel's Views integration sets "size" in the carousel options. Use that
  // if available, otherwise count the number of items in the carousel.
  var itemCount = carousel.options.size ? carousel.options.size : $(carousel.list).children('li').length;
  carousel.pageCount =  Math.ceil(itemCount / carousel.pageSize);
  carousel.pageNumber = 1;

  // Disable the previous/next arrows if there is only one page.
  if (carousel.pageCount == 1) {
    carousel.buttonNext.addClass('jcarousel-next-disabled').attr('disabled', true);
    carousel.buttonPrev.addClass('jcarousel-prev-disabled').attr('disabled', true);
  }

  // Always remove the hard-coded display: block from the navigation.
  carousel.buttonNext.css('display', '');
  carousel.buttonPrev.css('display', '');
}

/**
 * Setup callback for jCarousel. Adds the navigation to the carousel if enabled.
 */
Drupal.jcarousel.addNavigation = function(carousel, position) {
  // Don't add a pager if there's only one page of results.
  if (carousel.pageCount <= 1) {
    return;
  }

  // Add a class to the wrapper so it can adjust CSS.
  $(carousel.list).parents('.jcarousel-container:first').addClass('jcarousel-navigation-' + position);

  var navigation = $('<ul class="jcarousel-navigation"></ul>');

  for (var i = 1; i <= carousel.pageCount; i++) {
    var pagerItem = $(Drupal.theme('jCarouselPageLink', i));
    var listItem = $('<li></li>').attr('jcarousel-page', i).append(pagerItem);
    navigation.append(listItem);

    // Make the first page active by default.
    if (i === 1) {
      listItem.addClass('active');
    }

    // Scroll to the correct page when a pager is clicked.
    pagerItem.bind('click', function() {
      // We scroll to the new page based on item offsets. This works with
      // circular carousels that do not divide items evenly, making it so that
      // going back or forward in pages will not skip or repeat any items.
      var newPageNumber = $(this).parent().attr('jcarousel-page');
      var itemOffset = (newPageNumber - carousel.pageNumber) * carousel.pageSize;

      if (itemOffset) {
        carousel.scroll(carousel.first + itemOffset);
      }

      return false;
    });
  }

  $(carousel.list).parents('.jcarousel-clip:first')[position](navigation);
}

/**
 * itemVisibleInCallback for jCarousel. Update the navigation after page change.
 */
Drupal.jcarousel.updateNavigationActive = function(carousel, item, idx, state) {
  // The navigation doesn't even exist yet when this is called on init.
  var $listItems = $(carousel.list).parents('.jcarousel-container:first').find('.jcarousel-navigation li');
  if ($listItems.length == 0) {
    return;
  }

  // jCarousel does some very odd things with circular wraps. Items before the
  // first item are given negative numbers and items after the last are given
  // numbers beyond the total number of items. This complicated logic calculates
  // which page number is active based off this numbering scheme.
  var pageNumber = Math.ceil(idx / carousel.pageSize);
  if (pageNumber <= 0 || pageNumber > carousel.pageCount) {
    pageNumber = pageNumber % carousel.pageCount;
    pageNumber = pageNumber == 0 ? carousel.pageCount : pageNumber;
    pageNumber = pageNumber < 0 ? pageNumber + carousel.pageCount : pageNumber;
  }
  carousel.pageNumber = pageNumber;
  var currentPage = $listItems.get(carousel.pageNumber - 1);

  // Set the current page to be active.
  $listItems.not(currentPage).removeClass('active');
  $(currentPage).addClass('active');
}

/**
 * AJAX callback for all jCarousel-style views.
 */
Drupal.jcarousel.ajaxResponseCallback = function(jcarousel, target, response) {
  if (response.debug) {
    alert(response.debug);
  }

  var $view = $(target);
  var jcarousel = $view.find('ul.jcarousel').data('jcarousel');

  // Add items to the jCarousel.
  $('ul.jcarousel > li', response.display).each(function(i) {
    var itemNumber = this.className.replace(/.*?jcarousel-item-(\d+).*/, '$1');
    jcarousel.add(itemNumber, this.innerHTML);
  });

  // Add Drupal behaviors to the content of the carousel to affect new items.
  Drupal.attachBehaviors(jcarousel.list.get(0));

  // Treat messages the same way that Views typically handles messages.
  if (response.messages) {
    // Show any messages (but first remove old ones, if there are any).
    $view.find('.views-messages').remove().end().prepend(response.messages);
  }
};

/**
 * Display error messages using the same mechanism as Views module.
 */
Drupal.jcarousel.ajaxErrorCallback = function (xhr, path) {
  var error_text = '';

  if ((xhr.status == 500 && xhr.responseText) || xhr.status == 200) {
    error_text = xhr.responseText;

    // Replace all &lt; and &gt; by < and >
    error_text = error_text.replace("/&(lt|gt);/g", function (m, p) {
      return (p == "lt")? "<" : ">";
    });

    // Now, replace all html tags by empty spaces
    error_text = error_text.replace(/<("[^"]*"|'[^']*'|[^'">])*>/gi,"");

    // Fix end lines
    error_text = error_text.replace(/[\n]+\s+/g,"\n");
  }
  else if (xhr.status == 500) {
    error_text = xhr.status + ': ' + Drupal.t("Internal server error. Please see server or PHP logs for error information.");
  }
  else {
    error_text = xhr.status + ': ' + xhr.statusText;
  }

  alert(Drupal.t("An error occurred at @path.\n\nError Description: @error", {'@path': path, '@error': error_text}));
};

Drupal.theme.prototype.jCarouselButton = function(type) {
  // Use links for buttons for accessibility.
  return '<a href="javascript:void(0)"></a>';
};

Drupal.theme.prototype.jCarouselPageLink = function(pageNumber) {
  return '<a href="javascript:void(0)"><span>' + (pageNumber) + '</span></a>';
};

})(jQuery);
;
(function ($) {

/**
 * Retrieves the summary for the first element.
 */
$.fn.drupalGetSummary = function () {
  var callback = this.data('summaryCallback');
  return (this[0] && callback) ? $.trim(callback(this[0])) : '';
};

/**
 * Sets the summary for all matched elements.
 *
 * @param callback
 *   Either a function that will be called each time the summary is
 *   retrieved or a string (which is returned each time).
 */
$.fn.drupalSetSummary = function (callback) {
  var self = this;

  // To facilitate things, the callback should always be a function. If it's
  // not, we wrap it into an anonymous function which just returns the value.
  if (typeof callback != 'function') {
    var val = callback;
    callback = function () { return val; };
  }

  return this
    .data('summaryCallback', callback)
    // To prevent duplicate events, the handlers are first removed and then
    // (re-)added.
    .unbind('formUpdated.summary')
    .bind('formUpdated.summary', function () {
      self.trigger('summaryUpdated');
    })
    // The actual summaryUpdated handler doesn't fire when the callback is
    // changed, so we have to do this manually.
    .trigger('summaryUpdated');
};

/**
 * Sends a 'formUpdated' event each time a form element is modified.
 */
Drupal.behaviors.formUpdated = {
  attach: function (context) {
    // These events are namespaced so that we can remove them later.
    var events = 'change.formUpdated click.formUpdated blur.formUpdated keyup.formUpdated';
    $(context)
      // Since context could be an input element itself, it's added back to
      // the jQuery object and filtered again.
      .find(':input').andSelf().filter(':input')
      // To prevent duplicate events, the handlers are first removed and then
      // (re-)added.
      .unbind(events).bind(events, function () {
        $(this).trigger('formUpdated');
      });
  }
};

/**
 * Prepopulate form fields with information from the visitor cookie.
 */
Drupal.behaviors.fillUserInfoFromCookie = {
  attach: function (context, settings) {
    $('form.user-info-from-cookie').once('user-info-from-cookie', function () {
      var formContext = this;
      $.each(['name', 'mail', 'homepage'], function () {
        var $element = $('[name=' + this + ']', formContext);
        var cookie = $.cookie('Drupal.visitor.' + this);
        if ($element.length && cookie) {
          $element.val(cookie);
        }
      });
    });
  }
};

})(jQuery);
;
/*!
 * jCarousel - Riding carousels with jQuery
 *   http://sorgalla.com/jcarousel/
 *
 * Copyright (c) 2006 Jan Sorgalla (http://sorgalla.com)
 * Dual licensed under the MIT (http://www.opensource.org/licenses/mit-license.php)
 * and GPL (http://www.opensource.org/licenses/gpl-license.php) licenses.
 *
 * Built on top of the jQuery library
 *   http://jquery.com
 *
 * Inspired by the "Carousel Component" by Bill Scott
 *   http://billwscott.com/carousel/
 */

(function(g){var q={vertical:!1,rtl:!1,start:1,offset:1,size:null,scroll:3,visible:null,animation:"normal",easing:"swing",auto:0,wrap:null,initCallback:null,setupCallback:null,reloadCallback:null,itemLoadCallback:null,itemFirstInCallback:null,itemFirstOutCallback:null,itemLastInCallback:null,itemLastOutCallback:null,itemVisibleInCallback:null,itemVisibleOutCallback:null,animationStepCallback:null,buttonNextHTML:"<div></div>",buttonPrevHTML:"<div></div>",buttonNextEvent:"click",buttonPrevEvent:"click", buttonNextCallback:null,buttonPrevCallback:null,itemFallbackDimension:null},m=!1;g(window).bind("load.jcarousel",function(){m=!0});g.jcarousel=function(a,c){this.options=g.extend({},q,c||{});this.autoStopped=this.locked=!1;this.buttonPrevState=this.buttonNextState=this.buttonPrev=this.buttonNext=this.list=this.clip=this.container=null;if(!c||c.rtl===void 0)this.options.rtl=(g(a).attr("dir")||g("html").attr("dir")||"").toLowerCase()=="rtl";this.wh=!this.options.vertical?"width":"height";this.lt=!this.options.vertical? this.options.rtl?"right":"left":"top";for(var b="",d=a.className.split(" "),f=0;f<d.length;f++)if(d[f].indexOf("jcarousel-skin")!=-1){g(a).removeClass(d[f]);b=d[f];break}a.nodeName.toUpperCase()=="UL"||a.nodeName.toUpperCase()=="OL"?(this.list=g(a),this.clip=this.list.parents(".jcarousel-clip"),this.container=this.list.parents(".jcarousel-container")):(this.container=g(a),this.list=this.container.find("ul,ol").eq(0),this.clip=this.container.find(".jcarousel-clip"));if(this.clip.size()===0)this.clip= this.list.wrap("<div></div>").parent();if(this.container.size()===0)this.container=this.clip.wrap("<div></div>").parent();b!==""&&this.container.parent()[0].className.indexOf("jcarousel-skin")==-1&&this.container.wrap('<div class=" '+b+'"></div>');this.buttonPrev=g(".jcarousel-prev",this.container);if(this.buttonPrev.size()===0&&this.options.buttonPrevHTML!==null)this.buttonPrev=g(this.options.buttonPrevHTML).appendTo(this.container);this.buttonPrev.addClass(this.className("jcarousel-prev"));this.buttonNext= g(".jcarousel-next",this.container);if(this.buttonNext.size()===0&&this.options.buttonNextHTML!==null)this.buttonNext=g(this.options.buttonNextHTML).appendTo(this.container);this.buttonNext.addClass(this.className("jcarousel-next"));this.clip.addClass(this.className("jcarousel-clip")).css({position:"relative"});this.list.addClass(this.className("jcarousel-list")).css({overflow:"hidden",position:"relative",top:0,margin:0,padding:0}).css(this.options.rtl?"right":"left",0);this.container.addClass(this.className("jcarousel-container")).css({position:"relative"}); !this.options.vertical&&this.options.rtl&&this.container.addClass("jcarousel-direction-rtl").attr("dir","rtl");var j=this.options.visible!==null?Math.ceil(this.clipping()/this.options.visible):null,b=this.list.children("li"),e=this;if(b.size()>0){var h=0,i=this.options.offset;b.each(function(){e.format(this,i++);h+=e.dimension(this,j)});this.list.css(this.wh,h+100+"px");if(!c||c.size===void 0)this.options.size=b.size()}this.container.css("display","block");this.buttonNext.css("display","block");this.buttonPrev.css("display", "block");this.funcNext=function(){e.next()};this.funcPrev=function(){e.prev()};this.funcResize=function(){e.resizeTimer&&clearTimeout(e.resizeTimer);e.resizeTimer=setTimeout(function(){e.reload()},100)};this.options.initCallback!==null&&this.options.initCallback(this,"init");!m&&g.browser.safari?(this.buttons(!1,!1),g(window).bind("load.jcarousel",function(){e.setup()})):this.setup()};var f=g.jcarousel;f.fn=f.prototype={jcarousel:"0.2.8"};f.fn.extend=f.extend=g.extend;f.fn.extend({setup:function(){this.prevLast= this.prevFirst=this.last=this.first=null;this.animating=!1;this.tail=this.resizeTimer=this.timer=null;this.inTail=!1;if(!this.locked){this.list.css(this.lt,this.pos(this.options.offset)+"px");var a=this.pos(this.options.start,!0);this.prevFirst=this.prevLast=null;this.animate(a,!1);g(window).unbind("resize.jcarousel",this.funcResize).bind("resize.jcarousel",this.funcResize);this.options.setupCallback!==null&&this.options.setupCallback(this)}},reset:function(){this.list.empty();this.list.css(this.lt, "0px");this.list.css(this.wh,"10px");this.options.initCallback!==null&&this.options.initCallback(this,"reset");this.setup()},reload:function(){this.tail!==null&&this.inTail&&this.list.css(this.lt,f.intval(this.list.css(this.lt))+this.tail);this.tail=null;this.inTail=!1;this.options.reloadCallback!==null&&this.options.reloadCallback(this);if(this.options.visible!==null){var a=this,c=Math.ceil(this.clipping()/this.options.visible),b=0,d=0;this.list.children("li").each(function(f){b+=a.dimension(this, c);f+1<a.first&&(d=b)});this.list.css(this.wh,b+"px");this.list.css(this.lt,-d+"px")}this.scroll(this.first,!1)},lock:function(){this.locked=!0;this.buttons()},unlock:function(){this.locked=!1;this.buttons()},size:function(a){if(a!==void 0)this.options.size=a,this.locked||this.buttons();return this.options.size},has:function(a,c){if(c===void 0||!c)c=a;if(this.options.size!==null&&c>this.options.size)c=this.options.size;for(var b=a;b<=c;b++){var d=this.get(b);if(!d.length||d.hasClass("jcarousel-item-placeholder"))return!1}return!0}, get:function(a){return g(">.jcarousel-item-"+a,this.list)},add:function(a,c){var b=this.get(a),d=0,p=g(c);if(b.length===0)for(var j,e=f.intval(a),b=this.create(a);;){if(j=this.get(--e),e<=0||j.length){e<=0?this.list.prepend(b):j.after(b);break}}else d=this.dimension(b);p.get(0).nodeName.toUpperCase()=="LI"?(b.replaceWith(p),b=p):b.empty().append(c);this.format(b.removeClass(this.className("jcarousel-item-placeholder")),a);p=this.options.visible!==null?Math.ceil(this.clipping()/this.options.visible): null;d=this.dimension(b,p)-d;a>0&&a<this.first&&this.list.css(this.lt,f.intval(this.list.css(this.lt))-d+"px");this.list.css(this.wh,f.intval(this.list.css(this.wh))+d+"px");return b},remove:function(a){var c=this.get(a);if(c.length&&!(a>=this.first&&a<=this.last)){var b=this.dimension(c);a<this.first&&this.list.css(this.lt,f.intval(this.list.css(this.lt))+b+"px");c.remove();this.list.css(this.wh,f.intval(this.list.css(this.wh))-b+"px")}},next:function(){this.tail!==null&&!this.inTail?this.scrollTail(!1): this.scroll((this.options.wrap=="both"||this.options.wrap=="last")&&this.options.size!==null&&this.last==this.options.size?1:this.first+this.options.scroll)},prev:function(){this.tail!==null&&this.inTail?this.scrollTail(!0):this.scroll((this.options.wrap=="both"||this.options.wrap=="first")&&this.options.size!==null&&this.first==1?this.options.size:this.first-this.options.scroll)},scrollTail:function(a){if(!this.locked&&!this.animating&&this.tail){this.pauseAuto();var c=f.intval(this.list.css(this.lt)), c=!a?c-this.tail:c+this.tail;this.inTail=!a;this.prevFirst=this.first;this.prevLast=this.last;this.animate(c)}},scroll:function(a,c){!this.locked&&!this.animating&&(this.pauseAuto(),this.animate(this.pos(a),c))},pos:function(a,c){var b=f.intval(this.list.css(this.lt));if(this.locked||this.animating)return b;this.options.wrap!="circular"&&(a=a<1?1:this.options.size&&a>this.options.size?this.options.size:a);for(var d=this.first>a,g=this.options.wrap!="circular"&&this.first<=1?1:this.first,j=d?this.get(g): this.get(this.last),e=d?g:g-1,h=null,i=0,k=!1,l=0;d?--e>=a:++e<a;){h=this.get(e);k=!h.length;if(h.length===0&&(h=this.create(e).addClass(this.className("jcarousel-item-placeholder")),j[d?"before":"after"](h),this.first!==null&&this.options.wrap=="circular"&&this.options.size!==null&&(e<=0||e>this.options.size)))j=this.get(this.index(e)),j.length&&(h=this.add(e,j.clone(!0)));j=h;l=this.dimension(h);k&&(i+=l);if(this.first!==null&&(this.options.wrap=="circular"||e>=1&&(this.options.size===null||e<= this.options.size)))b=d?b+l:b-l}for(var g=this.clipping(),m=[],o=0,n=0,j=this.get(a-1),e=a;++o;){h=this.get(e);k=!h.length;if(h.length===0){h=this.create(e).addClass(this.className("jcarousel-item-placeholder"));if(j.length===0)this.list.prepend(h);else j[d?"before":"after"](h);if(this.first!==null&&this.options.wrap=="circular"&&this.options.size!==null&&(e<=0||e>this.options.size))j=this.get(this.index(e)),j.length&&(h=this.add(e,j.clone(!0)))}j=h;l=this.dimension(h);if(l===0)throw Error("jCarousel: No width/height set for items. This will cause an infinite loop. Aborting..."); this.options.wrap!="circular"&&this.options.size!==null&&e>this.options.size?m.push(h):k&&(i+=l);n+=l;if(n>=g)break;e++}for(h=0;h<m.length;h++)m[h].remove();i>0&&(this.list.css(this.wh,this.dimension(this.list)+i+"px"),d&&(b-=i,this.list.css(this.lt,f.intval(this.list.css(this.lt))-i+"px")));i=a+o-1;if(this.options.wrap!="circular"&&this.options.size&&i>this.options.size)i=this.options.size;if(e>i){o=0;e=i;for(n=0;++o;){h=this.get(e--);if(!h.length)break;n+=this.dimension(h);if(n>=g)break}}e=i-o+ 1;this.options.wrap!="circular"&&e<1&&(e=1);if(this.inTail&&d)b+=this.tail,this.inTail=!1;this.tail=null;if(this.options.wrap!="circular"&&i==this.options.size&&i-o+1>=1&&(d=f.intval(this.get(i).css(!this.options.vertical?"marginRight":"marginBottom")),n-d>g))this.tail=n-g-d;if(c&&a===this.options.size&&this.tail)b-=this.tail,this.inTail=!0;for(;a-- >e;)b+=this.dimension(this.get(a));this.prevFirst=this.first;this.prevLast=this.last;this.first=e;this.last=i;return b},animate:function(a,c){if(!this.locked&& !this.animating){this.animating=!0;var b=this,d=function(){b.animating=!1;a===0&&b.list.css(b.lt,0);!b.autoStopped&&(b.options.wrap=="circular"||b.options.wrap=="both"||b.options.wrap=="last"||b.options.size===null||b.last<b.options.size||b.last==b.options.size&&b.tail!==null&&!b.inTail)&&b.startAuto();b.buttons();b.notify("onAfterAnimation");if(b.options.wrap=="circular"&&b.options.size!==null)for(var c=b.prevFirst;c<=b.prevLast;c++)c!==null&&!(c>=b.first&&c<=b.last)&&(c<1||c>b.options.size)&&b.remove(c)}; this.notify("onBeforeAnimation");if(!this.options.animation||c===!1)this.list.css(this.lt,a+"px"),d();else{var f=!this.options.vertical?this.options.rtl?{right:a}:{left:a}:{top:a},d={duration:this.options.animation,easing:this.options.easing,complete:d};if(g.isFunction(this.options.animationStepCallback))d.step=this.options.animationStepCallback;this.list.animate(f,d)}}},startAuto:function(a){if(a!==void 0)this.options.auto=a;if(this.options.auto===0)return this.stopAuto();if(this.timer===null){this.autoStopped= !1;var c=this;this.timer=window.setTimeout(function(){c.next()},this.options.auto*1E3)}},stopAuto:function(){this.pauseAuto();this.autoStopped=!0},pauseAuto:function(){if(this.timer!==null)window.clearTimeout(this.timer),this.timer=null},buttons:function(a,c){if(a==null&&(a=!this.locked&&this.options.size!==0&&(this.options.wrap&&this.options.wrap!="first"||this.options.size===null||this.last<this.options.size),!this.locked&&(!this.options.wrap||this.options.wrap=="first")&&this.options.size!==null&& this.last>=this.options.size))a=this.tail!==null&&!this.inTail;if(c==null&&(c=!this.locked&&this.options.size!==0&&(this.options.wrap&&this.options.wrap!="last"||this.first>1),!this.locked&&(!this.options.wrap||this.options.wrap=="last")&&this.options.size!==null&&this.first==1))c=this.tail!==null&&this.inTail;var b=this;this.buttonNext.size()>0?(this.buttonNext.unbind(this.options.buttonNextEvent+".jcarousel",this.funcNext),a&&this.buttonNext.bind(this.options.buttonNextEvent+".jcarousel",this.funcNext), this.buttonNext[a?"removeClass":"addClass"](this.className("jcarousel-next-disabled")).attr("disabled",a?!1:!0),this.options.buttonNextCallback!==null&&this.buttonNext.data("jcarouselstate")!=a&&this.buttonNext.each(function(){b.options.buttonNextCallback(b,this,a)}).data("jcarouselstate",a)):this.options.buttonNextCallback!==null&&this.buttonNextState!=a&&this.options.buttonNextCallback(b,null,a);this.buttonPrev.size()>0?(this.buttonPrev.unbind(this.options.buttonPrevEvent+".jcarousel",this.funcPrev), c&&this.buttonPrev.bind(this.options.buttonPrevEvent+".jcarousel",this.funcPrev),this.buttonPrev[c?"removeClass":"addClass"](this.className("jcarousel-prev-disabled")).attr("disabled",c?!1:!0),this.options.buttonPrevCallback!==null&&this.buttonPrev.data("jcarouselstate")!=c&&this.buttonPrev.each(function(){b.options.buttonPrevCallback(b,this,c)}).data("jcarouselstate",c)):this.options.buttonPrevCallback!==null&&this.buttonPrevState!=c&&this.options.buttonPrevCallback(b,null,c);this.buttonNextState= a;this.buttonPrevState=c},notify:function(a){var c=this.prevFirst===null?"init":this.prevFirst<this.first?"next":"prev";this.callback("itemLoadCallback",a,c);this.prevFirst!==this.first&&(this.callback("itemFirstInCallback",a,c,this.first),this.callback("itemFirstOutCallback",a,c,this.prevFirst));this.prevLast!==this.last&&(this.callback("itemLastInCallback",a,c,this.last),this.callback("itemLastOutCallback",a,c,this.prevLast));this.callback("itemVisibleInCallback",a,c,this.first,this.last,this.prevFirst, this.prevLast);this.callback("itemVisibleOutCallback",a,c,this.prevFirst,this.prevLast,this.first,this.last)},callback:function(a,c,b,d,f,j,e){if(!(this.options[a]==null||typeof this.options[a]!="object"&&c!="onAfterAnimation")){var h=typeof this.options[a]=="object"?this.options[a][c]:this.options[a];if(g.isFunction(h)){var i=this;if(d===void 0)h(i,b,c);else if(f===void 0)this.get(d).each(function(){h(i,this,d,b,c)});else for(var a=function(a){i.get(a).each(function(){h(i,this,a,b,c)})},k=d;k<=f;k++)k!== null&&!(k>=j&&k<=e)&&a(k)}}},create:function(a){return this.format("<li></li>",a)},format:function(a,c){for(var a=g(a),b=a.get(0).className.split(" "),d=0;d<b.length;d++)b[d].indexOf("jcarousel-")!=-1&&a.removeClass(b[d]);a.addClass(this.className("jcarousel-item")).addClass(this.className("jcarousel-item-"+c)).css({"float":this.options.rtl?"right":"left","list-style":"none"}).attr("jcarouselindex",c);return a},className:function(a){return a+" "+a+(!this.options.vertical?"-horizontal":"-vertical")}, dimension:function(a,c){var b=g(a);if(c==null)return!this.options.vertical?b.outerWidth(!0)||f.intval(this.options.itemFallbackDimension):b.outerHeight(!0)||f.intval(this.options.itemFallbackDimension);else{var d=!this.options.vertical?c-f.intval(b.css("marginLeft"))-f.intval(b.css("marginRight")):c-f.intval(b.css("marginTop"))-f.intval(b.css("marginBottom"));g(b).css(this.wh,d+"px");return this.dimension(b)}},clipping:function(){return!this.options.vertical?this.clip[0].offsetWidth-f.intval(this.clip.css("borderLeftWidth"))- f.intval(this.clip.css("borderRightWidth")):this.clip[0].offsetHeight-f.intval(this.clip.css("borderTopWidth"))-f.intval(this.clip.css("borderBottomWidth"))},index:function(a,c){if(c==null)c=this.options.size;return Math.round(((a-1)/c-Math.floor((a-1)/c))*c)+1}});f.extend({defaults:function(a){return g.extend(q,a||{})},intval:function(a){a=parseInt(a,10);return isNaN(a)?0:a},windowLoaded:function(){m=!0}});g.fn.jcarousel=function(a){if(typeof a=="string"){var c=g(this).data("jcarousel"),b=Array.prototype.slice.call(arguments, 1);return c[a].apply(c,b)}else return this.each(function(){var b=g(this).data("jcarousel");b?(a&&g.extend(b.options,a),b.reload()):g(this).data("jcarousel",new f(this,a))})}})(jQuery);
;

/**
 * Cookie plugin 1.0
 *
 * Copyright (c) 2006 Klaus Hartl (stilbuero.de)
 * Dual licensed under the MIT and GPL licenses:
 * http://www.opensource.org/licenses/mit-license.php
 * http://www.gnu.org/licenses/gpl.html
 *
 */
jQuery.cookie=function(b,j,m){if(typeof j!="undefined"){m=m||{};if(j===null){j="";m.expires=-1}var e="";if(m.expires&&(typeof m.expires=="number"||m.expires.toUTCString)){var f;if(typeof m.expires=="number"){f=new Date();f.setTime(f.getTime()+(m.expires*24*60*60*1000))}else{f=m.expires}e="; expires="+f.toUTCString()}var l=m.path?"; path="+(m.path):"";var g=m.domain?"; domain="+(m.domain):"";var a=m.secure?"; secure":"";document.cookie=[b,"=",encodeURIComponent(j),e,l,g,a].join("")}else{var d=null;if(document.cookie&&document.cookie!=""){var k=document.cookie.split(";");for(var h=0;h<k.length;h++){var c=jQuery.trim(k[h]);if(c.substring(0,b.length+1)==(b+"=")){d=decodeURIComponent(c.substring(b.length+1));break}}}return d}};
;
/**
 * @file
 * Implement a simple, clickable dropbutton menu.
 *
 * See dropbutton.theme.inc for primary documentation.
 *
 * The javascript relies on four classes:
 * - The dropbutton must be fully contained in a div with the class
 *   ctools-dropbutton. It must also contain the class ctools-no-js
 *   which will be immediately removed by the javascript; this allows for
 *   graceful degradation.
 * - The trigger that opens the dropbutton must be an a tag wit hthe class
 *   ctools-dropbutton-link. The href should just be '#' as this will never
 *   be allowed to complete.
 * - The part of the dropbutton that will appear when the link is clicked must
 *   be a div with class ctools-dropbutton-container.
 * - Finally, ctools-dropbutton-hover will be placed on any link that is being
 *   hovered over, so that the browser can restyle the links.
 *
 * This tool isn't meant to replace click-tips or anything, it is specifically
 * meant to work well presenting menus.
 */

(function ($) {
  Drupal.behaviors.CToolsDropbutton = {
    attach: function() {
      // Process buttons. All dropbuttons are buttons.
      $('.ctools-button')
        .once('ctools-button')
        .removeClass('ctools-no-js');

      // Process dropbuttons. Not all buttons are dropbuttons.
      $('.ctools-dropbutton').once('ctools-dropbutton', function() {
        var $dropbutton = $(this);
        var $button = $('.ctools-content', $dropbutton);
        var $secondaryActions = $('li', $button).not(':first');
        var $twisty = $(".ctools-link", $dropbutton);
        var open = false;
        var hovering = false;
        var timerID = 0;

        var toggle = function(close) {
          // if it's open or we're told to close it, close it.
          if (open || close) {
            // If we're just toggling it, close it immediately.
            if (!close) {
              open = false;
              $secondaryActions.slideUp(100);
              $dropbutton.removeClass('open');
            }
            else {
              // If we were told to close it, wait half a second to make
              // sure that's what the user wanted.
              // Clear any previous timer we were using.
              if (timerID) {
                clearTimeout(timerID);
              }
              timerID = setTimeout(function() {
                if (!hovering) {
                  open = false;
                  $secondaryActions.slideUp(100);
                  $dropbutton.removeClass('open');
                }}, 500);
            }
          }
          else {
            // open it.
            open = true;
            $secondaryActions.animate({height: "show", opacity: "show"}, 100);
            $dropbutton.addClass('open');
          }
        }
        // Hide the secondary actions initially.
        $secondaryActions.hide();

        $twisty.click(function() {
            toggle();
            return false;
          });

        $dropbutton.hover(
          function() {
            hovering = true;
          }, // hover in
          function() { // hover out
            hovering = false;
            toggle(true);
            return false;
          }
        );
      });
    }
  }
})(jQuery);
;
(function ($) {

Drupal.ModuleFilter = {};

Drupal.ModuleFilter.explode = function(string) {
  var queryArray = string.match(/([a-zA-Z]+\:(\w+|"[^"]+")*)|\w+|"[^"]+"/g);
  if (!queryArray) {
    queryArray = new Array();
  }
  var i = queryArray.length;
  while (i--) {
    queryArray[i] = queryArray[i].replace(/"/g, "");
  }
  return queryArray;
};

Drupal.ModuleFilter.getState = function(key) {
  if (!Drupal.ModuleFilter.state) {
    Drupal.ModuleFilter.state = {};
    var cookie = $.cookie('DrupalModuleFilter');
    var query = cookie ? cookie.split('&') : [];
    if (query) {
      for (var i in query) {
        // Extra check to avoid js errors in Chrome, IE and Safari when
        // combined with JS like twitter's widget.js.
        // See http://drupal.org/node/798764.
        if (typeof(query[i]) == 'string' && query[i].indexOf('=') != -1) {
          var values = query[i].split('=');
          if (values.length === 2) {
            Drupal.ModuleFilter.state[values[0]] = values[1];
          }
        }
      }
    }
  }
  return Drupal.ModuleFilter.state[key] ? Drupal.ModuleFilter.state[key] : false;
};

Drupal.ModuleFilter.setState = function(key, value) {
  var existing = Drupal.ModuleFilter.getState(key);
  if (existing != value) {
    Drupal.ModuleFilter.state[key] = value;
    var query = [];
    for (var i in Drupal.ModuleFilter.state) {
      query.push(i + '=' + Drupal.ModuleFilter.state[i]);
    }
    $.cookie('DrupalModuleFilter', query.join('&'), { expires: 7, path: '/' });
  }
};

Drupal.ModuleFilter.Filter = function(element, selector, options) {
  var self = this;

  this.element = element;
  this.text = $(this.element).val();

  this.settings = Drupal.settings.moduleFilter;

  this.selector = selector;

  this.options = $.extend({
    delay: 500,
    striping: false,
    childSelector: null,
    empty: Drupal.t('No results'),
    rules: new Array()
  }, options);
  if (this.options.wrapper == undefined) {
    this.options.wrapper = $(self.selector).parent();
  }

  // Add clear button.
  this.element.after('<div class="module-filter-clear"><a href="#" class="js-hide">' + Drupal.t('clear') + '</a></div>');
  if (this.text) {
    $('.module-filter-clear a', this.element.parent()).removeClass('js-hide');
  }
  $('.module-filter-clear a', this.element.parent()).click(function() {
    self.element.val('');
    self.text = '';
    delete self.queries;
    self.applyFilter();
    self.element.focus();
    $(this).addClass('js-hide');
    return false;
  });

  this.updateQueries = function() {
    var queryStrings = Drupal.ModuleFilter.explode(self.text);

    self.queries = new Array();
    for (var i in queryStrings) {
      var query = { operator: 'text', string: queryStrings[i] };

      if (self.operators != undefined) {
        // Check if an operator is possibly used.
        if (queryStrings[i].indexOf(':') > 0) {
          // Determine operator used.
          var args = queryStrings[i].split(':', 2);
          var operator = args.shift();
          if (self.operators[operator] != undefined) {
            query.operator = operator;
            query.string = args.shift();
          }
        }
      }

      query.string = query.string.toLowerCase();

      self.queries.push(query);
    }

    if (self.queries.length <= 0) {
      // Add a blank string query.
      self.queries.push({ operator: 'text', string: '' });
    }
  };

  this.applyFilter = function() {
    self.results = new Array();

    self.updateQueries();

    if (self.index == undefined) {
      self.buildIndex();
    }

    self.element.trigger('moduleFilter:start');

    $.each(self.index, function(key, item) {
      var $item = item.element;

      for (var i in self.queries) {
        var query = self.queries[i];
        if (query.operator == 'text') {
          if (item.text.indexOf(query.string) < 0) {
            continue;
          }
        }
        else {
          var func = self.operators[query.operator];
          if (!(func(query.string, self, item))) {
            continue;
          }
        }

        var rulesResult = self.processRules(item);
        if (rulesResult !== false) {
          return true;
        }
      }

      $item.addClass('js-hide');
    });

    self.element.trigger('moduleFilter:finish', { results: self.results });

    if (self.options.striping) {
      self.stripe();
    }

    if (self.results.length > 0) {
      self.options.wrapper.find('.module-filter-no-results').remove();
    }
    else {
      if (!self.options.wrapper.find('.module-filter-no-results').length) {
        self.options.wrapper.append($('<p class="module-filter-no-results"/>').text(self.options.empty));
      };
    }
  };

  self.element.keyup(function(e) {
    switch (e.which) {
      case 13:
        if (self.timeOut) {
          clearTimeout(self.timeOut);
        }
        self.applyFilter();
        break;
      default:
        if (self.text != $(this).val()) {
          if (self.timeOut) {
            clearTimeout(self.timeOut);
          }

          self.text = $(this).val();

          if (self.text) {
            self.element.parent().find('.module-filter-clear a').removeClass('js-hide');
          }
          else {
            self.element.parent().find('.module-filter-clear a').addClass('js-hide');
          }

          self.element.trigger('moduleFilter:keyup');

          self.timeOut = setTimeout(self.applyFilter, self.options.delay);
        }
        break;
    }
  });

  self.element.keypress(function(e) {
    if (e.which == 13) e.preventDefault();
  });
};

Drupal.ModuleFilter.Filter.prototype.buildIndex = function() {
  var self = this;
  var index = new Array();
  $(this.selector).each(function(i) {
    var text = (self.options.childSelector) ? $(self.options.childSelector, this).text() : $(this).text();
    var item = {
      key: i,
      element: $(this),
      text: text.toLowerCase()
    };
    for (var j in self.options.buildIndex) {
      var func = self.options.buildIndex[j];
      item = $.extend(func(self, item), item);
    }
    $(this).data('indexKey', i);
    index.push(item);
    delete item;
  });
  this.index = index;
};

Drupal.ModuleFilter.Filter.prototype.processRules = function(item) {
  var self = this;
  var $item = item.element;
  var rulesResult = true;
  if (self.options.rules.length > 0) {
    for (var i in self.options.rules) {
      var func = self.options.rules[i];
      rulesResult = func(self, item);
      if (rulesResult === false) {
        break;
      }
    }
  }
  if (rulesResult !== false) {
    $item.removeClass('js-hide');
    self.results.push(item);
  }
  return rulesResult;
};

Drupal.ModuleFilter.Filter.prototype.stripe = function() {
  var self = this;
  var flip = { even: 'odd', odd: 'even' };
  var stripe = 'odd';

  $.each(self.index, function(key, item) {
    if (!item.element.hasClass('js-hide')) {
      item.element.removeClass('odd even')
        .addClass(stripe);
      stripe = flip[stripe];
    }
  });
};

$.fn.moduleFilter = function(selector, options) {
  var filterInput = this;
  filterInput.parents('.module-filter-inputs-wrapper').show();
  if (Drupal.settings.moduleFilter.setFocus) {
    filterInput.focus();
  }
  filterInput.data('moduleFilter', new Drupal.ModuleFilter.Filter(this, selector, options));
};

})(jQuery);
;
(function($) {

Drupal.behaviors.moduleFilter = {
  attach: function(context) {
    $('.module-filter-inputs-wrapper', context).once('module-filter', function() {
      var filterInput = $('input[name="module_filter[name]"]', context);
      var selector = '#system-modules table tbody tr';
      if (Drupal.settings.moduleFilter.tabs) {
        selector += '.module';
      }

      filterInput.moduleFilter(selector, {
        wrapper: $('#module-filter-modules'),
        delay: 500,
        striping: true,
        childSelector: 'td:nth(1)',
        rules: [
          function(moduleFilter, item) {
            if (!item.unavailable) {
              if (moduleFilter.options.showEnabled) {
                if (item.status && !item.disabled) {
                  return true;
                }
              }
              if (moduleFilter.options.showDisabled) {
                if (!item.status && !item.disabled) {
                  return true;
                }
              }
              if (moduleFilter.options.showRequired) {
                if (item.status && item.disabled) {
                  return true;
                }
              }
            }
            if (moduleFilter.options.showUnavailable) {
              if (item.unavailable || (!item.status && item.disabled)) {
                return true;
              }
            }
            return false;
          }
        ],
        buildIndex: [
          function(moduleFilter, item) {
            var $checkbox = $('td.checkbox :checkbox', item.element);
            if ($checkbox.size() > 0) {
              item.status = $checkbox.is(':checked');
              item.disabled = $checkbox.is(':disabled');
            }
            else {
              item.status = false;
              item.disabled = true;
              item.unavailable = true;
            }
            return item;
          }
        ],
        showEnabled: $('#edit-module-filter-show-enabled').is(':checked'),
        showDisabled: $('#edit-module-filter-show-disabled').is(':checked'),
        showRequired: $('#edit-module-filter-show-required').is(':checked'),
        showUnavailable: $('#edit-module-filter-show-unavailable').is(':checked')
      });

      var moduleFilter = filterInput.data('moduleFilter');

      moduleFilter.operators = {
        description: function(string, moduleFilter, item) {
          if (item.description == undefined) {
            var description = $('.description', item.element).clone();
            $('.admin-requirements', description).remove();
            $('.admin-operations', description).remove();
            item.description = description.text().toLowerCase();
          }

          if (item.description.indexOf(string) >= 0) {
            return true;
          }
        },
        requiredBy: function(string, moduleFilter, item) {
          if (item.requiredBy == undefined) {
            var requirements = Drupal.ModuleFilter.getRequirements(item.element);
            item.requires = requirements.requires;
            item.requiredBy = requirements.requiredBy;
          }

          for (var i in item.requiredBy) {
            if (item.requiredBy[i].indexOf(string) >= 0) {
              return true;
            }
          }
        },
        requires: function(string, moduleFilter, item) {
          if (item.requires == undefined) {
            var requirements = Drupal.ModuleFilter.getRequirements(item.element);
            item.requires = requirements.requires;
            item.requiredBy = requirements.requiredBy;
          }

          for (var i in item.requires) {
            if (item.requires[i].indexOf(string) >= 0) {
              return true;
            }
          }
        }
      };

      $('#edit-module-filter-show-enabled', context).change(function() {
        moduleFilter.options.showEnabled = $(this).is(':checked');
        moduleFilter.applyFilter();
      });
      $('#edit-module-filter-show-disabled', context).change(function() {
        moduleFilter.options.showDisabled = $(this).is(':checked');
        moduleFilter.applyFilter();
      });
      $('#edit-module-filter-show-required', context).change(function() {
        moduleFilter.options.showRequired = $(this).is(':checked');
        moduleFilter.applyFilter();
      });
      $('#edit-module-filter-show-unavailable', context).change(function() {
        moduleFilter.options.showUnavailable = $(this).is(':checked');
        moduleFilter.applyFilter();
      });

      if (!Drupal.settings.moduleFilter.tabs) {
        moduleFilter.element.bind('moduleFilter:start', function() {
          $('#system-modules fieldset').show();
        });

        moduleFilter.element.bind('moduleFilter:finish', function(e, data) {
          $('#system-modules fieldset').each(function(i) {
            $fieldset = $(this);
            if ($('tbody tr', $fieldset).filter(':visible').length == 0) {
              $fieldset.hide();
            }
          });
        });

        moduleFilter.applyFilter();
      }
    });
  }
};

Drupal.ModuleFilter.getRequirements = function(element) {
  var requires = new Array();
  var requiredBy = new Array();
  $('.admin-requirements', element).each(function() {
    var text = $(this).text();
    if (text.substr(0, 9) == 'Requires:') {
      // Requires element.
      requiresString = text.substr(9);
      requires = requiresString.replace(/\([a-z]*\)/g, '').split(',');
    }
    else if (text.substr(0, 12) == 'Required by:') {
      // Required by element.
      requiredByString = text.substr(12);
      requiredBy = requiredByString.replace(/\([a-z]*\)/g, '').split(',');
    }
  });
  for (var i in requires) {
    requires[i] = $.trim(requires[i].toLowerCase());
  }
  for (var i in requiredBy) {
    requiredBy[i] = $.trim(requiredBy[i].toLowerCase());
  }
  return { requires: requires, requiredBy: requiredBy };
};

})(jQuery);
;

/*
 * jQuery BBQ: Back Button & Query Library - v1.2.1 - 2/17/2010
 * http://benalman.com/projects/jquery-bbq-plugin/
 *
 * Copyright (c) 2010 "Cowboy" Ben Alman
 * Dual licensed under the MIT and GPL licenses.
 * http://benalman.com/about/license/
 */
(function($,p){var i,m=Array.prototype.slice,r=decodeURIComponent,a=$.param,c,l,v,b=$.bbq=$.bbq||{},q,u,j,e=$.event.special,d="hashchange",A="querystring",D="fragment",y="elemUrlAttr",g="location",k="href",t="src",x=/^.*\?|#.*$/g,w=/^.*\#/,h,C={};function E(F){return typeof F==="string"}function B(G){var F=m.call(arguments,1);return function(){return G.apply(this,F.concat(m.call(arguments)))}}function n(F){return F.replace(/^[^#]*#?(.*)$/,"$1")}function o(F){return F.replace(/(?:^[^?#]*\?([^#]*).*$)?.*/,"$1")}function f(H,M,F,I,G){var O,L,K,N,J;if(I!==i){K=F.match(H?/^([^#]*)\#?(.*)$/:/^([^#?]*)\??([^#]*)(#?.*)/);J=K[3]||"";if(G===2&&E(I)){L=I.replace(H?w:x,"")}else{N=l(K[2]);I=E(I)?l[H?D:A](I):I;L=G===2?I:G===1?$.extend({},I,N):$.extend({},N,I);L=a(L);if(H){L=L.replace(h,r)}}O=K[1]+(H?"#":L||!K[1]?"?":"")+L+J}else{O=M(F!==i?F:p[g][k])}return O}a[A]=B(f,0,o);a[D]=c=B(f,1,n);c.noEscape=function(G){G=G||"";var F=$.map(G.split(""),encodeURIComponent);h=new RegExp(F.join("|"),"g")};c.noEscape(",/");$.deparam=l=function(I,F){var H={},G={"true":!0,"false":!1,"null":null};$.each(I.replace(/\+/g," ").split("&"),function(L,Q){var K=Q.split("="),P=r(K[0]),J,O=H,M=0,R=P.split("]["),N=R.length-1;if(/\[/.test(R[0])&&/\]$/.test(R[N])){R[N]=R[N].replace(/\]$/,"");R=R.shift().split("[").concat(R);N=R.length-1}else{N=0}if(K.length===2){J=r(K[1]);if(F){J=J&&!isNaN(J)?+J:J==="undefined"?i:G[J]!==i?G[J]:J}if(N){for(;M<=N;M++){P=R[M]===""?O.length:R[M];O=O[P]=M<N?O[P]||(R[M+1]&&isNaN(R[M+1])?{}:[]):J}}else{if($.isArray(H[P])){H[P].push(J)}else{if(H[P]!==i){H[P]=[H[P],J]}else{H[P]=J}}}}else{if(P){H[P]=F?i:""}}});return H};function z(H,F,G){if(F===i||typeof F==="boolean"){G=F;F=a[H?D:A]()}else{F=E(F)?F.replace(H?w:x,""):F}return l(F,G)}l[A]=B(z,0);l[D]=v=B(z,1);$[y]||($[y]=function(F){return $.extend(C,F)})({a:k,base:k,iframe:t,img:t,input:t,form:"action",link:k,script:t});j=$[y];function s(I,G,H,F){if(!E(H)&&typeof H!=="object"){F=H;H=G;G=i}return this.each(function(){var L=$(this),J=G||j()[(this.nodeName||"").toLowerCase()]||"",K=J&&L.attr(J)||"";L.attr(J,a[I](K,H,F))})}$.fn[A]=B(s,A);$.fn[D]=B(s,D);b.pushState=q=function(I,F){if(E(I)&&/^#/.test(I)&&F===i){F=2}var H=I!==i,G=c(p[g][k],H?I:{},H?F:2);p[g][k]=G+(/#/.test(G)?"":"#")};b.getState=u=function(F,G){return F===i||typeof F==="boolean"?v(F):v(G)[F]};b.removeState=function(F){var G={};if(F!==i){G=u();$.each($.isArray(F)?F:arguments,function(I,H){delete G[H]})}q(G,2)};e[d]=$.extend(e[d],{add:function(F){var H;function G(J){var I=J[D]=c();J.getState=function(K,L){return K===i||typeof K==="boolean"?l(I,K):l(I,L)[K]};H.apply(this,arguments)}if($.isFunction(F)){H=F;return G}else{H=F.handler;F.handler=G}}})})(jQuery,this);
/*
 * jQuery hashchange event - v1.2 - 2/11/2010
 * http://benalman.com/projects/jquery-hashchange-plugin/
 *
 * Copyright (c) 2010 "Cowboy" Ben Alman
 * Dual licensed under the MIT and GPL licenses.
 * http://benalman.com/about/license/
 */
(function($,i,b){var j,k=$.event.special,c="location",d="hashchange",l="href",f=$.browser,g=document.documentMode,h=f.msie&&(g===b||g<8),e="on"+d in i&&!h;function a(m){m=m||i[c][l];return m.replace(/^[^#]*#?(.*)$/,"$1")}$[d+"Delay"]=100;k[d]=$.extend(k[d],{setup:function(){if(e){return false}$(j.start)},teardown:function(){if(e){return false}$(j.stop)}});j=(function(){var m={},r,n,o,q;function p(){o=q=function(s){return s};if(h){n=$('<iframe src="javascript:0"/>').hide().insertAfter("body")[0].contentWindow;q=function(){return a(n.document[c][l])};o=function(u,s){if(u!==s){var t=n.document;t.open().close();t[c].hash="#"+u}};o(a())}}m.start=function(){if(r){return}var t=a();o||p();(function s(){var v=a(),u=q(t);if(v!==t){o(t=v,u);$(i).trigger(d)}else{if(u!==t){i[c][l]=i[c][l].replace(/#.*/,"")+"#"+u}}r=setTimeout(s,$[d+"Delay"])})()};m.stop=function(){if(!n){r&&clearTimeout(r);r=0}};return m})()})(jQuery,this);
;

(function ($) {

Drupal.ModuleFilter.tabs = {};
Drupal.ModuleFilter.enabling = {};
Drupal.ModuleFilter.disabling = {};

Drupal.ModuleFilter.jQueryIsNewer = function() {
  if (Drupal.ModuleFilter.jQueryNewer == undefined) {
    var v1parts = $.fn.jquery.split('.');
    var v2parts = new Array('1', '4', '4');

    for (var i = 0; i < v1parts.length; ++i) {
      if (v2parts.length == i) {
        Drupal.ModuleFilter.jQueryNewer = true;
        return Drupal.ModuleFilter.jQueryNewer;
      }

      if (v1parts[i] == v2parts[i]) {
        continue;
      }
      else if (v1parts[i] > v2parts[i]) {
        Drupal.ModuleFilter.jQueryNewer = true;
        return Drupal.ModuleFilter.jQueryNewer;
      }
      else {
        Drupal.ModuleFilter.jQueryNewer = false;
        return Drupal.ModuleFilter.jQueryNewer;
      }
    }

    if (v1parts.length != v2parts.length) {
      Drupal.ModuleFilter.jQueryNewer = false;
      return Drupal.ModuleFilter.jQueryNewer;
    }

    Drupal.ModuleFilter.jQueryNewer = false;
  }
  return Drupal.ModuleFilter.jQueryNewer;
};

Drupal.behaviors.moduleFilterTabs = {
  attach: function(context) {
    if (Drupal.settings.moduleFilter.tabs) {
      $('#module-filter-wrapper table:not(.sticky-header)', context).once('module-filter-tabs', function() {
        var $modules = $('#module-filter-modules');
        var moduleFilter = $('input[name="module_filter[name]"]').data('moduleFilter');
        var table = $(this);

        $('thead', table).show();

        // Remove package header rows.
        $('tr.admin-package-header', table).remove();

        var $tabsWrapper = $('<div id="module-filter-tabs"></div>');

        // Build tabs from package title rows.
        var tabs = '<ul>';
        for (var i in Drupal.settings.moduleFilter.packageIDs) {
          var id = Drupal.settings.moduleFilter.packageIDs[i];

          var name = id;
          var tabClass = 'project-tab';
          var title = null;
          var summary = (Drupal.settings.moduleFilter.countEnabled) ? '<span class="count">' + Drupal.ModuleFilter.countSummary(id) + '</span>' : '';

          switch (id) {
            case 'all':
              name = Drupal.t('All');
              break;
            case 'new':
              name = Drupal.t('New');
              title = Drupal.t('Modules installed within the last week.');
              if (Drupal.settings.moduleFilter.enabledCounts['new'].total == 0) {
                tabClass += ' disabled';
                summary += '<span>' + Drupal.t('No modules added within the last week.') + '</span>';
              }
              break;
            case 'recent':
              name = Drupal.t('Recent');
              title = Drupal.t('Modules enabled/disabled within the last week.');
              if (Drupal.settings.moduleFilter.enabledCounts['recent'].total == 0) {
                tabClass += ' disabled';
                summary += '<span>' + Drupal.t('No modules were enabled or disabled within the last week.') + '</span>';
              }
              break;
            default: 
              var $row = $('#' + id + '-package');
              name = $.trim($row.text());
              $row.remove();
              break;
          }

          tabs += '<li id="' + id + '-tab" class="' + tabClass + '"><a href="#' + id + '" class="overlay-exclude"' + (title ? ' title="' + title + '"' : '') + '><strong>' + name + '</strong><span class="summary">' + summary + '</span></a></li>';
        }
        tabs += '</ul>';
        $tabsWrapper.append(tabs);
        $modules.before($tabsWrapper);

        // Index tabs.
        $('#module-filter-tabs li').each(function() {
          var $tab = $(this);
          var id = $tab.attr('id');
          Drupal.ModuleFilter.tabs[id] = new Drupal.ModuleFilter.Tab($tab, id);
        });

        $('tbody td.checkbox input', $modules).change(function() {
          var $checkbox = $(this);
          var key = $checkbox.parents('tr').data('indexKey');

          moduleFilter.index[key].status = $checkbox.is(':checked');

          if (Drupal.settings.moduleFilter.visualAid) {
            var type = ($checkbox.is(':checked')) ? 'enable' : 'disable';
            Drupal.ModuleFilter.updateVisualAid(type, $checkbox.parents('tr'));
          }
        });

        // Sort rows.
        var rows = $('tbody tr.module', table).get();
        rows.sort(function(a, b) {
          var compA = $('td:nth(1)', a).text().toLowerCase();
          var compB = $('td:nth(1)', b).text().toLowerCase();
          return (compA < compB) ? -1 : (compA > compB) ? 1 : 0;
        });
        $.each(rows, function(idx, itm) { table.append(itm); });

        // Re-stripe rows.
        $('tr.module', table)
          .removeClass('odd even')
          .filter(':odd').addClass('even').end()
          .filter(':even').addClass('odd');

        moduleFilter.adjustHeight();

        moduleFilter.element.bind('moduleFilter:start', function() {
          moduleFilter.tabResults = {
            'all-tab': { items: {}, count: 0 },
            'recent-tab': { items: {}, count: 0 },
            'new-tab': { items: {}, count: 0 }
          };

          // Empty result info from tabs.
          for (var i in Drupal.ModuleFilter.tabs) {
            if (Drupal.ModuleFilter.tabs[i].resultInfo != undefined) {
              Drupal.ModuleFilter.tabs[i].resultInfo.empty();
            }
          }
        });

        moduleFilter.element.bind('moduleFilter:finish', function(e, data) {
          $.each(moduleFilter.index, function(key, item) {
            if (!item.element.hasClass('js-hide')) {
              var id = Drupal.ModuleFilter.getTabID(item.element);

              if (moduleFilter.tabResults[id] == undefined) {
                moduleFilter.tabResults[id] = { items: {}, count: 0 };
              }
              if (moduleFilter.tabResults[id].items[item.key] == undefined) {
                // All tab
                moduleFilter.tabResults['all-tab'].count++;

                // Recent tab
                if (item.element.hasClass('recent-module')) {
                  moduleFilter.tabResults['recent-tab'].count++;
                }

                // New tab
                if (item.element.hasClass('new-module')) {
                  moduleFilter.tabResults['new-tab'].count++;
                }

                moduleFilter.tabResults[id].items[item.key] = item;
                moduleFilter.tabResults[id].count++;
              }

              if (Drupal.ModuleFilter.activeTab != undefined && Drupal.ModuleFilter.activeTab.id != 'all-tab') {
                if ((Drupal.ModuleFilter.activeTab.id == 'recent-tab' && !item.element.hasClass('recent-module')) || (Drupal.ModuleFilter.activeTab.id == 'new-tab' && !item.element.hasClass('new-module')) || (Drupal.ModuleFilter.activeTab.id != 'recent-tab' && Drupal.ModuleFilter.activeTab.id != 'new-tab' && id != Drupal.ModuleFilter.activeTab.id)) {
                  // The item is not in the active tab, so hide it.
                  item.element.addClass('js-hide');
                }
              }
            }
          });

          if (Drupal.settings.moduleFilter.visualAid) {
            if (moduleFilter.text) {
              // Add result info to tabs.
              for (var id in moduleFilter.tabResults) {
                var tab = Drupal.ModuleFilter.tabs[id];

                if (tab.resultInfo == undefined) {
                  var resultInfo = '<span class="result-info"></span>'
                  $('a', tab.element).prepend(resultInfo);
                  tab.resultInfo = $('span.result-info', tab.element);
                }

                tab.resultInfo.append(moduleFilter.tabResults[id].count);
              }

              if (Drupal.settings.moduleFilter.hideEmptyTabs) {
                for (var id in Drupal.ModuleFilter.tabs) {
                  if (moduleFilter.tabResults[id] != undefined) {
                    Drupal.ModuleFilter.tabs[id].element.show();
                  }
                  else if (Drupal.ModuleFilter.activeTab == undefined || Drupal.ModuleFilter.activeTab.id != id) {
                    Drupal.ModuleFilter.tabs[id].element.hide();
                  }
                }
              }
            }
            else {
              // Make sure all tabs are visible.
              if (Drupal.settings.moduleFilter.hideEmptyTabs) {
                $('#module-filter-tabs li').show();
              }
            }
          }

          if ((Drupal.ModuleFilter.activeTab != undefined && (moduleFilter.tabResults[Drupal.ModuleFilter.activeTab.id] == undefined || moduleFilter.tabResults[Drupal.ModuleFilter.activeTab.id].count <= 0))) {
            // The current tab contains no results.
            moduleFilter.results = 0;
          }

          moduleFilter.adjustHeight();
        });

        if (Drupal.settings.moduleFilter.useURLFragment) {
          $(window).bind('hashchange.module-filter', $.proxy(Drupal.ModuleFilter, 'eventHandlerOperateByURLFragment')).triggerHandler('hashchange.module-filter');
        }
        else {
          Drupal.ModuleFilter.selectTab();
        }

        if (Drupal.settings.moduleFilter.useSwitch) {
          $('td.checkbox div.form-item').hide();
          $('td.checkbox').each(function(i) {
            var $cell = $(this);
            var $checkbox = $(':checkbox', $cell);
            var $switch = $('.toggle-enable', $cell);
            $switch.removeClass('js-hide').click(function() {
              if (!$(this).hasClass('disabled')) {
                if (Drupal.ModuleFilter.jQueryIsNewer()) {
                  $checkbox.click();
                }
                else {
                  $checkbox.click().change();
                }
              }
            });
            $checkbox.click(function() {
              if (!$switch.hasClass('disabled')) {
                $switch.toggleClass('off');
              }
            });
          });
        }

        var $tabs = $('#module-filter-tabs');

        function getParentTopOffset($obj, offset) {
          var $parent = $obj.offsetParent();
          if ($obj[0] != $parent[0]) {
            offset += $parent.position().top;
            return getParentTopOffset($parent, offset);
          }
          return offset;
        }

        var tabsTopOffset = null;
        function getParentsTopOffset() {
          if (tabsTopOffset === null) {
            tabsTopOffset = getParentTopOffset($tabs.parent(), 0);
          }
          return tabsTopOffset;
        }

        function viewportTop() {
          var top = $(window).scrollTop();
          return top;
        }

        function viewportBottom() {
          var top = $(window).scrollTop();
          var bottom = top + $(window).height();

          bottom -= $('#page-actions').height();

          return bottom;
        }

        function fixToTop(top) {
          if ($tabs.hasClass('bottom-fixed')) {
            $tabs.css({
              'position': 'absolute',
              'top': $tabs.position().top - getParentsTopOffset(),
              'bottom': 'auto'
            });
            $tabs.removeClass('bottom-fixed');
          }

          if (($tabs.css('position') == 'absolute' && $tabs.offset().top - top >= 0) || ($tabs.css('position') != 'absolute' && $tabs.offset().top - top <= 0)) {
            $tabs.addClass('top-fixed');
            $tabs.attr('style', '');
          }
        }

        function fixToBottom(bottom) {
          if ($tabs.hasClass('top-fixed')) {
            $tabs.css({
              'position': 'absolute',
              'top': $tabs.position().top - getParentsTopOffset(),
              'bottom': 'auto'
            });
            $tabs.removeClass('top-fixed');
          }

          if ($tabs.offset().top + $tabs.height() - bottom <= 0) {
            $tabs.addClass('bottom-fixed');
            var style = '';
            var pageActionsHeight = $('#page-actions').height();
            if (pageActionsHeight > 0) {
              style = 'bottom: ' + pageActionsHeight + 'px';
            }
            else if (Drupal.settings.moduleFilter.dynamicPosition) {
              // style = 'bottom: ' + $('#module-filter-submit', $tabs).height() + 'px';
            }
            $tabs.attr('style', style);
          }
        }

        var lastTop = 0;
        $(window).scroll(function() {
          var top = viewportTop();
          var bottom = viewportBottom();

          if ($modules.offset().top >= top) {
            $tabs.removeClass('top-fixed').attr('style', '');
          }
          else {
            if (top > lastTop) { // Downward scroll.
              if ($tabs.height() > bottom - top) {
                fixToBottom(bottom);
              }
              else {
                fixToTop(top);
              }
            }
            else { // Upward scroll.
              fixToTop(top);
            }
          }
          lastTop = top;
        });

        moduleFilter.adjustHeight();
      });
    }
  }
};

Drupal.ModuleFilter.Tab = function(element, id) {
  var self = this;

  this.id = id;
  this.hash = id.substring(0, id.length - 4);
  this.element = element;

  $('a', this.element).click(function() {
    if (!Drupal.settings.moduleFilter.useURLFragment) {
      var hash = (!self.element.hasClass('selected')) ? self.hash : 'all';
      Drupal.ModuleFilter.selectTab(hash);
      return false;
    }

    if (self.element.hasClass('selected')) {
      // Clear the active tab.
      window.location.hash = 'all';
      return false;
    }
  });

  $('tr.' + this.id, $('#system-modules')).hover(
    function() {
      self.element.addClass('suggest');
    },
    function() {
      self.element.removeClass('suggest');
    }
  );
};

Drupal.ModuleFilter.selectTab = function(hash) {
  if (!hash || Drupal.ModuleFilter.tabs[hash + '-tab'] == undefined || Drupal.settings.moduleFilter.enabledCounts[hash].total == 0) {
    if (Drupal.settings.moduleFilter.rememberActiveTab) {
      var activeTab = Drupal.ModuleFilter.getState('activeTab');
      if (activeTab && Drupal.ModuleFilter.tabs[activeTab + '-tab'] != undefined) {
        hash = activeTab;
      }
    }

    if (!hash) {
      hash = 'all';
    }
  }

  if (Drupal.ModuleFilter.activeTab != undefined) {
    Drupal.ModuleFilter.activeTab.element.removeClass('selected');
  }

  Drupal.ModuleFilter.activeTab = Drupal.ModuleFilter.tabs[hash + '-tab'];
  Drupal.ModuleFilter.activeTab.element.addClass('selected');

  var moduleFilter = $('input[name="module_filter[name]"]').data('moduleFilter');
  var filter = moduleFilter.applyFilter();

  if (!Drupal.ModuleFilter.modulesTop) {
    Drupal.ModuleFilter.modulesTop = $('#module-filter-modules').offset().top;
  }
  else {
    // Scroll back to top of #module-filter-modules.
    $('html, body').animate({
      scrollTop: Drupal.ModuleFilter.modulesTop
    }, 500);
    // $('html, body').scrollTop(Drupal.ModuleFilter.modulesTop);
  }

  Drupal.ModuleFilter.setState('activeTab', hash);
};

Drupal.ModuleFilter.eventHandlerOperateByURLFragment = function(event) {
  var hash = $.param.fragment();
  Drupal.ModuleFilter.selectTab(hash);
};

Drupal.ModuleFilter.countSummary = function(id) {
  return Drupal.t('@enabled of @total', { '@enabled': Drupal.settings.moduleFilter.enabledCounts[id].enabled, '@total': Drupal.settings.moduleFilter.enabledCounts[id].total });
};

Drupal.ModuleFilter.Tab.prototype.updateEnabling = function(name, remove) {
  this.enabling = this.enabling || {};
  if (!remove) {
    this.enabling[name] = name;
  }
  else {
    delete this.enabling[name];
  }
};

Drupal.ModuleFilter.Tab.prototype.updateDisabling = function(name, remove) {
  this.disabling = this.disabling || {};
  if (!remove) {
    this.disabling[name] = name;
  }
  else {
    delete this.disabling[name];
  }
};

Drupal.ModuleFilter.Tab.prototype.updateVisualAid = function() {
  var visualAid = '';
  var enabling = new Array();
  var disabling = new Array();

  if (this.enabling != undefined) {
    for (var i in this.enabling) {
      enabling.push(this.enabling[i]);
    }
    if (enabling.length > 0) {
      enabling.sort();
      visualAid += '<span class="enabling">+' + enabling.join('</span>, <span class="enabling">') + '</span>';
    }
  }
  if (this.disabling != undefined) {
    for (var i in this.disabling) {
      disabling.push(this.disabling[i]);
    }
    if (disabling.length > 0) {
      disabling.sort();
      if (enabling.length > 0) {
        visualAid += '<br />';
      }
      visualAid += '<span class="disabling">-' + disabling.join('</span>, <span class="disabling">') + '</span>';
    }
  }

  if (this.visualAid == undefined) {
    $('a span.summary', this.element).append('<span class="visual-aid"></span>');
    this.visualAid = $('span.visual-aid', this.element);
  }

  this.visualAid.empty().append(visualAid);
};

Drupal.ModuleFilter.getTabID = function($row) {
  var id = $row.data('moduleFilterTabID');
  if (!id) {
    // Find the tab ID.
    var classes = $row.attr('class').split(' ');
    for (var i in classes) {
      if (Drupal.ModuleFilter.tabs[classes[i]] != undefined) {
        id = classes[i];
        break;
      }
    }
    $row.data('moduleFilterTabID', id);
  }
  return id;
};

Drupal.ModuleFilter.updateVisualAid = function(type, $row) {
  var id = Drupal.ModuleFilter.getTabID($row);

  if (!id) {
    return false;
  }

  var tab = Drupal.ModuleFilter.tabs[id];
  var name = $('td:nth(1) strong', $row).text();
  switch (type) {
    case 'enable':
      if (Drupal.ModuleFilter.disabling[id + name] != undefined) {
        delete Drupal.ModuleFilter.disabling[id + name];
        tab.updateDisabling(name, true);
        $row.removeClass('disabling');
      }
      else {
        Drupal.ModuleFilter.enabling[id + name] = name;
        tab.updateEnabling(name);
        $row.addClass('enabling');
      }
      break;
    case 'disable':
      if (Drupal.ModuleFilter.enabling[id + name] != undefined) {
        delete Drupal.ModuleFilter.enabling[id + name];
        tab.updateEnabling(name, true);
        $row.removeClass('enabling');
      }
      else {
        Drupal.ModuleFilter.disabling[id + name] = name;
        tab.updateDisabling(name);
        $row.addClass('disabling');
      }
      break;
  }

  tab.updateVisualAid();
};

Drupal.ModuleFilter.Filter.prototype.adjustHeight = function() {
  // Hack for adjusting the height of the modules section.
  var minHeight = $('#module-filter-tabs ul').height() + 10;
  minHeight += $('#module-filter-tabs #module-filter-submit').height();
  $('#module-filter-modules').css('min-height', minHeight);
  this.element.trigger('moduleFilter:adjustHeight');
}

})(jQuery);
;
(function($) {

Drupal.behaviors.moduleFilterDynamicPosition = {
  attach: function(context) {
    var $window = $(window);

    $('#module-filter-wrapper', context).once('dynamic-position', function() {
      // Move the submit button just below the tabs.
      $('#module-filter-tabs').append($('#module-filter-submit'));

      var positionSubmit = function() {
        var $tabs = $('#module-filter-tabs');
        var $submit = $('#module-filter-submit', $tabs);

        // Vertical movement.
        var bottom = $tabs.offset().top + $tabs.outerHeight();
        if ($submit.hasClass('fixed-bottom')) {
          bottom += $submit.height();
        }
        if (bottom >= $window.height() + $window.scrollTop()) {
          $submit.addClass('fixed fixed-bottom');
          $tabs.css('padding-bottom', $submit.height());
        }
        else {
          $submit.removeClass('fixed fixed-bottom');
          $tabs.css('padding-bottom', 0);
        }

        // Horizontal movement.
        if ($submit.hasClass('fixed-bottom') || $submit.hasClass('fixed-top')) {
          var left = $tabs.offset().left - $window.scrollLeft();
          if (left != $submit.offset().left - $window.scrollLeft()) {
            $submit.css('left', left);
          }
        }
      };

      // Control the positioning.
      $window.scroll(positionSubmit);
      $window.resize(positionSubmit);
      var moduleFilter = $('input[name="module_filter[name]"]').data('moduleFilter');
      moduleFilter.element.bind('moduleFilter:adjustHeight', positionSubmit);
      moduleFilter.adjustHeight();
    });
  }
};

})(jQuery);
;
(function ($) {

/**
 * A progressbar object. Initialized with the given id. Must be inserted into
 * the DOM afterwards through progressBar.element.
 *
 * method is the function which will perform the HTTP request to get the
 * progress bar state. Either "GET" or "POST".
 *
 * e.g. pb = new progressBar('myProgressBar');
 *      some_element.appendChild(pb.element);
 */
Drupal.progressBar = function (id, updateCallback, method, errorCallback) {
  var pb = this;
  this.id = id;
  this.method = method || 'GET';
  this.updateCallback = updateCallback;
  this.errorCallback = errorCallback;

  // The WAI-ARIA setting aria-live="polite" will announce changes after users
  // have completed their current activity and not interrupt the screen reader.
  this.element = $('<div class="progress" aria-live="polite"></div>').attr('id', id);
  this.element.html('<div class="bar"><div class="filled"></div></div>' +
                    '<div class="percentage"></div>' +
                    '<div class="message">&nbsp;</div>');
};

/**
 * Set the percentage and status message for the progressbar.
 */
Drupal.progressBar.prototype.setProgress = function (percentage, message) {
  if (percentage >= 0 && percentage <= 100) {
    $('div.filled', this.element).css('width', percentage + '%');
    $('div.percentage', this.element).html(percentage + '%');
  }
  $('div.message', this.element).html(message);
  if (this.updateCallback) {
    this.updateCallback(percentage, message, this);
  }
};

/**
 * Start monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.startMonitoring = function (uri, delay) {
  this.delay = delay;
  this.uri = uri;
  this.sendPing();
};

/**
 * Stop monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.stopMonitoring = function () {
  clearTimeout(this.timer);
  // This allows monitoring to be stopped from within the callback.
  this.uri = null;
};

/**
 * Request progress data from server.
 */
Drupal.progressBar.prototype.sendPing = function () {
  if (this.timer) {
    clearTimeout(this.timer);
  }
  if (this.uri) {
    var pb = this;
    // When doing a post request, you need non-null data. Otherwise a
    // HTTP 411 or HTTP 406 (with Apache mod_security) error may result.
    $.ajax({
      type: this.method,
      url: this.uri,
      data: '',
      dataType: 'json',
      success: function (progress) {
        // Display errors.
        if (progress.status == 0) {
          pb.displayError(progress.data);
          return;
        }
        // Update display.
        pb.setProgress(progress.percentage, progress.message);
        // Schedule next timer.
        pb.timer = setTimeout(function () { pb.sendPing(); }, pb.delay);
      },
      error: function (xmlhttp) {
        pb.displayError(Drupal.ajaxError(xmlhttp, pb.uri));
      }
    });
  }
};

/**
 * Display errors on the page.
 */
Drupal.progressBar.prototype.displayError = function (string) {
  var error = $('<div class="messages error"></div>').html(string);
  $(this.element).before(error).hide();

  if (this.errorCallback) {
    this.errorCallback(this);
  }
};

})(jQuery);
;
(function ($) {
    Drupal.behaviors.colorboxNode = {
        // Lets find our class name and change our URL to
        // our defined menu path to open in a colorbox modal.
        attach: function (context, settings) {
            // Make sure colorbox exists.
            if (!$.isFunction($.colorbox)) {
                return;
            }

            // Mobile detection extracted from the colorbox module.
            // If the mobile setting is turned on, it will turn off the colorbox modal for mobile devices.
            if (settings.colorbox.mobiledetect && window.matchMedia) {
                // Disable Colorbox for small screens.
                mq = window.matchMedia("(max-device-width: " + settings.colorbox.mobiledevicewidth + ")");
                if (mq.matches) {
                    return;
                }
            }


            $('.colorbox-node', context).once('init-colorbox-node-processed', function () {
                $(this).colorboxNode({'launch': false});
            });

            // When using contextual links and clicking from within the colorbox
            // we need to close down colorbox when opening the built in overlay.
            $('ul.contextual-links a', context).once('colorboxNodeContextual').click(function () {
                $.colorbox.close();
            });
        }
    };

    // Bind our colorbox node functionality to an anchor
    $.fn.colorboxNode = function (options) {
        var settings = {
            'launch': true
        };

        $.extend(settings, options);

        var href = $(this).attr('data-href');
        if (typeof href == 'undefined' || href == false) {
            href = $(this).attr('href');
        }
        // Create an element so we can parse our a URL no matter if its internal or external.
        var parse = document.createElement('a');
        parse.href = href;
        // Lets add our colorbox link after the base path if necessary.
        var base_path = Drupal.settings.basePath;
        var pathname = parse.pathname;

        // Lets check to see if the pathname has a forward slash.
        // This problem happens in IE7/IE8
        if (pathname.charAt(0) != '/') {
            pathname = '/' + parse.pathname;
        }

        // If clean URL's are not turned on, lets check for that.
        var url = $.getParameterByName('q', href);
        if (base_path != '/') {
            if (url != '') {
                var link = pathname.replace(base_path, base_path + '?q=colorbox/') + url;
            } else {
                console.log('check2');
                var link = pathname.replace(base_path, base_path + 'colorbox/') + parse.search;
            }
        } else {
            if (url != '') {
                var link = base_path + '?q=colorbox' + pathname + url;
            } else {
                var link = base_path + 'colorbox' + pathname + parse.search;
            }
        }

        // Bind Ajax behaviors to all items showing the class.
        var element_settings = {};

        // This removes any loading/progress bar on the clicked link
        // and displays the colorbox loading screen instead.
        element_settings.progress = { 'type': 'none' };
        // For anchor tags, these will go to the target of the anchor rather
        // than the usual location.
        if (href) {
            element_settings.url = link;
            element_settings.event = 'click';
        }

        $(this).click(function () {
            $this = $(this).clone();

            // Clear out the rel to prevent any confusion if not using the gallery class.
            if(!$this.hasClass('colorbox-node-gallery')) {
                $this.attr('rel', '');
            }

            // Lets extract our width and height giving priority to the data attributes.
            var innerWidth = $this.data('inner-width');
            var innerHeight = $this.data('inner-height');
            if (typeof innerWidth != 'undefined' && typeof innerHeight != 'undefined') {
                var params = $.urlDataParams(innerWidth, innerHeight);
            } else {
                var params = $.urlParams(href);
            }

            params.html = '<div id="colorboxNodeLoading"></div>';
            params.onComplete = function () {
                $this.colorboxNodeGroup();
            }
            params.open = true;

            // Launch our colorbox with the provided settings
            $this.colorbox($.extend({}, Drupal.settings.colorbox, params));
        });

        // Log our click handler to our ajax object
        var base = $(this).attr('id');
        Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);

        // Default to auto click for manual call to this function.
        if (settings.launch) {
            Drupal.ajax[base].eventResponse(this, 'click');
            $(this).click();
        }
    }

    // Allow for grouping on links to showcase a gallery with left/right arrows.
    // This function will find the next index of each link on the page by the rel
    // and manually force a click on the link to call that AJAX and update the
    // modal window.
    $.fn.colorboxNodeGroup = function () {
        // Lets do setup our gallery type of functions.
        var $this = $(this);
        var rel = $this.attr('rel');
        if(rel && $this.hasClass('colorbox-node-gallery')) {
            if ($('a.colorbox-node-gallery[rel="' + rel + '"]:not("#colorbox a[rel="' + rel + '"]")').length > 1) {
                $related = $('a.colorbox-node-gallery[rel="' + rel + '"]:not("#colorbox a[rel="' + rel + '"]")');

                // filter $related array by href, to have mutliple colorbox links to the same target
                // appear as one item in the gallery only
                var $related_unique = [];
                $related.each(function() {
                    findHref($related_unique, this.href);
                    if (!findHref($related_unique, this.href).length) {
                        $related_unique.push(this);
                    }
                });
                // we have to get the actual used element from the filtered list in order to get it's relative index
                var current = findHref($related_unique, $this.get(0).href);
                $related = $($related_unique);
                var idx = $related.index($(current));
                var tot = $related.length;

                // Show our gallery buttons
                $('#cboxPrevious, #cboxNext').show();
                $.colorbox.next = function () {
                    index = getIndex(1);
                    $related[index].click();
                };
                $.colorbox.prev = function () {
                    index = getIndex(-1);
                    $related[index].click();
                };

                // Setup our current HTML
                $('#cboxCurrent').html(Drupal.settings.colorbox.current.replace('{current}', idx + 1).replace('{total}', tot)).show();

                var prefix = 'colorbox';
                // Remove Bindings and re-add
                // @TODO: There must be a better way?  If we don't remove it causes a memory to be exhausted.
                $(document).unbind('keydown.' + prefix);

                // Add Key Bindings
                $(document).bind('keydown.' + prefix, function (e) {
                    var key = e.keyCode;
                    if ($related[1] && !e.altKey) {
                        if (key === 37) {
                            e.preventDefault();
                            $.colorbox.prev();
                        } else if (key === 39) {
                            e.preventDefault();
                            $.colorbox.next();
                        }
                    }
                });
            }

            function getIndex(increment) {
                var max = $related.length;
                var newIndex = (idx + increment) % max;
                return (newIndex < 0) ? max + newIndex : newIndex;
            }

            // Find a colorbox link by href in an array
            function findHref(items, href){
                return $.grep(items, function(n, i){
                    return n.href == href;
                });
            };
        }
    }

    // Utility function to parse out our width/height from our url params
    $.urlParams = function (url) {
        var p = {},
            e,
            a = /\+/g,  // Regex for replacing addition symbol with a space
            r = /([^&=]+)=?([^&]*)/g,
            d = function (s) {
                return decodeURIComponent(s.replace(a, ' '));
            },
            q = url.split('?');
        while (e = r.exec(q[1])) {
            e[1] = d(e[1]);
            e[2] = d(e[2]);
            switch (e[2].toLowerCase()) {
                case 'true':
                case 'yes':
                    e[2] = true;
                    break;
                case 'false':
                case 'no':
                    e[2] = false;
                    break;
            }
            if (e[1] == 'width') {
                e[1] = 'innerWidth';
            }
            if (e[1] == 'height') {
                e[1] = 'innerHeight';
            }
            p[e[1]] = e[2];
        }
        return p;
    };

    // Utility function to return our data attributes for width/height
    $.urlDataParams = function (innerWidth, innerHeight) {
        return {'innerWidth':innerWidth,'innerHeight':innerHeight};
    };

    $.getParameterByName = function(name, href) {
        name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
        var regexString = "[\\?&]" + name + "=([^&#]*)";
        var regex = new RegExp(regexString);
        var found = regex.exec(href);
        if(found == null)
            return "";
        else
            return decodeURIComponent(found[1].replace(/\+/g, " "));
    }

})(jQuery);
;
