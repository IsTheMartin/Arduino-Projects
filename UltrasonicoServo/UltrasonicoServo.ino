#include <Servo.h>

Servo myservo;

long distancia;
long tiempo;
int val;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
    pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
    myservo.attach(10); //pin servo
    myservo.write(0);
    delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);
    for(int i = 0; i <= 180; i++)
    {
      Sensor();
      if(distancia <= 10 || distancia == 0)
        delay(1000);
      else
      {
        myservo.write(i);                  // sets the servo position according to the scaled value
        delay(100); 
      }
      i++;
    }
    for(int j = 0; j <= 180; j++)
    {
      Sensor();
      if(distancia <= 10 || distancia == 0)
        delay(1000);
      else
      {
        myservo.write(180-j);                  // sets the servo position according to the scaled value
        delay(100); 
      }
            j++;
    }
  myservo.write(0);
  delay(100);
}

void Sensor()
{
  digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(50);
}
