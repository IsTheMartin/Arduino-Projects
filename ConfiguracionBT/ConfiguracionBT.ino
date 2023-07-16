#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); //RX TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available()){
    Serial.write(BT.read());
  }
  if(Serial.available()){
    BT.write(Serial.read());
  }
}
