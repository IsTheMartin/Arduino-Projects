#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

const char* ssid = "CatarsisWIDI";
const char* pass = "3314434995mM";

WiFiServer server(8080);
WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Serial.println("");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
   if (!client.connected()) {
        // try to connect to a new client
        client = server.available();
    } else {
        // read data from the connected client
        if (client.available() > 0) {
            Serial.write(client.read());
            
        }
    }
}
