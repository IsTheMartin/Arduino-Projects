void setup(){
  //inicializa la conexion serial
  Serial.begin(9600);
  // configura al pin2 como pin de entrada y habilita la resistencia interna en pull-up.
  pinMode(11, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop(){
  //asigna la entrada del pulsador a la variable sensorVal
  int sensorVal = digitalRead(11);
  //muestra el resultado
  Serial.println(sensorVal);
 
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  }
  else {
    digitalWrite(13, HIGH);
  }
}

