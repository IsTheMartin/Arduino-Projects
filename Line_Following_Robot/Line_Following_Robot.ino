/****************************************************************
         Robot Seguidor de Línea - Line Following Robot
*****************************************************************
Martin Ignacio Morales De Arco
06/Nov/2014*/
int sensor1 = 0;
int sensor2 = 1;

int out1 = 13;
int out2 = 12;

int val1 = 0;
int val2 = 0;

void setup()
{
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val1 = analogRead(sensor1);
  val2 = analogRead(sensor2);
 if(val1<=100)
    digitalWrite(out1, HIGH);
  else
    digitalWrite(out1, LOW);
  Serial.println(val1);
}


