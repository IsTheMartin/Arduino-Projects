#include <Stepper.h>

const int steps = 64;
Stepper motor(steps, 2,3,4,5);

void setup() {
  
}

void loop() {
  int pot = analogRead(A0);
  int motorSpeed = map(pot, 0, 1023, 0, 100);
  if(motorSpeed > 0){
    motor.setSpeed(motorSpeed);
    motor.step(steps / 64);
  }
  delay(15);
}
