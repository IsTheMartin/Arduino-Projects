int sensortemp = A0;     // LM35 va conectado al pin A0
int ventilador = 12;
float temp = 0;  // Variable para guardar datos del sensor temperatura
void setup(){
  Serial.begin(9600);  // configuracion serial
  pinMode(ventilador,OUTPUT);  //configuracion pin 12 como salida
}
void loop(){
  temp = analogRead(sensortemp);  // Leer datos del sensor de temperatura
  temp = (5.0 * temp * 100.0)/1024.0; // convertir el dato a C°
  if(temp>22){  //temperatura es mayor a 26?
    digitalWrite(ventilador,HIGH);
  }
  else if(temp<15){
    digitalWrite(ventilador,LOW);
  }
  else{
    digitalWrite(ventilador,LOW);
  }
  Serial.println("Temperatura es:");
  Serial.println(temp);
  delay(3000); // retraso de 1s
}
