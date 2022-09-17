// Používaní skeneru sběrnicí I²C 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

// připoj knihovny
#include <Wire.h>
 
void setup() {
	Wire.begin();
	Serial.begin(9600);
	while (!Serial);               // Leonardo: počkat na sériový monitor
	Serial.println("\nI2C Skener");
}

void loop() {
	byte error, address;
	int nDevices;

	Serial.println("Skenování...");

	nDevices = 0;
	for(address = 1; address < 127; address++ )	{
		// i2c_skener používá vrácenou hodnotu
		// Write.endTransmisstion pro zjištění,
		// zda zařízení potvrdilo adresu.
		Wire.beginTransmission(address);
		error = Wire.endTransmission();
		
		if (error == 0)	{
			Serial.print("I2C zařízení nalezeno na adrese 0x");
			if (address<16)
				Serial.print("0");
			Serial.print(address,HEX);
			Serial.println("  !");
		
			nDevices++;
		} else if (error==4) {
			Serial.print("Neznámá chyba na adrese 0x");
			if (address<16)
				Serial.print("0");
			Serial.println(address,HEX);
		}    
	}
	if (nDevices == 0)
	Serial.println("Žádné I2C zařízení nenalezeno\n");
	else
	Serial.println("Hotovo\n");
	
	delay(5000);               // počkat 5 vteřin
}