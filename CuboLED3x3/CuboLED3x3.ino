int Columnas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int Filas[] = {12, 11, 10};

int RandFila;     //Variable para fila aleatoria
int RandColumna;  //Variable para columna aleatoria

byte Sequence[3][3] = {
{1,0,0},
{0,1,0},
{0,0,1}
}; 
void setup()
{
  Serial.begin(9800);
  int contador;
 
  for (int contador = 0; contador < 9; contador++){
    pinMode(Columnas[contador], OUTPUT); }
 
  for (int contador = 0; contador < 3; contador++){
    pinMode(Filas[contador], OUTPUT); }
}
 
void loop()
{
  //ControlPosition();
  //CaracolLed();
  //RandLed();
  Sequence1();
}

void Sequence1(){
  for(int j = 0; j < 3; j++){
  for(int i = 0; i < 3; i++){
    digitalWrite(Sequence[i][j], HIGH);
  }
  }
}

void RandLed()
{
  RandFila = random(0,3);
  RandColumna = random(0,9);
 
  digitalWrite(Filas[RandFila], HIGH);
  digitalWrite(Columnas[RandColumna], HIGH);
 
  delay(75);
 
  digitalWrite(Filas[RandFila], LOW);
  digitalWrite(Columnas[RandColumna], LOW);
 
  delay(50);
}

void ControlPosition(){
  digitalWrite(Filas[0], HIGH);
  digitalWrite(Columnas[0], HIGH);
}

void CaracolLed(){
  int i, j;
  for(j = 0; j < 9; j++){
      digitalWrite(Columnas[j], HIGH);
      digitalWrite(Filas[0], HIGH);
      delay(50);
  }
  for(j = 9; j > 0 ; j--){
      digitalWrite(Columnas[j], LOW);
      digitalWrite(Filas[0], HIGH);
      delay(50);
  }
  digitalWrite(Filas[0], LOW);
  
  for(j = 0; j < 9; j++){
      digitalWrite(Columnas[j], HIGH);
      digitalWrite(Filas[1], HIGH);
      delay(50);
  }
  for(j = 9; j > 0 ; j--){
      digitalWrite(Columnas[j], LOW);
      digitalWrite(Filas[1], HIGH);
      delay(50);
  }
  digitalWrite(Filas[1], LOW);

  for(j = 0; j < 9; j++){
      digitalWrite(Columnas[j], HIGH);
      digitalWrite(Filas[2], HIGH);
      delay(50);
  }
  for(j = 9; j > 0 ; j--){
      digitalWrite(Columnas[j], LOW);
      digitalWrite(Filas[2], HIGH);
      delay(50);
  }
  digitalWrite(Filas[2], LOW);
  delay(200);
}

