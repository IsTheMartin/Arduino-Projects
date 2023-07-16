//////Invernadero Automatizado vía Bluetooth///////
//////Martin Ignacio Morales De Arco///////
////////Variables para conexión bluetooth////////
unsigned int timeout = 0;//variable para el timer
unsigned char state = 0;//variable de estado de conexion bluetooth
int valor = 0;//variable auxiliar
char leerchar[5];//variable para convertir de string a char*
String readString = 0;//variable para almacenar todos los datos
int bandbegin;//bandera para comenzar
////////Variables temperatura////////
int sensortemp = A0;     // LM35 va conectado al pin A0
int foco = 11;  // foco al pin 11
int ventilador = 12; //ventilador al pin 12
float temp = 0;  // Variable para guardar datos del sensor temperatura
int bandventi = 0;// varialble bandera ventilador
int bandfoco = 0;//variable bandera foco
int tempmax = 28;//variable temperatura maxima
int tempmin = 24;//variable temperatura minima
////////Variables humedad////////
int sensorhum = A1;     // HIH4010 va conectado al pin A1
int riego = 10;  // riego al pin 10
float hum = 0;  // Variable para guardar datos del sensor humedad
int bandriego = 0;//variable bandera riego
int hummax = 80;//variable humedad maxima
int hummin = 20;//variable humedad minima
////////Funcion Timer////////
ISR(TIMER2_OVF_vect){ //Timer2  Service  
  TCNT2 = 0;//timer igual a 0
  timeout++;//el timeout se suma una vez cada que entre a la funcion
  if (timeout>61){//si timeout es mayor a 61
    state=1;//state es igual a uno
    timeout=0;//timeout igual a cero
  }
}
////////Funcion timer interrupcion////////
void init_timer2(void){
  TCCR2A |= (1 << WGM21) | (1 << WGM20);   
  TCCR2B |= 0x07;   // by clk/1024
  ASSR |= (0<<AS2);  // Use internal clock - external clock not used in Arduino
  TIMSK2 |= 0x01;   //Timer2 Overflow Interrupt Enable
  TCNT2 = 0; //timer igual a cero
  sei();//llamado a la funcion sei
}
////////configuracion de pines////////
void setup(){
  Serial.begin(9600);//Puerto serial en 9600 baudios
  pinMode(2,INPUT);//pin 2 configurado como entrada
  pinMode(13,OUTPUT);//pin 13 configurado como salida
  attachInterrupt(0,cleantime,FALLING);//interrupcion
  init_timer2();//entero para el timer 2
  pinMode(foco,OUTPUT);  //configuracion pin 11 como salida
  pinMode(ventilador,OUTPUT);  //configuracion pin 12 como salida
  pinMode(riego,OUTPUT);  //configuracion pin 10 como salida
}
////////funcion del ciclo////////
void loop(){
  //Proceso de temperatura
  temp = 0; // Reiniciar valor de temperatura a 0
  temp = analogRead(sensortemp);  // Leer datos del sensor de temperatura
  temp = (5.0 * temp * 100.0)/1024.0; // convertir el dato a C°
  if(temp>tempmax){  //temperatura es mayor a 27?
    digitalWrite(foco,LOW);//foco se apaga
    digitalWrite(ventilador,HIGH);//ventilador enciende
    bandfoco = 0;//bandera del foco igual a cero
    bandventi = 1;//bandera del ventilador igual a uno
  }
  else if(temp<tempmin){//temperatura es menor a 24?
    digitalWrite(foco,HIGH);//foco enciende
    digitalWrite(ventilador,LOW);//ventilador apagado
    bandfoco = 1;//bandera del foco igual a uno
    bandventi = 0;//bandera del ventilador igual a cero
  }
  else{//si ninguna condicion afecta
    digitalWrite(foco,LOW);//foco apagado
    digitalWrite(ventilador,LOW);//ventilador apagado
    bandfoco = 0;//bandera del foco igual a cero
    bandventi = 0;//bandera del ventilador igual a cero
  }
////////Proceso Humedad////////
  hum = 0;//humedad es igual a 0
  hum = analogRead(sensorhum);  // Leer datos del sensor de humedad
  hum = ((((hum/1023)*5)-0.8)/3.1)*100;//convertir humedad relativa RH
  if(hum>hummax){  //humedad es mayor a 80%?
    digitalWrite(riego,LOW);//apaga el riego
    bandriego = 0;//bandera de riego igual a cero
  }
  else if(hum<hummin){  //humedad es menor al 40%
    digitalWrite(riego,HIGH);//riego encendido
    bandriego = 1;//bandera de riego igual a uno
  }
  else{
    digitalWrite(riego,LOW);//riego apagado 
    bandriego = 0;//bandera de riego igual a cero
  }
////////Envio de datos por bluetooth////////
  switch(state){//verifica el estado de la conexion del bluetooth
    case 0: //si no esta conectado
      digitalWrite(13,LOW);//pin 13 apagado
      if(bandbegin==1)//si bandera comienzo es igual a uno
        bandbegin=0;//entonces bandera comienzo es igual a cero
      break;//regresa al switch
    case 1: //si esta conectado
      readString = "";//readString se vacia
      valor = 0;// valor es igual a cero
      if(bandbegin==0){//si bandera comienzo es igual a cero
        Serial.println("Invernadero Automatizado vía Bluetooth");//envia el anterior texto
        bandbegin=1;//bandera comienzo es igual a uno
      }
      digitalWrite(13,HIGH);//pin 13 encendido
      while(Serial.available()){//mientras la transferencia de datos este activa
        delay(100);//retardo de tiempo de .1 segundos
        leerdato();//llama a la funcion leerdato
      }
        if(readString.equals("instrucciones")||readString.equals("comandos")){//si readString es igual a instrucciones o comandos
         Serial.println(" ");//envia un espacio
         Serial.println("Lista de Comandos");//envia el texto anterior
         Serial.println("comandos / instrucciones -> muestra la lista de comandos");//envia el texto anterior
         Serial.println("temperatura -> muestra la temperatura actual");//envia el texto anterior
         Serial.println("humedad -> muestra la humedad actual");//envia el texto anterior
         Serial.println("tempmax -> establece la temperatura maxima");//envia el texto anterior
         Serial.println("tempmin -> establece la temperatura minima");//envia el texto anterior
         Serial.println("hummax -> establece la humedad maxima");//envia el texto anterior
         Serial.println("hummin -> establece la humedad minima");//envia el texto anterior
         Serial.println("estado -> nuestra el estado en el que se encuentra el invernadero");//envia el texto anterior
         Serial.println("regar / riego -> activa el riego por 1 minuto");//envia el texto anterior
         Serial.println("ventilar / ventilador -> activa el ventilador por 2 minutos");//envia el texto anterior
         Serial.println("calentar / calefaccion -> activa el foco por 2 minutos");//envia el texto anterior
         Serial.println("acerca -> muestra los datos del desarrollador");//envia el texto anterior
        }
        else if(readString.equals("temperatura")){//si readString es igual a temperatura
          Serial.println("La temperatura es: ");//envio dato al celular
          Serial.print(temp);//envio valor de temperatura al celular
          Serial.print("°C");//envio dato al celular
        }
        else if(readString.equals("humedad")){//si readString es igual a humedad
          Serial.println("La humedad es: ");//envio dato al celular
          Serial.print(hum);//envio valor de humedad al celular
          Serial.print("%");//envio dato al celular
        }
        else if(readString.equals("estado")){
          Serial.println(" ");//envia el texto anterior
          if(bandfoco==1)//si bandera del foco es igual a uno
            Serial.println("El foco esta activado");//envia el texto anterior
          if(bandventi==1)//si bandera del ventilador es igual a uno
            Serial.println("El ventilador esta activado");//envia el texto anterior
          if(bandriego==1)//si bandera de riego es igual a uno
            Serial.println("El riego esta activado");//envia el texto anterior
          if(bandfoco==0)//si bandera del foco es igual a cero
            Serial.println("El foco esta desactivado");//envia el texto anterior
          if(bandventi==0)//si bandera del ventilador es igual a cero
          Serial.println("El ventilador esta desactivado");
          if(bandriego==0)//si bandera de riego es igual a cero
            Serial.println("El riego esta desactivado");
        }
        else if(readString.equals("regar") || readString.equals("riego")){//si readString es igual a regar o riego
          digitalWrite(riego,HIGH);//enciende riego
          Serial.println("El sistema de riego esta activado");//envio dato al celular
          delay(60000);//retardo de 1 minuto
          digitalWrite(riego,LOW);//apaga riego
          Serial.println("El sistema de riego esta desactivado");
        }
        else if(readString.equals("ventilador") || readString.equals("ventilar")){//si readString es igual a ventilador o ventilar
          digitalWrite(ventilador,HIGH);//enciende ventilador
          Serial.println("El ventilador esta activado");//envio dato al celular
          delay(120000);//retardo de 2 minutos
          digitalWrite(ventilador,LOW);//apaga ventilador
          Serial.println("El ventilador esta desactivado");//envio dato al celular
        }
        else if(readString.equals("calentar") || readString.equals("calefaccion")){//si readString es igual a calentar o calefaccion
          digitalWrite(foco,HIGH);//enciende foco
          Serial.println("El foco esta activado");//envio dato al celular
          delay(120000);//retardo de 2 minutos
          digitalWrite(foco,LOW);//apaga foco
          Serial.println("El foco esta desactivado");//envio dato al celular
        }
        else if(readString.equals("tempmax")){//si readString es igual a tempmax
          readString = "";//se vacia la cadena readString
          Serial.println("Limite actual ");
          Serial.print(tempmax);
          Serial.println(" Establece la temperatura maxima:");//envio dato al celular
          delay(10000);//retardo de 10 segundos
          while(Serial.available()){//mientras la transferencia de datos este activa
            char c = Serial.read();//variable c es igual a los datos recibidos del celular
            if(c == ',')//si variable c es igual a una coma ,
              break;//rompe el ciclo
            readString += c;//sino readString concatena lo que tiene la variable c
          }
          readString.toCharArray(leerchar, 4);//convierte la cadena readString al arreglo de caracteres leechar
          valor = atoi(leerchar);//valor es igual a la conversion numerica de leerchar
          if(valor < 0 || valor > 50 || valor <= tempmin || readString.equals(""))//si valor es menor que cero o mayor que 50 o menor que tempmin o readString este vacia
            Serial.println("Temperatura maxima invalida, ingrese el valor de nuevo");//envio dato al celular
          else{//si no
            tempmax = valor;//tempmax es igual a valor
            Serial.println("La temperatura maxima se ha establecido a: ");//envio dato al celular
            Serial.print(tempmax);//envio dato al celular
          }
        }
        else if(readString.equals("tempmin")){//si readString es igual a tempmin
          readString = "";//se vacia readString
          Serial.println("Limite actual ");
          Serial.print(tempmin);
          Serial.println(" Establece la temperatura minima:");//envio dato al celular
          delay(10000);//retardo de 10 segundos
          while(Serial.available()){//mientras la transferencia de datos este activa
            char c = Serial.read();//variable c es igual a los datos recibidos
            if(c == ',')//si variable c es igual a una coma ,
              break;//rompe el ciclo
            readString += c;//sino readString concatena lo que tiene la variable c
          }
          readString.toCharArray(leerchar, 4);//convierte la cadena readString al arreglo de caracteres leerchar
          valor = atoi(leerchar);//valor es igual a la conversion numerica de leerchar
          if(valor < 0 || valor > 50 || valor >= tempmax || readString.equals(""))//si valor es menor que cero o mayor que 50 o mayor que tempmax o readString este vacia
            Serial.println("Temperatura minima invalida, ingrese el valor de nuevo");//envio dato al celular
          else{//si no
            tempmin = valor;//tempmin es igual a tempmin
            Serial.println("La temperatura minima se ha establecido a: ");//envio dato al celular
            Serial.print(tempmin);//envio dato al celular
          }
        }
        else if(readString.equals("hummax")){//si readString es igual a hummax
          readString = "";//se vacia readString
          Serial.println("Limite actual ");
          Serial.print(hummax);
          Serial.println("Establece la humedad maxima:");//envio dato al celular
          delay(10000);//retardo de 10 segundos
          while(Serial.available()){//mientras la transferencia de datos este activa
            char c = Serial.read();//variable c es igual a los datos recibidos
            if(c == ',')//si variable c es igual a una coma ,
              break;//rompe el ciclo
            readString += c;//sino readString concatena lo que tiene la variable c
          }
          readString.toCharArray(leerchar, 4);//convierte la cadena readString al arreglo de caracteres leerchar
          valor = atoi(leerchar);//valor es igual a la conversion numerica de leerchar
          if(valor < 10 || valor > 90 || valor <= hummin || readString.equals(""))//si valor es menor que 10 o mayor q 90 o menor que hummin o readString este vacia
            Serial.println("Humedad maxima invalida, ingrese el valor de nuevo");//envio dato al celular
          else{//si no
            hummax = valor;//hummax es igual a valor
            Serial.println("La humedad maxima se ha establecido a: ");//envio dato al celular
            Serial.print(hummax);//envio dato al celular
          }
        }
        else if(readString.equals("hummin")){//si readString es igual a hummin
          readString = "";//readString se vacia
          Serial.println("Limite actual ");
          Serial.print(hummin);
          Serial.println(" Establece la humedad minima:");//envio dato al celular
          delay(10000);//retardo de 10 segundos
          while(Serial.available()){//mientras la transferencia de datos este activa
            char c = Serial.read();//variable c es igual a los datos recibidos
            if(c == ',')//si la variable c es igual a una coma ,
              break;//rompe el ciclo
            readString += c;//sino readString concatena lo que tiene la variable c
          }
          readString.toCharArray(leerchar, 4);//convierte la cadena readString al arreglo de caracteres leerchar
          valor = atoi(leerchar);//valor es igual a l aconversion numerica de leerchar
          if(valor < 10 || valor > 90 || valor >= hummax || readString.equals(""))//si valor es menor que 10 o mayor que 90 o es mayor que hummax o readString este vacia
            Serial.println("Humedad minima invalida, ingrese el valor de nuevo");//envio dato al celular
          else{// si no
            hummin = valor;//hummin es igual a valor
            Serial.println("La humedad minima se ha establecido a: ");//envio dato al celular
            Serial.print(hummin);//envio dato al celular
          }
        }
        else if(readString.equals("acerca")){//si readString es igual a acerca
          Serial.println(" ");//envio dato al celular
          Serial.println("Invernadero Automatizado via Bluetooth");//envio dato al celular
          Serial.println("Desarrollado por: Martin Ignacio Morales De Arco");//envio dato al celular
        }
        
      break;//regresa al ciclo switch
  }
}
////////leer datos del celular//////////
void leerdato(){
  char c = Serial.read();//c va ser igual a serial read
  if(c==';')//si c es igual a un punto y coma
    return;//entonces regresa
  readString += c;//readString se le agrega c
}
////////limpiar timers////////
void cleantime()
{
  timeout=0;//timeout es igual a cero
  state=0;//state es igual a cero
}

