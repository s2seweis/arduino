// Variablen
int LEDgruen = 8;
int LEDrot = 7;

// Setup
void setup(){
  	// OUTPUT z.B. LED, Motor, Display ....
 	pinMode(LEDgruen, OUTPUT); 
  	pinMode(LEDrot, OUTPUT);
  	// INPUT z.B. Temperatursensor, Tastenfeld, Taster ....
}

// Loop
void loop(){
 	digitalWrite(LEDgruen, HIGH);
  	
  	// Pause in Millisekunden 1000 = 1 sec
  	delay(1000);
  
  	// LOW =  LED leuchtet nicht mehr
  	digitalWrite(LEDgruen, LOW);
  	// HIGH = LED leuchtet 
  	digitalWrite(LEDrot, HIGH);
  
  	delay(1000);
  
  	digitalWrite(LEDrot, LOW);
}