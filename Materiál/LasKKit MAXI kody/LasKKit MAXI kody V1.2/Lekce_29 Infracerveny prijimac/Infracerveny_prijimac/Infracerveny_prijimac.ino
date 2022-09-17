// Infračervený přijímač
// Stiskni tlačítko „Play“ na dálkovém ovladači a LED, 
// připojená k vývodu 13 na Arduino, se rozsvítí. 
// Stiskni libovolnou jinou klávesu a LED zhasne.
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

#include <IRremote.h>   

const int IRPin = 2;			// číslo pinu tlačítka přijímače
const int ledPin = 13;			// číslo pinu zabudované LEDky

IRrecv irrecv(IRPin);			// vytvořeme objekt typu IRrecv
decode_results results;			// definujeme proměnnou
 
void setup() {
	pinMode(ledPin,OUTPUT);		// nastavení pinu LEDky jako výstupu
	Serial.begin(9600);			// spustit sériový monitor na 9600 bps
	irrecv.enableIRIn();		// zapnout infračervený přijímač  
}
 
void loop() {
	if (irrecv.decode(&results)) {			// jestli přijímač přijal data
		Serial.print("IR Kod: ");			// tisknout "irCode: "
		Serial.print(results.value, HEX);  	// tisknout data jako hexdecimal
		Serial.print(",  bity: ");  		// tisknout " ,  bity: "
		Serial.println(results.bits);  		// tisknout bity
		irrecv.resume();    				// přijat další data
	}  
	delay(600);  //počkat 600ms
	if(results.value == 0xFFC23D) {		// Kód tlačitka "Play"
		digitalWrite(ledPin,HIGH); 		// zapnout LEDku
	} else {
		digitalWrite(ledPin,LOW); 		// vypnout LEDku
	}
}