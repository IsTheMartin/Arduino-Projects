const int led1 = 12;
const int led2 = 11;
const int button1 = 10;
const int button2 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  if(Serial.available()){
    char inputChar = Serial.read();
    if(inputChar == 'a')
      digitalWrite(led1, HIGH);
    else if(inputChar == 's')
      digitalWrite(led1, LOW);
    else if(inputChar == 'z')
      digitalWrite(led2, HIGH);
    else if(inputChar == 'x')
      digitalWrite(led2, LOW);
  }

  if(digitalRead(button1) == HIGH){
    Serial.println("Boton oprimido");
  }

  if(digitalRead(button2) == HIGH){
    int ldr = analogRead(A0);
    Serial.print("Valor de la fotorresistencia: ");
    Serial.println(ldr);
  }
  delay(100);
}
