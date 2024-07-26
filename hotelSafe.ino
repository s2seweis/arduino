// C++ code
//
#include<LiquidCrystal_I2C.h>
#include<Keypad.h>
const byte Rows = 4;
const byte Cols = 4;
const int LEDPins[2]={A0,A1};
const int buzzer=2;
const int PushButton = 3;
bool OpenUnlock = false;
bool LockedSystem = false;
int count = 0;
String DefaultPassword = "1234";
String UserTypePassword;
char UserTypePass = 0;
char keys[Rows][Cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 byte RowsPins[Rows] = {13,12,11,10};
 byte ColsPins[Cols] = {7,6,5,4};
Keypad keyboard = Keypad(makeKeymap(keys),RowsPins,ColsPins,Rows,Cols);
LiquidCrystal_I2C lcd(0x20,16,2);
void setup()
{
  pinMode(PushButton, INPUT);
  pinMode(buzzer, OUTPUT);
  for(int i=0;i<2;i++)
  {
  	  pinMode(LEDPins[i], OUTPUT);

  }
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Loading");
  delay(2000);
  lcd.clear();
}

void loop()
{
  	if(OpenUnlock)
    {
        lcd.setCursor(0,0);
        lcd.print("Safe unlocked");
        digitalWrite(LEDPins[1], HIGH);
        digitalWrite(buzzer, HIGH);
    }
  	else if(LockedSystem)
    {
    	lcd.setCursor(1,0);
        lcd.print("Password wrong");
      	lcd.setCursor(1,1);
      	lcd.print("SYSTEM LOCKED");
      	digitalWrite(LEDPins[0], HIGH);
      	digitalWrite(buzzer, HIGH);
      	delay(800);
		digitalWrite(LEDPins[0], LOW);
      	digitalWrite(buzzer, LOW);
      	delay(800);
      	digitalWrite(LEDPins[0], HIGH);
      	digitalWrite(buzzer, HIGH);
      	delay(800);
    }
   	else
    {
      	lcd.setCursor(0,0);
        lcd.print("Enter Password : ");
        char key = keyboard.getKey();
        lcd.setCursor(0,1);
        if(key)
        {

                UserTypePass = key;
                UserTypePassword += UserTypePass;
                for(int i=0;i<UserTypePassword.length();i++)
                {
                        lcd.print("*");
                }
        }
        if(digitalRead(PushButton)==HIGH)
        {
            if(UserTypePassword==DefaultPassword)
            {
                OpenUnlock=true;
              	if(count>0)
                {
                	count=0;
                }
              	lcd.clear();
            }
          	else if(UserTypePassword!=DefaultPassword)
            {
                if(UserTypePass==0)
            	{
           			 digitalWrite(LEDPins[0], HIGH);
                     lcd.clear();
                     lcd.setCursor(0,0);
                     lcd.print("Please Enter");
                     lcd.setCursor(0,1);
                     lcd.print("The Password");
              		 delay(3000);
                     lcd.clear();
                     digitalWrite(LEDPins[0], LOW);
            	}
              	else
                {
                   UserTypePass=0;
                   UserTypePassword="";
                   count++;
                   delay(800);
                   if(count>3)
                   {
                      lcd.clear();
                      LockedSystem=true;

                   }
                   else
                   {
                       digitalWrite(LEDPins[0], HIGH);
                       lcd.clear();
                       lcd.setCursor(2,0);
                       lcd.print("Wrong Password");
                       lcd.setCursor(5,1);
                       if(count==1)
                       {
                           lcd.print(count);
                           lcd.print(" time");
                       }
                       else
                       {
                           lcd.print(count);
                           lcd.print(" times");
                       }
                       delay(3000);
                       lcd.clear();
                       digitalWrite(LEDPins[0], LOW);

                   }  

                 }
              	 
             
            }

          	

        }
    }
  
	
  	
    
    
}