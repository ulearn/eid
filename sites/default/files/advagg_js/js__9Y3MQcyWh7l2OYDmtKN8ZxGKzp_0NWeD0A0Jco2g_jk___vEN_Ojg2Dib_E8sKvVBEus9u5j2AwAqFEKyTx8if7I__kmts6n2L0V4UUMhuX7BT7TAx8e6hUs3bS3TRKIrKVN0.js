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
(function ($) {

/**
 * Webform node form interface enhancments.
 */

Drupal.behaviors.webformAdmin = {};
Drupal.behaviors.webformAdmin.attach = function(context) {
  // On click or change, make a parent radio button selected.
  Drupal.webform.setActive(context);
  Drupal.webform.updateTemplate(context);
  // Update the template select list upon changing a template.
  // Select all link for file extensions.
  Drupal.webform.selectCheckboxesLink(context);
  // Enhance the normal tableselect.js file to support indentations.
  Drupal.webform.tableSelectIndentation(context);
  // Automatically download exports if available.
  Drupal.webform.downloadExport(context);
  // Enhancements for the conditionals administrative page.
  Drupal.webform.conditionalAdmin(context);
}

Drupal.webform = Drupal.webform || {};

Drupal.webform.setActive = function(context) {
  var setActiveOnChange = function(e) {
    if ($(this).val()) {
      var $checkbox = $(this).closest('.form-type-radio').find('input[type=radio]');
      $.fn.prop ? $checkbox.prop('checked', true) : $checkbox.attr('checked', true);
    }
    e.preventDefault();
  };
  var setActiveOnClick = function(e) {
    var $checkbox = $(this).closest('.form-type-radio').find('input[type=radio]');
    $.fn.prop ? $checkbox.prop('checked', true) : $checkbox.attr('checked', true);
  };
  $('.webform-inline-radio', context).click(setActiveOnClick);
  $('.webform-set-active', context).change(setActiveOnChange);

  // Firefox improperly selects the parent radio button when clicking inside
  // a label that contains an input field. The only way of preventing this
  // currently is to remove the "for" attribute on the label.
  // See https://bugzilla.mozilla.org/show_bug.cgi?id=213519.
  if (navigator.userAgent.match(/Firefox/)) {
    $('.webform-inline-radio', context).removeAttr('for');
  }
};

Drupal.webform.updateTemplate = function(context) {
  var defaultTemplate = $('#edit-templates-default').val();
  var $templateSelect = $('#webform-template-fieldset select#edit-template-option', context);
  var $templateTextarea = $('#webform-template-fieldset textarea:visible', context);

  var updateTemplateSelect = function() {
    if ($(this).val() == defaultTemplate) {
      $templateSelect.val('default');
    }
    else {
      $templateSelect.val('custom');
    }
  }

  var updateTemplateText = function() {
    if ($(this).val() == 'default' && $templateTextarea.val() != defaultTemplate) {
      if (confirm(Drupal.settings.webform.revertConfirm)) {
        $templateTextarea.val(defaultTemplate);
      }
      else {
        $(this).val('custom');
      }
    }
  }

  $templateTextarea.keyup(updateTemplateSelect);
  $templateSelect.change(updateTemplateText);
}

Drupal.webform.selectCheckboxesLink = function(context) {
  function selectCheckboxes() {
    var group = this.className.replace(/.*?webform-select-link-([^ ]*).*/, '$1');
    var $checkboxes = $('.webform-select-group-' + group + ' input[type=checkbox]');
    var reverseCheck = !$checkboxes[0].checked;
    $checkboxes.each(function() {
      this.checked = reverseCheck;
    });
    $checkboxes.trigger('change');
    return false;
  }
  $('a.webform-select-link', context).click(selectCheckboxes);
}

Drupal.webform.tableSelectIndentation = function(context) {
  var $tables = $('th.select-all', context).parents('table');
  $tables.find('input.form-checkbox').change(function() {
    var $rows = $(this).parents('table:first').find('tr');
    var $checkbox;
    var row = $(this).parents('tr:first').get(0);
    var rowNumber = $rows.index(row);
    var rowTotal = $rows.size();
    var indentLevel = $(row).find('div.indentation').size();
    for (var n = rowNumber + 1; n < rowTotal; n++) {
      if ($rows.eq(n).find('div.indentation').size() <= indentLevel) {
        break;
      }
      $checkbox = $rows.eq(n).find('input.form-checkbox');
      $.fn.prop ? $checkbox.prop('checked', this.checked) : $checkbox.attr('checked', this.checked);
    }
  });
}

/**
 * Attach behaviors for Webform results download page.
 */
Drupal.webform.downloadExport = function(context) {
  if (context === document && Drupal.settings && Drupal.settings.webformExport && document.cookie.match(/webform_export_info=1/)) {
    window.location = Drupal.settings.webformExport;
    delete Drupal.settings.webformExport;
  }
}

/**
 * Attach behaviors for Webform conditional administration.
 */
Drupal.webform.conditionalAdmin = function(context) {
  $context = $(context);
  // Bind to the entire form and allow events to bubble-up from elements. This
  // saves a lot of processing when new conditions are added/removed.
  $context.find('#webform-conditionals-ajax:not(.webform-conditional-processed)').bind('change', function(e) {
    $(this).addClass('webform-conditional-processed');

    if ($(e.target).is('.webform-conditional-source select')) {
      Drupal.webform.conditionalSourceChange.apply(e.target);
    }

    if ($(e.target).is('.webform-conditional-operator select')) {
      Drupal.webform.conditionalOperatorChange.apply(e.target);
    }

    if ($(e.target).is('.webform-conditional-andor select')) {
      Drupal.webform.conditionalAndOrChange.apply(e.target);
    }
  });

  $context.find('.webform-conditional-rule-remove:not(.webform-conditional-processed)').bind('click', function() {
    window.setTimeout($.proxy(Drupal.webform.conditionalRemove, this), 100);
  }).addClass('webform-conditional-processed');

  // Trigger default handlers on the source element, this in turn will trigger
  // the operator handlers.
  $context.find('.webform-conditional-source select').trigger('change');

  // When adding a new table row, make it draggable and hide the weight column.
  if ($context.is('tr.ajax-new-content') && $context.find('.webform-conditional').length === 1) {
    Drupal.tableDrag['webform-conditionals-table'].makeDraggable($context[0]);
    $context.find('.webform-conditional-weight').closest('td').addClass('tabledrag-hide');
    if ($.cookie('Drupal.tableDrag.showWeight') !== '1') {
      Drupal.tableDrag['webform-conditionals-table'].hideColumns();
    }
    $context.removeClass('ajax-new-content');
  }
}

/**
 * Event callback for the remove button next to an individual rule.
 */
Drupal.webform.conditionalRemove = function() {
  // See if there are any remaining rules in this element.
  var ruleCount = $(this).parents('.webform-conditional:first').find('.webform-conditional-rule-remove').length;
  if (ruleCount <= 1) {
    var $tableRow = $(this).parents('tr:first');
    var $table = $('#webform-conditionals-table');
    if ($tableRow.length && $table.length) {
      $tableRow.remove();
      Drupal.webform.restripeTable($table[0]);
    }
  }
}

/**
 * Event callback to update the list of operators after a source change.
 */
Drupal.webform.conditionalSourceChange = function() {
  var source = $(this).val();
  var dataType = Drupal.settings.webform.conditionalValues.sources[source]['data_type'];
  var $operator = $(this).parents('.webform-conditional-rule:first').find('.webform-conditional-operator select');

  // Store a the original list of all operators for all data types in the select
  // list DOM element.
  if (!$operator[0]['webformConditionalOriginal']) {
    $operator[0]['webformConditionalOriginal'] = $operator[0].innerHTML;
  }

  // Reference the original list to create a new list matching the data type.
  var $originalList = $($operator[0]['webformConditionalOriginal']);
  var $newList = $originalList.filter('optgroup[label=' + dataType + ']');
  $operator.html($newList[0].innerHTML);

  // Fire the change event handler on the list to update the value field.
  $operator.trigger('change');
}

/**
 * Event callback to update the value field after an operator change.
 */
Drupal.webform.conditionalOperatorChange = function() {
  var source = $(this).parents('.webform-conditional-rule:first').find('.webform-conditional-source select').val();
  var dataType = Drupal.settings.webform.conditionalValues.sources[source]['data_type'];
  var operator = $(this).val();
  var $value = $(this).parents('.webform-conditional-rule:first').find('.webform-conditional-value');
  var name = $value.find('input, select, textarea').attr('name');
  var originalValue = false;

  // Given the dataType and operator, we can determine the form key.
  var formKey = Drupal.settings.webform.conditionalValues.operators[dataType][operator]['form'];

  // On initial request, save the default field as printed on the original page.
  if (!$value[0]['webformConditionalOriginal']) {
    $value[0]['webformConditionalOriginal'] = $value[0].innerHTML;
    originalValue = $value.find('input:first').val();
  }
  // On changes to an existing operator, check if the form key is different
  // before bothering with replacing the form with an identical version.
  else if ($value[0]['webformConditionalFormKey'] == formKey) {
    return;
  }

  // Store the current form key for checking the next time the operator changes.
  $value[0]['webformConditionalFormKey'] = formKey;

  // If using the default (a textfield), restore the original field.
  if (formKey === 'default') {
    $value[0].innerHTML = $value[0]['webformConditionalOriginal'];
  }
  // If the operator does not need a source value (i.e. is empty), hide it.
  else if (formKey === false) {
    $value[0].innerHTML = '&nbsp;';
  }
  // Lastly check if there is a specialized form for this source and operator.
  else {
    // If there is a per-source form for this operator (e.g. option lists), use
    // the specialized value form.
    if (typeof Drupal.settings.webform.conditionalValues.forms[formKey] == 'object') {
      $value[0].innerHTML = Drupal.settings.webform.conditionalValues.forms[formKey][source];
    }
    // Otherwise all the sources use a generic field (e.g. a text field).
    else {
      $value[0].innerHTML = Drupal.settings.webform.conditionalValues.forms[formKey];
    }
  }

  // Set the name attribute to match the original placeholder field.
  var $firstElement = $value.find('input, select, textarea').filter(':first');
  $firstElement.attr('name', name);

  if (originalValue) {
    $firstElement.val(originalValue);
  }
}

/**
 * Event callback to make sure all group and/or operators match.
 */
Drupal.webform.conditionalAndOrChange = function() {
  $(this).parents('.webform-conditional:first').find('.webform-conditional-andor select').val(this.value);
}

/**
 * Given a table's DOM element, restripe the odd/even classes.
 */
Drupal.webform.restripeTable = function(table) {
  // :even and :odd are reversed because jQuery counts from 0 and
  // we count from 1, so we're out of sync.
  // Match immediate children of the parent element to allow nesting.
  $('> tbody > tr, > tr', table)
    .filter(':odd').filter('.odd')
      .removeClass('odd').addClass('even')
    .end().end()
    .filter(':even').filter('.even')
      .removeClass('even').addClass('odd');
};
})(jQuery);
;/**/
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
