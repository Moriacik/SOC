// Krokový motor
// Krokový motor následuje potenciometr. 
// Email:laskarduino@gmail.com
// Web:laskarduino.cz
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/*/

#include <Stepper.h>

// počet kroků motoru
#define STEPS 100

// Vytvoříme objekt třídy Stepper, specifikujeme
// počet kroků motoru a piny, ke kterým je řadič připojen
Stepper stepper(STEPS, 8, 9, 10, 11);

// předchozi stav analogového vstupu
int previous = 0;

void setup() {
	// nastavit rychlost motoru na 60 ot/m
	stepper.setSpeed(60);
}

void loop() {
	// přečíst hodnotu pinu A0
	int val = analogRead(0);
	
	// otočit motor na počet kroků = rozdilu 
	//předchozího stavu potenciometru a aktualního
	stepper.step(val - previous);
	
	// zapamatovat stav pinu A0
	previous = val;
}
