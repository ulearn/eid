/* This aggregate contains the following files:
sites/all/modules/contrib/popup/popup.js,
sites/all/modules/dev/devel/devel_krumo_path.js,
sites/all/modules/contrib/adminimal_admin_menu/adminimal_admin_menu.js,
misc/textarea.js,
sites/all/modules/contrib/backup_migrate/backup_migrate.js,
misc/collapse.js,
misc/progress.js,
sites/all/modules/contrib/colorbox_node/colorbox_node.js. */

(function ($) {

Drupal.behaviors.popup = {

  attach: function(context){

    // Make sure we have an overlay space
    if(!$('#popup-active-overlay').length){
      $('body').append('<div id="popup-active-overlay"></div>');
    }

    // Process flat menu containers
    $('.popup-menu-flat:not(.popup-menu-flat-processed)').each(
      function(){
        var thisObject = $(this);
        thisObject.addClass('popup-menu-flat-processed');
        new PopupMenuContainerElement(thisObject);
      }
    );

    // Process popup-elements
    $('.popup-element:not(.popup-element-processed)').each(
      function(){
        var thisObject = $(this);
        thisObject
          .addClass('popup-element-processed')
          .removeClass('popup-element-noscript');
        new PopupElement(thisObject);
      }
    );

    // Process menu leaves
    $('.popup-menu-leaf-title:not(.popup-menu-leaf-processed)').each(
      function(){
        var thisObject = $(this);
        thisObject.addClass('popup-menu-leaf-processed');
        new PopupMenuLeafElement(thisObject);
      }
    );

    // Process relative links in AJAX loaded content
    $("a[href^='/ahah/popup/view']", context).each(
      function(){

        var thisObject = $(this);
        var thisContext = $(thisObject.parents('div.inner').get(0));

        var placeContent = function(data){
          thisContext.html(data);
          Drupal.attachBehaviors(context);
        }

        var fetchContent = function(){
          $.get(thisObject.attr('href'), null, placeContent);
          return false;
        }

        thisObject.click(fetchContent);
      }
    );

    // Correct relative form submits
    $(".ajax form").each(
      function(){
        var thisForm = $(this);

        if (thisForm.attr('action').match(/^\/ahah\/popup/)){
          thisForm.attr('action', '');
        }
      }
    );

    // Reposition on window resize
    var reposition = function(){
      $('.popup-element').trigger('reposition');
    }
    $(window).unbind('resize', reposition).resize(reposition);

  }

}



/* ---- Popup element objects ---- */



PopupElement = function(element){

  var thisObject = this;

  // Gather elements
  this.element = element;
  this.title = $($('.popup-element-title', this.element)[0]);
  this.body = $($('.popup-element-body', this.element)[0]);
  this.elementId = this.element.attr('id');
  this.closeButton = $('.popup-close', this.body);

  this.children = new Array();

  this.isRoot = this
    .title
    .parents('.popup-element-body,.popup-menu-flat')
    .length == 0;

  this.body.data('popupElement', this);

  // Assign show/hide effects
  PopupElement.assignEffects.apply(this);

  // Assign origin positioning function
  PopupElement.assignPositioning.apply(this);

  // Move body and add a wrapper
  PopupElement.dom.apply(this);

  // Assign expansion function
  PopupElement.assignExpansion.apply(this);

  // Assign activation/deactivation events
  PopupElement.assignEvents.apply(this);

  // Apply css attributes
  PopupElement.applyAttributes.apply(this);

  // Attach AJAX behaviors
  PopupElement.applyAJAX.apply(this);

  // Reposition on window resize
  this.element.bind(
    'reposition',
    function(){
      thisObject.position();
    }
  );

  // Close button
  this.closeButton.click(
    function(){
      PopupElement.hide.apply(thisObject);
      return false;
    }
  );

}



PopupMenuLeafElement = function(element){

  this.element = element;
  this.parent = this.element.parents('.popup-element-body,.popup-menu-flat').data('popupElement');
  var thisObject = this;

  this.element.mouseover(
    function(){
      if (thisObject.parent){
        for(var i in thisObject.parent.children){
          PopupElement.hide.apply(thisObject.parent.children[i]);
        }
      }
    }
  );
}



PopupMenuContainerElement = function(element){

  this.element = element;
  this.body = element;
  this.children = new Array();
  this.element.data('popupElement', this);

}



PopupElement.count = 0;



/* ---- DOM preparation ---- */



PopupElement.dom = function(){

  this.body.appendTo('#popup-active-overlay');

  var classAttr = this.element.attr('class');
  var styleClass = classAttr.match(/popup-style-[^'\s]+/);

  this.body.wrap(
      '<div id="' +
        this.elementId +
      '-active" class="popup-element-wrapper' + (styleClass ? ' ' + styleClass : '') + '">'
    );

  this.wrapper = this.body.parent();
  this.wrapper.css('position', 'absolute');

  // Wrap in origin element
  this.body.wrap('<div class="popup-element-origin">');
  this.origin = this.body.parent();
  this.origin.css('position', 'absolute');
}



/* ---- Dynamic functions ---- */



PopupElement.assignEffects = function(){
  var effectName = this
    .element
    .attr('class')
    .match(/effect-([^\s]+)/)[1];
  this.animShow = new Function(
    Drupal.settings.popup.effects.show[effectName]
  );
  this.animHide = new Function(
    Drupal.settings.popup.effects.hide[effectName]
  );
}



PopupElement.assignPositioning = function(){
  var originName = this
    .element
    .attr('class')
    .match(/origin-([^\s]+)/)[1];
  this.position = PopupElement.position[originName];
}



PopupElement.assignExpansion = function(){
  var expandName = this
    .element
    .attr('class')
    .match(/expand-([^\s]+)/)[1];
  PopupElement.expand[expandName].apply(this);
}



PopupElement.assignEvents = function(){
  if (this.element.hasClass('activate-hover')){
    PopupElement.hoverEvents.apply(this);
  } else {
    PopupElement.clickEvents.apply(this);
  }

  var thisObject = this;

  // API show/hide events
  this.element.bind(
    'hide',
    function(){
      PopupElement.hide.apply(thisObject);
    }
  ).bind(
    'show',
    function(){
      PopupElement.show.apply(thisObject);
    }
  );

}



PopupElement.applyAttributes = function(){

  if (this.body.attr('class')){

    var opacity = this.body.attr('class').match(/opacity-([^\s]+)/);
    if (opacity && opacity[1] < 1){
      this.body.css(
        {
          opacity: opacity[1],
          filter: 'alpha(opacity=' + opacity[1] + ')'
        }
      );
    }

    var width = this.body.attr('class').match(/width-([^\s]+)/);
    if (width){
      $('.inner', this.body).css('width', width[1] + 'px');
    }
  }
}



/* ---- AJAX preparation ---- */



PopupElement.applyAJAX = function(){

  var thisObject = this;

  var placeContent = function(data, destination){

    thisObject.body.unbind('showing', fetchContent);
    var close = $('.popup-close-button', destination);

    if (close.length){
      close.siblings().remove();
      destination.append(data);
    } else {
      destination.html(data);
    }

    Drupal.attachBehaviors(destination);
  }

  var fetchContent = function(){

    var placeHolder = thisObject.body.find('.popup-ahah-placeholder');
    var destination = placeHolder.parent();
    var url = $('a.ahah-path', placeHolder).attr('href');

    $.get(url, null, function(data){ placeContent(data, destination); });
  }

  // Ajax
  if (this.body.hasClass('ajax')){
    this.body.bind('showing', fetchContent);
  }

}



/* ---- Popup actions ---- */



PopupElement.hide = function(){
  if (this.visible){
    this.body.trigger('hiding');
    this.animHide();
    this.title.removeClass('popup-title-active');
    this.element.removeClass('popup-element-active');
    this.visible = false;
    this.body.queue('function(){ PopupElement.count--; }');
    this.body.trigger('hidden');
  }
}



PopupElement.show = function(){
  if (!this.visible){
    this.body.css('z-index', ++PopupElement.count);
    this.body.trigger('showing');
    this.position();
    this.animShow();
    this.title.addClass('popup-title-active');
    this.element.addClass('popup-element-active');
    this.visible = true;
    this.body.trigger('shown');
  }
}



/* ---- Popup events ---- */



PopupElement.clickEvents = function(){

  this.visible = false;
  var thisObject = this;

  this.title.click(
    function(){
      if (thisObject.visible == true){
        PopupElement.hide.apply(thisObject);
      } else {
        PopupElement.show.apply(thisObject);
      }
      return false;
    }
  );
}



PopupElement.hoverEvents = function(){

  var thisObject = this;

  if (!this.isRoot){
    var popupElement = this.title.parents('.popup-element-body').data('popupElement');
    this.parent = popupElement
      ? popupElement
      : this.title.parents('.popup-menu-flat').data('popupElement');
    this.parent.children.push(this);
  }

  // Trigger hiding
  var delayedHide = function(){
    clearTimeout(thisObject.hideTimeout);
    if (thisObject.showTimeout) {
      clearTimeout(thisObject.showTimeout);
    }
    thisObject.hideTimeout = setTimeout(
      function(){
        PopupElement.hide.apply(thisObject);
      },
      Drupal.settings.popup.linger
    );
    if (!thisObject.isRoot){
      thisObject.parent.body.trigger('mouseleave');
    }
  }
  this.body.bind('mouseleave', delayedHide);
  this.title.bind('mouseleave', delayedHide);

  // Cancel hiding
  var cancelHide = function(){
    var element = thisObject;
    clearTimeout(thisObject.hideTimeout);
    while(element = element.parent){
      clearTimeout(element.hideTimeout);
    }
  }
  this.body.bind('mouseover', cancelHide);
  this.title.bind('mouseover', cancelHide);

  // Trigger showing
  var handler = function(event){
    thisObject.showTimeout = setTimeout(
			function(){
				if (!thisObject.visible){
					PopupElement.show.apply(thisObject);
					if (thisObject.parent){
						for(var i in thisObject.parent.children){
							if (thisObject.parent.children[i] != thisObject){
								PopupElement.hide.apply(thisObject.parent.children[i]);
							}
						}
					}
				}
      }, Drupal.settings.popup.delay
    );
	}

  this.title.bind('mouseenter', handler);
}



/* ---- Popup positioning ---- */



PopupElement.position = {

  'top-left': function(){
    var origin = this.title.offset();
    this.origin.css(
      {
        top: origin.top,
        left: origin.left
      }
    );
  },

  'top-right': function(){
    var origin = this.title.offset();
    this.origin.css(
      {
        top: origin.top,
        left: origin.left + this.title.outerWidth()
      }
    );
  },

  'bottom-left': function(){
    var origin = this.title.offset();
    this.origin.css(
      {
        top: origin.top + this.title.outerHeight(),
        left: origin.left
      }
    );
  },

  'bottom-right': function(){
    var origin = this.title.offset();
    this.origin.css(
      {
        top: origin.top + this.title.outerHeight(),
        left: origin.left + this.title.outerWidth()
      }
    );
  }

}



PopupElement.expand = {

  'top-left': function(){
    this.body.css({bottom: 0, right: 0});
  },

  'top-right': function(){
    this.body.css({bottom: 0, left: 0});
  },

  'bottom-left': function(){
    this.body.css({top: 0, right: 0});
  },

  'bottom-right': function(){
    this.body.css({top: 0, left: 0});
  }

}


})(jQuery);;/**/
/* Above code came from sites/all/modules/contrib/popup/popup.js */

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
;/**/
/* Above code came from sites/all/modules/dev/devel/devel_krumo_path.js */

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
;/**/
/* Above code came from sites/all/modules/contrib/adminimal_admin_menu/adminimal_admin_menu.js */

(function ($) {

Drupal.behaviors.textarea = {
  attach: function (context, settings) {
    $('.form-textarea-wrapper.resizable', context).once('textarea', function () {
      var staticOffset = null;
      var textarea = $(this).addClass('resizable-textarea').find('textarea');
      var grippie = $('<div class="grippie"></div>').mousedown(startDrag);

      grippie.insertAfter(textarea);

      function startDrag(e) {
        staticOffset = textarea.height() - e.pageY;
        textarea.css('opacity', 0.25);
        $(document).mousemove(performDrag).mouseup(endDrag);
        return false;
      }

      function performDrag(e) {
        textarea.height(Math.max(32, staticOffset + e.pageY) + 'px');
        return false;
      }

      function endDrag(e) {
        $(document).unbind('mousemove', performDrag).unbind('mouseup', endDrag);
        textarea.css('opacity', 1);
      }
    });
  }
};

})(jQuery);
;/**/
/* Above code came from misc/textarea.js */

(function($) {
  Drupal.behaviors.backupMigrate = {
    attach: function(context) {
      if (Drupal.settings.backup_migrate !== undefined) { 
        if (Drupal.settings.backup_migrate.dependents !== undefined) {
          for (key in Drupal.settings.backup_migrate.dependents) {
            info = Drupal.settings.backup_migrate.dependents[key];
            dependent = $('#edit-' + info['dependent']);
            for (key in info['dependencies']) {
              $('[name="' + key + '"]').each(function() {
                var dependentval = info['dependencies'][key];
                var dependency = $(this);
                (function(dependent, dependency) {
                  var checkval = function(inval) {
                    if (dependency.attr('type') == 'radio') {
                      var val = $('[name="' + dependency.attr('name') + '"]:checked').val();
                      return val == inval;
                    }
                    else if (dependency.attr('type') == 'checkbox') {
                      return dependency.attr('checked') && inval == dependency.val();
                    }
                    else {
                      return dependency.val() == inval;
                    }
                    return false;
                  };
                  if (!checkval(dependentval)) {
                    // Hide doesn't work inside collapsed fieldsets.
                    dependent.css('display', 'none');
                  }
                  dependency.bind('load change click keypress focus', function() {
                    if (checkval(dependentval)) {
                      dependent.slideDown();
                    }
                    else {
                      dependent.slideUp();
                    }
                  }).load();
                })(dependent, dependency);
              });
            }
          }
          for (key in Drupal.settings.backup_migrate.destination_selectors) {
            var info = Drupal.settings.backup_migrate.destination_selectors[key];
            (function(info) {
              var selector = $('#' + info['destination_selector']);
              var copy = $('#' + info['copy'])
              var copy_selector = $('#' + info['copy_destination_selector']);
              var copy_selector_options = {};

              // Store a copy of the secondary selector options.
              copy_selector.find('optgroup').each(function() {
                var label = $(this).attr('label');
                copy_selector_options[label] = [];
                $(this).find('option').each(function() {
                  copy_selector_options[label].push(this); 
                });
                $(this).remove();
              })

              // Assign an action to the main selector to modify the secondary selector
              selector.each(function() {
                $(this).bind('load change click keypress focus', function() {
                  var group = $(this).find('option[value=' + $(this).val() + ']').parents('optgroup').attr('label');
                  if (group) {
                    copy.parent().find('.backup-migrate-destination-copy-label').text(info['labels'][group]);
                    copy_selector.empty();
                    for (var key in copy_selector_options) {
                      if (key != group) {
                        copy_selector.append(copy_selector_options[key]);
                      }
                    }
                  }
                }).load();
              });
            })(info);
          }
          // Add the convert to checkboxes functionality to all multiselects.
          $('#backup-migrate-ui-manual-backup-form select[multiple], #backup-migrate-crud-edit-form select[multiple]').each(function() {
            var self = this;
            $(self).after(
              $('<div class="description backup-migrate-checkbox-link"></div>').append(
                $('<a>'+ Drupal.settings.backup_migrate.checkboxLinkText +'</a>').click(function() {
                  var $select = $(self);
                  var $checkboxes = $('<div></div>').addClass('backup-migrate-tables-checkboxes');
                  $('option', $select).each(function(i) {
                    $checkboxes.append(
                      $('<div class="form-item"></div>').append(
                        $('<label class="option backup-migrate-table-select">' + this.value + '</label>').prepend(
                          $('<input type="checkbox" class="backup-migrate-tables-checkbox" name="'+ $select.attr('name') +'"'+ (this.selected ? 'checked="checked"' : '') +' value="'+ this.value +'"/>')
                            .bind('click change load', function() {
                                if (this.checked) {
                                  $(this).parent().addClass('checked');
                                }
                                else {
                                  $(this).parent().removeClass('checked');
                                }
                              }).load()
                        )
                      )
                    );
                  });
                  $select.parent().find('.backup-migrate-checkbox-link').remove();
                  $select.before($checkboxes);
                  $select.hide();
                })
              )
            );
          });
        }
      }
    }
  }
})(jQuery);
;/**/
/* Above code came from sites/all/modules/contrib/backup_migrate/backup_migrate.js */

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
;/**/
/* Above code came from misc/collapse.js */

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
;/**/
/* Above code came from misc/progress.js */

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
;/**/
/* Above code came from sites/all/modules/contrib/colorbox_node/colorbox_node.js */

