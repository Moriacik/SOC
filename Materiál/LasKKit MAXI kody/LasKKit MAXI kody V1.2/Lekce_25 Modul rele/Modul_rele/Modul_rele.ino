// Modul relé
// Každou minutu zavírej a otevírej relé. 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int relayPin = 8;           // číslo pinu rele

void setup() {                         
	pinMode(relayPin, OUTPUT);      // nastavení pinu relé jako výstupu
}                                      

void loop() {                          
	digitalWrite(relayPin, HIGH);   // vypnut relé
	delay(1000);                    // počkat 1s
	digitalWrite(relayPin, LOW);    // zapnut relé 
	delay(1000);                    // počkat 1s
}
