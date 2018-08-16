<?php
$file = 'database.json';
$arr_data = array(); // create empty array
 
 try{
         //Get form data
	  $formdata = array(
	      'table'=> $_POST['table'],
              'seatID'=> $_POST['seatID'],
              'status'=> $_POST['status'],
	      'members'=> array($_POST['members']),
	   );

	   //Get data from existing json file
           $jsondata = file_get_contents($file);
	   // converts json data into array
          $arr_data = json_decode($jsondata, true);
          

	   // Push user data to array
          array_push($arr_data,$formdata);

       //Convert updated array to JSON
	   $jsondata = json_encode($arr_data, JSON_PRETTY_PRINT|JSON_UNESCAPED_SLASHES);
	   
	   //write json data into data.json file
	   if(file_put_contents($file, $jsondata)) {
	        echo 'Data successfully saved';
	    }
	   else 
	        echo "error";

       }
       catch (Exception $e) {
            echo 'Caught exception: ',  $e->getMessage(), "\n";
           
       }
  
?>
 