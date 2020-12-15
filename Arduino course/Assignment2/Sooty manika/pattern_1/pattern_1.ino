
//Arduino for Beginner - Assignment 2 - Led Patterns

int LEDS[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //LED Array
int d = 100; // delay variable
int x = 0;
int i = 0;

void setup() {
  for (i = 0; i < 12; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  for (i = 0; i < 12; i++) { 
    x = i - 2;
    digitalWrite(LEDS[i], 1);
    digitalWrite(LEDS[x], 1);
    delay(d);
    digitalWrite(LEDS[i], 0);
    digitalWrite(LEDS[x], 0);
  }
  for (i = 9; i > 0; i--) {
    x = i - 2;
    digitalWrite(LEDS[i], 1);
    digitalWrite(LEDS[x], 1);
    delay(d);
    digitalWrite(LEDS[i], 0);
    digitalWrite(LEDS[x], 0);
  }
}
