/* This aggregate contains the following files:
sites/all/modules/contrib/ckeditor/plugins/media/library.js,
sites/all/modules/contrib/ckeditor/includes/ckeditor.utils.js,
sites/all/libraries/ckeditor/ckeditor_basic.js. */


/**
 *  @file
 *  Attach Media ckeditor behaviors.
 */

(function ($) {
  Drupal.media = Drupal.media || {};

  Drupal.settings.ckeditor.plugins['media'] = {

    /**
       * Initializes the tag map.
       */
    initializeTagMap: function () {
      if (typeof Drupal.settings.tagmap == 'undefined') {
        Drupal.settings.tagmap = { };
      }
    },
    /**
       * Execute the button.
       */
    invoke: function (data, settings, instanceId) {
      if (data.format == 'html') {
        Drupal.media.popups.mediaBrowser(function (mediaFiles) {
          Drupal.settings.ckeditor.plugins['media'].mediaBrowserOnSelect(mediaFiles, instanceId);
        }, settings['global']);
      }
    },

    /**
       * Respond to the mediaBrowser's onSelect event.
       */
    mediaBrowserOnSelect: function (mediaFiles, instanceId) {
      var mediaFile = mediaFiles[0];
      var options = {};
      Drupal.media.popups.mediaStyleSelector(mediaFile, function (formattedMedia) {
        Drupal.settings.ckeditor.plugins['media'].insertMediaFile(mediaFile, formattedMedia.type, formattedMedia.html, formattedMedia.options, CKEDITOR.instances[instanceId]);
      }, options);

      return;
    },

    insertMediaFile: function (mediaFile, viewMode, formattedMedia, options, ckeditorInstance) {

      this.initializeTagMap();
      // @TODO: the folks @ ckeditor have told us that there is no way
      // to reliably add wrapper divs via normal HTML.
      // There is some method of adding a "fake element"
      // But until then, we're just going to embed to img.
      // This is pretty hacked for now.
      //
      var imgElement = $(this.stripDivs(formattedMedia));
      this.addImageAttributes(imgElement, mediaFile.fid, viewMode, options);

      var toInsert = this.outerHTML(imgElement);
      // Create an inline tag
      var inlineTag = Drupal.settings.ckeditor.plugins['media'].createTag(imgElement);
      // Add it to the tag map in case the user switches input formats
      Drupal.settings.tagmap[inlineTag] = toInsert;
      ckeditorInstance.insertHtml(toInsert);
    },

    /**
       * Gets the HTML content of an element
       *
       * @param jQuery element
       */
    outerHTML: function (element) {
      return $('<div>').append( element.eq(0).clone() ).html();
    },

    addImageAttributes: function (imgElement, fid, view_mode, additional) {
      imgElement.addClass('media-image');

      this.forceAttributesIntoClass(imgElement, fid, view_mode, additional);
    },

    /**
       * Due to problems handling wrapping divs in ckeditor, this is needed.
       *
       * Going forward, if we don't care about supporting other editors
       * we can use the fakeobjects plugin to ckeditor to provide cleaner
       * transparency between what Drupal will output <div class="field..."><img></div>
       * instead of just <img>, for now though, we're going to remove all the stuff surrounding the images.
       *
       * @param String formattedMedia
       *  Element containing the image
       *
       * @return HTML of <img> tag inside formattedMedia
       */
    stripDivs: function (formattedMedia) {
      // Check to see if the image tag has divs to strip
      var stripped = null;
      if ($(formattedMedia).is('img')) {
        stripped = this.outerHTML($(formattedMedia));
      } else {
        stripped = this.outerHTML($('img', $(formattedMedia)));
      }
      // This will fail if we pass the img tag without anything wrapping it, like we do when re-enabling ckeditor
      return stripped;
    },

    /**
       * Attach function, called when a rich text editor loads.
       * This finds all [[tags]] and replaces them with the html
       * that needs to show in the editor.
       *
       */
    attach: function (content, settings, instanceId) {
      var matches = content.match(/\[\[.*?\]\]/g);
      this.initializeTagMap();
      var tagmap = Drupal.settings.tagmap;
      if (matches) {
        var inlineTag = "";
        for (i = 0; i < matches.length; i++) {
          inlineTag = matches[i];
          if (tagmap[inlineTag]) {
            // This probably needs some work...
            // We need to somehow get the fid propogated here.
            // We really want to
            var tagContent = tagmap[inlineTag];
            var mediaMarkup = this.stripDivs(tagContent); // THis is <div>..<img>

            var _tag = inlineTag;
            _tag = _tag.replace('[[','');
            _tag = _tag.replace(']]','');
            mediaObj = JSON.parse(_tag);

            var imgElement = $(mediaMarkup);
            this.addImageAttributes(imgElement, mediaObj.fid, mediaObj.view_mode);
            var toInsert = this.outerHTML(imgElement);
            content = content.replace(inlineTag, toInsert);
          }
          else {
            debug.debug("Could not find content for " + inlineTag);
          }
        }
      }
      return content;
    },

    /**
       * Detach function, called when a rich text editor detaches
       */
    detach: function (content, settings, instanceId) {
      var content = $('<div>' + content + '</div>');
      $('img.media-image',content).each(function (elem) {
        var tag = Drupal.settings.ckeditor.plugins['media'].createTag($(this));
        $(this).replaceWith(tag);
        var newContent = content.html();
        var tagContent = $('<div></div>').append($(this)).html();
        Drupal.settings.tagmap[tag] = tagContent;
      });
      return content.html();
    },

    /**
       * @param jQuery imgNode
       *  Image node to create tag from
       */
    createTag: function (imgNode) {
      // Currently this is the <img> itself
      // Collect all attribs to be stashed into tagContent
      var mediaAttributes = {};
      var imgElement = imgNode[0];
      var sorter = [];

      // @todo: this does not work in IE, width and height are always 0.
      for (i=0; i< imgElement.attributes.length; i++) {
        var attr = imgElement.attributes[i];
        if (attr.specified == true) {
          if (attr.name !== 'class') {
            sorter.push(attr);
          }
          else {
            // Exctract expando properties from the class field.
            var attributes = this.getAttributesFromClass(attr.value);
            for (var name in attributes) {
              if (attributes.hasOwnProperty(name)) {
                var value = attributes[name];
                if (value.type && value.type === 'attr') {
                  sorter.push(value);
                }
              }
            }
          }
        }
      }

      sorter.sort(this.sortAttributes);

      for (var prop in sorter) {
        mediaAttributes[sorter[prop].name] = sorter[prop].value;
      }

      // The following 5 ifs are dedicated to IE7
      // If the style is null, it is because IE7 can't read values from itself
      if (jQuery.browser.msie && jQuery.browser.version == '7.0') {
        if (mediaAttributes.style === "null") {
          var imgHeight = imgNode.css('height');
          var imgWidth = imgNode.css('width');
          mediaAttributes.style = {
            height: imgHeight,
            width: imgWidth
          }
          if (!mediaAttributes['width']) {
            mediaAttributes['width'] = imgWidth;
          }
          if (!mediaAttributes['height']) {
            mediaAttributes['height'] = imgHeight;
          }
        }
        // If the attribute width is zero, get the CSS width
        if (Number(mediaAttributes['width']) === 0) {
          mediaAttributes['width'] = imgNode.css('width');
        }
        // IE7 does support 'auto' as a value of the width attribute. It will not
        // display the image if this value is allowed to pass through
        if (mediaAttributes['width'] === 'auto') {
          delete mediaAttributes['width'];
        }
        // If the attribute height is zero, get the CSS height
        if (Number(mediaAttributes['height']) === 0) {
          mediaAttributes['height'] = imgNode.css('height');
        }
        // IE7 does support 'auto' as a value of the height attribute. It will not
        // display the image if this value is allowed to pass through
        if (mediaAttributes['height'] === 'auto') {
          delete mediaAttributes['height'];
        }
      }

      // Remove elements from attribs using the blacklist
      for (var blackList in Drupal.settings.media.blacklist) {
        delete mediaAttributes[Drupal.settings.media.blacklist[blackList]];
      }
      tagContent = {
        "type": 'media',
        // @todo: This will be selected from the format form
        "view_mode": attributes['view_mode'].value,
        "fid" : attributes['fid'].value,
        "attributes": mediaAttributes
      };
      return '[[' + JSON.stringify(tagContent) + ']]';
    },

    /**
       * Forces custom attributes into the class field of the specified image.
       *
       * Due to a bug in some versions of Firefox
       * (http://forums.mozillazine.org/viewtopic.php?f=9&t=1991855), the
       * custom attributes used to share information about the image are
       * being stripped as the image markup is set into the rich text
       * editor.  Here we encode these attributes into the class field so
       * the data survives.
       *
       * @param imgElement
       *   The image
       * @fid
       *   The file id.
       * @param view_mode
       *   The view mode.
       * @param additional
       *   Additional attributes to add to the image.
       */
    forceAttributesIntoClass: function (imgElement, fid, view_mode, additional) {
      var wysiwyg = imgElement.attr('wysiwyg');
      if (wysiwyg) {
        imgElement.addClass('attr__wysiwyg__' + wysiwyg);
      }
      var format = imgElement.attr('format');
      if (format) {
        imgElement.addClass('attr__format__' + format);
      }
      var typeOf = imgElement.attr('typeof');
      if (typeOf) {
        imgElement.addClass('attr__typeof__' + typeOf);
      }
      if (fid) {
        imgElement.addClass('img__fid__' + fid);
      }
      if (view_mode) {
        imgElement.addClass('img__view_mode__' + view_mode);
      }
      if (additional) {
        for (var name in additional) {
          if (additional.hasOwnProperty(name)) {
            if (name !== 'alt') {
              imgElement.addClass('attr__' + name + '__' + additional[name]);
            }
          }
        }
      }
    },

    /**
       * Retrieves encoded attributes from the specified class string.
       *
       * @param classString
       *   A string containing the value of the class attribute.
       * @return
       *   An array containing the attribute names as keys, and an object
       *   with the name, value, and attribute type (either 'attr' or
       *   'img', depending on whether it is an image attribute or should
       *   be it the attributes section)
       */
    getAttributesFromClass: function (classString) {
      var actualClasses = [];
      var otherAttributes = [];
      var classes = classString.split(' ');
      var regexp = new RegExp('^(attr|img)__([^\S]*)__([^\S]*)$');
      for (var index = 0; index < classes.length; index++) {
        var matches = classes[index].match(regexp);
        if (matches && matches.length === 4) {
          otherAttributes[matches[2]] = {
            name: matches[2],
            value: matches[3],
            type: matches[1]
          };
        }
        else {
          actualClasses.push(classes[index]);
        }
      }
      if (actualClasses.length > 0) {
        otherAttributes['class'] = {
          name: 'class',
          value: actualClasses.join(' '),
          type: 'attr'
        };
      }
      return otherAttributes;
    },

    sortAttributes: function (a, b) {
      var nameA = a.name.toLowerCase();
      var nameB = b.name.toLowerCase();
      if (nameA < nameB) {
        return -1;
      }
      if (nameA > nameB) {
        return 1;
      }
      return 0;
    }
  };

})(jQuery);
;/**/
/* Above code came from sites/all/modules/contrib/ckeditor/plugins/media/library.js */

