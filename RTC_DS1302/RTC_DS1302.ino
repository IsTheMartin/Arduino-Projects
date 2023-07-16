#include <RTClib.h>

// Inicializacion del modulo
DS1302 rtc(2, 3, 5);
Time t;

void setup(){
  // Desproteger contra escritura
  rtc.halt(false);
  rtc.writeProtect(false);

  rtc.setDOW(TUESDAY);  // Configurar dia de la semana: MARTES.
  rtc.setTime(17, 00, 00);  // Configurar hora en formato 24hs con min y seg: 17:00:00 HORAS.
  rtc.setDate(4, 3, 2014);  // Configurar fecha en formato dia/mes/año: 4/3/2014.
}

void loop(){
  digitalWrite(13,HIGH);  // El led integrado confirmara la finalizacion.
}
