<?php
$arr_data = array();
$json = file_get_contents('database.json');
$data = json_decode($json, true);
$arr_data = $data;

$table= $_POST['table'];
$seatId= $_POST['seatID'];
$status= $_POST['status'];
$members= $_POST['members'];

foreach ($arr_data as $key => $edntry) {
    if ($entry['table'] == $table) {
        $arr_data[$key]['table'] = $table;
        $arr_data[$key]['seatID'] = $seatId;
        $arr_data[$key]['status'] = $status;
        $arr_data[$key]['members'] = $members;
    }
}
$newJsonString = json_encode($arr_data,JSON_PRETTY_PRINT| JSON_UNESCAPED_SLASHES);
file_put_contents('database.json', $newJsonString);
?>