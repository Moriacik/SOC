// Stopky - 4-místný sedmisegmentový displej
// Na displeji uvidíš číslo, které se zvyšuje o jednu každou vteřinu.
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/
#include <TimerOne.h>

//#define CC			// Jestli máme CC (společná katoda) displej
#define CA			// Jestli máme CA (společná anoda) displej


#ifdef CA
	#define ON_NUMBER LOW	//vymení v kódu před kompilací ON_NUMBER za LOW
	#define OFF_NUMBER HIGH
	#define ON_DIGIT HIGH
	#define OFF_DIGIT LOW
#else
	#define ON_NUMBER HIGH
	#define OFF_NUMBER LOW
	#define ON_DIGIT LOW
	#define OFF_DIGIT HIGH
#endif

// Připojení displeje k pinům Arduino
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int p = 9;
const int d1 = 10;
const int d2 = 11;
const int d3 = 12;
const int d4 = 13;
// n představuje hodnotu zobrazenou na displeji. 
// například při zobrazení n = 0 se zobrazí 0000. Maximální hodnota je 9999. 
long n = 0;
int x = 100;
// del je pauza mezi spínanými číslovkami, 5ms je dobrá hodnota pro hodiny.
int del = 5;
// nastavit count = 0. Zde je count hodnota počítání, která se zvyšuje o 1 každých 0,1 sekundy,
// znamená, že 1 sekunda se počítá, když je hodnota 10
int count = 0;

void setup() {
	// nastavení pinů displeje jako výstupu  
	pinMode(d1, OUTPUT);
	pinMode(d2, OUTPUT);
	pinMode(d3, OUTPUT);
	pinMode(d4, OUTPUT);
	pinMode(a, OUTPUT);
	pinMode(b, OUTPUT);
	pinMode(c, OUTPUT);
	pinMode(d, OUTPUT);
	pinMode(e, OUTPUT);
	pinMode(f, OUTPUT);
	pinMode(g, OUTPUT);
	pinMode(p, OUTPUT);
 
	// nastavime časovač o délce 100000 mikrosekund
	// (nebo 0,1s - nebo 10Hz => led 5x bliká,
	// 5 cyklů zapnutí a vypnutí, za sekundu)
	Timer1.initialize(100000);
	Timer1.attachInterrupt( add ); // připojme servisní rutinu
}

void loop() {
	clearLEDs();			    // vypnout všechny segmenty
	pickDigit(0);			    // rozsvítit displej d1
	pickNumber(n%10);	// získat a ukázat hodnotu tisíce
	delay(del);				    // pauza 5ms
	
	clearLEDs();
	pickDigit(1);			    // rozsvítit displej d2
	pickNumber(n%100/10);// získat a ukázat hodnotu sto
	delay(del);
	
	clearLEDs();
	pickDigit(2);			    // rozsvítit displej d3
	pickNumber((n%1000)/100);	// získat a ukázat hodnotu deset
	delay(del);
	
	clearLEDs();
	pickDigit(3);			  // rozsvítit displej d4
	pickNumber((n/1000));		// získat a ukázat hodnotu do 9
	delay(del);
}