/*
Copyright (c) 2003-2011, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/
if (typeof window.CKEDITOR_BASEPATH === 'undefined') {
  window.CKEDITOR_BASEPATH = Drupal.settings.ckeditor.editor_path;
}
(function ($) {
  Drupal.ckeditor = (typeof(CKEDITOR) != 'undefined');
  Drupal.ckeditor_ver = false;

  Drupal.ckeditorToggle = function(textarea_ids, TextTextarea, TextRTE){
    if (!CKEDITOR.env.isCompatible) {
      return;
    }

    for (i=0; i<textarea_ids.length; i++){
      if (typeof(CKEDITOR.instances) != 'undefined' && typeof(CKEDITOR.instances[textarea_ids[i]]) != 'undefined'){
        Drupal.ckeditorOff(textarea_ids[i]);
        $('#switch_' + textarea_ids[i]).text(TextRTE);
      }
      else {
        Drupal.ckeditorOn(textarea_ids[i]);
        $('#switch_' + textarea_ids[i]).text(TextTextarea);
      }
    }
  };

  /**
 * CKEditor starting function
 *
 * @param string textarea_id
 */
  Drupal.ckeditorInit = function(textarea_id) {
    var ckeditor_obj = Drupal.settings.ckeditor;
    $("#" + textarea_id).next(".grippie").css("display", "none");
    $("#" + textarea_id).addClass("ckeditor-processed");

    var textarea_settings = false;
    ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]].toolbar = eval(ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]].toolbar);
    textarea_settings = ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]];

    var drupalTopToolbar = $('#toolbar, #admin-menu', Drupal.overlayChild ? window.parent.document : document);

    textarea_settings['on'] =
    {
      configLoaded  : function(ev)
      {
        Drupal.ckeditor_ver = CKEDITOR.version.split('.')[0];
        if (Drupal.ckeditor_ver == 3) {
          ev.editor.addCss(ev.editor.config.extraCss);
        }
        else {
          CKEDITOR.addCss(ev.editor.config.extraCss);
        }
        // Let Drupal trigger formUpdated event [#1895278]
        ev.editor.on('change', function(ev) {
          $(ev.editor.element.$).trigger('change');
        });
        ev.editor.on('blur', function(ev) {
          $(ev.editor.element.$).trigger('blur');
        });
        ev.editor.on('focus', function(ev) {
          $(ev.editor.element.$).trigger('click');
        });
      },
      instanceReady : function(ev)
      {
        var body = $(ev.editor.document.$.body);
        if (typeof(ev.editor.dataProcessor.writer.setRules) != 'undefined') {
          ev.editor.dataProcessor.writer.setRules('p', {
            breakAfterOpen: false
          });

          if (typeof(ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]].custom_formatting) != 'undefined') {
            var dtd = CKEDITOR.dtd;
            for ( var e in CKEDITOR.tools.extend( {}, dtd.$block, dtd.$listItem, dtd.$tableContent ) ) {
              ev.editor.dataProcessor.writer.setRules( e, ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]].custom_formatting);
            }
            ev.editor.dataProcessor.writer.setRules( 'pre',
            {
              indent: ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]].output_pre_indent
            });
          }
        }

        if (ev.editor.config.bodyClass)
          body.addClass(ev.editor.config.bodyClass);
        if (ev.editor.config.bodyId)
          body.attr('id', ev.editor.config.bodyId);
        if (typeof(Drupal.smileysAttach) != 'undefined' && typeof(ev.editor.dataProcessor.writer) != 'undefined')
          ev.editor.dataProcessor.writer.indentationChars = '    ';

        // Let Drupal trigger formUpdated event [#1895278]
        ((ev.editor.editable && ev.editor.editable()) || ev.editor.document.getBody()).on( 'keyup', function() {
          $(ev.editor.element.$).trigger('keyup');
        });
        ((ev.editor.editable && ev.editor.editable()) || ev.editor.document.getBody()).on( 'keydown', function() {
          $(ev.editor.element.$).trigger('keydown');
        });
      },
      focus : function(ev)
      {
        Drupal.ckeditorInstance = ev.editor;
        Drupal.ckeditorActiveId = ev.editor.name;
      },
      afterCommandExec: function(ev)
      {
        if (ev.data.name != 'maximize') {
          return;
        }
        if (ev.data.command.state == CKEDITOR.TRISTATE_ON) {
          drupalTopToolbar.hide();
        } else {
          drupalTopToolbar.show();
        }
      }
    };

    if (typeof Drupal.settings.ckeditor.scayt_language != 'undefined'){
      textarea_settings['scayt_sLang'] = Drupal.settings.ckeditor.scayt_language;
    }

    if (typeof textarea_settings['js_conf'] != 'undefined'){
      for (var add_conf in textarea_settings['js_conf']){
        textarea_settings[add_conf] = eval(textarea_settings['js_conf'][add_conf]);
      }
    }

    //remove width 100% from settings because this may cause problems with theme css
    if (textarea_settings.width == '100%') textarea_settings.width = '';

    if (CKEDITOR.loadFullCore) {
      CKEDITOR.on('loaded', function() {
        textarea_settings = Drupal.ckeditorLoadPlugins(textarea_settings);
        Drupal.ckeditorInstance = CKEDITOR.replace(textarea_id, textarea_settings);
      });
      CKEDITOR.loadFullCore();
    }
    else {
      textarea_settings = Drupal.ckeditorLoadPlugins(textarea_settings);
      Drupal.ckeditorInstance = CKEDITOR.replace(textarea_id, textarea_settings);
    }
  }

  Drupal.ckeditorOn = function(textarea_id, run_filter) {

    run_filter = typeof(run_filter) != 'undefined' ? run_filter : true;

    if (typeof(textarea_id) == 'undefined' || textarea_id.length == 0 || $("#" + textarea_id).length == 0) {
      return;
    }
    if ((typeof(Drupal.settings.ckeditor.load_timeout) == 'undefined') && (typeof(CKEDITOR.instances[textarea_id]) != 'undefined')) {
      return;
    }
    if (typeof(Drupal.settings.ckeditor.elements[textarea_id]) == 'undefined') {
      return;
    }
    var ckeditor_obj = Drupal.settings.ckeditor;

    if (!CKEDITOR.env.isCompatible) {
      return;
    }

    if (run_filter && ($("#" + textarea_id).val().length > 0) && typeof(ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]]) != 'undefined' && ((ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]]['ss'] == 1 && typeof(Drupal.settings.ckeditor.autostart) != 'undefined' && typeof(Drupal.settings.ckeditor.autostart[textarea_id]) != 'undefined') || ckeditor_obj.input_formats[ckeditor_obj.elements[textarea_id]]['ss'] == 2)) {
      $.ajax({
        type: 'POST',
        url: Drupal.settings.ckeditor.xss_url,
        async: false,
        data: {
          text: $('#' + textarea_id).val(),
          input_format: ckeditor_obj.textarea_default_format[textarea_id],
          token: Drupal.settings.ckeditor.ajaxToken
        },
        success: function(text){
          $("#" + textarea_id).val(text);
          Drupal.ckeditorInit(textarea_id);
        }
      })
    }
    else {
      Drupal.ckeditorInit(textarea_id);
    }
  };

  /**
 * CKEditor destroy function
 *
 * @param string textarea_id
 */
  Drupal.ckeditorOff = function(textarea_id) {
    if (!CKEDITOR.instances || typeof(CKEDITOR.instances[textarea_id]) == 'undefined') {
      return;
    }
    if (!CKEDITOR.env.isCompatible) {
      return;
    }
    if (Drupal.ckeditorInstance && Drupal.ckeditorInstance.name == textarea_id)
      delete Drupal.ckeditorInstance;

    $("#" + textarea_id).val(CKEDITOR.instances[textarea_id].getData());
    CKEDITOR.instances[textarea_id].destroy(true);

    $("#" + textarea_id).next(".grippie").css("display", "block");
  };

  /**
* Loading selected CKEditor plugins
*
* @param object textarea_settings
*/
  Drupal.ckeditorLoadPlugins = function(textarea_settings) {
    if (typeof(textarea_settings.extraPlugins) == 'undefined') {
      textarea_settings.extraPlugins = '';
    }
    if (typeof CKEDITOR.plugins != 'undefined') {
      for (var plugin in textarea_settings['loadPlugins']) {
        if (typeof(textarea_settings['loadPlugins'][plugin]['active']) == 'undefined' || textarea_settings['loadPlugins'][plugin]['active'] == 1) {
          textarea_settings.extraPlugins += (textarea_settings.extraPlugins) ? ',' + textarea_settings['loadPlugins'][plugin]['name'] : textarea_settings['loadPlugins'][plugin]['name'];
          CKEDITOR.plugins.addExternal(textarea_settings['loadPlugins'][plugin]['name'], textarea_settings['loadPlugins'][plugin]['path']);
        }
      }
    }
    return textarea_settings;
  }

  /**
 * Returns true if CKEDITOR.version >= version
 */
  Drupal.ckeditorCompareVersion = function (version){
    var ckver = CKEDITOR.version;
    ckver = ckver.match(/(([\d]\.)+[\d]+)/i);
    version = version.match(/((\d+\.)+[\d]+)/i);
    ckver = ckver[0].split('.');
    version = version[0].split('.');
    for (var x in ckver) {
      if (ckver[x]<version[x]) {
        return false;
      }
      else if (ckver[x]>version[x]) {
        return true;
      }
    }
    return true;
  };

  Drupal.ckeditorInsertHtml = function(html) {
    if (!Drupal.ckeditorInstance)
      return false;

    if (Drupal.ckeditorInstance.mode == 'wysiwyg') {
      Drupal.ckeditorInstance.insertHtml(html);
      return true;
    }
    else {
      alert(Drupal.t('Content can only be inserted into CKEditor in the WYSIWYG mode.'));
      return false;
    }
  };

  /**
 * Ajax support
 */
  if (typeof(Drupal.Ajax) != 'undefined' && typeof(Drupal.Ajax.plugins) != 'undefined') {
    Drupal.Ajax.plugins.CKEditor = function(hook, args) {
      if (hook === 'submit' && typeof(CKEDITOR.instances) != 'undefined') {
        for (var i in CKEDITOR.instances)
          CKEDITOR.instances[i].updateElement();
      }
      return true;
    };
  }

  //Support for Panels [#679976]
  Drupal.ckeditorSubmitAjaxForm = function () {
    if (typeof(CKEDITOR.instances) != 'undefined' && typeof(CKEDITOR.instances['edit-body']) != 'undefined') {
      Drupal.ckeditorOff('edit-body');
    }
  };

  function attachCKEditor(context) {
    // make sure the textarea behavior is run first, to get a correctly sized grippie
    if (Drupal.behaviors.textarea && Drupal.behaviors.textarea.attach) {
      Drupal.behaviors.textarea.attach(context);
    }

    $(context).find("textarea.ckeditor-mod:not(.ckeditor-processed)").each(function () {
      var ta_id=$(this).attr("id");
      if (CKEDITOR.instances && typeof(CKEDITOR.instances[ta_id]) != 'undefined'){
        Drupal.ckeditorOff(ta_id);
      }

      if ((typeof(Drupal.settings.ckeditor.autostart) != 'undefined') && (typeof(Drupal.settings.ckeditor.autostart[ta_id]) != 'undefined')) {
        Drupal.ckeditorOn(ta_id);
      }

      if (typeof(Drupal.settings.ckeditor.input_formats[Drupal.settings.ckeditor.elements[ta_id]]) != 'undefined') {
        $('.ckeditor_links').show();
      }

      var sel_format = $("#" + ta_id.substr(0, ta_id.lastIndexOf("-")) + "-format--2");
      if (sel_format && sel_format.not('.ckeditor-processed')) {
        sel_format.addClass('ckeditor-processed').change(function() {
          Drupal.settings.ckeditor.elements[ta_id] = $(this).val();
          if (CKEDITOR.instances && typeof(CKEDITOR.instances[ta_id]) != 'undefined') {
            $('#'+ta_id).val(CKEDITOR.instances[ta_id].getData());
          }
          Drupal.ckeditorOff(ta_id);
          if (typeof(Drupal.settings.ckeditor.input_formats[$(this).val()]) != 'undefined'){
            if ($('#'+ta_id).hasClass('ckeditor-processed')) {
              Drupal.ckeditorOn(ta_id, false);
            }
            else {
              Drupal.ckeditorOn(ta_id);
            }
            $('#switch_'+ta_id).show();
          }
          else {
            $('#switch_'+ta_id).hide();
          }
        });
      }
    });
  }

  /**
 * Drupal behaviors
 */
  Drupal.behaviors.ckeditor = {
    attach:
    function (context) {
      // If CKEDITOR is undefined and script is loaded from CDN, wait up to 15 seconds until it loads [#2244817]
      if ((typeof(CKEDITOR) == 'undefined') && Drupal.settings.ckeditor.editor_path.match(/^(http(s)?:)?\/\//i)) {
        if (typeof(Drupal.settings.ckeditor.loadAttempts) == 'undefined') {
          Drupal.settings.ckeditor.loadAttempts = 50;
        }
        if (Drupal.settings.ckeditor.loadAttempts > 0) {
          Drupal.settings.ckeditor.loadAttempts--;
          window.setTimeout(function() {
            Drupal.behaviors.ckeditor.attach(context);
          }, 300);
        }
        return;
      }
      if ((typeof(CKEDITOR) == 'undefined') || !CKEDITOR.env.isCompatible) {
        return;
      }
      attachCKEditor(context);
    },
    detach:
    function(context, settings, trigger){
      $(context).find("textarea.ckeditor-mod.ckeditor-processed").each(function () {
        var ta_id=$(this).attr("id");
        if (CKEDITOR.instances[ta_id])
          $('#'+ta_id).val(CKEDITOR.instances[ta_id].getData());
        if(trigger != 'serialize') {
          Drupal.ckeditorOff(ta_id);
          $(this).removeClass('ckeditor-processed');
        }
      });
    }
  };

  // Support CTools detach event.
  $(document).bind('CToolsDetachBehaviors', function(event, context) {
    Drupal.behaviors.ckeditor.detach(context, {}, 'unload');
  });
})(jQuery);

