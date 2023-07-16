void setup(){
   Serial.begin(9600);
   Serial1.begin(38400);
 
   Serial1.println("AT");
}
 
void loop(){
 
   while (Serial1.available()){
      Serial.write(Serial1.read());
   }
   delay(50);
 
   while (Serial.available()){
      Serial1.write(Serial.read());
   }
   delay(50);
}
