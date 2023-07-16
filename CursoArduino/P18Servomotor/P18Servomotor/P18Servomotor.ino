#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
}

void loop() {
  int pot = analogRead(A0);
  pot = map(pot, 0, 1023, 0, 180);
  servo.write(pot);
  delay(15);
}
