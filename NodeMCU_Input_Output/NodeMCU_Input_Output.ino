#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//PIN VARIABLES//
int pinAlarm0 = D0;
int pinAlarm1 = D1;
int pinAlarm2 = D2;
int pinAlarm3 = D3;
int pinAlarm4 = D4;

int lastStateAlarm0 = 0;
int lastStateAlarm1 = 0;
int lastStateAlarm2 = 0;
int lastStateAlarm3 = 0;
int lastStateAlarm4 = 0;
//
unsigned long lastMillis = 0;
const long intervalSendPowerOn = 10000;
const long intervalReadStates = 500;

//NETWORK VARIABLES
const char* ssid = "CatarsisWIDI";
const char* pass = "3314434995mM";
//SERVER VARIABLES
const char* host = "mcuadrada.com";
const String sHost = "mcuadrada.com";
const int port = 80;

String macaddress = WiFi.macAddress();
  

void setup() {
  //PIN CONFIGURATION
  pinMode(pinAlarm0, INPUT);
  pinMode(pinAlarm1, INPUT);
  pinMode(pinAlarm2, INPUT);
  pinMode(pinAlarm3, INPUT);
  pinMode(pinAlarm4, INPUT);
  macaddress.replace(':','-');
  //SERIAL CONFIGURATION
  Serial.begin(115200);
  //TRYING CONNECTION TO NETWORK
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
  //usar cuando por primera vez se configura
  firstTime();
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= intervalSendPowerOn) {
    lastMillis = currentMillis;
    
  }

  if (currentMillis - lastMillis >= intervalReadStates) {
    lastMillis = currentMillis;
    Serial.println("Reading states");
    String fetchDigitalStates = readDigitalSignal();
  
    if(fetchDigitalStates.indexOf("0") > 0){
      Serial.println("Se encontró pinAlarm0");
      int stateAlarm0 = digitalRead(pinAlarm0);
      Serial.println(stateAlarm0);
      Serial.println(lastStateAlarm0);
      if(stateAlarm0 != lastStateAlarm0)
        writeDigitalSignal("pinAlarm0", "output", stateAlarm0);
      lastStateAlarm0 = stateAlarm0;
    }
  
    if(fetchDigitalStates.indexOf("1") > 0){
      Serial.println("Se encontró pinAlarm1");
      int stateAlarm1 = digitalRead(pinAlarm1);
      Serial.println(stateAlarm1);
      Serial.println(lastStateAlarm1);
      if(stateAlarm1 != lastStateAlarm1)
        writeDigitalSignal("pinAlarm1", "output", stateAlarm1);
      lastStateAlarm1 = stateAlarm1;
    }
  
    if(fetchDigitalStates.indexOf("2") > 0){
      Serial.println("Se encontró pinAlarm2");
      int stateAlarm2 = digitalRead(pinAlarm2);
      Serial.println(stateAlarm2);
      Serial.println(lastStateAlarm2);
      if(stateAlarm2 != lastStateAlarm2)
        writeDigitalSignal("pinAlarm2", "output", stateAlarm2);
      lastStateAlarm2 = stateAlarm2;
    }
  
    if(fetchDigitalStates.indexOf("3") > 0){
      Serial.println("Se encontró pinAlarm3");
      int stateAlarm3 = digitalRead(pinAlarm3);
      Serial.println(stateAlarm3);
      Serial.println(lastStateAlarm3);
      if(stateAlarm3 != lastStateAlarm3)
        writeDigitalSignal("pinAlarm3", "output", stateAlarm3);
      lastStateAlarm3 = stateAlarm3;
    }
  
    if(fetchDigitalStates.indexOf("4") > 0){
      Serial.println("Se encontró pinAlarm4");
      int stateAlarm4 = digitalRead(pinAlarm4);
      Serial.println(stateAlarm4);
      Serial.println(lastStateAlarm4);
      if(stateAlarm4 != lastStateAlarm4)
        writeDigitalSignal("pinAlarm4", "output", stateAlarm4);
      lastStateAlarm4 = stateAlarm4;
    }  
  }
} 



void writeDigitalSignal(String pinname, String pinmode, int pinstate){
  String url = "/nodedroid/webservices/";
  String writeScript = "write_states.php?";
  String closeURL = " HTTP/1.1\r\nHost: " + sHost + "\r\nConnection: close\r\n\r\n";
  
  String sAmpersand = "&";
  String sMacAddress = "macaddress=";
  String sPinname = "pinname=";
  String sPinmode = "pinmode=";
  String sPinstate = "pinstate=";
  //String urlSend = "GET " + url + writeScript + sMacAddress + macaddress + sAmpersand + sPinname + pinname + sAmpersand + sPinmode + pinmode + sAmpersand + sPinstate + pinstate + closeURL;
  String urlSend = "GET " + url + writeScript + sMacAddress + macaddress + sAmpersand + sPinname + pinname + sAmpersand + sPinmode + pinmode + sAmpersand + sPinstate + pinstate + sAmpersand + "pinenable=1" + closeURL;

  Serial.print("Requesting URL: ");
  Serial.println(urlSend);

  WiFiClient client;
  if(!client.connect(host, port)){
    Serial.println("Connection failed");
    return;
  }

  client.print(urlSend);
  
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
}

String readDigitalSignal(){
  HTTPClient http;
  String url = "/nodedroid/webservices/";
  String fetchScript = "fetch_states.php?";
  String sAmpersand = "&";
  String sMacAddress = "macaddress=";
  String sPinEnable = "pinenable=";
  String urlSend = "http://"+sHost+":"+port+url+fetchScript+sMacAddress+macaddress+sAmpersand+sPinEnable+"1";
  
  http.begin(urlSend);
  //Serial.println(urlSend);

  int httpCode = http.GET();
  //Serial.println(httpCode);

  String response = "";

  if(httpCode > 0){
    response = http.getString();
    Serial.println(response);
  }

  return response;
}

void firstTime(){
  writeDigitalSignal("pinAlarm0", "output", lastStateAlarm0);
  writeDigitalSignal("pinAlarm1", "output", lastStateAlarm1);
  writeDigitalSignal("pinAlarm2", "output", lastStateAlarm2);
  writeDigitalSignal("pinAlarm3", "output", lastStateAlarm3);
  writeDigitalSignal("pinAlarm4", "output", lastStateAlarm4);
}

