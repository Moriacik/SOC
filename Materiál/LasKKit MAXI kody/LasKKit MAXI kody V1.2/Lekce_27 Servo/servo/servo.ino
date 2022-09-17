// Servo
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

#include <Servo.h>

Servo myservo;  		// vytvořít objekt pro řízení serva
const int servoPin = 9; // číslo pinu serva

int pos = 0;    		// proměnna pro ukládání pozice serva

void setup() {
  myservo.attach(servoPin);			// nastavení pinu serva 
}

void loop() {
  for (pos = 0; pos <= 160; pos += 1) {	// točení servem od 0 do 160 stupnů
    // in steps of 1 degree
    myservo.write(pos);              	// nastavit servo do pozice "pos"
    delay(15);                       	// počkat 15ms než servo dosáhne pozice
  }
  for (pos = 160; pos >= 0; pos -= 1) { // točení servem od 160 do 0 stupnů
    myservo.write(pos);              	// nastavit servo do pozice "pos"
    delay(15);                       	// počkat 15ms než servo dosáhne pozice
  }
}
