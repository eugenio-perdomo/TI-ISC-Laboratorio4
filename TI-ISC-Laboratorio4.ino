//Eugenio Perdomo, Germán Torres,  Andrés Romano
// Esta es la librería para utilizar las funciones de red del ESP8266
#include <ESP8266WiFi.h> 
#include <stdio.h>
#include <iostream>
#include <string>

const char* ssid = "alfacharly";; // Rellena con el nombre de tu red WiFi
const char* password = "H90zGM364Md"; // Rellena con la contraseña de la red WiFi

const char* host = "192.168.1.6";//IP de host
const char* url_test = "https://192.168.1.6/misphp/Status.info";//Ruta de Status.info
String peticionHTTP= "GET /misphp/Status.info";//Comando de la petición

Servo servoMotor1;

void setup() 
{
  Serial.begin(115200);
  servoMotor1.attach(D4, 500, 2400);
  delay(10);
  // Conectamos a la red WiFi
  Serial.println(url_test); 
  Serial.println();
  Serial.println();
  Serial.print("Conectandose a: ");
  Serial.println(ssid);
 
  /* Configuramos el ESP8266 como cliente WiFi. Si no lo hacemos 
     se configurará como cliente y punto de acceso al mismo tiempo */
  WiFi.mode(WIFI_STA); // Modo cliente WiFi
  WiFi.begin(ssid, password);

  // Esperamos a que estemos conectados a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado"); 
  Serial.println("Direccion IP: ");
  Serial.println(WiFi.localIP()); // Mostramos la IP
  servoMotor1.write(0);
  Serial.println("//---------------------------------------------------------");
}

void loop() {
  Serial.print("conectando a ");
  Serial.println(host);
  // Creamos el cliente
  WiFiClient client;
  const int httpPort = 80; // Puerto HTTP
  
  if (!client.connect(host, httpPort)) {
    // ¿hay algún error al conectar?
    Serial.println("Ha fallado la conexión, todo mal che !");
    return;
  }
  
  Serial.print("URL de la petición: ");
  Serial.print(host);
  Serial.print(":");
  Serial.print(httpPort);
  Serial.println(url_test);
  
  Serial.println("//---------------------------------------------------------");   
  // Enviamos la petición 
  client.println(peticionHTTP);        
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Superado el tiempo de espera !");
      client.stop();
      return;
    }
  }
  Serial.println("Mostrando el contenido de Status.info: ");
 
  // Leemos la respuesta y la enviamos al monitor serie
  while(client.available()){
    line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("//---------------------------------------------------------");
  Serial.print("Este será el estado del led 1: ");
  Led1=line[0];
  Serial.println(Led1);

  Serial.println("Próxima revisión en 5s.");
  Serial.println("//---------------------------------------------------------");
  delay(5000);
}
