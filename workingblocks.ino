#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define screen_width 128
#define screen_height 32

#define smokeA0 A2
#define motion 3
#define LED 4

int sensorThres = 400;


Adafruit_SSD1306 display(screen_width, screen_height);

void motsens()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  if(digitalRead (motion) == HIGH)
    {
      digitalWrite(LED, LOW);
      display.print("Run for your life");
      motsens();
    }
    else
    {
      digitalWrite(LED, HIGH);
    }
   }
   if (analogSensor > sensorThres)
   {
    
   }
}

void fire()
{
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("FIRE");
}
int iCountdown()
{
  int countdown=10;
  while (countdown !=0)
  {
    
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 16);
    display.print(countdown);
    fire();
    display.display();
    
    delay(1000);
    countdown--;
  }
  display.clearDisplay();
  fire();
  display.display();
    return 0; 
}

void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  pinMode(smokeA0, INPUT);
  pinMode(motion, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}
 
 
void loop()
{
int analogSensor = analogRead(smokeA0);
 if (analogSensor > sensorThres)
  {
    iCountdown(); 
  
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    /*if(digitalRead (motion) == HIGH)
    {
      digitalWrite(LED, LOW);
      display.print("Run for your life");
    }
    else
    {
      digitalWrite(LED, HIGH);
    }
   }
  display.display();
  delay(30000);*/
  
  digitalWrite(LED, LOW);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.print("Fire extinguished");
  
}
