int ledPin[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};


void setup() {
  for(int i = 0; i < 10; i++){
    pinMode(ledPin[i], OUTPUT);
  }
  Serial.begin(9600);

}

void loop() {
  int pot = analogRead(A0);
  int mayor = map(pot, 0, 1023, 0, 10);
  for(int i = 0; i < 10; i++){
    if(i < mayor){
      digitalWrite(ledPin[i], HIGH);
    } else {
      digitalWrite(ledPin[i], LOW);
    }
  }
  delay(10);
}
