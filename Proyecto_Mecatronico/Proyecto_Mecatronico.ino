#include <HX711.h>

//ENTRADAS DIGITALES 22-29
const byte SensorICMX = 22,           //SENSOR INICIO DE CARRERA PARA MOTOR X
           SensorFCMX = 23,           //SENSOR FINAL DE CARRERA PARA MOTOR X
           SensorICMY = 24,           //SENSOR INICIO DE CARRERA PARA MOTOR Y
           SensorFCMY = 25,           //SENSOR FINAL DE CARRERA PARA MOTOR y
           SensorGripper = 26,        //SENSOR MAGNETICO PARA CILINDRO GRIPPER
           SensorCabezal = 27,        //SENSOR MAGNETICO PARA CILINDRO CABEZAL VERTICAL
           ActivarCiclo = 28,         //BOTON INICIO DE CICLO
           Home = 29,                 //BOTON DE RESET O LLEVAR A HOME TODO
           BotonParoEmergencia = 2,   //BOTON DE PARO DE EMERGENCIA 
           GuardaParoEmergencia = 3;  //SENSOR PARA GUARDA
//ENTRADAS ANALÓGICAS A0-A7
const byte PotLineal = 2;             //POTENCIOMETRO LINEAL PARA PRESION VERTICAL
#define DOUT A1                       //DATOS DE LA CELDA DE CARGA
#define CLK A0                        //RELOJ DE LA CELDA DE CARGA
//SALIDAS DIGITALES 30-52
const byte CWMX = 30,                 //SENTIDO DE GIRO MOTOR X
           CLKMX = 31,                //RELOJ DE MOTOR X
           CWMY = 32,                 //SENTIDO DE GIRO MOTOR Y
           CLKMY = 33,                //RELOJ DE MOTOR Y
           EV_Gripper = 34,           //ELECTROVALVULA PARA ACTIVAR CILINDRO DE GRIPPER
           EV_Cabezal = 35,           //ELECTROVALVULA PARA ACTIVAR CILINDRO DE CABEZAL VERTICAL
           LED_Rojo = 36,             //INDICADOR DE PARO DE EMERGENCIA  
           LED_Verde = 37,            //INDICADOR DE STAND BY
           LED_Azul = 38;             //INDICADOR DE CICLO ACTIVO
//SALIDAS ANALÓGICAS (PWM) 6-13
const byte Variador = 6;              //SEÑAL HACIA EL VARIADOR DE FRECUENCIA

//VARIABLES GLOBALES
int estadoMX = LOW;                   //VARIABLE AUXILIAR PARA ENVIAR PULSOS HACIA EL MOTOR X (CWMX)
int estadoMY = LOW;                   //VARIABLE AUXILIAR PARA ENVIAR PULSOS HACIA EL MOTOR Y (CWMY)
int paroEmergencia = 0;               //BANDERA PARA SABER SI EL PARO DE EMERGENCIA SE ENCUENTRA ACTIVO

HX711 celda(DOUT, CLK);
        
void setup() {
  // put your setup code here, to run once:
  //ENTRADAS *
  pinMode(SensorICMX, INPUT_PULLUP);
  pinMode(SensorFCMX, INPUT_PULLUP);
  pinMode(SensorICMY, INPUT_PULLUP);
  pinMode(SensorFCMY, INPUT_PULLUP);
  pinMode(SensorGripper, INPUT_PULLUP);
  pinMode(SensorCabezal, INPUT_PULLUP);
  pinMode(BotonParoEmergencia, INPUT_PULLUP);
  pinMode(GuardaParoEmergencia, INPUT_PULLUP);
  //SALIDAS
  pinMode(LED_Rojo, OUTPUT);
  pinMode(LED_Verde, OUTPUT);
  pinMode(LED_Azul, OUTPUT);
  pinMode(CLKMX, OUTPUT);
  pinMode(CLKMY, OUTPUT);
  pinMode(CWMX, OUTPUT);
  pinMode(CWMY, OUTPUT);
  pinMode(13, OUTPUT);
  //OTROS
  Serial.begin(9600);
  //Serial.println(celda.read());
  celda.set_scale(1);
  celda.tare(1);
  attachInterrupt(digitalPinToInterrupt(BotonParoEmergencia), StopEmergency, HIGH); //CAMBIAR A LOW
  attachInterrupt(digitalPinToInterrupt(GuardaParoEmergencia), StopEmergency, HIGH);
  Serial.println("Inicializando espere...");
  Inicializar();
}

