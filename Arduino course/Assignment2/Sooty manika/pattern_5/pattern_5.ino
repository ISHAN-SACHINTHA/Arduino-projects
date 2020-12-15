//Arduino for Beginner - Assignment 2 - Led Patterns

int LEDS[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //LED Array
int d = 250; // delay variable
int i = 0;
int y = 0;

void setup() {
  for (i = 0; i < 12; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  pattern();
  Clear();
  delay(d);
}

void pattern() {
  y = 9;
  for (i = 0; i < 5; i++) {
    digitalWrite(LEDS[y], 1);
    delay(d);
    digitalWrite(LEDS[i], 1);
    delay(d);
    y--;
  }
}


void Clear() {
  for (i = 0; i < 10; i++) {
    digitalWrite(LEDS[i], 0);
  }
}
