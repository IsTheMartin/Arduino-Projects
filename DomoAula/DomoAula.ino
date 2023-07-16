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
//int foco = 11;  // foco al pin 11
int vent1 = 13; //ventilador al pin 13
int vent2 = 12;
float temp = 0;  // Variable para guardar datos del sensor temperatura
int bandventi = 0;// varialble bandera ventilador
//int bandfoco = 0;//variable bandera foco
int tempmax = 28;//variable temperatura maxima
int tempmin = 24;//variable temperatura minima
////////Variables humedad////////
int sensorhum = A1;     // HIH4010 va conectado al pin A1
int riego = 11;  // riego al pin 12
float hum = 0;  // Variable para guardar datos del sensor humedad
//int bandriego = 0;//variable bandera riego
//int hummax = 80;//variable humedad maxima
//int hummin = 20;//variable humedad minima
//////Computadoras/////////
int compu1 = 10;
int compu2 = 9;
int compu3 = 8;
int compu4 = 7;
int compu5 = 6;
int compu6 = 5;
int compu7 = 4;
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
  pinMode(vent1,OUTPUT);  //configuracion pin 13 como salida
  pinMode(vent2,OUTPUT);  //configuracion pin 12 como salida
  pinMode(riego,OUTPUT);  //configuracion pin 11 como salida
  pinMode(compu1,INPUT);  //configuracion pin 10 como salida
  pinMode(compu2,INPUT);  //configuracion pin 9 como salida
  pinMode(compu3,INPUT);  //configuracion pin 8 como salida
  pinMode(compu4,INPUT);  //configuracion pin 7 como salida
  pinMode(compu5,INPUT);  //configuracion pin 6 como salida
  pinMode(compu6,INPUT);  //configuracion pin 5 como salida
  pinMode(compu7,INPUT);  //configuracion pin 4 como salida
}
////////funcion del ciclo////////
void loop(){
  //Proceso de temperatura
  temp = 0; // Reiniciar valor de temperatura a 0
  temp = analogRead(sensortemp);  // Leer datos del sensor de temperatura
  temp = (5.0 * temp * 100.0)/1024.0; // convertir el dato a C°
  if(temp>tempmax){  //temperatura es mayor a 27?
    digitalWrite(vent1,HIGH);//ventilador enciende
    digitalWrite(vent2,HIGH);//ventilador enciende
    //bandfoco = 0;//bandera del foco igual a cero
    bandventi = 1;//bandera del ventilador igual a uno
  }
  else if(temp<tempmin){//temperatura es menor a 24?
    digitalWrite(vent1,LOW);//ventilador apagado
    digitalWrite(vent2,LOW);//ventilador apagado
    bandventi = 0;//bandera del ventilador igual a cero
  }
  else{//si ninguna condicion afecta
    digitalWrite(vent1,LOW);//ventilador apagado
    digitalWrite(vent2,LOW);//ventilador apagado    
    bandventi = 0;//bandera del ventilador igual a cero
  }
////////Proceso Humedad////////
  hum = 0;//humedad es igual a 0
  hum = analogRead(sensorhum);  // Leer datos del sensor de humedad
  hum = ((((hum/1023)*5)-0.8)/3.1)*100;//convertir humedad relativa RH
////////Envio de datos por bluetooth////////
  switch(state){//verifica el estado de la conexion del bluetooth
    case 0: //si no esta conectado
      digitalWrite(3,LOW);//pin 13 apagado
      if(bandbegin==1)//si bandera comienzo es igual a uno
        bandbegin=0;//entonces bandera comienzo es igual a cero
      break;//regresa al switch
    case 1: //si esta conectado
      readString = "";//readString se vacia
      valor = 0;// valor es igual a cero
      if(bandbegin==0){//si bandera comienzo es igual a cero
        Serial.println("DomoAula");//envia el anterior texto
        bandbegin=1;//bandera comienzo es igual a uno
      }
      digitalWrite(3,HIGH);//pin 13 encendido
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
         Serial.println("estado -> nuestra el estado en el que se encuentra la DomoAula");//envia el texto anterior
         Serial.println("ventilar / ventilador -> activa el ventilador por 2 minutos");//envia el texto anterior
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
        else if(readString.equals("ventilador") || readString.equals("ventilar")){//si readString es igual a ventilador o ventilar
          digitalWrite(vent1,HIGH);//enciende ventilador
          digitalWrite(vent2,HIGH);//enciende ventilador
          Serial.println("El ventilador esta activado");//envio dato al celular
          delay(120000);//retardo de 2 minutos
          digitalWrite(vent1,LOW);//apaga ventilador
          digitalWrite(vent2,LOW);//apaga ventilador
          Serial.println("El ventilador esta desactivado");//envio dato al celular
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
        else if(readString.equals("acerca")){//si readString es igual a acerca
          Serial.println(" ");//envio dato al celular
          Serial.println("DomoAula V.1.0");//envio dato al celular
          Serial.println("Desarrollado por: ");//envio dato al celular
          Serial.println("Rubens");//envio dato al celular
          Serial.println("Lomeli Chavez Ivan Emmanuel");//envio dato al celular
          Serial.println("Melendez Checa Cristian Giovanni");//envio dato al celular
          Serial.println("Morales De Arco Martin Ignacio");//envio dato al celular
          Serial.println("Perez Quintana Ernesto Alejandro");//envio dato al celular
          Serial.println("Lawyer");//envio dato al celular          
        }       
        else if(readString.equals("computadoras")){
          if(digitalRead(11)==HIGH)
            Serial.println("Computadora 1 esta encendida");
          if(digitalRead(10)==HIGH)
            Serial.println("Computadora 2 esta encendida");
          if(digitalRead(9)==HIGH)
            Serial.println("Computadora 3 esta encendida");
          if(digitalRead(8)==HIGH)
            Serial.println("Computadora 4 esta encendida");
          if(digitalRead(7)==HIGH)
            Serial.println("Computadora 5 esta encendida");
          if(digitalRead(6)==HIGH)
            Serial.println("Computadora 6 esta encendida");
          if(digitalRead(5)==HIGH)
            Serial.println("Computadora 7 esta encendida");
          if(digitalRead(11)==LOW)
            Serial.println("Computadora 1 esta apagada");
          if(digitalRead(10)==LOW)
            Serial.println("Computadora 2 esta apagada");
          if(digitalRead(9)==LOW)
            Serial.println("Computadora 3 esta apagada");
          if(digitalRead(8)==LOW)
            Serial.println("Computadora 4 esta apagada");
          if(digitalRead(7)==LOW)
            Serial.println("Computadora 5 esta apagada");
          if(digitalRead(6)==LOW)
            Serial.println("Computadora 6 esta apagada");
          if(digitalRead(5)==LOW)
            Serial.println("Computadora 7 esta apagada");
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
