int salida1 = 2;
int salida2 = 3;
char dato;
String readString;

void setup() {
  // put your setup code here, to run once:
  pinMode(salida1, OUTPUT);
  pinMode(salida2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  leer_Dato();
  if(readString.length() >0)
  {
    if(readString == "Success")
      Serial.println("Se ha conectado el bluetooth con dispositivo móvil");
    else if(readString == "Giro Izquierdo")
    {
      Serial.println("Giro Izquierdo");
      digitalWrite(salida1, LOW);
      digitalWrite(salida2, HIGH);
      delay(500);
      digitalWrite(salida2, LOW);
    }
    else if(readString == "Giro Derecho")
    {
      Serial.println("Giro Derecho");
      digitalWrite(salida1, HIGH);
      digitalWrite(salida2, LOW);
      delay(500);
      digitalWrite(salida1, LOW);
    }
    else
    {
      digitalWrite(salida1, LOW);
      digitalWrite(salida2, LOW);
    }
    readString = "";
  }
}

void leer_Dato()
{
  while(Serial.available())
  {
    delay(10);
    if(Serial.available() >0)
    {
      dato = Serial.read();
      readString += dato;
    }
  }
}
