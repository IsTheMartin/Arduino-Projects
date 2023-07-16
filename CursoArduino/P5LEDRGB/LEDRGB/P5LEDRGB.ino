int led_red = 12;
int led_green = 11;
int led_blue = 10;

int button = 9;
unsigned int state = 0;
unsigned int pot = 0;
int sumatoria;


void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button) == LOW){
    state++;
    if(state >= 3)
      state = 0;
  }

  sumatoria = 0;
  //Limpieza de señal
  for(int i = 0; i < 10; i++){
    sumatoria = sumatoria + analogRead(A0);
  }
  pot = sumatoria / 10;

  switch(state){
    case 0:
      analogWrite(led_red, pot);
      break;
    case 1:
      analogWrite(led_green, pot);
      break;
    case 2:
      analogWrite(led_blue, pot);
      break;
  }
  delay(10);
}
