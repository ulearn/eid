(function ($) {

Drupal.behaviors.initModalFormsContact = {
  attach: function (context, settings) {
    $("a[href*='/contact'], a[href*='?q=contact']", context).once('init-modal-forms-contact', function () {
      var pattern = /user\/[0-9]+\/contact/;
      if (pattern.test(this.href)) {
        // This is a personal contact form.
        this.href = this.href.replace(pattern, 'modal_forms/nojs/' + this.href.match(pattern));
      }
      else {
        // This is a site wide contact form.
        this.href = this.href.replace(/contact/,'modal_forms/nojs/contact');
      }
    }).addClass('ctools-use-modal ctools-modal-modal-popup-medium');
  }
};

})(jQuery);
