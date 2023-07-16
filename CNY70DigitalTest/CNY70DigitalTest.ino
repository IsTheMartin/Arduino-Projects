int cny70 = 7;
int out = 13;
int val = 0;
int dig = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(cny70, INPUT);
  pinMode(out, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  dig = digitalRead(cny70);
  val = analogRead(cny70);
  digitalWrite(out, dig);
  Serial.println(val);
}
