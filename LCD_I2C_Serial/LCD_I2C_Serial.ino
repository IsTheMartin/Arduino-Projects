#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //Creating a new instance from LCD putting the address of the  I2C Module, number of characters and number of rows.
String input, row, column, content;
void setup() {
  // put your setup code here, to run once:
  lcd.init(); //Initializing lcd
  lcd.backlight(); //Turning on the backlight
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    input = Serial.readString();
    content = input.substring(2,input.length()-2);
    column = input.substring(0,1);
    row = input.substring(1,2);
    lcd.clear();
    lcd.setCursor(column.toInt(), row.toInt());
    lcd.print(content); 
  }
}
