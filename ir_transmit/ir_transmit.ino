#include <IRremote.h>

IRsend irsend;

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
}

void loop() {
    val = analogRead(potpin); // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 500, 0, 180);// scale it to use it with the servo (value between 0 and 180)
    irsend.sendSony(val,32);
    delay(200);
    
}
