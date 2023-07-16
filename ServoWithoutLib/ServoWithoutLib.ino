int nPeriod, nDutyCycle;
long nAngle;
String readStrings;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  nPeriod = 2500;
  nAngle = 0;
  nDutyCycle = getDutyCycle(nAngle);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readStrings += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }
  if(readStrings.length() > 0){
    nAngle = readStrings.toInt();
    Serial.println(nAngle);
    Serial.println(getDutyCycle(nAngle));
    readStrings = "";
  }

  digitalWrite(8, HIGH);
  delayMicroseconds(getDutyCycle(nAngle));
  digitalWrite(8, LOW);
  delayMicroseconds(nPeriod - getDutyCycle(nAngle));
}

long getDutyCycle(int angle){
  //DutyCycle = (angle * 2000 / 180) + 500
  return (angle * (2000 / 180) ) + 500;
}

