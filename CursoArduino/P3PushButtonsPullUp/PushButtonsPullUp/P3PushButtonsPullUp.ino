int led1 = 12;
int led2 = 11; 
int led3 = 10;

int button1 = 4;
int button2 = 3;
int button3 = 2;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button1) == HIGH){
    digitalWrite(led1, HIGH);
  } else{
    digitalWrite(led1, LOW);
  }
  if(digitalRead(button2) == HIGH){
    digitalWrite(led2, HIGH);
  } else{
    digitalWrite(led2, LOW);
  }
  if(digitalRead(button3) == HIGH){
    digitalWrite(led3, HIGH);
  } else{
    digitalWrite(led3, LOW);
  }
  delay(10);
}
