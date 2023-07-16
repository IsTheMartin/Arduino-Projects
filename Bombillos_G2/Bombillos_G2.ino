#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); //RX TX

int Micros[] = {4, 5, 6, 7}; //microswitch
int Focos[] = {8, 9, 10, 11}; //focos indicadores
int plcInput = 13; //Señal hacia el PLC
int dato;
int flagReceived = 0;
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  for(int i = 0; i > sizeof(Micros); i++)
    pinMode(Micros[i], INPUT_PULLUP);
  pinMode(Micros[0], INPUT_PULLUP);
  pinMode(Micros[1], INPUT_PULLUP);
  pinMode(Micros[2], INPUT_PULLUP);
  pinMode(Micros[3], INPUT_PULLUP);
  for(int i = 0; i > sizeof(Focos); i++)
    pinMode(Focos[i], OUTPUT);
  pinMode(plcInput, OUTPUT);
  turnOffFocos();
}

void loop() {
  if(BT.available()>0) //Cambiar a BT
  {
    char gato = BT.read();
    turnOffFocos();
    dato = (int)gato;
  }
  if(digitalRead(Micros[0]) == LOW){
    if(dato == 49){
      digitalWrite(Focos[0], LOW);
      enviarPLC();
    }
  }
  else if(digitalRead(Micros[1]) == LOW){
    if(dato == 50){
      digitalWrite(Focos[1], LOW);
      enviarPLC();
    }
  }
  else if(digitalRead(Micros[2]) == LOW){
    if(dato == 51){
      digitalWrite(Focos[2], LOW);
      enviarPLC();
    }
  }
  else if(digitalRead(Micros[3]) == LOW){
    if(dato == 52){
      digitalWrite(Focos[3], LOW);
      enviarPLC();
    }
  }
  else{
    if(dato == 49)
      digitalWrite(Focos[0], HIGH);
    else if(dato == 50)
      digitalWrite(Focos[1], HIGH);
    else if(dato == 51)
      digitalWrite(Focos[2], HIGH);
    else if(dato == 52)
      digitalWrite(Focos[3], HIGH);
    else
      turnOffFocos();
  }
  delay(500);
}

void turnOffFocos(){
  digitalWrite(Focos[0], LOW);
  digitalWrite(Focos[1], LOW);
  digitalWrite(Focos[2], LOW);
  digitalWrite(Focos[3], LOW);
}

void enviarPLC(){
  digitalWrite(plcInput, HIGH);
  delay(100);
  digitalWrite(plcInput, LOW);
}

