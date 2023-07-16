#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); //RX TX

int plcInput[] = {8, 9, 10, 11}; //Señales que van a la entrada del PLC
int plcOutput = 12; //Señal que va a la salida del PLC
String dato;
int flagSent = 0, flagReceived = 0;
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(13, OUTPUT);
  for(int i = 0; i > sizeof(plcInput); i++)
    pinMode(plcInput[i], OUTPUT);
  pinMode(plcOutput, INPUT_PULLUP); //cambiar a input
  turnOffOutputs();
}

void loop() {
  if(Serial.available() > 0){
    dato = Serial.readString();
    flagReceived = 1;
  }
  if(flagReceived == 1){
    sendToPLC(dato);
    sendToBT(dato);
    flagReceived = 0;
  }
  if(digitalRead(plcOutput) == 0){
    Serial.println("OK");
    delay(500);
  }
}

void sendToPLC(String modelo){
    digitalWrite(plcInput[0], LOW);
    digitalWrite(plcInput[1], LOW);
    digitalWrite(plcInput[2], LOW);
  if(modelo.equals("1"))
    digitalWrite(plcInput[0], HIGH);
  else if(modelo.equals("2"))
    digitalWrite(plcInput[1], HIGH);
  else if(modelo.equals("3"))
    digitalWrite(plcInput[2], HIGH);

  delay(1000);
  digitalWrite(plcInput[0], LOW);
  digitalWrite(plcInput[1], LOW);
  digitalWrite(plcInput[2], LOW);
}

void sendToBT(String modelo){
  BT.print(modelo);
}

void turnOffOutputs(){
  for(int i = 0; i > sizeof(plcInput); i++)
    digitalWrite(plcInput[i], LOW);
}

