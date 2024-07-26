int LED = 7;
int taster = 2;
int status = 0;

void setup()
{
	pinMode(LED, OUTPUT);
  	pinMode(taster, INPUT);
}

void loop()
{
  // Lesen, ob Taster gedrückt wurde
  status = digitalRead(taster);
  // falls gedrückt, dann status = HIGH
  if(status == HIGH){
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
  }
}