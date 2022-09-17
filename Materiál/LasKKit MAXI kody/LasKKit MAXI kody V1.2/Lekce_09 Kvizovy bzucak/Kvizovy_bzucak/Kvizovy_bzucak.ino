// Kvízový bzučák
// Nejprve zmáčkni tlačítko 4 pro nastartování. 
// Pokud nejprve stiskneš tlačítko 1, uvidíš, jak se odpovídající LEDka rozvítí a bzučák zabzučí.  
// Poté zmáčkni znovu tlačítko 4 pro restart (toto udělej dřív, než zmáčkneš nějaké jiné tlačítko). 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

#define button1 2		// číslo pinu 1 tlačítka
#define button2 3		// číslo pinu 2 tlačítka
#define button3 4		// číslo pinu 3 tlačítka
#define button4 9		// číslo pinu 4 tlačítka
#define buzzerPin 5	// číslo pinu bzučáku
#define LED1 6			// číslo pinu 1 LEDky
#define LED2 7			// číslo pinu 2 LEDky
#define LED3 8			// číslo pinu 3 LEDky
#define LED4 10			// číslo pinu 4 LEDky
#define uint8 unsigned char
uint8 flag = 0;			// indikace stavu tlačítka 4
uint8 b1State,b2State,b3State,b4State = 0;

void setup() {
	// nastavení pinů LEDek a bzučáku jako výstupu
	pinMode(buzzerPin, OUTPUT);     
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);     
	pinMode(LED3, OUTPUT); 
	pinMode(LED4, OUTPUT);
	// nastavení pinů tlačítek jako vstupu s pullup odporem
	pinMode(button1, INPUT_PULLUP);
	pinMode(button2, INPUT_PULLUP);
	pinMode(button3, INPUT_PULLUP);    
	pinMode(button4, INPUT_PULLUP);
	// vypnout všechny LEDky
	digitalWrite(LED1, LOW);
	digitalWrite(LED2, LOW);  
	digitalWrite(LED3, LOW); 
	digitalWrite(LED4, LOW);
}

void loop() {
	// vypnout všechny LEDky
	digitalWrite(LED1, LOW);
	digitalWrite(LED2, LOW);  
	digitalWrite(LED3, LOW);  
	digitalWrite(LED4, LOW);
	// přečíst stav pinu tlačítka 4
	b4State = digitalRead(button4);
	// pokud je tlačítko 4 stisknuté
	if(b4State == 0) {
		flag = 1;  // nastavím flag na 1
		digitalWrite(LED4, HIGH);		// zapnout 4 LEDku
		delay(200);  
	}
	if(1 == flag) {
		// přečíst stav pinů tlačítek 1 až 3
		b1State = digitalRead(button1);  
		b2State = digitalRead(button2);
		b3State = digitalRead(button3);
		// pokud bylo tlačítko 1 stisknuto jako první
		if(b1State == 0) {
			flag = 0;
			digitalWrite(LED4, LOW);
			Alarm();					        // zvuk bzučáku
			digitalWrite(LED1,HIGH);	// zapnout jen 1 LEDku
			digitalWrite(LED2,LOW); 
			digitalWrite(LED3,LOW);
			// čekání na stisknutí tlačítka 4
			while(digitalRead(button4));
		}
		// pokud bylo tlačítko 2 stisknuto jako první
		if(b2State == 0) {
			flag = 0;
			digitalWrite(LED4, LOW);
			Alarm();
			digitalWrite(LED1,LOW);
			digitalWrite(LED2,HIGH); 
			digitalWrite(LED3,LOW); 
			while(digitalRead(button4));
		}
		// pokud bylo tlačítko 3 stisknuto jako první
		if(b3State == 0) {
			flag = 0;
			digitalWrite(LED4, LOW);
			Alarm();
			digitalWrite(LED1,LOW);
			digitalWrite(LED2,LOW); 
			digitalWrite(LED3,HIGH); 
			while(digitalRead(button4));
		}
	}
}

// zvuk bzučáku
void Alarm() {
	for(int i=0;i<300;i++){
		digitalWrite(buzzerPin,HIGH);		// zapnout bzučák
		delay(1);							          // pauza nastaví frekvenci
		digitalWrite(buzzerPin,LOW);		// vypnout bzučák
		delay(1);							          // pauza nastaví frekvenci
	}
}
