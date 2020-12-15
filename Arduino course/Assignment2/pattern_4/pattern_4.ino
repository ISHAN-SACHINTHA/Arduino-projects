
//Arduino for Beginner

//Assignment 2 - Led Patterns



int pins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Array for 10 LEDS
int t = 100; // delay time
int i = 0;
int j = 0;



void setup() {
  // put your setup code here, to run once:

  for (i = 0; i < 10; i++) {
    pinMode(pins[i], OUTPUT);
  }

}

void loop() {

  j = 9;
  for (i = 0; i < 5; i++) {
    digitalWrite(pins[j], 1);
    digitalWrite(pins[i], 1);
    j--;
    delay(t);

  }

  j = 5;
  for (i = 5; i > -1; i--) {
    digitalWrite(pins[j], 0);
    digitalWrite(pins[i], 0);
    j++;
    delay(t);

  }
  
}


