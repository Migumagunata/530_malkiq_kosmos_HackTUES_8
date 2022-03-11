#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define screen_width 128
#define screen_height 32

#define smokeA0 A2

int sensorThres = 400;


Adafruit_SSD1306 display(screen_width, screen_height);

void fire()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("FIRE");
  display.display();
}
int iCountdown()
{
  int countdown=60;
  while (countdown !=0)
  {
    
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 16);
    display.print(countdown);
    display.display();
    fire();
    delay(1000);
    countdown--;
  }
    return 0; 
}

void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(smokeA0, INPUT);
}
 
 
void loop()
{
int analogSensor = analogRead(smokeA0);
 if (analogSensor > sensorThres)
  {
    iCountdown(); 
  }  
}
