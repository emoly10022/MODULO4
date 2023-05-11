int LED_BILDIN = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BILDIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BILDIN,HIGH);
  delay(200);
  digitalWrite(LED_BILDIN,LOW);
  delay(200);

}
