#define led 11
char dato;
String readString;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  leer_Dato();
  if(readString.length() >0)
  {
    if(readString == "Exito")
      Serial.println("Se ha conectado el bluetooth con dispositivo móvil");
    else if(readString == "Led Off")
    {
      Serial.println("APAGAR");
      digitalWrite(led, LOW);
    }
    else if(readString == "Led On")
    {
      Serial.println("ENCENDER");
      digitalWrite(led, HIGH);
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
