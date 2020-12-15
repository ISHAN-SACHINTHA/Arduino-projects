Code below and link to the driver schematic...

// Spindle Motor Driver
// Relic1974
// 10/25/2012

int pulsePin1 = 5;
int pulsePin2 = 6;
int pulsePin3 = 7;
int speedbuttonPin = 11;
int pulsespeed = 1;
int pulsewidth = 2;

void setup()
{
pinMode(pulsePin1, OUTPUT);
pinMode(pulsePin2, OUTPUT);
pinMode(pulsePin3, OUTPUT);
pinMode(speedbuttonPin, INPUT);
digitalWrite(speedbuttonPin, LOW);
}

void loop()
{

// if (speedbuttonPin = HIGH){
// pulsespeed = pulsespeed -1;
// speedbuttonPin = LOW;
// } digitalWrite(pulsePin1, HIGH);
delay(pulsewidth);
digitalWrite(pulsePin1, LOW);
delay(pulsespeed); digitalWrite(pulsePin2, HIGH);
delay(pulsewidth);
digitalWrite(pulsePin2, LOW);
delay(pulsespeed); digitalWrite(pulsePin3, HIGH);
delay(pulsewidth);
digitalWrite(pulsePin3, LOW);
delay(pulsespeed);
}
