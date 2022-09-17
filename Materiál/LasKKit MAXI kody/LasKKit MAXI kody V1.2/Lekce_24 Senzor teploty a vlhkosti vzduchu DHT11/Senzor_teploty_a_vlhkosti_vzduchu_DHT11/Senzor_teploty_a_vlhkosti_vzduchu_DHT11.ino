// Senzor teploty a vlhkosti vzduchu DHT11
// Na displeji I2C LCD1602 uvidíš vlhkost a teplotu vzduchu.
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/


#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,16,2);  

dht DHT; //vytvořit objekt třídy dht

const int DHT11_PIN= 4;

void setup() {
	Serial.begin(9600); 	// spustit sériový monitor na 9600 bps
	lcd.init();  			// inicializace lcd 
	lcd.backlight();  		// zapnout podsvícení
}

void loop() {
	lcd.setCursor(0, 0);
	// přečíst hodnoty vrácené z čidla 
	int chk = DHT.read11(DHT11_PIN);
	switch (chk) {
		case DHTLIB_OK:  
			lcd.print("DHT11: OK!"); 
			break;
		case DHTLIB_ERROR_CHECKSUM: 
			lcd.print("Checksum chyba"); 
			break;
		case DHTLIB_ERROR_TIMEOUT: 
			lcd.print("Time out chyba"); 
			break;
		default: 
			lcd.print("Neznama chyba"); 
			break;
	}
	delay(500);
	// zobrazit data
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Teplota:");
	lcd.print(DHT.temperature,1); 	// zobrazit teplotu na displeji
	lcd.print(char(223));			// zobrazit znak "°"
	lcd.print("C");	
	lcd.setCursor(0, 1);
	lcd.print("Vlhkost:");
	lcd.print(DHT.humidity,1); 		//zobrazit vlhkost na displeji
	lcd.print(" %"); 
	delay(300);						// počkat 300 ms
}
