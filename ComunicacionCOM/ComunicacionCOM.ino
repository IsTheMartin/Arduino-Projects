void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String incomingString;
  while(Serial.available() > 0)
  {
    incomingString = Serial.readString();
    if(incomingString == "si")
      Serial.println("ok");
    else if(incomingString.equals("no"))
      Serial.println(">.<");
  }
}
