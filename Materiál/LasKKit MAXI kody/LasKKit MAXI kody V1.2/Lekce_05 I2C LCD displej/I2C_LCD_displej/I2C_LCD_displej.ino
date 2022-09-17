// I2C LCD displej
// Teď by jsi měl na svém displeji vidět běžící text:“Laskarduino” a "Zdravim bastlire!".
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

// připoj knihovny
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

char array1[]=" Laskarduino              ";	// první řádek displeje (26 znaků!)
char array2[]=" Zdravim bastlire!        ";	// druhý řádek displeje (26 znaků!)
int tim = 500;  //délka pauzy 
// inicializace knihovny displeje 
LiquidCrystal_I2C lcd(0x27,16,2);			// nastavit adresu displeje na 0x27 pro 1602 displej 

void setup() {
	lcd.init();								          // inicializace lcd
	lcd.backlight();						        // zapnout podsvícení 
}

void loop() {
	lcd.setCursor(15,0);					      // nastavení kurzoru na sloupec 15, řádek 0
	for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++) {
		lcd.scrollDisplayLeft();			    // Protáhnout obsah zprávy na displeji zprava do leva.
		lcd.print(array1[positionCounter1]);// Zobrazit zprávu na displeji.
		delay(tim);							          // počkat 500 ms
	}
	lcd.clear();							          // vyčistit displej a přesunout kurzor na začátek. 
	lcd.setCursor(15,1);					      // nastavení kurzoru na sloupec 15, řádek 1
	for (int positionCounter = 0; positionCounter < 26; positionCounter++) {
		lcd.scrollDisplayLeft();			    // protáhnout obsah zprávy na displeji zprava do leva.
		lcd.print(array2[positionCounter]);	// zobrazit zprávu na displeji.
		delay(tim);							          // počkat 500 ms
	}
	lcd.clear();							          // vyčistit displej a přesunout kurzor na začátek.
}


