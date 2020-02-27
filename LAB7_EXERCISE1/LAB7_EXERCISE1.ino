#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define SW1 4
#define SW2 5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() 
{
  Serial.begin(9600);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
}

void loop() 
{
  int SW1pull = digitalRead(SW1);
  int SW2pull = digitalRead(SW2);
 display.clearDisplay();
 display.drawCircle(55, 15, 12, WHITE);
 display.drawCircle(55, 45, 12, WHITE);
 
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(0,10);
 display.println("SW1");

 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(0,40);
 display.println("SW2");
 
 display.display();
 if(SW1pull==0)
 {
  display.fillCircle(55, 45, 12, WHITE);
  display.display();
  Serial.println("111");
 }
 else if (SW2pull==0)
 {
  display.fillCircle(55, 15, 12, WHITE);
  display.display();
  Serial.println("222");
 }
 Serial.println("AA");
}
