#include <HX711.h>
#define DOUT  A1
#define CLK  A0

HX711 balanza(DOUT, CLK);

void setup() {
Serial.begin(9600);
  Serial.print("Lectura del valor del ADC:t");
  Serial.println(balanza.read());
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  balanza.set_scale(439430.25); // Establecemos la escala
  balanza.tare(20);  //El peso actual es considerado Tara.
  
  Serial.println("Listo para pesar");  
}

void loop() {
  Serial.print("Peso:t");
  Serial.print(balanza.get_units(20),3);
  Serial.println("kg");
  delay(500);
}
