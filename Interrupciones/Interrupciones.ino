const byte led1 = 13;
const byte led2 = 12;
const byte interrupt = 2;
volatile byte state1 = LOW;
volatile byte state2 = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interrupt), cambio, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, state1);
  digitalWrite(led2, state2);
}

void cambio(){
  state1= !state1;
  state2= !state2;
}

