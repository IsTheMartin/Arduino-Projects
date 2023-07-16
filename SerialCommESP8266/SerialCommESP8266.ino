#include <SoftwareSerial.h>
SoftwareSerial ESP8266(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ESP8266.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(ESP8266.available() > 0){
    char c = ESP8266.read();
    Serial.write(c);
  }
  while(Serial.available() > 0){
    char c = Serial.read();
    ESP8266.write(c);
  }
}
