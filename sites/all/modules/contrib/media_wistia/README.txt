
Readme for the Media: Wistia module.
========================================

Media: Wistia integrates with the Media module to make Wistia videos
available as file entities. Users can insert Wistia videos with file fields
 or directly into into WYSIWYG text areas with the Media module insert button.


File fields
==============

- Add a new field of type "File" to your content type or entity. Choose the widget
  type "Media file selector". You can also select an existing file field.
- While setting up the field (or after selecting "edit" on an existing field)
  enable:
    - Allowed remote media types: "Video"
    - Allowed URI schemes: "wistia:// (Wistia videos)"

- On "Manage display" for the file field's content or entity type, choose
  "Rendered file" and a view mode. You can also change the view mode for the field.
- Set up the Wistia video formatter options for each view mode in Configuration ->
  Media -> File types -> Manage file display. This is where you can choose all your
  wistia options.
- When using the file field while creating or editing content, paste a Wistia
  video url into the Web tab.

# Advanced

- If you have a Wistia API Key you can enter this in Configuration -> Web Services
  -> Wistia Settings. This will enable a "Wistia" tab on the media selector where
  you can browse your Wistia projects and videos and select them directly from wistia.


WYSIWYG inserts
==================

- Enable the Media module "Media insert" button on your WYSIWYG profile.
- Enable "Convert Media tags to markup" filter in the appropriate text formats.
- Configure any desired settings in Configuration -> Media -> "Media browser
  settings"
- Set up Wistia video formatter options in Configuration -> Media -> File types
  -> Manage file display. **Note:** for any view mode that will be used in a WYSIWYG,
  enable both the Wistia video and preview image formatter. Arrange the Video
  formatter on top. This allows the video to be used when the content is viewed,
  and the preview when the content is being edited.

- When editing a text area with your WYSIWYG, click the "Media insert" button.