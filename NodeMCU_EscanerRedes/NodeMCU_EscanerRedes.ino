#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println(" ");
  Serial.println("Modo Workstation");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Escaneando redes");
  int R = WiFi.scanNetworks();
  if (R == 0){
    Serial.println("No hay redes disponibles");
    digitalWrite(12, LOW);
  }
  else{
    Serial.print(R);
    Serial.println(" redes encontradas");
    for (int i=0; i<R; ++i){
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");
  delay(5000);
}
