#include <LiquidCrystal.h> 
#include <ezButton.h>
#include <Arduino.h>
ezButton  nut_nhan(7); 

const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

int relay = 8;
int count = 0;
unsigned long t = 0;
void setup()
{ 
  nut_nhan.setDebounceTime(100);
  nut_nhan.setCountMode(COUNT_FALLING);
  lcd.begin(16, 2);
  pinMode(relay,OUTPUT);
  
  
   lcd.setCursor(0, 1);
   lcd.print("count = 00");
  
//    while(nut_nhan  ==   1);
}

void loop()
{ 
  nut_nhan.loop();
  unsigned long count = nut_nhan.getCount();
  nut_nhan.resetCount();
  Serial.println(count);
 
  if(millis() -  t >= 250 )
    {
      count++;  
        lcd.clear();  
        lcd.setCursor(0, 1);         
        lcd.print("count = ");
        lcd.print(count/10);
        lcd.print(count%10);   
    
      if(count >= 100)
        {
          digitalWrite(relay,HIGH);
         } 
         else{digitalWrite(relay,LOW);}
      t=millis();
    }
}
      
 
   
