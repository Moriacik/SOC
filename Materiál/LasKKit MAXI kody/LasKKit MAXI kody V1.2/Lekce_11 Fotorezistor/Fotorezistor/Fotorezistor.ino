// Fotorezistor
// Pokud bude na fotorezistor svítit světlo určité intenzity, uvidíš určitý počet svítících LEDek. 
// Pokud tuto intenzitu zvětšíš, uvidíš víc svítících LEDek.  
// Pokud to dáš do tmy, žádná LEDka svítit nebude.
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int NbrLEDs = 8;							      // počet LEDek
const int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12};	// vytvoříme pole pro LED piny
const int photocellPin = A0;				      // číslo pinu fotorezistoru                        
int sensorValue = 0;								      // přečteny hodnoty z čidla 
int ledLevel = 0; 									      // hodnota čidla převedená do LED řádku

void setup() {
	for (int led = 0; led < NbrLEDs; led++) {
		pinMode(ledPins[led], OUTPUT);				// nastavím všechny LED piny jako výstup
	}
}

void loop() {
	sensorValue = analogRead(photocellPin);     // přečíst hodnotu pinu A0 
	ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs); // převedeme hodnotu čidla do LED řádku
	for (int led = 0; led < NbrLEDs; led++) {	  // půjdeme po každé LEDce
		if (led < ledLevel ) {					          // Jestli je číslo LED méně, než ledLevel 
			digitalWrite(ledPins[led], HIGH);	      // zapneme tuto LEDku
		} else {
			digitalWrite(ledPins[led],LOW);		      // jinak vypneme tuto LEDku
		}
	}
}
