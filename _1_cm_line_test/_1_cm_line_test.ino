#include <Stepper.h>
 
// ca. Schritte pro Umdrehung
const int stepsPerRevolution = 20; 
 
// Schrittmotor initialisieren
// Y-Achse hängt an Pin 2,3,4,5 des Arduino
// X-Achse hängt an Pin 8,9,10,11 des Arduino
Stepper myStepperY(stepsPerRevolution, 2,3,4,5);
Stepper myStepperX(stepsPerRevolution, 8,9,10,11); 
 
void setup() {
 // Geschwindigkeit setzen
 myStepperY.setSpeed(100);
 myStepperX.setSpeed(100);
 
 // 60 Schritte nach rechts
 myStepperX.step(60);
 delay(100);
 
 // 60 Schritte nach hinten
 myStepperY.step(60);
 delay(100);
 
}
 
void loop() {
 // Leer 
}
