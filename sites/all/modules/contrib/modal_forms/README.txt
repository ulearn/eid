Drupal modal_forms module:
------------------------
Maintainers:
  Fredrik Jonsson (http://drupal.org/user/5546)
Requires - Drupal 7
License - GPL (see LICENSE)


Overview:
--------
Modal forms make use of the modal feature in the ctools module to open
some common forms in a modal window.


Supported forms:
---------------

* Log in (modal_forms/nojs/login)
* Request new password (modal_forms/nojs/password)
* Create new account (modal_forms/nojs/register)
* Contact (modal_forms/nojs/contact)
* Comment (modal_forms/nojs/comment/reply/%node)
* Webform (modal_forms/nojs/webform/%node)

Function that rewrite normal links to modal forms links (except for webforms) can be
activated on the modules configuration page.


Links to the modal version of the forms:
---------------------------------------

JavaScript that can rewrite standard links to these forms in to a modal equivalent are
provided, see the module configuration page to activate them.

To build links in code I recommend using the ctools_modal_text_button() function.

$links[] = ctools_modal_text_button(t('Modal Login'), 'modal_forms/nojs/login', t('Login via modal'));
$links[] = ctools_modal_text_button(t('Modal Login'), 'modal_forms/nojs/login', t('Login via modal'),  'ctools-modal-modal-popup-small');

It is also possible to build links manually.

<a class="ctools-use-modal" href="modal_forms/nojs/login">Modal Login</a>
<a class="ctools-use-modal ctools-modal-modal-popup-small" href="modal_forms/nojs/login">Modal Login</a>

Popup styles and sizes:

The include CSS file tries to mimic the default Colorbox style.

The extra class "ctools-modal-modal-popup-small" in the links above tells the module what
popup style size to use. There are three options included.

* ctools-modal-modal-popup-small (defaults to 300x300)
* ctools-modal-modal-popup-medium (defaults to 550x450)
* ctools-modal-modal-popup-large (defaults to 80%x80%)

Go to the configurations page for Modal forms to adjust the sizes.


Webforms:
--------
There is support to open webforms in a modal by constructing special links.

A webform link should look like this one:

<a class="ctools-use-modal ctools-modal-modal-popup-large" href="/modal_forms/nojs/webform/[nid]">Link to click</a>

Replace [nid] with the node id of your webform.


Installation:
------------
1. Download and unpack the Modal forms module directory in your modules folder
   (this will usually be "sites/all/modules/").
2. Go to "Administer" -> "Modules" and enable the module.


Configuration:
-------------
Go to "Configuration" -> "Development" -> "Modal forms" to find
all the configuration options.
