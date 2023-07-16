int ledPins[] = {2,3,4,5,6,7,8};
const int TAM = 7;
int N1[] = {0,1,1,0,0,0,0};
int N2[] = {1,1,0,1,1,0,1};
int N3[] = {1,1,1,1,0,0,1};
int N4[] = {0,1,1,0,0,1,1};
int N5[] = {1,0,1,1,0,1,1};
int N6[] = {1,0,1,1,1,1,1};
int N7[] = {1,1,1,0,0,0,0};
int N8[] = {1,1,1,1,1,1,1};
int N9[] = {1,1,1,0,0,1,1};
int N0[] = {1,1,1,1,1,1,0};

void setup() {
  for(int i = 0; i < TAM; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  for(int i = 0; i < TAM; i++){
    if(N1[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N2[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N3[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N4[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N5[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N6[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N7[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N8[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N9[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for(int i = 0; i < TAM; i++){
    if(N0[i] == 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }
  delay(500);
}
