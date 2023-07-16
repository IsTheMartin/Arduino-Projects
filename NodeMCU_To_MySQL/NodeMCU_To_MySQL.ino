#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>

const char* ssid = "CatarsisWIDI";
const char* pass = "3314434995mM";

const char* host = "192.168.100.9";
const String sHost = "192.168.100.9";
const int port = 90;

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client;
  if(!client.connect(host, port)){
    Serial.println("Connection failed");
    return;
  }

  String url = "/nodemcu/webservices/";
  String scriptWrite = "register.php?";
  String scriptRead = "searching.php?";
  String closeURL = " HTTP/1.1\r\nHost: " + sHost + "\r\nConnection: close\r\n\r\n";

  String sAmpersand = "&";
  String sPinname = "pinname=";
  String sPinmode = "pinmode=";
  String sPinstate = "pinstate=";

  String sendToWrite = "GET " + url + scriptWrite + sPinname + "led1" + sAmpersand + sPinmode + "output" + sAmpersand + sPinstate + "1" + closeURL;
  Serial.print("Requesting URL: ");
  Serial.println(sendToWrite);

  client.print(sendToWrite);
  
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  delay(2000);
}
