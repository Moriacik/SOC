// Řízení LEDky tlačítkem 
// Zapíná a vypíná LEDku když stiskneš tlačítko
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int keyPin = 12;    // číslo pinu tlačítka
const int ledPin = 13;    // číslo pinu LEDky

void setup() {
	pinMode(keyPin,INPUT);	// nastavení pinu tlačítka jako vstupu
	pinMode(ledPin,OUTPUT);	// nastavení pinu LEDky jako výstupu
}

void loop() {
	// přečíst stav hodnoty pinu tlačítka
	// a zkontrolovat, jestli je tlačítko stisknuté
	// pokud ano, stav pinu bude HIGH
	if(digitalRead(keyPin) == HIGH ) {
		digitalWrite(ledPin,HIGH);	// zapnout LEDku
	} else {
		digitalWrite(ledPin,LOW);   // vypnout LEDku
	}
}
