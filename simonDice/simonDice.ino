//Definicion de variables
const int button1 = 2; //conectado al pin 2. Estas variables no cambian
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

const int led1 = 7;
const int led2 = 8;
const int led3 = 9;
const int led4 = 10;

const int buzzer = 12;

const int tones[] = {1900, 1600, 1300, 1000, 3200}; //Estas variables guardan la frecuencia para cada sonido

int buttonState[] = {0, 0, 0, 0}; //Aqui se guardan los estados de cada boton
int lastButtonState[] = {0, 0, 0, 0}; //Aqui se guarda el estado anterior de cada boton
int buttonCounter[] = {0, 0, 0, 0}; //Aqui se guarda las veces que se oprime un boton
int gameOn = 0; //Un juego nuevo inicia guando gameOn vale 0
int wait = 0; //Esta variable le indica al juego que debe esperar a que el jugador pulse un boton
int currentLevel = 1; //Se guarda el nivel inicial
int dlay = 500; //Aqui se guarda el tiempo que debe esperar entre activacion de LEDS en ms
int ledTime = 500;  //Guarda el tiempo que el LED va a encender en ms
int n_levels = 10; //El nivel mas algo. Despues de este, la velocidad ira mas rapido
int pinAndTone = 0; //Con esta variable se determinara cual LED debe encender
int correct = 0; //Aqui se guarda 1 si el patron es correcto
int speedFactor = 5; //La velocidad aumenta en un factor de 5 cada vez que se gana
int ledDelay = 200; //Tiempo entre patrones

//Esta funcion activa el buzzer con la frecuencia deseada
void playTone(int tone, int duration) 
{
  for (long i = 0; i < duration * 1000L; i += tone * 2) 
  {
    digitalWrite(buzzer, HIGH); // Turns the buzzer on.
    delayMicroseconds(tone); // Creates the tone of the buzzer.
    digitalWrite(buzzer, LOW); // Turns the buzzer off.
    delayMicroseconds(tone);
  }
}

//Configuracion de pines
void setup() 
{
  randomSeed(analogRead(0)); // Se genera un numero aleatorio
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

//Aqui inicia el juego
void loop() 
{
  int n_array[n_levels];//Aqui se guarda un patron aleatorio
  int u_array[n_levels]; //Aqui se guarda el patron generado por el jugador

  int i;
  if (gameOn == 0) //Si el gameOn vale 0, el juego inicia
  { 
    for (i = 0; i < n_levels; i = i + 1) 
    {
      n_array[i] = 0;
      u_array[i] = 0;
      n_array[i] = random(0, 4); //Guarda el numero aleatorio del patron
    }
    gameOn = 1; //Le dice al juego que debe iniciar
  }

  if (wait == 0) //Se activa cuando el jugador no debe oprimir nada
  { 
    delay (200);
    i = 0;
    for (i = 0; i < currentLevel; i = i + 1) 
    {
      ledDelay = ledTime / (1 + (speedFactor / n_levels) * (currentLevel - 1));
      pinAndTone = n_array[i];
      digitalWrite(pinAndTone + 7, HIGH);
      playTone(tones[pinAndTone ], ledDelay);
      digitalWrite(pinAndTone + 7, LOW);
      delay(100 / speedFactor); //Aqui se muestra al jugador el patron actual
    }
    wait = 1; //Aqui pone al juego en pausa mientras el usuario no pulsa botones
  }

  i = 0;
  int buttonChange = 0;//Aqui se guarda un 1 cuando el jugador pulsa un boton
  int j = 0; //j es la posicion actual en el patron
  while (j < currentLevel) 
  {
    while (buttonChange == 0) 
    {
      for (i = 0; i < 4; i = i + 1) 
      {
        buttonState[i] = digitalRead(i + 2);
        buttonChange += buttonState[i]; //Aqui se determina cual boton pulso el usuario
      }
    }

    for (i = 0; i < 4; i = i + 1) 
    {
      if (buttonState[i] == HIGH) 
      {
        digitalWrite(i + 7, HIGH);
        playTone(tones[i], ledTime);
        digitalWrite(i + 7, LOW); //Aqui se enciende el LED correspondiente al boton y su frecuencia en la bocina
        wait = 0;
        u_array[j] = i; //Aqui se guarda la pulsacion del jugador para comparar con la del programa
        buttonState[i] = LOW;
        buttonChange = 0; //Aqui le hace reset al boton
      }
    }

    if (u_array[j] == n_array[j]) 
    {
      j++;
      correct = 1;
    }
    else 
    {
      correct = 0;
      i = 4;
      j = currentLevel;
      wait = 0; //Aqui revisa si es igual el patron
    }
  }

  if (correct == 0) 
  {
    delay(300);
    i = 0;
    gameOn = 0;
    currentLevel = 1; //Si el jugador se equivoca, esta variable reinicia el juego

    for (i = 0; i < 4; i = i + 1) 
    {
      digitalWrite(i + 7, HIGH);
    }
    playTone(tones[4], ledTime);
    
    for (i = 0; i < 4; i = i + 1) 
    {
      digitalWrite(i + 7, LOW);
    }
    delay (200);
    
    for (i = 0; i < 4; i = i + 1) 
    {
      digitalWrite(i + 7, HIGH);
    }
    playTone(tones[4], ledTime);
    
    for (i = 0; i < 4; i = i + 1) 
    {
      digitalWrite(i + 7, LOW);
    }
    delay(500);
    gameOn = 0;
  }
  //Esta parte hace que los LEDS parpadeen dos veces cuando pierde el jugador

  if (correct == 1) 
  {
    currentLevel++;
    wait = 0;
  }
    //Si el patron es correcto, el nivel sube 1   

  if (currentLevel == n_levels) 
  {
    delay(500);
    int notes[] = {2, 2, 2, 2, 0, 1, 2, 1, 2};
    int note = 0;
    int tempo[] = {200, 200, 200, 400, 400, 400, 200, 200, 600};
    int breaks[] = {100, 100, 100, 200, 200, 200, 300, 100, 200};
    for (i = 0; i < 9; i = i + 1) 
    {
      note = notes[i];
      digitalWrite(note + 7, HIGH);
      playTone(tones[note], tempo[i]);
      digitalWrite(note + 7, LOW);
      delay(breaks[i]);
    } //Esta parte toca una melodia si el juego es terminado

    gameOn = 0;
    currentLevel = 1;
    n_levels = n_levels + 2; //Aqui se suman 2 niveles al juego
    speedFactor += 1; //Aqui se incrementa el factor de velocidad en 1
  } //Esta seccion solo se activa si el juego se termina
}
