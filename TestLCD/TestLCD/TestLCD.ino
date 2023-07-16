#include <LiquidCrystal.h> /*Incluyo la librería del display LCD 
                            para poder utilizar las funciones*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); /*Defino los pines del 
                                        Arduino a los que voy 
                                        a conectar el display LCD*/

void setup() {
  lcd.begin(16, 2); //Inicializo el display LCD (columnas, filas)
}
void loop() {
 lcd.setCursor(0,0); /*Fijo el cursor para escribir en la 
                       primera fila, primera columna*/
 lcd.print("HOLA MUNDO!");
 lcd.setCursor(0,1); /*Fijo el cursor para escribir en la 
                       segunda fila, primera columna*/
 lcd.print("@MartinMorales");
 delay(1500); /*Delay de 1.5 segundos en los que la 
                pantalla se mantendrá encendida*/
 lcd.clear(); //Limpio el display
 delay(1500); /*Delay de 1.5 segundos en los que 
                la pantalla se mantendrá apagada*/
}
