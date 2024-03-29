//plc_ip_address.php
//https://lhnam.000webhostapp.com/plc_ip_address.php?api_key=abc123&device=NODEMCU1&value=192.168.100.5

<?php

$servername = "localhost";

//  Database name
$dbname = "id6963370_scada";
//  Database user
$username = "id6963370_shindong0411";
//  Database user password
$password = "4tHang11";

// If you change this value, the ESP32 sketch needs to match
$api_key_value = "abc123";

$api_key= $device = $value = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $api_key = test_input($_POST["api_key"]);
    if($api_key == $api_key_value) {
        $device = test_input($_POST["device"]);
        $value = test_input($_POST["value"]);
        
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
        
        $sql = "INSERT INTO PLCData (device, value)
        VALUES ('" . $device . "', '" . $value . "')";
        
        if ($conn->query($sql) === TRUE) {
            echo "New record created successfully";
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();
    }
    else {
        echo "Wrong API Key provided.";
    }

}
else {
    echo "No data posted with HTTP POST.";
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}