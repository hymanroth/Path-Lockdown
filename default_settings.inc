<?php
// $Id$ 

/* Settings file for the Path Lockdown module
 * 
 * Note: To prevent this file getting clobbered, do not modify it directly.
 *       Instead, copy it to settings.inc (in the same folder) and then modify settings.inc
 *       The module will automatically detect the presence of settings.inc and use it if it exists.
 * 
 *       Depending on your setup, you will almost certainly have to add some root paths to the 'system' array below.
 *       Run Path Lockdown first, and then make a note of which paths are showing-up in your 'site' section.
 *       Then add them to the 'system' array in your settings.inc file.
 *       
 *       For usage instructions see the README file.
 * 
 */

function _plockdown_settings($file){
  
  return array(
    'file'      => $file,  // appears at the top of Path Lockdown output - useful to know which config file is being used
    'key'       => 'pl',   // used for the enabling query string and the hash basis for the cookie name
    'pwd'       => 'pwd',  // to enable Path Lockdown you must add a query of the following form to any Drupal url: ?key=pwd (where key and pwd are defined above)
    'menu_path' => 'pl',   // to avoid conflicts (and for security), you can specify which menu path the module responds to (remember to rebuild your menus!) 
  
    'system' => array(     // any root menu path not in this list will be considered a 'site' path. Add your own depending on your setup
       'admin', 'admin_menu','advanced_help','batch','content','ctools','devel','filter','filefield','help','js','logout',
       'node','nodereference','noderelationships','panels','rss.xml','sites','system','taxonomy','upload','user','userreference',
       'test','test2','test3', //ctools!
      ),
      
     'format' => array(
        'wrapper_start' => '<PRE>',    // all Path Lockdown output is wrapped inside these two tags..
        'wrapper_end'   => '</PRE>',
      
        'path_width_sum'    => 50,     // width (in chars) of path field in summary section
        'path_width_det'    => 80,     // width (in chars) of path field in details section
        'pad_char'          => '.',    // char used to pad out path field
          
        //each line of output in both summary and detail sections is wrapped inside these tags, based on the menu access status.
        
        's_aic' => "<span style='color:red'>",   // summary: all items closed, detail: path closed
        'e_aic' => "</span><br>",
      
        's_aio' => "<span style='color:green'>", // summary: all items open,   detail: path open
        'e_aio' => "</span><br>",
      
        's_aim' => "<span style='color:blue'>",  // summary: mixed, some open, some closed, detail: path not found
        'e_aim' => "</span><br>",
      )  
  );
}  