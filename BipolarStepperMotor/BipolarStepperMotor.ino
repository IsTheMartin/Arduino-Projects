const int p1 = 8;
const int p2 = 9;
const int p3 = 10;
const int p4 = 11;

void setup() {
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
}
  
void loop() {
  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, LOW);
  digitalWrite(p4, LOW);
  delay(100);

  digitalWrite(p1, LOW);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, HIGH);
  digitalWrite(p4, LOW);
  delay(100);

  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, HIGH);
  digitalWrite(p4, HIGH);
  delay(100);

  digitalWrite(p1, HIGH);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
  digitalWrite(p4, HIGH);
  delay(100);
}
