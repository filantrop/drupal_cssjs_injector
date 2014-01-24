<?php

function cssjs_injector_drush_help($command) {
  switch ($command) {
    case 'drush:cssjs-viewrules':
      return dt('Shows all defined rules.');
  }
}

function cssjs_injector_drush_command() {
  $items = array();
  $items['cssjs-viewrules'] = array(
    'description' => dt('Shows all defined cssjs-rules.'),
    'arguments'   => array(
      'filter'    => dt('Used to filter out a specific rule'),
    ),
    'examples' => array(
      'Standard example' => 'drush cssjs-viewrules',
      'Argument example' => 'drush cssjs-viewrules --filter=',
    ),
    'aliases' => array('cjr'),
	'bootstrap' => DRUSH_BOOTSTRAP_SITE, // No bootstrap at all.	
  );
  return $items;
}

function drush_cssjs_injector_cssjs_viewrules($filter = NULL) {
  //check if the argument was passed in and just print it out
  if (isset($filter)) {
   drush_print($filter);
  }
  else {

    $obj = cssjs_injector_loadrules();
    
    foreach($obj->rules as $rule) {

    	drush_print(serialize($rule)."\n");
		
		

    }     
  }
 
  //log to the command line with an OK status
  drush_log('Shows defined cssjs-rules', 'ok');
}



?>
