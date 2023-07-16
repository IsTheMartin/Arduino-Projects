#define LED 17

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    // Enciende el LED verde (RX)
    RXLED1;      // == digitalWrite(LED, HIGH);
    delay(1000);

    // Apaga el LED verde (RX)
    RXLED0;      // == digitalWrite(LED, LOW);
    delay(1000);
  
  
    // Enciende el LED amarillo (TX)
    TXLED1;      // != digitalWrite(LED, HIGH);
    delay(1000);

    // Apaga el LED amarillo (TX)
    TXLED0;      // != digitalWrite(LED, LOW);
    delay(1000);  
}
