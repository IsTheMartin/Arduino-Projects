/*
 --------------------------------------------- 
  LED RGB + Potenciómetro
 ---------------------------------------------

  Programa que varia el color del LED según
  el valor obtenido por unos potenciómetros.

*/

//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int ledRojo = 9; //Declara Pin LED Rojo
int ledVerde=10; //Declara Pin LED Verde
int ledAzul=11;  //Declara Pin LED Azul

int pinPot0 = A0;  //Declara Pin Potenciometro Rojo
int pinPot1 = A1;  //Declara Pin Potenciometro Verde
int pinPot2 = A2;  //Declara Pin Potenciometro Azul

int valorsensor0 = 0;  //Valores analogicos de la salida del potenciometro
int valorsensor1 = 0;  //   ||        ||            ||            ||
int valorsensor2 = 0;  //   ||        ||            ||            ||

float divisionR; 
float divisionV;
float divisionA;

//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{ 
  pinMode(ledRojo,OUTPUT);  //El LED Rojo como una salida
  pinMode(ledVerde,OUTPUT); //El LED Verde como una salida
  pinMode(ledAzul,OUTPUT);  //El LED Azul como una salida
  Serial.begin(9600);

}

//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() {

   // Llamada a la función Color que recibe
   // 1er posicion: Intensidad Rojo
   // 2da posición: Intensidad Verde
   // 3ra posición: Intensidad Azul

   float Constante = (float) 255 / 1023;  //Divide el máximo valor de color entre el máximo valor del potenciómetro

   valorsensor0 = analogRead(pinPot0);
   valorsensor1 = analogRead(pinPot1);
   valorsensor2 = analogRead(pinPot2);

   divisionR = Constante * valorsensor0;    
   divisionV = Constante * valorsensor1;
   divisionA = Constante * valorsensor2;

   color(divisionR,divisionV,divisionA);     // Carga un valor para (ROJO,VERDE,AZUL)
                                             //segun el valor de tres potenciómetros.

}

//------------------------------------
//Funcion color
//------------------------------------

void color(int rojo, int verde, int azul){

    //ROJO. Le resta al total (255) el valor obtenido de los potenciometros
    analogWrite(ledRojo, 255-rojo);

    //VERDE. Le resta al total (255) el valor obtenido de los potenciometros
    analogWrite(ledVerde, 255-verde);

    //AZUL. Le resta al total (255) el valor obtenido de los potenciometros
    analogWrite(ledAzul, 255-azul);
}
