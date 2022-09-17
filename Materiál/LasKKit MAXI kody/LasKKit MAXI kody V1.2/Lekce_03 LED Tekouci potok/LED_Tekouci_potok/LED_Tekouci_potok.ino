// LED Tekoucí potok
// Tato plynulá světla jsou tvořena osmi LED v řadě, která se postupně rozsvítí a tmavnou jeden po druhém, stejně jako tekoucí voda.
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int lowestPin = 2;			// číslo pinu první LEDky 
const int highestPin = 9;			// číslo pinu poslední LEDky

void setup() {
	// nastavení pinu od 2 do 9 LEDky jako výstupu  
	for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++){
		pinMode(thisPin,OUTPUT);	// nastavení pinu jako výstupu
	}
}

void loop() {
	// iterace pinu za pinem
	// zapnout LEDky od první do poslední 
	for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++) {
		digitalWrite(thisPin,HIGH);	// zapnout tuto LEDku 
		delay(100);					        // počkat 100 ms
	}
	// vypnout LEDky od poslední do první 
	for(int thisPin = highestPin;thisPin>=lowestPin;thisPin--) {
		digitalWrite(thisPin,LOW);	// vypnout tuto LEDku
		delay(100);					        // počkat 100 ms
	}
	for(int thisPin = highestPin;thisPin>=lowestPin;thisPin--) {
		digitalWrite(thisPin,HIGH);	// zapnout tuto LEDku
		delay(100);					        // počkat 100 ms
	}
	for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++) {
		digitalWrite(thisPin,LOW);	// vypnout tuto LEDku
		delay(100);					        // počkat 100 ms
	}
}
