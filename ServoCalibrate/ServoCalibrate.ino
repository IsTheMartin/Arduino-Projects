#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(8);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

  while(Serial.available())
  {
  int dato = Serial.parseInt();
  servo.writeMicroseconds(dato);
  delay(15);
  }
}
