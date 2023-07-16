#include<Wire.h>

const int MPU_addr = 0x68; //DIRECCION I2C DEL MPU6050
int16_t AcelX, AcelY, AcelZ, Temp, GiroX, GiroY, GiroZ;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); //REGISTRO PWR_MGMT_1
  Wire.write(0);  //SET TO ZERO (DESPIERTA EL MPU)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B); //EMPIEZA CON EL REGISTRO (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  AcelX = Wire.read() << 8|Wire.read();
  Serial.print("Aceleracion X = "); Serial.println(AcelX);
  AcelY = Wire.read() << 8|Wire.read();
  Serial.print("Aceleracion Y = "); Serial.println(AcelY);
  AcelZ = Wire.read() << 8|Wire.read();
  Serial.print("Aceleracion Z = "); Serial.println(AcelZ);
  Temp = Wire.read() << 8|Wire.read();
  Serial.print("Temperatura C° = "); Serial.println(Temp/340.00+36.56);
  GiroX = Wire.read() << 8|Wire.read();
  Serial.print("Giroscopio X = "); Serial.println(GiroX);
  GiroY = Wire.read() << 8|Wire.read();
  Serial.print("Giroscopio Y = "); Serial.println(GiroY);
  GiroZ = Wire.read() << 8|Wire.read();
  Serial.print("Giroscopio Z = "); Serial.println(GiroZ);
  delay(333);
}
