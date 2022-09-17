// Ovládání zvuku pomocí světla
// Pokud dáš fotorezistor do tmavého prostředí, bzučák bude intenzivně pípat. 
// Pokud dáš fotorezistor do světlého prostředí, bzučák bude pípat pomalu. 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int photocellPin = A0;  	// číslo pinu fotorezistoru
int sensorValue = 0;        	  // prečteny hodnoty z čidla 
const int buzzerPin = 9;  		  // číslo pinu bzučáku

void setup() {
	pinMode(buzzerPin, OUTPUT);	  // nastavení pinů bzučáku jako výstupu
}
void loop() {
	sensorValue = analogRead(photocellPin);	// přečíst hodnotu pinu A0 
	digitalWrite(buzzerPin, HIGH);	// zapnout bzučák
	delay(sensorValue);  			      // pauza nastaví frekvenci
	digitalWrite(buzzerPin, LOW); 	// vypnout bzučák
	delay(sensorValue);           	// pauza nastaví frekvenci
}