void pickDigit(int x) {       // vybrat displej
	// Tento 7 segmentový displej je CA (se společnou anodou) nebo CC (se společnou katodou)
	// Takže také pomocí digitalWrite nastavíme všechny anody na LOW (jestli displej je CA ) 
	// nebo na HIGH (jestli displej je CC) a celý displej vypneme
	digitalWrite(d1, OFF_DIGIT);
	digitalWrite(d2, OFF_DIGIT);
	digitalWrite(d3, OFF_DIGIT);
	digitalWrite(d4, OFF_DIGIT);
	
	switch(x){
		case 0: 
			digitalWrite(d1, ON_DIGIT); // zapnout displej d1
			break;                     
		case 1:                        
			digitalWrite(d2, ON_DIGIT); // zapnout displej d2 
			break;                     
		case 2:                        
			digitalWrite(d3, ON_DIGIT); // zapnout displej d3 
			break;                     
		default:                       
			digitalWrite(d4, ON_DIGIT); // zapnout displej d4 
			break;
	}
}
// Funkce je pro ovládání 7 segmentového displeje pro zobrazení čísel
// Zde "x" je číslo, které chceš zobrazit. Je to celé číslo od 0 do 9
void pickNumber(int x) {
	switch(x) {
		default: 
			zero(); 
			break;
		case 1: 
			one(); 
			break;
		case 2: 
			two(); 
			break;
		case 3: 
			three(); 
			break;
		case 4: 
			four(); 
			break;
		case 5: 
			five(); 
			break;
		case 6: 
			six(); 
			break;
		case 7: 
			seven(); 
			break;
		case 8: 
			eight(); 
			break;
		case 9: 
			nine(); 
			break;
	}
} 
// vypnout všechny segmenty
void clearLEDs() {
	digitalWrite(a, OFF_NUMBER);
	digitalWrite(b, OFF_NUMBER);
	digitalWrite(c, OFF_NUMBER);
	digitalWrite(d, OFF_NUMBER);
	digitalWrite(e, OFF_NUMBER);
	digitalWrite(f, OFF_NUMBER);
	digitalWrite(g, OFF_NUMBER);
	digitalWrite(p, OFF_NUMBER);
}
// zobrazit 0 na displeji
void zero() { 
	digitalWrite(a, ON_NUMBER);
	digitalWrite(b, ON_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, ON_NUMBER);
	digitalWrite(e, ON_NUMBER);
	digitalWrite(f, ON_NUMBER);
	digitalWrite(g, OFF_NUMBER);
}
// zobrazit 1 na displeji
void one() {
	digitalWrite(a, OFF_NUMBER);
	digitalWrite(b, ON_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, OFF_NUMBER);
	digitalWrite(e, OFF_NUMBER);
	digitalWrite(f, OFF_NUMBER);
	digitalWrite(g, OFF_NUMBER);
}
// zobrazit 2 na displeji
void two() {
	digitalWrite(a, ON_NUMBER);
	digitalWrite(b, ON_NUMBER);
	digitalWrite(c, OFF_NUMBER);
	digitalWrite(d, ON_NUMBER);
	digitalWrite(e, ON_NUMBER);
	digitalWrite(f, OFF_NUMBER);
	digitalWrite(g, ON_NUMBER);
}
// zobrazit 3 na displeji
void three() {
	digitalWrite(a, ON_NUMBER);
	digitalWrite(b, ON_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, ON_NUMBER);
	digitalWrite(e, OFF_NUMBER);
	digitalWrite(f, OFF_NUMBER);
	digitalWrite(g, ON_NUMBER);
}
// zobrazit 4 na displeji
void four() {
	digitalWrite(a, OFF_NUMBER);
	digitalWrite(b, ON_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, OFF_NUMBER);
	digitalWrite(e, OFF_NUMBER);
	digitalWrite(f, ON_NUMBER);
	digitalWrite(g, ON_NUMBER);
}
// zobrazit 5 na displeji
void five() {
	digitalWrite(a, ON_NUMBER);
	digitalWrite(b, OFF_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, ON_NUMBER);
	digitalWrite(e, OFF_NUMBER);
	digitalWrite(f, ON_NUMBER);
	digitalWrite(g, ON_NUMBER);
}
// zobrazit 6 na displeji
void six() {
	digitalWrite(a, ON_NUMBER);
	digitalWrite(b, OFF_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, ON_NUMBER);
	digitalWrite(e, ON_NUMBER);
	digitalWrite(f, ON_NUMBER);
	digitalWrite(g, ON_NUMBER);
}
// zobrazit 7 na displeji
void seven() {
	digitalWrite(a, ON_NUMBER);
	digitalWrite(b, ON_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, OFF_NUMBER);
	digitalWrite(e, OFF_NUMBER);
	digitalWrite(f, OFF_NUMBER);
	digitalWrite(g, OFF_NUMBER);
}
// zobrazit 8 na displeji
void eight() {
	digitalWrite(a, ON_NUMBER);
	digitalWrite(b, ON_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, ON_NUMBER);
	digitalWrite(e, ON_NUMBER);
	digitalWrite(f, ON_NUMBER);
	digitalWrite(g, ON_NUMBER);
}
// zobrazit 9 na displeji
void nine() {
	digitalWrite(a, ON_NUMBER);
	digitalWrite(b, ON_NUMBER);
	digitalWrite(c, ON_NUMBER);
	digitalWrite(d, ON_NUMBER);
	digitalWrite(e, OFF_NUMBER);
	digitalWrite(f, ON_NUMBER);
	digitalWrite(g, ON_NUMBER);
}

void add() {
	// přepnout LED
	count ++;
	if(count == 10) {
		count = 0;
		n++;
		if(n == 10000) {
			n = 0;
		}
	}
}
