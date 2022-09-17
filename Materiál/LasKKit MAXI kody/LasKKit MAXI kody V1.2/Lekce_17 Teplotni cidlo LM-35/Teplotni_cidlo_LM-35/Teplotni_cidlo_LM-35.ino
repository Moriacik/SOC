// Teplotní čidlo LM-35
// Čidlo zatím funguje nestabilně, teplota skáče. V příští verzi bude opraveno. 
// Napěťový výstup čidla LM35 je lineárně závislý na teplotě. Při 0°C je 0V. 
// Při zvětšení teploty na 1°C se napětí zvětší na 10 mV. 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

#define lmPin A0  					// číslo pinu LM35
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

float tem = 0;
long lmVal = 0;

void setup() {
	lcd.init();
	lcd.backlight();
}
void loop() {
	lmVal = analogRead(lmPin);			//	přečíst hodnotu pinu lmPin
	tem = (lmVal * 0.0048828125 * 100);	// Převedeme hodnotu do voltu (5/1024=0.0048828125) a pak mV
	                                    // mV Převedeme do °C (z datasheetu LM35 Vout = 10mV/°C × T)
	lcd.setCursor(5,0);					// nastavení kurzoru na sloupec 5, řádek 0
	lcd.print("LM35");					// zobrazit "LM35"
	lcd.setCursor(0,1);					// nastavení kurzoru na sloupec 0, řádek 1
	lcd.print("Teplota= ");			// zobrazit "Tepl= "
	lcd.setCursor(5,1);					// nastavení kurzoru na sloupec 5, řádek 1
	lcd.print(tem);             // zobrazit teplotu
	lcd.print(char(223));				// zobrazit znak "°"
	lcd.print("C");						
	delay(300);                 // počkat 300 ms
}

