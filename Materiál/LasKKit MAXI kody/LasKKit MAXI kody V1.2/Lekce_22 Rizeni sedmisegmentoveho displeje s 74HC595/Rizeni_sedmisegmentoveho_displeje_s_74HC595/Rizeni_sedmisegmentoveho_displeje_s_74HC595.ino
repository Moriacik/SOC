// Řízení sedmisegmentového displeje s 74HC595
// Teď by jsi měl na sedmisegmentovém displeji vidět zobrazené symboly od 0 do F. 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int latchPin = 12;	//	číslo pinu ST_CP 74HC595
const int clockPin = 8;		//	číslo pinu SH_CP 74HC595 
const int dataPin = 11;		//	číslo pinu DS 74HC595 
//kódy pro 0,1,2,3,4,5,6,7,8,9,A,b,C,d,E,F
int datArray[16] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};

void setup () {
	// nastavení pinu jako výstupu
	pinMode(latchPin,OUTPUT);
	pinMode(clockPin,OUTPUT);
	pinMode(dataPin,OUTPUT);
}

void loop() {
	//cyklus od 0 do 16
	for(int num = 0; num < 16; num++) {
		// latcPin do stavu LOW pro start zapisování dat do 74HC595
		digitalWrite(latchPin,LOW);
		shiftOut(dataPin, clockPin, MSBFIRST, datArray[num]);
		// latcPin do stavu HIGH pro konec zapisování dat a uložení do 74HC595
		digitalWrite(latchPin,HIGH);
		delay(1000); 					// počkat 1s
	}
}
