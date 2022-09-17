// Interaktivní LED tekoucí potok 
// Zde bys měl vidět osm LEDek, které se budou rozsvěcovat jedna po druhé. 
// Nastav potenciometr a uvidíš, že se interval rozsvěcování LEDek změnil.
// Email:support@sunfounder.com
// Web:www.sunfounder.com
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

int ledNum = 8;								// počet LEDek
byte ledPin[] = { 2, 3, 4, 5, 6, 7, 8, 9};	// vytvoříme pole pro LED piny
int ledDelay;								  // pauza mezi změnami
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = A0;							// nastavení pinu potentiometru jako vstupu 

void setup() {
	for (int x = 0; x < ledNum; x++) { 
		// nastavení pinu od 2 do 9 LEDky jako výstupu
		pinMode(ledPin[x], OUTPUT); 
	}
	changeTime = millis();
}

void loop() {
	ledDelay = analogRead(potPin);			// přečíst hodnotu pinu potenciometru 
	// tady se změní interval po nastavení potenciometru 
	if ((millis() - changeTime) > ledDelay) {
		changeLED();
		changeTime = millis();
	}
}

void changeLED() {
	for (int x=0; x < ledNum; x++) {
		// vypnout všechny LEDky
		digitalWrite(ledPin[x], LOW);
	}
	digitalWrite(ledPin[currentLED], HIGH); // zapnout tuto LEDku
	currentLED += direction;
	// změnit směr, pokud jsme dosáhli konce
	if (currentLED == ledNum-1) {
		direction = -1;
	}
	if (currentLED == 0) {
		direction = 1;
	}
}
