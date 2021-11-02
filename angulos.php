<!DOCTYPE html>
<html>
<title>ServoMotorAngulos</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
<style>


  .topnav {
    overflow: hidden;
    background-color: #333;
  }

  .topnav a {
    float: left;
    display: block;
    color: #f2f2f2;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    font-size: 17px;
  }

  .topnav a:hover {
    background-color: #ddd;
    color: black;
  }

  .topnav a.active {
    background-color: #04AA6D;
    color: white;
  }

  .topnav .icon {
    display: none;
  }

</style>


<div class="topnav" class="w3-bar w3-white w3-center w3-padding w3-opacity-max w3-hover-opacity-on">
    <a href="index.php" style="width:20%" class="w3-bar-item w3-button" class="active">INICIO</a>
    <a href="angulos.php" style="width:20%" class="w3-bar-item w3-button">ANGULOS</a>
  </div>
</div>

<!-- Navbar (sticky bottom) -->
</body>
</html>

<?php
if($fp = fopen("status.info", "r"))
{
  echo "<br>";
  while (!feof($fp)){
      $linea = fgets($fp);
      echo $linea . "<br>";
  }
}

?>