#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define screen_width 128
#define screen_height 32

#define smokeA0 A2
#define motion 3
#define FAN 5

int sensorThres = 400;
int timer_one = 60;
int timer_two = 30;
int last_smoke = 0;
int last_motion = 0;


Adafruit_SSD1306 display(screen_width, screen_height);

void fire()
{
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("FIRE");
}

void iCountdown()
{
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 16);
    display.print(timer_one);
    
    delay(1000);
    timer_one--; 
}

void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  pinMode(smokeA0, INPUT);
  pinMode(motion, INPUT);
  pinMode(FAN, OUTPUT);
  digitalWrite(FAN, LOW);
}
 
 
void loop()
{
  int analogSensor = analogRead(smokeA0);
  
  if(last_smoke == 0)
  {
    //proverqvam pak
    if(analogSensor > sensorThres)
    {
      last_smoke = 1;
    }
  }
  else
  {
    display.clearDisplay();
    fire();
    if (timer_one > 0)
    {
      iCountdown();
      if(last_motion == 0)
      {
        if (digitalRead(motion) == HIGH)
        {
          display.setTextSize(2);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(64, 0);
          display.print("RUN!");
          timer_one = timer_one + timer_two;
          last_motion = 1;
        }
      }
      else
      {
          display.setTextSize(2);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(64, 0);
          display.print("RUN!");
      }
    }
    else 
    {
      digitalWrite(FAN, HIGH);
    }
    
    display.display();
  }
}
