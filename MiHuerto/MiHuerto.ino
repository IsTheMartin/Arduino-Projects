#include <ESP8266WiFi.h>
#include <Firebase.h>
#include <ArduinoJson.h>
#include <FirebaseArduino.h>
#include <FirebaseError.h>

#define WIFI_SSID "CatarsisWIDI"
#define WIFI_PASSWORD "3314434995mM"

#define FIREBASE_HOST "elhuerto-220218.firebaseio.com"
#define FIREBASE_AUTH "eiUNYwMUAG0Izn4PzguZML6GTAlcUOgilhkE9jYE"

int mostureSensorPin = A0;
int humidityValue = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while(WiFi.status() != WL_CONNECTED){
    delay(300);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(100);
}

void loop() {
  getHumidity();
  setIrrigate();
  delay(2000);
}

void getHumidity(){
  humidityValue = map(analogRead(mostureSensorPin),0,1024,100,0);
  Firebase.setInt("martin/huerto1/humedad", humidityValue);
  Serial.print("Humedad: ");
  Serial.println(humidityValue);
}

void setIrrigate(){
  String irrigate = Firebase.getString("martin/huerto1/riego");
  Serial.print("Riego: ");
  Serial.println(irrigate);
  if(irrigate.equals("Activado")){
    delay(5000);
    Firebase.setString("martin/huerto1/riego", "Desactivado");
  }
}
