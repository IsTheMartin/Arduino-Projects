void distanceUS(){
  int cm;
  //distancia(cm);
  lcd.setCursor(0, 0);
  lcd.print("Distancia: ");
  lcd.print(cm);
  lcd.print(" cm      ");
}

int distancia(int *cm){
  long duration;
  int trigger = 9;
  int echo = 8;

  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);

  *cm = us2cm(duration);
}

long us2cm(long microseconds){
  long dato = microseconds/29/2;
  Serial.println(dato);
  return dato;
}

