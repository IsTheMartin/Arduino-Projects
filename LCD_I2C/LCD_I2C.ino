#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //Creating a new instance from LCD putting the address of the  I2C Module, number of characters and number of rows.

void setup() {
  // put your setup code here, to run once:
  lcd.init(); //Initializing lcd
  lcd.backlight(); //Turning on the backlight
}

void loop() {
  lcd.setCursor(0,0); //Setting the cursor on column 0 and row 0
  lcd.print("Hola mundo"); //Printing the phrase
  lcd.setCursor(0,1); //Setting the cursor on column 0 and row 1
  lcd.print(millis()/1000); //Printing the phrase
}
