
(function ($) {
    
  Drupal.behaviors.populateFullName = {
    attach: function(context) {
      $( "#edit-profile-trainer-field-full-name-und-0-value" ).change(function() {
          $("#edit-profile-trainer-field-trainer-billing-address-und-0-name-line").val(this.value);
      });
    }
  };
  
  })(jQuery);
