#include <Password.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

Password password = Password("1908");
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};
byte rowPins[ROWS] = {6, 7, 1, 0}; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = {10, 9, 8}; 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int ledpin=13;

LiquidCrystal lcd(12,11,5,4,3,2);
void setup ( ) 
{
 kpd.addEventListener(keypadEvent);
 lcd.begin(16,2);
 pinMode(ledpin,OUTPUT);
}
void loop()
{
  char key = kpd.getKey();
  kpd.getKey();
}
void keypadEvent(KeypadEvent ekey)
{
  switch (kpd.getState())
  {
    case PRESSED:
    lcd.setCursor(3,0);
    lcd.print("INGRESAR PASSWORD PARA COMENZAR");
    lcd.setCursor(0,1);
    lcd.print(ekey);
    switch (ekey)
    {
	  case '*': checkPassword(); break;
	  case '#': password.reset(); break;
	  default: password.append(ekey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    digitalWrite(ledpin,OUTPUT);
    lcd.setCursor(3,1);
    lcd.print("BIENVENIDO A DOMOAULA 1.0");
     }else{
     lcd.setCursor(5,1);
    lcd.print("INCORRECTA");
      }
}
