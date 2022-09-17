// 8x8 LED matice
// Každý znak "LASK♥RDUINO" postupně blikne na displeji, jeden za druhým. 
// Generuj svůj symbol zde http://embed.plnkr.co/3VUsekP3jC5xwSIQDVHx/preview
// Písma pro 8x8 maticový displej zde https://github.com/dhepper/font8x8
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

#define ROW_1 10    // pin matice 9
#define ROW_2 A1    // pin 14
#define ROW_3 2     // pin 8
#define ROW_4 13    // pin 12
#define ROW_5 9     // pin 1
#define ROW_6 3     // pin 7
#define ROW_7 8     // pin 2
#define ROW_8 5     // pin 5

#define COL_1 A0    // pin 13
#define COL_2 7     // pin 3
#define COL_3 6     // pin 4
#define COL_4 11    // pin 10
#define COL_5 4     // pin 6
#define COL_6 12    // pin 11
#define COL_7 A2    // pin 15
#define COL_8 A3    // pin 16

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

// kódy káždého znaku, zobrazeného na displeji
// jako Hexadecimal
byte l[] = { 0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00};
byte a[] = { 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00};
byte s[] = { 0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00};
byte k[] = { 0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00};
byte r[] = { 0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00};
byte d[] = { 0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00};
byte u[] = { 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00};
byte i[] = { 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00};
byte n[] = { 0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00};
byte o[] = { 0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00};
// jako binární
byte heart[] = {
B00000000,
B01100110,
B11111111,
B11111111,
B01111110,
B00111100,
B00011000,
B00000000};

float timeCount = 0;

void setup() {
  // nastavení pinů displeje jako výstupu  
  for (byte i = 2; i <= 13; i++)
    pinMode(i, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() {
	// Pauzu můžeš odstranit. 
    // tím pádem bude displej jasnější.
	delay(2);
	timeCount += 1;
	if(timeCount <  100) {
		drawScreen(l);
	} else if (timeCount <   210) {
		// nic neděláme -> pauza mezi znaky
	} else if (timeCount <   300) {
		drawScreen(a);
	} else if (timeCount <   410) {
		// nic neděláme -> pauza mezi znaky     
	} else if (timeCount <   500) {
		drawScreen(s);       
	} else if (timeCount <   610) {
		// nic neděláme -> pauza mezi znaky     
	} else if (timeCount <   700) {
		drawScreen(k);       
	} else if (timeCount <   810) {
		// nic neděláme -> pauza mezi znaky
	} else if (timeCount <   900) {
		drawScreen(heart);
	} else if (timeCount <  1010) {
		// nic neděláme -> pauza mezi znaky
	} else if (timeCount <  1100) {
		drawScreen(d);
	} else if (timeCount <  1210) {
		// nic neděláme -> pauza mezi znaky
	} else if (timeCount <  1300) {
		drawScreen(u);
	} else if (timeCount <  1410) {
		// nic neděláme -> pauza mezi znaky
	} else if (timeCount <  1500) {
		drawScreen(i);
	} else if (timeCount <  1610) {
		// nic neděláme -> pauza mezi znaky
	} else if (timeCount <  1700) {
	drawScreen(n);
	} else if (timeCount <  1810) {
		// nic neděláme -> pauza mezi znaky
	} else if (timeCount <  1900) {
		drawScreen(o);
	} else if (timeCount <  2010) {
		// nic neděláme -> pauza mezi znaky
	} else {
		// a zase od začátku...
		timeCount = 0;
	}
}
 void  drawScreen(byte buffer2[]){
     
    
   // zapínáme každý řádek v sérii
    for (byte i = 0; i < 8; i++) {
        setColumns(buffer2[i]); // nastav sloupce pro tento konkrétní řádek
        
        digitalWrite(rows[i], LOW);
        delay(2); // nastav na 50 až 100, chceš-li vidět multiplexní efekt!!!
        digitalWrite(rows[i], HIGH);
        
    }
}

void setColumns(byte b) {
    digitalWrite(COL_1, (b >> 0) & 0x01); // získat 1 bit: 10000000
    digitalWrite(COL_2, (b >> 1) & 0x01); // získat 2 bit: 01000000
    digitalWrite(COL_3, (b >> 2) & 0x01); // získat 3 bit: 00100000
    digitalWrite(COL_4, (b >> 3) & 0x01); // získat 4 bit: 00010000
    digitalWrite(COL_5, (b >> 4) & 0x01); // získat 5 bit: 00001000
    digitalWrite(COL_6, (b >> 5) & 0x01); // získat 6 bit: 00000100
    digitalWrite(COL_7, (b >> 6) & 0x01); // získat 7 bit: 00000010
    digitalWrite(COL_8, (b >> 7) & 0x01); // získat 8 bit: 00000001
}
