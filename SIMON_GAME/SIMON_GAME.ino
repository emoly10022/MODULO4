// setando botões 
const int buttonAmarelo = 14;
const int buttonAzul = 25;
const int buttonVerde = 27;
const int buttonVermelho = 16;
const int buttonReset = 18;

// setando LEDS
const int ledVerde = 33;
const int ledAmarelo = 26;
const int ledVermelho = 12;
const int ledAzul = 19;

// variáveis que controlam estado
int roundGame = 0;
int passo = 0;
int pressionado = 0;
bool gamePlayed;
bool perdeu = false;

// elementos em formato de array
int sequence[3] = {};
int botoes[4] = {buttonVerde, buttonAmarelo, buttonVermelho, buttonAzul};
int leds[4] = {ledVerde, ledAmarelo, ledVermelho, ledAzul};
bool reset = false;
int LED_BILDIN = 2;

// reseta os jogos em intervalos definidos
void restartGame()
{
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAzul, HIGH);
    delay(200);
    delay(200);


    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAzul, LOW);

    delay(200);
    delay(200);

}

// pula para o próximo elemento da sequência
void nextPart()
{
    sequence[roundGame] = random(4);
    roundGame += 1;
}

// conecta a sequência com a luz de cada led
void returnSequence()
{
    for (int i = 0; i < roundGame; i++)
    {
        digitalWrite(leds[sequence[i]], HIGH);
        delay(500);
        digitalWrite(leds[sequence[i]], LOW);
        delay(500);
    }
}

// define como o jogo irá funcionar
void startGame()
{
    for (int i = 0; i < roundGame; i++)
    {
        gamePlayed = false;
        while (!gamePlayed)
        {
            for (int i = 0; i <= 3; i++)
            {
                if (digitalRead(botoes[i]) == 1)
                {
                    pressionado = i;
                    digitalWrite(leds[i], HIGH);
                    delay(300);
                    digitalWrite(leds[i], LOW);
                    delay(300);
                    gamePlayed = true;
                }
            }
        }
        if (sequence[passo] != pressionado)
        {

          restartGame();
          perdeu = true;
          break;
        }
        passo += 1;
    }
    passo = 0;
}

void setup()
{
    // LEDS do jogo
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAmarelo, OUTPUT);
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledAzul, OUTPUT);

    // butões do jogo
    pinMode(buttonVerde, INPUT_PULLUP);
    pinMode(buttonAmarelo, INPUT_PULLUP);
    pinMode(buttonVermelho, INPUT_PULLUP);
    pinMode(buttonAzul, INPUT_PULLUP);
    pinMode(buttonReset, INPUT_PULLUP);
    pinMode(LED_BILDIN, OUTPUT);

    randomSeed(analogRead(4));
}

void loop()
{

  nextPart();
  returnSequence();
  startGame();

  if (perdeu == true){
    while(true){
      digitalWrite(ledVerde,HIGH);
      digitalWrite(ledAmarelo,HIGH);
      digitalWrite(ledVermelho,HIGH);
      digitalWrite(ledAzul,HIGH);
      delay(500);
      digitalWrite(ledVerde,LOW);
      digitalWrite(ledAmarelo,LOW);
      digitalWrite(ledVermelho,LOW);
      digitalWrite(ledAzul,LOW);
      if (digitalRead(buttonReset)==LOW){
        break;
      }
    }
    sequence[3] = {};
    roundGame = 0;
    passo = 0;
    pressionado = 0;
    perdeu = false; 
  }
  delay(1200);


}