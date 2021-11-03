<?php
  $ang1 = $_POST['ang1'];
  $ang2 = $_POST['ang2'];
  $ang3 = $_POST['ang3'];
  $ang4 = $_POST['ang4'];
  $ang5 = $_POST['ang5'];
  $ang6 = $_POST['ang6'];

  $info = "[" . date("Y m d H:i:s") . "]". ";" . $ang1 . ";" . $ang2 . ";" . $ang3 . ";" . $ang3 . ";" . $ang4 . ";" . $ang5 . ";" . $ang6 . ";" . "\n";  
  $nombre_archivo = "status.info";
  if($archivo = fopen($nombre_archivo, "w"))
  {
    fwrite($archivo, $info);
    fclose($archivo);
  }

  $nombre_archivo = "historial.info";
  if($archivo = fopen($nombre_archivo, "a"))
  {
    fwrite($archivo, $info);
    fclose($archivo);
  }
  header('Location: /Paginas/act4.html');
  //header('Location: /TI-ISC-Laboratorio4/paginaPrincipal.html');


?>
