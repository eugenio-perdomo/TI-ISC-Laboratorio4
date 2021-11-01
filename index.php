<?php
if(isset($_POST['submit'])){//Validacion de envio de formulario 
  $ang1 = $_POST['ang1'];
  $ang2 = $_POST['ang2'];


  $info = "[" . date("Y m d H:i:s") . "]". ";" . $ang1 . ";" . $ang2 . ";" . "\n";  
  $nombre_archivo = "status.info";
  if($archivo = fopen($nombre_archivo, "a"))
  {
    if(fwrite($archivo, $info)){
      //echo "Datos transmitidos/recibidos: <br/>";
    }
    else{
      //echo "Ha habido un problema al transferir datos <br/>";
    }
  
    echo $info;

    fclose($archivo);
  }

}

?>

<!DOCTYPE html>
<html>
<title>ServoMotor</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
<style>
body,h1,h2{font-family: "Raleway", sans-serif}
body, html {height: 100%}
.bgimg{
  min-height: 100%;

  background-position: left;

}

.bgimg {background-image: url("img/brazo.png" )}
.box {
  position: relative;
  top: 130px;
  left: 200px;
}
input:invalid+span:after {
  content: '✖';
  padding-left: 5px;
}
input:valid+span:after {
  content: '✓';
  padding-left: 5px;
}
input{
  width: 100px; 
  heigth: 20px; 
  margin: 1.2% auto;;
}

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
  color: blue;
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
<header class="w3-display-container w3-wide bgimg w3-grayscale-min" id="home">
<form action="" method="post">
  <div class="box" align="center">
  <style>
  .slidecontainer {
    width: 100%;
  }

  .slider {
    -webkit-appearance: none;
    width: 100%;
    height: 25px;
    background: #d3d3d3;
    outline: none;
    opacity: 0.7;
    -webkit-transition: .2s;
    transition: opacity .2s;
  }

  .slider:hover {
    opacity: 1;
  }

  .slider::-webkit-slider-thumb {
    -webkit-appearance: none;
    appearance: none;
    width: 25px;
    height: 25px;
    background: #04AA6D;
    cursor: pointer;
  }

  .slider::-moz-range-thumb {
    width: 25px;
    height: 25px;
    background: #04AA6D;
    cursor: pointer;
  }
</style>
</head>

<body>


  <div class="slidecontainer" style="width:500px;">
  <div style = "background-color: #cfc ; padding: 10px; border: 1px solid green;">
    <p>ServoMotor 1: <span class="sliderValue"></span></p>
    <input type="range" name = "ang1" min="1" max="180"  class="slider" id="myRange" oninput="this.nextElementSibling.value = this.value">
    <output>---</output>
  </div>
<body>


  <div class="slidecontainer" style="width:500px;">
  <div style = "background-color: #cfc ; padding: 10px; border: 1px solid green;">
    <p>ServoMotor 2: <span class="sliderValue"></span></p>
    <input type="range" name = "ang2" min="1" max="180"  class="slider" id="myRange" oninput="this.nextElementSibling.value = this.value">
    <output>---</output>
  </div>
</body>


    <input type="submit" name="submit" value="Enviar"/>
  </div>
</form>
</header>
<!-- Navbar (sticky bottom) -->



<!-- Navbar (sticky bottom) -->
</body>
</html>
