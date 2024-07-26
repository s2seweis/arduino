int rot = 8;
int orange = 7;
int gruen = 6;
int fRot = 3;
int fGruen = 2;
int taster = 4;
int lautsprecher = 5;

int status = 0;


void setup()
{
	pinMode(rot, OUTPUT);
  	pinMode(orange, OUTPUT);
  	pinMode(gruen, OUTPUT);
 	pinMode(fRot, OUTPUT);
  	pinMode(fGruen, OUTPUT);
  	pinMode(lautsprecher, OUTPUT);
  
  	pinMode(taster, INPUT);
}

void gruenRot(){
  digitalWrite(gruen, LOW);
  digitalWrite(orange, HIGH);
  delay(2000);
  digitalWrite(orange, LOW);
  digitalWrite(rot, HIGH);

}

void rotGruen(){
  digitalWrite(rot, HIGH);
  digitalWrite(orange, HIGH);
  delay(2000);
  digitalWrite(rot, LOW);
  digitalWrite(orange, LOW);  
  digitalWrite(gruen, HIGH);
  

}

void fussgaenger(){
	digitalWrite(fRot, LOW);
  	digitalWrite(fGruen, HIGH);
  	digitalWrite(lautsprecher, HIGH);
  	// laufen ..... 10sec
  	delay(10000);
  	digitalWrite(fGruen, LOW);
  	digitalWrite(fRot, HIGH);
  	digitalWrite(lautsprecher, LOW);
}


void loop()
{
 
  // Beginn: Autos grün, Fussgänger rot
  digitalWrite(gruen, HIGH);
  digitalWrite(fRot, HIGH);
  
  // Fussgänger drückt Taster
  status = digitalRead(taster);
  
  if(status == HIGH){
    delay(1000);
   // Autos von gruen auf rot
    gruenRot();
  // kurze Pause
    delay(1000);
  // Fussgänger von rot auf gruen
    fussgaenger();
  // kurze Pause
    delay(1000);
  // Autos von rot auf gruen  
	rotGruen();
  
   
  }
}