// hiển thị số lần nhấn nút lên oled
// hơn 10 lần nhấn oled tắt
// hơn 20 lần nhấn oled sáng


#include <ezButton.h>

ezButton button(7);  // create ezButton object that attach to pin 7;
//-------------------------------
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(100); // set debounce time to 100 milliseconds
 
  button.setCountMode(COUNT_FALLING);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  Serial.println(F("SSD1306 allocation failed"));
  while (true);
  }
   oled.clearDisplay(); // clear display
   delay(20);      
}

void loop() {
  
  button.loop(); // MUST call the loop() function first
  
  unsigned long count = button.getCount(); // dem so lan nhan 
  
  Serial.println(count);
    
    oled.setTextSize(2);          
    oled.setTextColor(WHITE);     
    oled.setCursor(0, 10);       
    oled.print("count: ");
    oled.print(count);
    
   if(count > 10){
     oled.clearDisplay();}
   if(count > 20){
    oled.setTextSize(2);          
    oled.setTextColor(WHITE);     
    oled.setCursor(0, 10);       
    oled.print("count: ");
    oled.print(count);}
   
   oled.display(); 
   oled.clearDisplay();
   delay(80);
   
   
   }
     
   oled.display(); 
   }