void loop() {
  if(digitalRead(ActivarCiclo) == 1){
    digitalWrite(LED_Azul, HIGH);
    digitalWrite(LED_Verde, HIGH);
    SecuenciaMotores();
    GoToHome();
  }
  digitalWrite(LED_Azul, LOW);
  digitalWrite(LED_Verde, HIGH);
}

/*SECUENCIA DE INICIO
 * - APAGAR EL VARIADOR Y PONER LA SEÑAL PWM EN 0
 * - DESACTIVAR CILINDRO DEL CABEZAL (DEBE QUEDAR CONTRAIDO) Y ACTIVAR CILINDRO DE GRIPPER (DEBE QUEDAR ACTIVADO PARA LA INSERCION O EXTRACCION DE LA PERILLA
 * - MOTORES DEBEN ESTAR ORIENTADOS HACIA LOS MICROS DE INICIO DE CARRERA
 * - LEDS ENCENDERLOS Y APAGARLOS
 * - QUITAR INTERRUPCIONES
*/
void GoToHome(){
  unsigned long intervalo = 4, previo = 0;          //intervalo cambia dependiendo la velocidad del motor (CAMBIAR A 1 PARA LA MAYOR VELOCIDAD)
  digitalWrite(CWMX, HIGH);                         //HIGH -> CAMINA HACIA EL INICIO DE CARRERA DEL MOTOR X
  digitalWrite(CWMY, LOW);                          //LOW -> CAMINA HACIA EL INICIO DE CARRERA DEL MOTOR Y
  Serial.println("Go To Home");                     
  int flag = 0;
  while(flag < 2){
    unsigned long actual = millis();
    int f1 = 0, f2 = 0;
    if(actual - previo >= intervalo){
      previo = actual;
      int ICMX = digitalRead(SensorICMX), ICMY = digitalRead(SensorICMY);
      
      if(ICMX != 1){
        if(estadoMX == LOW)
          estadoMX = HIGH;
        else
          estadoMX = LOW;
      }
      else{
        f1 = 1;
        estadoMX = LOW;
      }
      if(ICMY != 1){
        if(estadoMY == LOW)
          estadoMY = HIGH;
        else
          estadoMY = LOW;
      }
      else{
        f2 = 1;
        estadoMY = LOW;
      }
//      digitalWrite(CLKMX, estadoMX);
//      digitalWrite(CLKMY, estadoMY);
//      flag = f1 + f2;
   }
   digitalWrite(CLKMX, estadoMX);
   digitalWrite(CLKMY, estadoMY);
   flag = f1 + f2;
  }
  digitalWrite(CLKMX, LOW);
  digitalWrite(CLKMY, LOW);
  Serial.println("Motores han llegado a home");
}

void StopEmergency(){
  
}

void VariadorFrecuencia(int nValue){
  analogWrite(Variador, nValue);
  Serial.print("Variador de frecuencia establecido a: ");
  Serial.println(nValue);
}

void Gripper(int nState){
  if(nState == 1){
    digitalWrite(EV_Gripper, HIGH);
    Serial.println("Electrovalvula de gripper se ha activado");
  }
  else{
    digitalWrite(EV_Gripper, LOW);
    Serial.println("Electrovalvula de gripper se ha desactivado");
  }
}

void Cabezal(int nState){
  if(nState == 1){
    digitalWrite(EV_Cabezal, HIGH);
    Serial.println("Electrovalvula de cabezal se ha activado");
  }
  else{
    digitalWrite(EV_Cabezal, LOW);
    Serial.println("Electrovalvula de cabezal se ha desactivado");
  }
}

long CeldaCarga(){
//  Serial.print("Valor de lectura: ");
//  Serial.println(celda.get_value(2),0);
  long valorCelda = celda.get_value(1);
  if(celda.get_value(1) >= 100000)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  return valorCelda;
}

