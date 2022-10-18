#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
int pocet = 0;
char test = 0;

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{

if(digitalRead(2) == LOW && test == 0)
     {
     if(pocet==0)
          { 
          lcd.clear();
          lcd.setCursor(0,0); 
          lcd.print(" Mode 1 ");   
          pocet ++;
          }

     else if (pocet ==1)
          {
          lcd.clear();
          lcd.setCursor(0,0); 
          lcd.print(" Mode 2 ");
          pocet ++;
          }

     else if (pocet ==2)
          {
          lcd.clear();
          lcd.setCursor(0,0); 
          lcd.print(" Mode 3 ");
          pocet = 0;
          }
     test = 1;
     }

if ( digitalRead(2) == HIGH && test == 1)
     {
     test = 0;
     }
}
