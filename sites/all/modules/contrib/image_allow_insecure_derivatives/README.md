Image Allow Insecure Derivatives
================================

Drupal 7.20 comes with a security fix that changes all image derivative URLs
generated by Drupal to append a token as a query string. ("Image derivatives"
are copies of images which the Drupal Image module automatically creates based
on configured image styles; for example, thumbnail, medium, large, etc.)

As an example, links that previously pointed to a URL like:

    /sites/default/files/styles/thumbnail/public/field/image/example.png

will now point to a URL like:

    /sites/default/files/styles/thumbnail/public/field/image/example.png?itok=zD_VaCaD.

For more information on the security improvement, visit the
[release notes](https://drupal.org/drupal-7.20-release-notes).

This is a fantastic security improvement, but in certain cases, has some
ramifications. This module provides a configuration setting in order to toggle
whether or not Drupal bypasses that token check.


Warning
-------

Only use this module if you know what you're doing. It can result in security
instabilities.


Installation
------------

1. Install the module as usual at:

   `sites/all/modules/image_allow_insecure_derivatives`

2. Enable the module in `admin/modules`.

3. The module defaults to allow insecure derivatives, but that can be toggled:

   `admin/config/media/image-toolkit`

4. Troubleshoot by making sure the variable isn't already set in settings.php:

   ```php
   $conf['image_allow_insecure_derivatives'] = TRUE;
   ```