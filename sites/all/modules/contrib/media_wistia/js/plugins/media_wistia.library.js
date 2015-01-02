/**
 *  @file
 *  Create the 'Wistia' tab for the WYSIWYG plugins.
 */

(function ($) {
  namespace('Drupal.media.browser');

  Drupal.behaviors.wistia = {
    attach: function (context, settings) {
      var library = new Drupal.media.browser.wistia(Drupal.settings.media.browser.wistia);
      $('#media-browser-tabset').bind('tabsshow', function (event, ui) {
        if (ui.tab.hash === '#media-tab-wistia') {
          // Grab the parameters from the Drupal.settings object
          var params = {};
          for (var parameter in Drupal.settings.media.browser.wistia) {
            params[parameter] = Drupal.settings.media.browser.wistia[parameter];
          }
          library.start($(ui.panel), params);
        }
      });
    }
  };

  Drupal.media.browser.wistia = function (settings) {
    this.settings = Drupal.media.browser.wistia.getDefaults();
    $.extend(this.settings, settings);

    this.done = false; // Keeps track of if the last request for media returned 0 results.

    this.projectId = 0; // the current project we are viewing
    this.cursor = 0; // keeps track of what the last requested media object was.
    this.end = false; // keeps track if weve got all the wistia videos or not
    this.page = 1; // keeps track of what page we need to request next
    this.projects = []; // An array of wistia projects from the server.
    this.mediaFiles = []; // An array of loaded media files from the server.
    this.selectedMediaFiles = [];
  };

  Drupal.media.browser.wistia.getDefaults = function () {
    return {
      emtpyMessage: Drupal.t('There is nothing in your media wistia library. Select the Upload tab above to add a file.'),
      limit: 15
    };
  };

  Drupal.media.browser.wistia.prototype.start = function (renderElement, params) {
    this.renderElement = renderElement;
    this.params = params;
    this.clickFunction = this.singleSelect;

    this.loadProjects();
  };

  Drupal.media.browser.wistia.prototype.backToProjects = function (event) {
    event.preventDefault();
    var lib = event.data;
    lib.loadProjects();
  };

  Drupal.media.browser.wistia.prototype.loadProjects = function () {
    var that = this;

    $('#media-browser-wistia-list').empty().hide();
    $('#wistia-status').text(Drupal.t('Loading...')).show();

    var gotMedia = function (data, status) {
      $('#media-browser-wistia-list').show();
      $('#wistia-status').text('').hide();
      that.projects = data.media;
      that.render(that.renderElement);
      // Remove the flag that prevents loading of more media
      that.loading = false;
    };

    var errorCallback = function () {
      alert(Drupal.t('Error getting media.'));
    };

    $.ajax({
      url: this.settings.getProjectList,
      type: 'GET',
      dataType: 'json',
      data: this.params,
      error: errorCallback,
      success: gotMedia
    });
  };

  Drupal.media.browser.wistia.prototype.render = function (renderElement) {

    if (this.projects.length < 1) {
      $('<div id="media-empty-message" class="media-empty-message"></div>').appendTo(renderElement)
        .html(this.emptyMessage);
      return;
    }
    else {
      var projectList = $('#media-browser-wistia-list', renderElement);
      projectList.empty();
      // If the list doesn't exist, bail.
      if (projectList.length === 0) {
        throw('Cannot continue, list element is missing');
      }
    }

    var project;
    for(var i in this.projects) {
      project = this.projects[i];

      var data = {};
      data.obj = this;
      data.id = project.id;

      var listItem = $('<a></a>').appendTo(projectList)
        .attr('href', '#')
        .attr('id', 'media-item-' + project.id);

      listItem.append('<h3>' + project.name + '</h3>');
      listItem.bind('click', data, this.openProject);
    }
  };

  Drupal.media.browser.wistia.prototype.openProject = function (event) {
    event.preventDefault();
    event.stopPropagation();

    var lib = event.data.obj;

    lib.cursor = 0;
    lib.page = 1;
    lib.mediaFiles = [];
    lib.projectId = event.data.id;

    var $list = $('#media-browser-wistia-list').empty().hide();
    $('#wistia-status').text(Drupal.t('Loading...')).show();

    var $header = $('<h2></h2>').appendTo($list);
    var $link = $('<a></a>').appendTo($header)
      .attr('href', '#')
      .html(Drupal.t('Back to projects'))
      .bind('click', lib, lib.backToProjects);

    $.extend(lib.params, {start: lib.page, limit: lib.settings.limit, id: lib.projectId});

    var gotMedia = function (data, status) {
      $('#wistia-status').text('').hide();
      $('#media-browser-wistia-list').show();
      if (data.media.length == lib.params.limit) {
        $('#scrollbox', '#media-tab-wistia').bind('scroll', lib, lib.scrollUpdater);
      }
      lib.mediaFiles = lib.mediaFiles.concat(data.media);
      lib.listMedia(lib.renderElement);
      // Remove the flag that prevents loading of more media
      lib.loading = false;
    };

    var errorCallback = function () {
      alert(Drupal.t('Error getting media.'));
    };

    $.ajax({
      url: lib.settings.getProject,
      type: 'GET',
      dataType: 'json',
      data: lib.params,
      error: errorCallback,
      success: gotMedia
    });
  };

  /**
   * Appends more media onto the list
   */
  Drupal.media.browser.wistia.prototype.loadMedia = function () {
    var that = this;
    $('#wistia-status').text(Drupal.t('Loading...')).show();

    this.page++;

    $.extend(this.params, {start: this.page, limit: this.settings.limit, id: this.projectId});

    var gotMedia = function (data, status) {
      $('#wistia-status').text('').hide();
      if (data.media.length < that.params.limit) {
        $('#scrollbox', '#media-tab-wistia').unbind('scroll');
      }
      that.mediaFiles = that.mediaFiles.concat(data.media);
      that.listMedia(that.renderElement);
      // Remove the flag that prevents loading of more media
      that.loading = false;
    };

    var errorCallback = function () {
      alert(Drupal.t('Error getting media.'));
    };

    $.ajax({
      url: this.settings.getProject,
      type: 'GET',
      dataType: 'json',
      data: this.params,
      error: errorCallback,
      success: gotMedia
    });
  };

  Drupal.media.browser.wistia.prototype.listMedia = function (renderElement) {

    if (this.mediaFiles.length < 1) {
      $('<div id="media-empty-message" class="media-empty-message"></div>').appendTo(renderElement)
        .html(this.emptyMessage);
      return;
    }
    else {
      var mediaList = $('#media-browser-wistia-list', renderElement);
      // If the list doesn't exist, bail.
      if (mediaList.length === 0) {
        throw('Cannot continue, list element is missing');
      }
    }

    while (this.cursor < this.mediaFiles.length) {
      var mediaFile = this.getNextMedia();

      var data = {};
      data.obj = this;
      data.id = mediaFile.file.id;
      data.file = mediaFile.file;

//      data.file.fid = mediaFile.hashed_id;

      var listItem = $('<li></li>').appendTo(mediaList)
        .attr('id', 'media-item-' + mediaFile.id)
        .html(mediaFile.file.preview)
        .bind('click', data, this.clickFunction);
    }
  };

  /**
   * Fetches the next media object and increments the cursor.
   */
  Drupal.media.browser.wistia.prototype.getNextMedia = function () {
    if (this.cursor >= this.mediaFiles.length) {
      return false;
    }
    var ret = this.mediaFiles[this.cursor];
    this.cursor += 1;
    return ret;
  };

  Drupal.media.browser.wistia.prototype.scrollUpdater = function (e) {
    if (!e.data.loading) {
      var scrollbox = $('#scrollbox', '#media-tab-wistia');
      var scrolltop = scrollbox.attr('scrollTop');
      var scrollheight = scrollbox.attr('scrollHeight');
      var windowheight = scrollbox.attr('clientHeight');
      var scrolloffset = 20;

      if (scrolltop >= (scrollheight - (windowheight + scrolloffset))) {
        // Set a flag so we don't make multiple concurrent AJAX calls
        e.data.loading = true;
        // Fetch new items
        e.data.loadMedia();
      }
    }
  };

  Drupal.media.browser.wistia.prototype.mediaSelected = function (media) {
    Drupal.media.browser.selectMedia(media);
  };

  Drupal.media.browser.wistia.prototype.singleSelect = function (event) {
    var lib = event.data.obj;
    var file = event.data.file;
    event.preventDefault();
    event.stopPropagation();

    $('.media-item').removeClass('selected');
    $('.media-item', $(this)).addClass('selected');
    lib.mediaSelected([file]);
    return false;
  };

}(jQuery));
