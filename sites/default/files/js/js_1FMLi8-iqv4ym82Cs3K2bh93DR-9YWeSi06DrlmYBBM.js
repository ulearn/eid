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
;
(function ($) {

Drupal.mollom = Drupal.mollom || {};

/**
 * Open links to Mollom.com in a new window.
 *
 * Required for valid XHTML Strict markup.
 */
Drupal.behaviors.mollomTarget = {
  attach: function (context) {
    $(context).find('.mollom-target').click(function () {
      this.target = '_blank';
    });
  }
};

/**
 * Retrieve and attach the form behavior analysis tracking image if it has not
 * yet been added for the form.
 */
Drupal.behaviors.mollomFBA = {
  attach: function (context, settings) {
    $(':input[name="mollom[fba]"][value=""]', context).once().each(function() {
      $input = $(this);
      $.ajax({
        url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'mollom/fba',
        type: 'POST',
        dataType: 'json',
        success: function(data) {
          if (!data.tracking_id || !data.tracking_url) {
            return;
          }
          // Save the tracking id in the hidden field.
          $input.val(data.tracking_id);
          // Attach the tracking image.
          $('<img src="' + data.tracking_url + '" width="1" height="1" alt="" />').appendTo('body');
        }
      })
    });
  }
};

 /**
 * Attach click event handlers for CAPTCHA links.
 */
Drupal.behaviors.mollomCaptcha = {
  attach: function (context, settings) {
    $('a.mollom-switch-captcha', context).click(function (e) {
      var $mollomForm = $(this).parents('form');
      var newCaptchaType = $(this).hasClass('mollom-audio-captcha') ? 'audio' : 'image';
      Drupal.mollom.getMollomCaptcha(newCaptchaType, $mollomForm);
    });
    $('a.mollom-refresh-captcha', context).click(function (e) {
      var $mollomForm = $(this).parents('form');
      var currentCaptchaType = $(this).hasClass('mollom-refresh-audio') ? 'audio' : 'image';
      Drupal.mollom.getMollomCaptcha(currentCaptchaType, $mollomForm);
    });
  }
};

/**
 * Fetch a Mollom CAPTCHA and output the image or audio into the form.
 *
 * @param captchaType
 *   The type of CAPTCHA to retrieve; one of "audio" or "image".
 * @param context
 *   The form context for this retrieval.
 */
Drupal.mollom.getMollomCaptcha = function (captchaType, context) {
  var formBuildId = $('input[name="form_build_id"]', context).val();
  var mollomContentId = $('input.mollom-content-id', context).val();

  var path = 'mollom/captcha/' + captchaType + '/' + formBuildId;
  if (mollomContentId) {
    path += '/' + mollomContentId;
  }

  // Retrieve a new CAPTCHA.
  $.ajax({
    url: Drupal.settings.basePath + Drupal.settings.pathPrefix + path,
    type: 'POST',
    dataType: 'json',
    success: function (data) {
      if (!(data && data.content)) {
        return;
      }
      // Inject new CAPTCHA.
      $('.mollom-captcha-content', context).parent().html(data.content);
      // Update CAPTCHA ID.
      $('input.mollom-captcha-id', context).val(data.captchaId);
      // Add an onclick-event handler for the new link.
      Drupal.attachBehaviors(context);
      // Focus on the CAPTCHA input.
      if (captchaType == 'image') {
          $('input[name="mollom[captcha]"]', context).focus();
      } else {
         // Focus on audio player.
         // Fallback player code is responsible for setting focus upon embed.
         if ($('#mollom_captcha_audio').is(":visible")) {
             $('#mollom_captcha_audio').focus();
         }
      }
    }
  });
  return false;
}

})(jQuery);
;
(function ($) {

Drupal.googleanalytics = {};

$(document).ready(function() {

  // Attach mousedown, keyup, touchstart events to document only and catch
  // clicks on all elements.
  $(document.body).bind("mousedown keyup touchstart", function(event) {

    // Catch the closest surrounding link of a clicked element.
    $(event.target).closest("a,area").each(function() {

      // Is the clicked URL internal?
      if (Drupal.googleanalytics.isInternal(this.href)) {
        // Skip 'click' tracking, if custom tracking events are bound.
        if ($(this).is('.colorbox')) {
          // Do nothing here. The custom event will handle all tracking.
          //console.info("Click on .colorbox item has been detected.");
        }
        // Is download tracking activated and the file extension configured for download tracking?
        else if (Drupal.settings.googleanalytics.trackDownload && Drupal.googleanalytics.isDownload(this.href)) {
          // Download link clicked.
          ga("send", "event", "Downloads", Drupal.googleanalytics.getDownloadExtension(this.href).toUpperCase(), Drupal.googleanalytics.getPageUrl(this.href));
        }
        else if (Drupal.googleanalytics.isInternalSpecial(this.href)) {
          // Keep the internal URL for Google Analytics website overlay intact.
          ga("send", "pageview", { page: Drupal.googleanalytics.getPageUrl(this.href) });
        }
      }
      else {
        if (Drupal.settings.googleanalytics.trackMailto && $(this).is("a[href^='mailto:'],area[href^='mailto:']")) {
          // Mailto link clicked.
          ga("send", "event", "Mails", "Click", this.href.substring(7));
        }
        else if (Drupal.settings.googleanalytics.trackOutbound && this.href.match(/^\w+:\/\//i)) {
          if (Drupal.settings.googleanalytics.trackDomainMode != 2 && !Drupal.googleanalytics.isCrossDomain(this.hostname, Drupal.settings.googleanalytics.trackCrossDomains)) {
            // External link clicked / No top-level cross domain clicked.
            ga("send", "event", "Outbound links", "Click", this.href);
          }
        }
      }
    });
  });

  // Track hash changes as unique pageviews, if this option has been enabled.
  if (Drupal.settings.googleanalytics.trackUrlFragments) {
    window.onhashchange = function() {
      ga('send', 'pageview', location.pathname + location.search + location.hash);
    }
  }

  // Colorbox: This event triggers when the transition has completed and the
  // newly loaded content has been revealed.
  $(document).bind("cbox_complete", function () {
    var href = $.colorbox.element().attr("href");
    if (href) {
      ga("send", "pageview", { page: Drupal.googleanalytics.getPageUrl(href) });
    }
  });

});

/**
 * Check whether the hostname is part of the cross domains or not.
 *
 * @param string hostname
 *   The hostname of the clicked URL.
 * @param array crossDomains
 *   All cross domain hostnames as JS array.
 *
 * @return boolean
 */
Drupal.googleanalytics.isCrossDomain = function (hostname, crossDomains) {
  /**
   * jQuery < 1.6.3 bug: $.inArray crushes IE6 and Chrome if second argument is
   * `null` or `undefined`, http://bugs.jquery.com/ticket/10076,
   * https://github.com/jquery/jquery/commit/a839af034db2bd934e4d4fa6758a3fed8de74174
   *
   * @todo: Remove/Refactor in D8
   */
  if (!crossDomains) {
    return false;
  }
  else {
    return $.inArray(hostname, crossDomains) > -1 ? true : false;
  }
}

/**
 * Check whether this is a download URL or not.
 *
 * @param string url
 *   The web url to check.
 *
 * @return boolean
 */
Drupal.googleanalytics.isDownload = function (url) {
  var isDownload = new RegExp("\\.(" + Drupal.settings.googleanalytics.trackDownloadExtensions + ")([\?#].*)?$", "i");
  return isDownload.test(url);
}

/**
 * Check whether this is an absolute internal URL or not.
 *
 * @param string url
 *   The web url to check.
 *
 * @return boolean
 */
Drupal.googleanalytics.isInternal = function (url) {
  var isInternal = new RegExp("^(https?):\/\/" + window.location.host, "i");
  return isInternal.test(url);
}

/**
 * Check whether this is a special URL or not.
 *
 * URL types:
 *  - gotwo.module /go/* links.
 *
 * @param string url
 *   The web url to check.
 *
 * @return boolean
 */
Drupal.googleanalytics.isInternalSpecial = function (url) {
  var isInternalSpecial = new RegExp("(\/go\/.*)$", "i");
  return isInternalSpecial.test(url);
}

/**
 * Extract the relative internal URL from an absolute internal URL.
 *
 * Examples:
 * - http://mydomain.com/node/1 -> /node/1
 * - http://example.com/foo/bar -> http://example.com/foo/bar
 *
 * @param string url
 *   The web url to check.
 *
 * @return string
 *   Internal website URL
 */
Drupal.googleanalytics.getPageUrl = function (url) {
  var extractInternalUrl = new RegExp("^(https?):\/\/" + window.location.host, "i");
  return url.replace(extractInternalUrl, '');
}

/**
 * Extract the download file extension from the URL.
 *
 * @param string url
 *   The web url to check.
 *
 * @return string
 *   The file extension of the passed url. e.g. "zip", "txt"
 */
Drupal.googleanalytics.getDownloadExtension = function (url) {
  var extractDownloadextension = new RegExp("\\.(" + Drupal.settings.googleanalytics.trackDownloadExtensions + ")([\?#].*)?$", "i");
  var extension = extractDownloadextension.exec(url);
  return (extension === null) ? '' : extension[1];
}

})(jQuery);
;
