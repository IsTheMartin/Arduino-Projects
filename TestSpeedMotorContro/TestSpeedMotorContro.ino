int pote=7;
int motor=3;

void setup(){
 pinMode(pote,INPUT);
}

void loop(){
  int value = analogRead(pote);
  analogWrite(motor,value/4);
}
