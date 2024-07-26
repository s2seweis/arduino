int LED = 3;
int helligkeit = 0;
int x = 5;


void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
 	analogWrite(LED, helligkeit);
  	helligkeit = helligkeit + x;
  	// Pause 0,5 Sec
  	delay(50);
  	
    if(helligkeit == 0 || helligkeit == 255){
      // Vorzeichenwechsel aus
      x = -x;
    }
}