void SecuenciaMotores(){
  unsigned long velAvance = 7, velRetroceso = 2, velFina = 10, previo = 0; //intervalo cambia dependiendo la velocidad del motor
  digitalWrite(CWMX, LOW);                          //LOW -> HACIA FINAL DE CARRERA DE MOTOR X
  digitalWrite(CWMY, HIGH);                         // HIGH -> HACIA FINAL DE CARRERA DE MOTOR Y
  estadoMX = estadoMY = LOW;
  Serial.println("Secuencia Motores");
  int contLimX = 0, contX = 0, contY = 0;
  while(digitalRead(SensorFCMY) != 1){              //MIENTRAS EL SENSOR FINAL DE CARRERA DEL MOTOR Y NO SE ACTIVE        
    Serial.println("Hacia la perilla!");          
    while(digitalRead(SensorFCMX) != 1)
    //while(CeldaCarga <= 200000)
    {
      unsigned long actual = millis();
      digitalWrite(CWMX, LOW);                      //LOW -> HACIA FINAL DE CARRERA DE MOTOR X
      if(actual - previo >= velAvance){             
        previo = actual;
        if(estadoMX == LOW){
          estadoMX = HIGH;
          contLimX++;
        }
        else
          estadoMX = LOW;
      }
      digitalWrite(CLKMX, estadoMX);
    }
    digitalWrite(CLKMX, LOW);
    //ESPERAR 2 SEGUNDOS (HACER FUNCION)
    Serial.println("Hacia el inicio de carrera del motor X");
    contX = contLimX;
    //INTERPOLACION DE PRUEBA
    int flag = 0;
    while(flag <= 2){
      int flagX = 0, flagY = 0;
      unsigned long actual = millis();
      digitalWrite(CWMX, HIGH);                      //HIGH -> HACIA INICIO DE CARRERA DE MOTOR X
      digitalWrite(CWMY, HIGH);                     //HIGH -> HACIA FINAL DE CARRERA DE MOTOR Y
      if(actual - previo >= velRetroceso){             
        previo = actual;
        if(contX >= contLimX - 100){                //MODIFICAR EL VALOR
          if(estadoMX == LOW){
            estadoMX = HIGH;
            contX--;
          }
          else
            estadoMX = LOW;
        }
        else{
          flagX = 1;
          estadoMX = LOW;
        }
        if(contY <= 30){                          //MODIFICAR VALOR
          if(estadoMY == LOW){
            estadoMY = HIGH;
            contY++;
          }
          else
            estadoMY = LOW;
        }
        else{
            flagY = 1;
            estadoMY = LOW;
        }
//        digitalWrite(CLKMX, estadoMX);
//        digitalWrite(CLKMY, estadoMY);
//        flag = flagX + flagY;
      }
      digitalWrite(CLKMX, estadoMX);
      digitalWrite(CLKMY, estadoMY);
      flag = flagX + flagY;
    }
//    while(contX >= contLimX - 100) //Modificar dependiendo el retroceso del cabezal
//    {
//      digitalWrite(CWMX, HIGH);                     //HIGH -> HACIA INCIO DE CARRERA DE MOTOR X
//      unsigned long actual = millis();
//      if(actual - previo >= velRetroceso){
//        previo = actual;
//        if(estadoMX == LOW){
//          estadoMX = HIGH;
//          contX--;
//        }
//        else
//          estadoMX = LOW;
//      }
//      digitalWrite(CLKMX, estadoMX);
//    }
//    digitalWrite(CLKMX, LOW);
//    //ESPERAR 2 SEGUNDOS (HACER FUNCION)
//    Serial.println("Hacia el final de carrera del motor Y");
//    while(contY <= 100)
//    {
//      digitalWrite(CWMY, HIGH);                     //HIGH -> HACIA FINAL DE CARRERA DE MOTOR Y
//      unsigned long actual = millis();
//      if(digitalRead(SensorFCMY) == 1)
//        contY = 1001;
//      if(actual - previo >= velRetroceso){
//        previo = actual;
//        if(estadoMY == LOW){
//          estadoMY = HIGH;
//          contY++;
//        }
//        else
//          estadoMY = LOW;
//      }
//      digitalWrite(CLKMY, estadoMY);
//    }
  }
  digitalWrite(CLKMX, LOW);
  digitalWrite(CLKMY, LOW);
  Serial.println("Secuencia finalizada, regresaré a home");
}

void Inicializar(){
  GoToHome();
  Esperar(2);
  Cabezal(1);
  Esperar(1);
  Cabezal(0);
  Esperar(2);
  Gripper(0);
  Esperar(1);
  Gripper(1);
  Esperar(2);
  VariadorFrecuencia(255);
  Esperar(3);
  VariadorFrecuencia(0);
  digitalWrite(LED_Rojo, HIGH);
  digitalWrite(LED_Azul, HIGH);
  digitalWrite(LED_Verde, HIGH);
  digitalWrite(LED_Rojo, LOW);
  digitalWrite(LED_Azul, LOW);
  digitalWrite(LED_Verde, LOW);
  Serial.println("La inicializacion ha terminado");
}

void Esperar(int segundos){
  unsigned long intervalo = (segundos * 1000), previo = 0;
  bool estado = false;
  while(estado != true){
  unsigned long actual = millis();
    if(actual - previo >= intervalo){             
      previo = actual;
      estado = true;
    }
  }
}

