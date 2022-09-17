// Sériový monitor
// Otevři sériový monitor. Pokud do monitoru napíšeš "cervena" a stiskneš Enter, 
// rozsvítí se červené LED světlo. Zkus další barvy! 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int modraPin= 2;		// číslo pinu modré LEDky
const int zlutaPin= 3;		// číslo pinu žluté LEDky
const int cervenaPin= 4;	// číslo pinu červené LEDky
String comdata = "";
int lastLength = 0;

void setup() {
	pinMode(modraPin,OUTPUT);		  // nastavení pinu modré LEDky jako výstupu
	pinMode(zlutaPin, OUTPUT);		// nastavení pinu žluté LEDky jako výstupu
	pinMode(cervenaPin, OUTPUT);	// nastavení pinu červené LEDky jako výstupu
	Serial.begin(9600);				    // spustit sériový monitor na 9600 bps
	Serial.print("Vlož prosím jakoukoli LED barvu:");  // tisknout zprávu do sériového monitoru
}

void loop() {
	// jestli jsi neco napsal do monitoru
	if(Serial.available()>0) {  
		comdata = "";
		while (Serial.available() > 0) {        
			comdata += char(Serial.read());	// sbírame "char" do "stringu"
			delay(2);
		}
		Serial.println(comdata);
	}
	if(comdata == "cervena") {
		digitalWrite(cervenaPin, HIGH);		// zapnout červenu LEDku
		digitalWrite(modraPin, LOW);		  // vypnout modrou LEDku
		digitalWrite(zlutaPin, LOW);		  // vypnout žlutou LEDku
	} else if(comdata == "zluta") {            
		digitalWrite(cervenaPin, LOW);		// vypnout červenu LEDku
		digitalWrite(modraPin, LOW);		  // vypnout modrou LEDku
		digitalWrite(zlutaPin, HIGH);		  // zapnout žlutou LEDku
	} else if(comdata == "modra") {            
		digitalWrite(cervenaPin, LOW);		// vypnout červenu LEDku
		digitalWrite(modraPin, HIGH);		  // zapnout modrou LEDku
		digitalWrite(zlutaPin, LOW);		  // vypnout žlutou LEDku
	} else {                                   
		digitalWrite(cervenaPin, LOW);		// vypnout červenu LEDku
		digitalWrite(modraPin, LOW);		  // vypnout modrou LEDku
		digitalWrite(zlutaPin, LOW);		  // vypnout žlutou LEDku
	}    
}
