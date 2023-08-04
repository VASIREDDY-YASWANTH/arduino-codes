#include <Arduino.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8,7,6,5,4,3);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.clear();
}

void loop() {
  float cp=0,loopvar=0;         // cp=clock pulses      loopvar=counts number of loops 
  byte B = 0x64;
  cp = cp + 7;                  // To assign value to B processor takes 7 clock pulses.
  while (B > 0) {
    B--;
    cp = cp +4;                 //To perform decrement operation processsor takes 4 clock pulses each time.
  loopvar++;
  }
  cp = cp + 10*(loopvar-1) + 7; // The loop continous for (loopvar-1) times by taking 10 clock pulses each time and finally breakes when B=0 by taking 7 clock pulses.
  float dly = cp*0.2;           //0.2 is time period of each clock pulse
  lcd.setCursor(0,0);
lcd.print(dly);
lcd.setCursor(0,1);
lcd.print("micro_seconds");
}


