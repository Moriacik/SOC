// Řízení LEDky PWMkou 
// LEDka se bude pomalu rozsvěcovat a pomalu zhasínat, opakovaně 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
const int ledPin = 9;			  // číslo pinu LEDky

void setup () {
	pinMode(ledPin, OUTPUT);	// nastavení pinu LEDky jako výstupu
}
 
void loop() {
	for (int a=0; a<=255;a++) {	// smyčka od 0 do 255 
		analogWrite(ledPin, a);	  // nastavit jas pinu LEDky:
		delay(8);				          // počkat 8 ms             
	}
	for (int a=255; a>=0;a--) {	// smyčka od 255 do 0
		analogWrite(ledPin, a);	  // nastavit jas pinu LEDky:
		delay(8);				          // počkat 8 ms   
	}
	delay(800);				          // počkat 800 ms  
}

