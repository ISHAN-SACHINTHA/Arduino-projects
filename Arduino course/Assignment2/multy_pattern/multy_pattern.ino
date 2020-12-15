
//Arduino for Beginner
//Assignment 2 - Led Patterns

int pins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Array for 10 LEDS
int t = 100; // delay time
int i = 0;
int x = 0;
int interval = 5000;
int y = 0;
int j = 0;

void setup() {
  for (i = 0; i < 10; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  for (y = 0; y < 3; y++) {
    pattern1();
  }
  delay(1000);
  for (y = 0; y < 3; y++) {
    pattern2();
  }
  delay(1000);
  for (y = 0; y < 3; y++) {
    pattern3();
  }
  delay(1000);
  for (y = 0; y < 3; y++) {
    pattern4();
  }
  delay(1000);
  for (y = 0; y < 100; y++) {
    pattern5();
  }
  delay(1000);
}

void pattern1() {
  for (i = 0; i < 10; i++) {
    x = i - 1;
    digitalWrite(pins[i], 1);
    digitalWrite(pins[x], 1);
    delay(t);
    digitalWrite(pins[i], 0);
    digitalWrite(pins[x], 0);
  }
  for (i = 8; i > 0; i--) {
    x = i - 1;
    digitalWrite(pins[i], 1);
    digitalWrite(pins[x], 1);
    delay(t);
    digitalWrite(pins[i], 0);
    digitalWrite(pins[x], 0);
  }
}
void pattern2() {
  for (i = 0; i < 10; i++) {
    digitalWrite(pins[i], 1);
    delay(t);
  }
  for (i = 9; i > -1; i--) {
    digitalWrite(pins[i], 0);
    delay(t);
  }
}

void pattern3() {
  for (i = 0; i < 10; i++) {

    digitalWrite(pins[i], 1);
    delay(t);
  }
  for (i = 0; i < 10; i++) {
    digitalWrite(pins[i], 0);
    delay(t);
  }
}

void pattern4() {
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

void pattern5() {
  i = random(0, 10);
  digitalWrite(pins[i], 1);
  delay(t);
  digitalWrite(pins[i], 0);
}

