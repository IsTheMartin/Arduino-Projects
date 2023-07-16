byte letterN[7][5] {
  {1,0,0,0,1},
  {1,1,0,0,1},
  {1,1,0,0,1},
  {1,0,1,0,1},
  {1,0,1,0,1},
  {1,0,0,1,1},
  {1,0,0,1,1}
};
byte letterA[7][5] {
  {0,0,1,0,0},
  {0,1,0,1,0},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,1,1,1,1},
  {1,0,0,0,1},
  {1,0,0,0,1}
};

int rows[] = {1,2,3,4,5,6,7};
int cols[] = {8,9,10,11,12};

void setup() {
  // put your setup code here, to run once:
  turnOff();
}

void loop() {
  // put your main code here, to run repeatedly:
    for(int j = 0; j < 5; j++){
      digitalWrite(cols[j], HIGH);
      for(int k = 0; k < 7; k++){
        if(letterA[k][j] == 1){
          delay(4);
          digitalWrite(rows[k], HIGH);
        }
      }
      delay(4);
      turnOff();
  }
}

void turnOff(){
  for(int i = 0; i < sizeof(rows); i++){
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], LOW);
  }
  for(int i = 0; i < sizeof(cols); i++){
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], LOW);
  }
}

void turnOnCols(){
  for(int i = 0; i < sizeof(cols); i++){
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], HIGH);
  }
}

