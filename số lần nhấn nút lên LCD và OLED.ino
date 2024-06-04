#include <ezButton.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#include <LiquidCrystal.h>

const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

ezButton button(7);  

void setup() {
  Serial.begin(9600);
  button.setCountMode(COUNT_FALLING);
  
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);}
 lcd.begin(16, 2); // set up number of columns and rows   
// lcd.clear(); 
    
}

void loop() {
  button.loop(); // MUST call the loop() function first
  
 
  unsigned long count = button.getCount();
  Serial.println(count);
  
  if(count >= 100){
    button.resetCount();}

    lcd.setCursor(0, 0);         
    lcd.print("count: ");  
    lcd.print(count/10); 
    lcd.print(count%10); 
    
    oled.setTextSize(1);          
    oled.setTextColor(WHITE);     
    oled.setCursor(0, 10);       
    oled.print("count: ");
    oled.println(count/10);
    oled.println(count%10);
  
  oled.display(); 
  oled.clearDisplay(); // clear display 
  delay(200);           
}
