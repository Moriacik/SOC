// Vstupní systém pomocí hesla 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);


#define relayPin 13 	// číslo pinu relé
	
	
const byte ROWS = 4;	// 4 řádky
const byte COLS = 4;	// 4 sloupce
// definujeme  znaky tlačitek klávesnice
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','A','B','C'},
  {'D','*','0','#'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; 	// číslo pinu řádků
byte colPins[COLS] = { 7, 6, 5, 4}; 	// číslo pinu sloupců


int pos = 0;
char secretCode[6] = {'1', '2', '3', '4', '5', '6'};
char inputCode[6] = {'0', '0', '0', '0', '0', '0'};

//vytvoříme objekt typu NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
	lcd.init();
	lcd.backlight();
	pinMode(relayPin, OUTPUT);
	lcd.setCursor(0,0);
	lcd.print("     Vitej!     ");
	delay(2000);
}

void loop() {
	readKey();
}

void readKey() {
	int correct = 0;
	int i;
	char customKey = customKeypad.getKey();
	if (customKey) {
		switch(customKey) {
			case '*':
				pos = 0;
				lcd.clear();
				lcd.setCursor(0,0);
				lcd.print("Zadej sve heslo:");
				break;
			case '#':    	
				for(i = 0; i < 6; i++) {
					if(inputCode[i] == secretCode[i]) {
						correct ++;
					}
				}
				if(correct == 6) {
					lcd.clear();
					lcd.setCursor(0, 0);
					lcd.print("    Spravne!    ");
					lcd.setCursor(0, 1);
					lcd.print("     Vstup      ");
					digitalWrite(relayPin, HIGH);
				} else {
					lcd.clear();
					lcd.setCursor(0, 0);
					lcd.print("     Chyba!     ");
					lcd.setCursor(0, 1);
					lcd.print("  Zkus to znova ");
					digitalWrite(relayPin, LOW);
					delay(2000);
					lcd.clear();
					lcd.setCursor(0,0);
					lcd.print("     Vitej!     ");
				}
				break;
			default:
				inputCode[pos] = customKey;
				lcd.setCursor(pos,1);
				lcd.print(inputCode[pos]);
				pos ++;
		}
	}
}

