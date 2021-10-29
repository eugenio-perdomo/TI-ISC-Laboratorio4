#include <SPI.h>

void setup_init();
void wifi_init();
void servo_init();

String readString;
File myFile;

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = { 192, 168, 0, 177 };
byte server[] = { 192, 168, 0, 114 };


void wifi_init() {

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for (;;)
      ;
  }

  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      cadena.concat(c);
      Serial.print(c);
    }
  }
  delay(1);
  client.stop();
}

void setup_init() {
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  
}

// Aqui ver los pines de la placa
void servo_init() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

void setup() {
  setup_init();
  servo_init();
}

void loop() {
  wifi_init();
}
