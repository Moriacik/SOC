// Joystick PS2
// Pohybuj s joystickem, stiskni joystick a souřadnice X, Y a Z sériového monitoru se budou měnit.  
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int xPin = A0;	// číslo pinu osy X  
const int yPin = A1;	// číslo pinu osy Y  
const int swPin = 8;	// číslo pinu tlačítka

void setup() {
	pinMode(swPin,INPUT);		// nastavení pinu tlačítka jako vstupu
	digitalWrite(swPin, HIGH);	// "HIGH" zapne pullup odpor zabudovaný do Atmelu 
	Serial.begin(9600);			// spustit sériový monitor na 9600 bps
}

void loop() {
	Serial.print("X: ");
	// přečíst hodnotu pinu xPin a tisknout do sériového monitoru, jak decimal
	Serial.print(analogRead(xPin),DEC);
	Serial.print("|Y: ");
	// přečíst hodnotu pinu yPin a tisknout do sériového monitoru, jak decimal
	Serial.print(analogRead(yPin),DEC);
	Serial.print("|Z: ");
	// přečíst stav pinu tlačítka a tisknout do sériového monitoru
	Serial.println(digitalRead(swPin));
	delay(500); 						// počkat 100 ms
}

