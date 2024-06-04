#include <LiquidCrystal.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int nut_nhan = 7;
int Lcd = 0;
int Oled = 0;
int count = 0;
String data ="";


void strings(){
   if (Serial.available() > 0) {
    delay(10);
      data = Serial.readString();
      Serial.println(data);
   if (data.indexOf("LCD") >= 0) {
     data = "";
     Lcd = 1;  // ON
     Oled = 0;  // OFF
     Serial.print("LCD: ");
     Serial.print(count);
  }
   if (data.indexOf("OLED") >= 0) { 
     data = "";
     Lcd = 0;  // OFF
     Oled = 1;  // ON
     Serial.print("OLED: ");
     Serial.print(count);
  }
    data="";
  }
}


void setup()
{
  pinMode(nut_nhan,INPUT_PULLUP);
  Serial.begin(9600);
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Khong the ket noi"));
    while (true);
  }
  delay(200);
  
  lcd.begin(16, 2);
  lcd.clear(); 
  
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.clearDisplay();
  oled.display(); 
  
}




void loop()
{
     int a = digitalRead(nut_nhan);
    if(a == 0 && nut_nhan <99)
      {
        delay(10);
        while(a == 0) {}
          count++;
          Serial.println(count);
         lcd.clear();
        
        oled.clearDisplay();
        oled.display(); 
       }
  
  strings();
  
  if(Lcd == 1 && Oled == 0)
      {
        lcd.setCursor(0, 0);        
        lcd.print("Count: ");
        lcd.print(count/10);
        lcd.print(count%10);
        
        oled.clearDisplay();
        oled.display(); 
      }
  if(Lcd == 0 && Oled == 1)
      {
        oled.setCursor(0,0);        
        oled.print("Count: ");
        oled.print(count/10);
        oled.print(count%10);
        oled.display(); 
        
        lcd.clear();
      }
}
