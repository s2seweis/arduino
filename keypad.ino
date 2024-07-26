// C++ code
//

#include <Keypad.h>
const byte COLS = 4;
const byte ROWS = 4;

byte colPins[4] = {2,3,4,5};
byte rowPins[4] = {6,7,8,9};

char hexaKeys[ROWS][COLS]={
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};

Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char Taste;

void setup()
{
	Serial.begin(9600);
}

void loop(){
	Taste = Tastenfeld.getKey();
	if(Taste){
      Serial.print(Taste);
	}
}