// Senzor hladiny vody
// Pokud ponoříš senzor do vody, uvidíš na displeji hodnotu, která bude závislá na hloubce ponoření. 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

// připoj knihovny
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);	// nastavit adresu displeje na 0x27 pro 1602 displej
const int waterSensor = 0;
int waterValue = 0;

void setup() {
	lcd.init();							        // inicializace lcd
	lcd.backlight();                // zapnout podsvícení
	lcd.setCursor(0,0);					    // nastavení kurzoru na sloupec 0, řádek 0
	lcd.print("   Objem vody   ");  // zobrazit "Objem vody" na displeji
}

void loop() {
	int waterValue = analogRead(waterSensor);	// přečíst hodnotu pinu senzoru hladiny vody
	lcd.setCursor(6,1);							// nastavení kurzoru na sloupec 6, řádek 1
	lcd.print(waterValue);					// zobrazit hodnotu na lcd
	delay(300);									    // počkat 300 ms
	lcd.setCursor(0,1);							// nastavení kurzoru na sloupec 0, řádek 1
	lcd.print("                ");	// zobrazit 16 mezer na lcd (vymazat celý řádek)
}


