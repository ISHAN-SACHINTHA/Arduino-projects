int LEDS[] = {3, 5, 6, 9, 10, 11}; //LED Array
int i = 0;

void setup() {
  
  for (i = 0; i < 6; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  
  for (i = 0; i < 6; i++) {
    digitalWrite(LEDS[i], 1);
    delay(500);
  }

}
