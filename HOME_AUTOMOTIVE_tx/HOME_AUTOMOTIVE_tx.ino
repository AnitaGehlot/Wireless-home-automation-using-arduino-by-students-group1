#include <LiquidCrystal.h>

LiquidCrystal lcd(10,9,8,7,6,5);

int SWITCH1 = 4;
int SWITCH2 = 2;

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  
  pinMode(SWITCH1,INPUT_PULLUP);
  pinMode(SWITCH2,INPUT_PULLUP);
  
  lcd.print("BUTTON 1 -> Bulbs");
  lcd.setCursor(0,1);
  lcd.print("BUTTON 2 -> Fan");
}

void loop()
{
  int bulb=10;
  int fan=20;
  int both=30;
  
  if(digitalRead(SWITCH2)==LOW && digitalRead(SWITCH1)==LOW)
    Serial.write(both);
  else if(digitalRead(SWITCH1)==LOW)
    Serial.write(bulb);
  else if(digitalRead(SWITCH2)==LOW)
    Serial.write(fan);
    
  delay(100);
}
