#include <Keyboard.h>

int button = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button) == 0)
  {
    Keyboard.write('z');
    delay(1000);
  }
}
