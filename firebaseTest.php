<?php
require_once 'firebaseLib.php';
// --- This is your Firebase URL
$url = 'https://YOUR_PROJECT.firebaseio.com/';
// --- Use your token from Firebase here
$token = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx';
// --- Here is your parameter from the http GET
$arduino_data = $_GET['arduino_data'];

$DT = new DateTime( 'now', new DateTimeZone( 'America/Sao_Paulo') );
$firebasePath = "/";
/// --- Making calls
$fb = new fireBase($url, $token);
$response = $fb->push($firebasePath . $arduino_data, $DT->format( "d/m/Y - h:i:s a" ));

printf("Result: %s\n", $response);
sleep(2);