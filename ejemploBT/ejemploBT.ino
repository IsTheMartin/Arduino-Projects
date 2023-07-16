long unsigned antes = millis();
long unsigned ahora;

void setup()
{
  Serial2.begin(9600);
}
 
void loop()
{
  long unsigned ahora = millis();

  if(ahora - antes > 5000)
  {
    antes = millis();
    Serial2.print("1");
  }
}
