  int pin1 = 7;
  int ledpin1 = 13;
  int val1 = 0;
  int pin2 = 6;
  int ledpin2 = 12;
  int val2 = 0;
void setup()
{
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val1 = analogRead(pin1);
  if(val1>600)
    digitalWrite(ledpin1, HIGH);
  else
    digitalWrite(ledpin1, LOW);
  Serial.println(val1);
  val2 = analogRead(pin2);
  if(val2>600)
    digitalWrite(ledpin2, HIGH);
  else
    digitalWrite(ledpin2, LOW);
 // Serial.println(val2);
}
