#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

const char* ssid = "TOTALPLAY";
const char* password = "PASSWORD";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  startingConnection();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void sendDataToMysql(){
  WiFiClient esp8266;
  char server[] = "192.168.100.7";
  if(esp8266.connect(server, 90)){
    esp8266.print("GET /writer.php?field=");
    esp8266.print(5);
    esp8266.print("&value=");
    esp8266.print(66);
    esp8266.println(" HTTP/1.1");
    esp8266.println("Host: 192.168.100.7");
    esp8266.println("Connection: close");
    esp8266.println();
    esp8266.stop();
  }
  else{
    Serial.println("Conexión fallida");
  }
  delay(1000);
}

