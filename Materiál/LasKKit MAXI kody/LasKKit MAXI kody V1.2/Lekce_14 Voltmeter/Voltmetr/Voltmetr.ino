// Voltmetr
// Nastav potenciometr a uvidíš, že napětí zobrazené na displeji I2C LCD1602 se změnilo odpovídajícím způsobem.
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

// připoj knihovny
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);	// nastavit adresu displeje na 0x27 pro 1602 displej
float val = 0;
int volt = A0;						        // číslo pinu pro meření napětí

void setup() {
	Serial.begin(9600);		          // spustit sériový monitor na 9600 bps
	lcd.init();  			              // inicializace lcd
	lcd.backlight();  		          // zapnout podsvícení 
	lcd.setCursor(5,0);		          // nastavení kurzoru na sloupec 5, řádek 0
	lcd.print("Napeti:");	          // zobrazit "Napeti:" na displeji
}

void loop() {
	val = analogRead(volt);	        // přečíst hodnotu pinu A0
	val = val/1024*5.0;		          // konvertování hodnoty pinu do napětí
	Serial.print(val);		          // tisknout napětí do sériového monitoru
	Serial.println("V"); 	          // tisknout "V" do sériového monitoru a přejít na nový řádek (ln)
	lcd.setCursor(6,1);		          // nastavení kurzoru na sloupec 6, řádek 1
	lcd.print(val);			            // zobrazit napětí na LCD
	lcd.print("V");			            // zobrazit "V" na LCD
	delay(300); 			              // počkat 300 ms
}
