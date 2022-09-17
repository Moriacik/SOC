// RGB LED
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

const int redPin   = 11;	// číslo pinu červené barvy
const int greenPin = 10;	// číslo pinu zelené barvy
const int bluePin  = 9;		// číslo pinu modré barvy
  
void setup() { 
	pinMode(redPin, OUTPUT);	// nastavení pinu redPin jako výstupu 
	pinMode(greenPin, OUTPUT);	// nastavení pinu greenPin jako výstupu
	pinMode(bluePin, OUTPUT);	// nastavení pinu bluePin jako výstupu
}    
   
void loop() {    
	// Zakladní barvy:  
	color(255, 0, 0); // zapnout červenou 
	delay(1000);      // počkat 1s  
	color(0,255, 0);  // zapnout zelenou
	delay(1000);      // počkat 1s  
	color(0, 0, 255); // zapnout modrou  
	delay(1000);      // počkat 1s  
	// Michaný barvy:  
	color(255,0,0);   // červená
	delay(1000);
	color(237,109,0); // oranžová
	delay(1000);
	color(255,215,0); // žlutá
	delay(1000);
	color(0,255,0); 	// zelená
	delay(1000);
	color(0,0,255); 	// modrá
	delay(1000);
	color(0,46,90); 	// indigo
	delay(1000);
	color(128,0,128); // purpurová
	delay(1000);
}     
// generace barvy  
void color (unsigned char red, unsigned char green, unsigned char blue)
{    
          analogWrite(redPin, red);   
          analogWrite(bluePin, blue); 
          analogWrite(greenPin, green); 
}
