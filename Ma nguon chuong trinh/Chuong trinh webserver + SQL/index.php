<!DOCTYPE html>
<html>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <head>
     <style>
h1 { 
    algin: center;
  display: block;
  font-size: 2em;
  margin-top: 0.67em;
  margin-bottom: 0.67em;
  margin-left: 0;
  margin-right: 0;
  font-weight: bold;
}
table {
  width:100%;
  text-align: center;
}
table, th, td {
  border: 1px solid black;
  border-collapse: collapse;
}
th, td {
  padding: 15px;
  text-align: center;
}
</style>
    </head>
<body align="center";>
    <h1>Bảng cập nhập IP Address PLC</h1>
    <hr>
    <br>
<?php
 
$servername = "localhost";
 
// REPLACE with your Database name
$dbname = "id6963370_scada";
// REPLACE with Database user
$username = "id6963370_shindong0411";
// REPLACE with Database user password
$password = "4tHang11";
 
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
 
$sql = "SELECT id, device, value, reading_time FROM PLCData ORDER BY id DESC";
 
echo '<table cellspacing="5" cellpadding="5">
      <tr> 
        <td>ID</td> 
        <td>Thiết bị</td> 
        <td>IP Address</td> 
        <td>Thời gian</td> 
      </tr>';
 
if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_device = $row["device"];
        $row_value = $row["value"];
        $row_reading_time = $row["reading_time"];
        // Uncomment to set timezone to - 1 hour (you can change 1 to any number)
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time - 1 hours"));
      
        // Uncomment to set timezone to + 4 hours (you can change 4 to any number)
        $row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time + 7 hours"));
      
        echo '<tr> 
                <td>' . $row_id . '</td> 
                <td>' . $row_device . '</td> 
                <td>' . $row_value . '</td> 
                <td>' . $row_reading_time . '</td> 
              </tr>';
    }
    $result->free();
}