// Senzor plamene
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

int flame = A0;				    // číslo pinu senzoru
int LED = 13;				      // číslo pinu LEDky
int val = 0;				      // inicializace proměny

void setup() {
	pinMode(LED,OUTPUT);	  // nastavení pinu LEDky jako výstupu
	pinMode(flame,INPUT);	  // nastavení pinu senzoru jako vstupu
	Serial.begin(9600);		  // spoustit sériový monitor na 9600 bps
} 

void loop() { 
	val = analogRead(flame);  // přečíst hodnotu pinu senzoru 
	Serial.println(val);		  // tisknout hodnotu pinu senzoru do sériového monitoru
	if(val > 30) {				    // jestli je hodnota > 30
		digitalWrite(LED,HIGH); // zapnout LEDku
	} else {  
		digitalWrite(LED,LOW); 	// jinak vypnout LEDku
	}
	delay(500); 
}