/**
 * IMCE support
 */
var ckeditor_imceSendTo = function (file, win){
  var cfunc = win.location.href.split('&');

  for (var x in cfunc) {
    if (cfunc[x].match(/^CKEditorFuncNum=\d+$/)) {
      cfunc = cfunc[x].split('=');
      break;
    }
  }
  CKEDITOR.tools.callFunction(cfunc[1], file.url);
  win.close();
}

;/**/
/* Above code came from sites/all/modules/contrib/ckeditor/includes/ckeditor.utils.js */

﻿/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

(function(){if(window.CKEDITOR&&window.CKEDITOR.dom)return;if(!window.CKEDITOR)window.CKEDITOR=(function(){var a={timestamp:'D03G5XL',version:'3.6.6',revision:'7689',rnd:Math.floor(Math.random()*900)+100,_:{},status:'unloaded',basePath:(function(){var d=window.CKEDITOR_BASEPATH||'';if(!d){var e=document.getElementsByTagName('script');for(var f=0;f<e.length;f++){var g=e[f].src.match(/(^|.*[\\\/])ckeditor(?:_basic)?(?:_source)?.js(?:\?.*)?$/i);if(g){d=g[1];break;}}}if(d.indexOf(':/')==-1)if(d.indexOf('/')===0)d=location.href.match(/^.*?:\/\/[^\/]*/)[0]+d;else d=location.href.match(/^[^\?]*\/(?:)/)[0]+d;if(!d)throw 'The CKEditor installation path could not be automatically detected. Please set the global variable "CKEDITOR_BASEPATH" before creating editor instances.';return d;})(),getUrl:function(d){if(d.indexOf(':/')==-1&&d.indexOf('/')!==0)d=this.basePath+d;if(this.timestamp&&d.charAt(d.length-1)!='/'&&!/[&?]t=/.test(d))d+=(d.indexOf('?')>=0?'&':'?')+'t='+this.timestamp;return d;}},b=window.CKEDITOR_GETURL;if(b){var c=a.getUrl;a.getUrl=function(d){return b.call(a,d)||c.call(a,d);};}return a;})();var a=CKEDITOR;if(!a.event){a.event=function(){};a.event.implementOn=function(b){var c=a.event.prototype;for(var d in c){if(b[d]==undefined)b[d]=c[d];}};a.event.prototype=(function(){var b=function(d){var e=d.getPrivate&&d.getPrivate()||d._||(d._={});return e.events||(e.events={});},c=function(d){this.name=d;this.listeners=[];};c.prototype={getListenerIndex:function(d){for(var e=0,f=this.listeners;e<f.length;e++){if(f[e].fn==d)return e;}return-1;}};return{on:function(d,e,f,g,h){var i=b(this),j=i[d]||(i[d]=new c(d));if(j.getListenerIndex(e)<0){var k=j.listeners;if(!f)f=this;if(isNaN(h))h=10;var l=this,m=function(o,p,q,r){var s={name:d,sender:this,editor:o,data:p,listenerData:g,stop:q,cancel:r,removeListener:function(){l.removeListener(d,e);}};e.call(f,s);return s.data;};m.fn=e;m.priority=h;for(var n=k.length-1;n>=0;n--){if(k[n].priority<=h){k.splice(n+1,0,m);return;}}k.unshift(m);}},fire:(function(){var d=false,e=function(){d=true;},f=false,g=function(){f=true;};return function(h,i,j){var k=b(this)[h],l=d,m=f;d=f=false;if(k){var n=k.listeners;if(n.length){n=n.slice(0);for(var o=0;o<n.length;o++){var p=n[o].call(this,j,i,e,g);if(typeof p!='undefined')i=p;if(d||f)break;}}}var q=f||(typeof i=='undefined'?false:i);d=l;f=m;return q;};})(),fireOnce:function(d,e,f){var g=this.fire(d,e,f);delete b(this)[d];return g;},removeListener:function(d,e){var f=b(this)[d];if(f){var g=f.getListenerIndex(e);
if(g>=0)f.listeners.splice(g,1);}},hasListeners:function(d){var e=b(this)[d];return e&&e.listeners.length>0;}};})();}if(!a.editor){a.ELEMENT_MODE_NONE=0;a.ELEMENT_MODE_REPLACE=1;a.ELEMENT_MODE_APPENDTO=2;a.editor=function(b,c,d,e){var f=this;f._={instanceConfig:b,element:c,data:e};f.elementMode=d||0;a.event.call(f);f._init();};a.editor.replace=function(b,c){var d=b;if(typeof d!='object'){d=document.getElementById(b);if(d&&d.tagName.toLowerCase() in {style:1,script:1,base:1,link:1,meta:1,title:1})d=null;if(!d){var e=0,f=document.getElementsByName(b);while((d=f[e++])&&d.tagName.toLowerCase()!='textarea'){}}if(!d)throw '[CKEDITOR.editor.replace] The element with id or name "'+b+'" was not found.';}d.style.visibility='hidden';return new a.editor(c,d,1);};a.editor.appendTo=function(b,c,d){var e=b;if(typeof e!='object'){e=document.getElementById(b);if(!e)throw '[CKEDITOR.editor.appendTo] The element with id "'+b+'" was not found.';}return new a.editor(c,e,2,d);};a.editor.prototype={_init:function(){var b=a.editor._pending||(a.editor._pending=[]);b.push(this);},fire:function(b,c){return a.event.prototype.fire.call(this,b,c,this);},fireOnce:function(b,c){return a.event.prototype.fireOnce.call(this,b,c,this);}};a.event.implementOn(a.editor.prototype,true);}if(!a.env)a.env=(function(){var b=navigator.userAgent.toLowerCase(),c=window.opera,d={ie:/*@cc_on!@*/false,opera:!!c&&c.version,webkit:b.indexOf(' applewebkit/')>-1,air:b.indexOf(' adobeair/')>-1,mac:b.indexOf('macintosh')>-1,quirks:document.compatMode=='BackCompat',mobile:b.indexOf('mobile')>-1,iOS:/(ipad|iphone|ipod)/.test(b),isCustomDomain:function(){if(!this.ie)return false;var g=document.domain,h=window.location.hostname;return g!=h&&g!='['+h+']';},secure:location.protocol=='https:'};d.gecko=navigator.product=='Gecko'&&!d.webkit&&!d.opera;var e=0;if(d.ie){e=parseFloat(b.match(/msie (\d+)/)[1]);d.ie8=!!document.documentMode;d.ie8Compat=document.documentMode==8;d.ie9Compat=document.documentMode==9;d.ie7Compat=e==7&&!document.documentMode||document.documentMode==7;d.ie6Compat=e<7||d.quirks;}if(d.gecko){var f=b.match(/rv:([\d\.]+)/);if(f){f=f[1].split('.');e=f[0]*10000+(f[1]||0)*100+ +(f[2]||0);}}if(d.opera)e=parseFloat(c.version());if(d.air)e=parseFloat(b.match(/ adobeair\/(\d+)/)[1]);if(d.webkit)e=parseFloat(b.match(/ applewebkit\/(\d+)/)[1]);d.version=e;d.isCompatible=d.iOS&&e>=534||!d.mobile&&(d.ie&&e>=6||d.gecko&&e>=10801||d.opera&&e>=9.5||d.air&&e>=1||d.webkit&&e>=522||false);d.cssClass='cke_browser_'+(d.ie?'ie':d.gecko?'gecko':d.opera?'opera':d.webkit?'webkit':'unknown');
if(d.quirks)d.cssClass+=' cke_browser_quirks';if(d.ie){d.cssClass+=' cke_browser_ie'+(d.version<7?'6':d.version>=8?document.documentMode:'7');if(d.quirks)d.cssClass+=' cke_browser_iequirks';if(document.documentMode&&document.documentMode>=9)d.cssClass+=' cke_browser_ie9plus';}if(d.gecko&&e<10900)d.cssClass+=' cke_browser_gecko18';if(d.air)d.cssClass+=' cke_browser_air';return d;})();var b=a.env;var c=b.ie;if(a.status=='unloaded')(function(){a.event.implementOn(a);a.loadFullCore=function(){if(a.status!='basic_ready'){a.loadFullCore._load=1;return;}delete a.loadFullCore;var e=document.createElement('script');e.type='text/javascript';e.src=a.basePath+'ckeditor.js';document.getElementsByTagName('head')[0].appendChild(e);};a.loadFullCoreTimeout=0;a.replaceClass='ckeditor';a.replaceByClassEnabled=1;var d=function(e,f,g,h){if(b.isCompatible){if(a.loadFullCore)a.loadFullCore();var i=g(e,f,h);a.add(i);return i;}return null;};a.replace=function(e,f){return d(e,f,a.editor.replace);};a.appendTo=function(e,f,g){return d(e,f,a.editor.appendTo,g);};a.add=function(e){var f=this._.pending||(this._.pending=[]);f.push(e);};a.replaceAll=function(){var e=document.getElementsByTagName('textarea');for(var f=0;f<e.length;f++){var g=null,h=e[f];if(!h.name&&!h.id)continue;if(typeof arguments[0]=='string'){var i=new RegExp('(?:^|\\s)'+arguments[0]+'(?:$|\\s)');if(!i.test(h.className))continue;}else if(typeof arguments[0]=='function'){g={};if(arguments[0](h,g)===false)continue;}this.replace(h,g);}};(function(){var e=function(){var f=a.loadFullCore,g=a.loadFullCoreTimeout;if(a.replaceByClassEnabled)a.replaceAll(a.replaceClass);a.status='basic_ready';if(f&&f._load)f();else if(g)setTimeout(function(){if(a.loadFullCore)a.loadFullCore();},g*1000);};if(window.addEventListener)window.addEventListener('load',e,false);else if(window.attachEvent)window.attachEvent('onload',e);})();a.status='basic_loaded';})();})();
;/**/
/* Above code came from sites/all/libraries/ckeditor/ckeditor_basic.js */

