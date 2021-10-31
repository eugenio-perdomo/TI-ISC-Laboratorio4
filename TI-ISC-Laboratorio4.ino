#include <SPI.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

void setup_init();
void wifi_init();
void servo_init();
void ejecutarServos();
void recibePosiciones(String angulo, Servo numeroDeServo, int posActual, int posPrevia);

const char* ssid = "Tu-RED"; // Rellena con el nombre de tu red WiFi
const char* password = "Tu.Clave"; // Rellena con la contraseña de la red WiFi
const char* host = "192.168.1.7"; // Direccion IP o nombre
const char* url_test = "http://192.168.1.7/iot/form/status.info"; // status.info tiene los datos separados con ";"
const char* apiKey = "kikirikikiiii"; // Se puede usar una validacion simple para aceptar el GET

String dataRecibida = "";
Servo servo1, servo2, servo3, servo4, servo5, servo6;
int servo1PosActual, servo2PosActual, servo3PosActual, servo4PosActual, servo5PosActual, servo6PosActual;
int servo1PosPrevia, servo2PosPrevia, servo3PosPrevia, servo4PosPrevia, servo5PosPrevia, servo6PosPrevia;

void setup_init() {
  Serial.begin(9600);
  /* Configura el ESP8266 como cliente WiFi. Si no se hace
    se configura como cliente y punto de acceso al mismo tiempo */
  WiFi.mode(WIFI_STA); // Modo cliente WiFi
  WiFi.begin(ssid, password);

  // Espera a estar conectado a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
}

void wifi_init() {
  // Crear el cliente
  WiFiClient client;
  const int httpPort = 80; // Puerto HTTP
  if (!client.connect(host, httpPort)) {  // Si hay error al conectar
    Serial.println("Ha fallado la conexión, todo mal che !");
    return;
  }
}

// TODO: Definir cual es la posición inicial para cada uno, [0,180]
void servo_init() {
  // Pin al que va el servo
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);
  servo5.attach(9);
  servo6.attach(10);
  // Posición inicial del brazo del robot
  servo1PosPrevia = 0;
  servo2PosPrevia = 0;
  servo3PosPrevia = 0;
  servo4PosPrevia = 0;
  servo5PosPrevia = 0;
  servo6PosPrevia = 0;
  // Mueve el servo
  servo1.write(servo1PosPrevia);
  servo2.write(servo2PosPrevia);
  servo3.write(servo3PosPrevia);
  servo4.write(servo4PosPrevia);
  servo5.write(servo5PosPrevia);
  servo6.write(servo6PosPrevia);
}

void ejecutarServos() {
  // Pongo una posibilidad con la data recibida de la peticion
  // dataRecibida se la podemos pasar como parametro a esta funcion
  // Puede venir: servo1180, en donde servo -1- va a ser el cual mover
  // y 180 el angulo.
  String numeroDeServoAMover = dataRecibida.substring(5, 1);
  String angulo = dataRecibida.substring(6, dataRecibida.length());
  numeroDeServoAMover.toInt();
  angulo.toInt();
  switch (numeroDeServoAMover) {
    case 1:
      recibePosiciones(angulo, servo1, servo1PosActual, servo1PosPrevia);
      break;
    case 2:
      recibePosiciones(angulo, servo2, servo2PosActual, servo2PosPrevia);
      break;
    case 3:
      recibePosiciones(angulo, servo3, servo3PosActual, servo3PosPrevia);
      break;
    case 4:
      recibePosiciones(angulo, servo4, servo4PosActual, servo4PosPrevia);
      break;
    case 5:
      recibePosiciones(angulo, servo5, servo5PosActual, servo5PosPrevia);
      break;
    case 6:
      recibePosiciones(angulo, servo6, servo6PosActual, servo6PosPrevia);
      break;
  }
}

void recibePosiciones(String angulo, Servo numeroDeServo, int posActual, int posPrevia) {
  posActual = angulo;
  if (posPrevia > posActual) {
    for ( int i = posPrevia; i >= posActual; i--) {
      numeroDeServo.write(i);
      delay(50);
    }
  }
  if (posPrevia < posActual) {
    for ( int j = posPrevia; j <= posActual; j++) {
      numeroDeServo.write(j);
      delay(50);
    }
  }
  posPrevia = posActual;
}

void setup() {
  setup_init();
  servo_init();
}

void loop() {
  wifi_init();
}
