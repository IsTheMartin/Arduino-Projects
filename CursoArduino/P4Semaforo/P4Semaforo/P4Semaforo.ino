const int ledRed1 = 2;
const int ledYellow1 = 3;
const int ledGreen1 = 4;

const int ledRed2 = 6;
const int ledYellow2 = 7;
const int ledGreen2 = 8;

unsigned long ledOnRed1Interval = 6000;
unsigned long ledOffRed1Interval = 12000;
unsigned long ledOnYellow1Interval = 5000;
unsigned long ledOffYellow1Interval = 6000;
unsigned long ledOnGreen1Interval = 0;
unsigned long ledOffGreen1Interval = 5000;

unsigned long ledOnRed2Interval = 0;
unsigned long ledOffRed2Interval = 6000;
unsigned long ledOnYellow2Interval = 11000;
unsigned long ledOffYellow2Interval = 12000;
unsigned long ledOnGreen2Interval = 6000;
unsigned long ledOffGreen2Interval = 11000;

unsigned long previousMillis = 0;

void setup() {
  pinMode(ledRed1, OUTPUT);
  pinMode(ledYellow1, OUTPUT);
  pinMode(ledGreen1, OUTPUT);
  pinMode(ledRed2, OUTPUT);
  pinMode(ledYellow2, OUTPUT);
  pinMode(ledGreen2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  //Semaforo 1
  if(currentMillis - previousMillis > ledOnGreen1Interval){
    digitalWrite(ledGreen1, HIGH);
  }
  if(currentMillis - previousMillis > ledOffGreen1Interval){
    digitalWrite(ledGreen1, LOW);
  }
  if(currentMillis - previousMillis > ledOnYellow1Interval){
    digitalWrite(ledYellow1, HIGH);
  }
  if(currentMillis - previousMillis > ledOffYellow1Interval){
    digitalWrite(ledYellow1, LOW);
  }
  if(currentMillis - previousMillis > ledOnRed1Interval){
    digitalWrite(ledRed1, HIGH);
  }
  if(currentMillis - previousMillis > ledOffRed1Interval){
    digitalWrite(ledRed1, LOW);
  }

  //Semaforo 2
  if(currentMillis - previousMillis > ledOnGreen2Interval){
    digitalWrite(ledGreen2, HIGH);
  }
  if(currentMillis - previousMillis > ledOffGreen2Interval){
    digitalWrite(ledGreen2, LOW);
  }
  if(currentMillis - previousMillis > ledOnYellow2Interval){
    digitalWrite(ledYellow2, HIGH);
  }
  if(currentMillis - previousMillis > ledOffYellow2Interval){
    //previousMillis = currentMillis;
    digitalWrite(ledYellow2, LOW);
  }
  if(currentMillis - previousMillis > ledOnRed2Interval){
    digitalWrite(ledRed2, HIGH);
  }
  if(currentMillis - previousMillis > ledOffRed2Interval){
    digitalWrite(ledRed2, LOW);
  }

  //Reinicio de millis actual
  if(currentMillis - previousMillis > 12000){
    previousMillis = currentMillis;
  }
}
