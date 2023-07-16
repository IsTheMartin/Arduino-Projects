const int relay = 12;
const int button = 9;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(relay, LOW);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(button));
  if(digitalRead(button) == HIGH)
    digitalWrite(relay, HIGH);
  else
    digitalWrite(relay, LOW);
  delay(500);
}
