#include <LiquidCrystal.h>

LiquidCrystal lcd(9,10,5,6,7,8);

int FAN_PIN = 2;
int BULB_PIN = 4;

void setup()
{
  lcd.begin(20,2);
  Serial.begin(9600);
  
  pinMode(FAN_PIN,OUTPUT);
  pinMode(BULB_PIN,OUTPUT);
}

void loop()
{
  lcd.clear();
  int signal=Serial.read();
  if(signal==30){
    digitalWrite(FAN_PIN,HIGH);
    digitalWrite(BULB_PIN,HIGH);
    lcd.print("Fan Switched ON");
    lcd.setCursor(0,1);
    lcd.print("Bulbs Switched ON");
    delay(100);
  }
  else if(signal==10){
    digitalWrite(BULB_PIN,HIGH);
    lcd.print("Fan Switched OFF");
    lcd.setCursor(0,1);
    lcd.print("Bulbs Switched ON");
    delay(100);
  }
  else if(signal==20){
    digitalWrite(FAN_PIN,HIGH);
    lcd.print("Fan Switched ON");
    lcd.setCursor(0,1);
    lcd.print("Bulbs Switched OFF");
    delay(100);
  }
  else {
    digitalWrite(FAN_PIN,LOW);
    digitalWrite(BULB_PIN,LOW);
    lcd.print("Fan Switched OFF");
    lcd.setCursor(0,1);
    lcd.print("Bulbs Switched OFF");
  }
  delay(100);
}
