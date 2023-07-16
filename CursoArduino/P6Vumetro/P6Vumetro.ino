int led_pin[] = {3,4,5,6,7,8,9,10,11,12};
const int TAM = 10;

void setup() {
  for(int i = 0; i < TAM; i++){
    pinMode(led_pin[i], OUTPUT);
    digitalWrite(led_pin[i], LOW);
  }
  Serial.begin(9600);
}

void loop() {
  int pot = analogRead(A0);
  Serial.println(pot);
  int mapping = map(pot, 0, 1023, 0, 10);
  for(int i = 0; i < TAM; i++){
    if(i >= mapping)
      digitalWrite(led_pin[i], HIGH);
    else
      digitalWrite(led_pin[i], LOW);
  }
  delay(10);
}
