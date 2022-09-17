// Bzučák
// Bzučák můžeš využít kdykoli, pokud budeš chtít použít nějaký zvuk.
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

int buzzer = 12;			    // číslo pinu bzučáku
void setup() {
	pinMode(buzzer,OUTPUT);	// nastavení pinu bzučáku jako výstupu
}
void loop() {
	unsigned char i;		    // definuj proměnnou
	while(1) {
		// generace frekvence 
		for(i=0;i<80;i++) {
			digitalWrite(buzzer,HIGH);
			delay(1);		        // počkat 1ms
			digitalWrite(buzzer,LOW);
			delay(1);		        // počkat 1ms
		}
		//generace jiné frekvence 
		for(i=0;i<100;i++) {
			digitalWrite(buzzer,HIGH);
			delay(2);		        // počkat 2ms
			digitalWrite(buzzer,LOW);
			delay(2);		        // počkat 2ms
		}
	}
}
