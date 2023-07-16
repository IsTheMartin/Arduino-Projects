#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //Creating a new instance from LCD putting the address of the  I2C Module, number of characters and number of rows.

int cny70 = 0;

unsigned long readMillis;  //some global variables available anywhere in the program
unsigned long clearMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long readPeriod = 200;  //the value is a number of milliseconds
const unsigned long clearPeriod = 3000;  //the value is a number of milliseconds

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  readMillis = millis();
  clearMillis = millis();
}

void loop() {
  currentMillis = millis(); //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - readMillis >= readPeriod){  //test whether the period has elapsed
    cny70 = analogRead(A0);
    lcd.setCursor(0,0);
    lcd.print("Read value:");
    lcd.setCursor(0,1);
    lcd.print(cny70);
    Serial.println(cny70);
    readMillis = currentMillis;
  }

  if (currentMillis - clearMillis >= clearPeriod){  //test whether the period has elapsed
    lcd.clear();
    clearMillis = currentMillis;
  }
}
