// Zvukový senzor
// Hladinu intenzity zvuku můžeš vidět na Sériovém monitoru. 
// Pokud dosáhne hlasitost určité hodnoty, LEDka na Arduino se rozsvítí.  
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int ledPin = 13;		// číslo pinu LEDky (integrovaná LED)
const int soundPin = A0;	// číslo pinu zvukového senzoru

void setup() {
	pinMode(ledPin,OUTPUT);	// nastavení pinu LEDky jako výstupu
	Serial.begin(9600);		  // spustit sériový monitor na 9600 bps
}

void loop() {
	int value = analogRead(soundPin); 	// přečíst hodnotu pinu zvukového senzoru
	Serial.println(value);				      // tisknout hodnotu do sériového monitoru
	if(value > 25) {					          // jestli je hodnota > 25
		digitalWrite(ledPin,HIGH); 		    // zapnout LEDku
		delay(2000); 					            // počkat 2 ms
	} else {
		digitalWrite(ledPin,LOW); 		    // vypnout LEDku
	}
}
