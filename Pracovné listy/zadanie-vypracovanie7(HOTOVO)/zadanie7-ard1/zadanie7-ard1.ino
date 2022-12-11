
//ARDUINO 1

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
char test = 1;
String sprava;
  
void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop()
{
  if(digitalRead(2) == LOW && test == 0) 
  {
    Serial.print("Sprava od ard1");
    delay(35);
    test = 1;
  }
  
  if ( digitalRead(2) == HIGH && test == 1)
  {
     test = 0;
  }

    if (Serial.available())
  {
    lcd.clear();
    sprava = Serial.readString();
    lcd.print(sprava);
  }
}
