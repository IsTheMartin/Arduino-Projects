#include<Tone.h>
#include<Wire.h>
const int GY521 = 0x68;  // I2C address of the MPU-6050
int16_t X, Y, Z;
const int GY45 = 0x1C;
int16_t AX, AY, AZ;
int bocina = 9;
int bocina2 = 10;
int boton = 8;
int boton2 = 7;
int izquierda, estadoBoton, estadoBoton2, derecha;
Tone sonido1;
Tone sonido2;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(GY521);
  Wire.write(0x6B);  //
  Wire.write(0);     //
  Wire.endTransmission(true);
  Wire.begin();
  Wire.beginTransmission(GY45);
  Wire.write(0x2A);     // set to zero (wakes up the MPU-6050)
  Wire.write(0x01);
  Wire.endTransmission(true);
  sonido1.begin(bocina);
  sonido2.begin(bocina2);
  pinMode(bocina, OUTPUT);
  pinMode(bocina2,OUTPUT);
  pinMode(boton, INPUT);
  pinMode(boton2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  estadoBoton = digitalRead(boton);
  izquierda = gy521();
  if (estadoBoton == HIGH)
  {
    if (izquierda == 1)
      sonido1.play(NOTE_E4);
    else if (izquierda == 2)
      sonido1.play(NOTE_D4);
    else if (izquierda == 3)
      sonido1.play(NOTE_A4);
    else if (izquierda == 4)
      sonido1.play(NOTE_C4);
    else if (izquierda == 5)
      sonido1.play(NOTE_F4);
    else if (izquierda == 6)
      sonido1.play(NOTE_G4);
    else
      sonido1.stop();
  }
  else
    sonido1.stop();
    
  estadoBoton2 = digitalRead(boton2);
  derecha = gy45();

  if (estadoBoton2 == HIGH)
  {
    if (derecha == 1)
      sonido2.play(NOTE_A4);
    else if (derecha == 2)
      sonido2.play(NOTE_B4);
    else if (derecha == 3)
      sonido2.play(NOTE_E4);
    else if (derecha == 4)
      sonido2.play(NOTE_F4);
    else if (derecha== 5)
      sonido2.play(NOTE_C5);
    else if (derecha == 6)
      sonido2.play(NOTE_G4);
    else
      sonido2.stop();
  }
  else
    sonido2.stop();

  delay(50);
}

int gy521()
{
  Wire.beginTransmission(GY521);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(GY521, 6, true); // request a total of 14 registers
  X = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  Y = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  Z = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)*/
  Serial.print("GY-521: X = "); Serial.print(X);
  Serial.print(" | Y = "); Serial.print(Y);
  Serial.print(" | Z = "); Serial.print(Z);

  if (Z > 13000 && Z < 18000)//E
    return 1;
  else if (X > 10000 && X < 18000) //D
    return 2;
  else if (Y > 10000 && Y < 18000) //A  
    return 3;
  else if (Z > -18000 && Z < -7000) // C
    return 4;
  else if (X > -18000 && X < -9000) //F
    return 5;
  else if (Y > -18000 && Y < -10000) //G
    return 6;
  else
    return 0;
}

int gy45()
{
  Wire.beginTransmission(GY45);
  Wire.write(0x01);
  Wire.endTransmission(false);
  Wire.requestFrom(GY45, 6, true);
  AX = Wire.read() << 8 | Wire.read();
  AY = Wire.read() << 8 | Wire.read();
  AZ = Wire.read() << 8 | Wire.read();
  Serial.print("    //    GY-45: AX = "); Serial.print(AX);
  Serial.print(" | AY = "); Serial.print(AY);
  Serial.print(" | AZ = "); Serial.println(AZ);

  if (AZ > 10000 && AZ < 18000)//A
    return 1;
  else if(AX > 10000 && AX < 18000)//B
    return 2;
  else if (AY > 10000 && AY < 18000)//E
    return 3;
  else if (AZ > -18000 && AZ < -9000)//F
    return 4; 
  else if (AX > -18000 && AX < -9000)//C
    return 5;
  else if (AY > -18000 && AY < -9000)//G
    return 6; 
    
    else
    return 0;
}
    

