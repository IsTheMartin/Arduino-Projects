#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x25,20,4);  // set the LCD address to 0x20 for a 16 chars and 2 line display

void setup()
{
  lcd.begin(20,4);                      // initialize the lcd 

  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop()
{
}
