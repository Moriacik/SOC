// Sedmisegmentový displej
// Teď by jsi měl vidět cyklus sedmisegmentového displeje, od 1 po 0.
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

#define ON HIGH			// Jestli máme CC (společná katoda) displej
//#define ON LOW			// Jestli máme CA (společná anoda) displej

const int a = 7;		// číslo pinu segmentu "a"
const int b = 6;		// číslo pinu segmentu "b"
const int c = 5;		// číslo pinu segmentu "c"
const int d = 11;		// číslo pinu segmentu "d"
const int e = 10;		// číslo pinu segmentu "e"
const int f = 8;		// číslo pinu segmentu "f"
const int g = 9;		// číslo pinu segmentu "g"
const int dp =4;		// číslo pinu segmentu "dp"

void setup() {
	// nastavení pinu každého segmentu jako výstupu
	for(int thisPin = 4; thisPin <= 11; thisPin++) {
		pinMode(thisPin,OUTPUT);
	}
}

void loop() {
	digital_1();	// zobrazit 1 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_2();	// zobrazit 2 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_3();	// zobrazit 3 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_4();	// zobrazit 4 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_5();	// zobrazit 5 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_6();	// zobrazit 6 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_7();	// zobrazit 7 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_8();	// zobrazit 8 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_9();	// zobrazit 9 na displeji
	delay(1000);	// počkat 1000 ms (1s)
	digital_0();	// zobrazit 0 na displeji
	delay(1000);	// počkat 1000 ms (1s)
}

void digital_1() { 		    // zobrazit 1 na displeji
	// vypnout všechny segmenty
	clear();
	digitalWrite(c, ON);	// zapnout segment "c"
	digitalWrite(b, ON);	// zapnout segment "b"
}
void digital_2() { 		    // zobrazit 2 na displeji
	// vypnout všechny segmenty
	clear();
	digitalWrite(a, ON);	// zapnout segment "a"
	digitalWrite(b, ON);	// zapnout segment "b"
	digitalWrite(g, ON);	// zapnout segment "g"
	digitalWrite(e, ON);	// zapnout segment "e"
	digitalWrite(d, ON);	// zapnout segment "d"
}
void digital_3() { 		    // zobrazit 3 na displeji
	clear();
	digitalWrite(a, ON);
	digitalWrite(b, ON);
	digitalWrite(g, ON);
	digitalWrite(c, ON);
	digitalWrite(d, ON);
}
void digital_4() {		    // zobrazit 4 na displeji
	clear();
	digitalWrite(f, ON);
	digitalWrite(g, ON);
	digitalWrite(b, ON);
	digitalWrite(c, ON);
}
void digital_5() {		    // zobrazit 5 na displeji
	clear();
	digitalWrite(f, ON);
	digitalWrite(g, ON);
	digitalWrite(c, ON);
	digitalWrite(d, ON);
	digitalWrite(a, ON);
}
void digital_6() {		    // zobrazit 6 na displeji
	clear();
	digitalWrite(a, ON);
	digitalWrite(f, ON);
	digitalWrite(e, ON);
	digitalWrite(d, ON);
	digitalWrite(c, ON);
	digitalWrite(g, ON);
}
void digital_7() {		    // zobrazit 7 na displeji
	clear();
	digitalWrite(a, ON);
	digitalWrite(b, ON);
	digitalWrite(c, ON);
}
void digital_8() {		    // zobrazit 8 na displeji
	clear();
	digitalWrite(a, ON);
	digitalWrite(f, ON);
	digitalWrite(e, ON);
	digitalWrite(d, ON);
	digitalWrite(c, ON);
	digitalWrite(g, ON);
	digitalWrite(b, ON);
}
void digital_9() {		    // zobrazit 9 na displeji
	clear();
	digitalWrite(a, ON);
	digitalWrite(f, ON);
	digitalWrite(g, ON);
	digitalWrite(b, ON);
	digitalWrite(c, ON);
}
void digital_0() {		    // zobrazit 0 na displeji
	clear();
	digitalWrite(a, ON);
	digitalWrite(f, ON);
	digitalWrite(e, ON);
	digitalWrite(d, ON);
	digitalWrite(c, ON);
	digitalWrite(b, ON);
}
void clear () {			      // vypnout všechny segmenty
	for(int thisPin = 4; thisPin <= 11; thisPin++) {
		digitalWrite(thisPin, !ON);
	}
}
