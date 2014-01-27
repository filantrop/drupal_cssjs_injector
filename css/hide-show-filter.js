(function($) {
    $().ready(function() {
        var elm = $('<a href="">Visa / Dölj Filter</a>').insertAfter('#page-title');
        elm.click(function(event){
                 $('.views-exposed-form').toggle();
                  event.preventDefault();
        });
    });
})(jQuery);
