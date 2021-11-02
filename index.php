<?php
  $ang1 = $_POST['ang1'];
  $ang2 = $_POST['ang2'];

  $info = "[" . date("Y m d H:i:s") . "]". ";" . $ang1 . ";" . $ang2 . ";" . "\n";  
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
  header('Location: /TI-ISC-Laboratorio4/paginaPrincipal.html');

?>
