#define SET0(REG,BIT) REG &= ~(1<<BIT)
#define SET1(REG,BIT) REG |= (1<<BIT)
#define TEST(REG,BIT) (REG&(1<<BIT))

#include <LiquidCrystal.h>
LiquidCrystal disp(8,9,10,11,12,13);
  
int vysledok;
byte predoslyStav = PINC;

void loop() 
{
   
  
    
      
       SET1(ADCSRA,ADSC); // začatie konverzie
       while(TEST(ADCSRA,ADIF)==0); // testovanie dokončenia
       vysledok = ADCL; // načítanie dolného registra
       vysledok = vysledok | (ADCH<<8); // pripočítanie horného
       vysledok = map(vysledok, 0, 1023, 0, 100);
       
       if( vysledok == 0 )
       {
       disp.clear();
       disp.print("VOLUME MAX");
       delay(10);
       }
       
       else if( vysledok == 100 )
       {
       disp.clear();
       disp.print("VOLUME MUTE");
       delay(10);
       }
       
       else
       {
       disp.clear();
       disp.print("VOLUME ");
       disp.print(vysledok);
       delay(10);
       }
    
    

}



void setup() 
{
   SET0(ADMUX,REFS1); // voľba Aref
   SET0(ADMUX,REFS0);
   SET0(ADMUX,ADLAR); // zarovnanie nadol
   SET1(ADMUX,MUX0); // voľba kanála ADC1
   SET0(ADMUX,MUX1);
   SET0(ADMUX,MUX2);
   SET0(ADMUX,MUX3);
   SET1(ADCSRA,ADEN); // zapnutie ADC
   SET0(ADCSRA,ADATE); // spúšťanie príkazom
   SET0(ADCSRA,ADIE); // negenerovanie prerušenia
   SET1(ADCSRA,ADPS2); // voľba preddeličky 128 
   SET1(ADCSRA,ADPS1);
   SET1(ADCSRA,ADPS0);
   disp.begin(16,2);
}


//test(PIN,5) == 0 && test(predoslyStav,5) != test(PINB,5)

  //f( vysledok == 0 )
 // {  
  // disp.clear();
  // disp.print("VOLUME MUTE");
  // delay(10);
  
