#include <Servo.h>

Servo g_sMiServo;
int g_nAngulo;
int g_nValor;
const int g_nPinPot = 0;
const int g_nPinServo = 2;
const int g_nPulsoMin = 650;
const int g_nPulsoMax = 2550;

void setup() {
  // put your setup code here, to run once:
  g_sMiServo.attach(g_nPinServo,g_nPulsoMin,g_nPulsoMax);
}

void loop() {
  // put your main code here, to run repeatedly:
  g_nValor = analogRead(g_nPinPot);
  g_nAngulo = map(g_nValor, 0, 1023, 180, 0);
  g_sMiServo.write(g_nAngulo);
  delay(20);
}
