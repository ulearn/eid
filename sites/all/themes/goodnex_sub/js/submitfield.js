var active_color = '#000'; // Colour of user provided text
var inactive_color = '#999'; // Colour of default text
jQuery(document).ready(function() {
jQuery("input.form-text").css("color", inactive_color);
var default_values = new Array();
jQuery("input.form-text").focus(function() {
if (!default_values[this.id]) {
default_values[this.id] = this.value;
}
if (this.value == default_values[this.id]) {
this.value = '';
this.style.color = active_color;
}
jQuery(this).blur(function() {
if (this.value == '') {
this.style.color = inactive_color;
this.value = default_values[this.id];
}
});
});
});
jQuery(document).ready(function() {
jQuery("textarea.form-textarea").css("color", inactive_color);
var default_values = new Array();
jQuery("textarea.form-textarea").focus(function() {
if (!default_values[this.id]) {
default_values[this.id] = this.value;
}
if (this.value == default_values[this.id]) {
this.value = '';
this.style.color = active_color;
}
jQuery(this).blur(function() {
if (this.value == '') {
this.style.color = inactive_color;
this.value = default_values[this.id];
}
});
});
});
/* jQuery(".webform-client-form input:text, .webform-client-form textarea").each(function(i){
jQuery(this).data("default", this.value).bind("focus", function(e){
if (jQuery.trim(this.value)==jQuery(this).data("default")) this.value = "";
}).bind("blur", function(e){
if (jQuery.trim(this.value).length==0) this.value = jQuery(this).data("default");
});
}); */