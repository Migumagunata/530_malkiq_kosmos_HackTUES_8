#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define screen_width 128
#define screen_height 32


int sensorThres = 100;
int smokeA0 = A2;


Adafruit_SSD1306 display(screen_width, screen_height);


void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}
 
 
void loop()
{
int analogSensor = analogRead(smokeA0);
 if (analogSensor > sensorThres)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("FIRE");
    
  }
  

  display.display();
}
