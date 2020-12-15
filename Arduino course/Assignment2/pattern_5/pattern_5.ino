
//Arduino for Beginner

//Assignment 2 - Led Patterns



int pins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Array for 10 LEDS
int t = 50; // delay time
int i = 0;
int j = 0;



void setup() {
  // put your setup code here, to run once:

  for (i = 0; i < 10; i++) {
    pinMode(pins[i], OUTPUT);
  }

}

void loop() {
  i=random(0, 10);
  digitalWrite(pins[i],1);
  delay(t);
  digitalWrite(pins[i],0);

  
}

  
