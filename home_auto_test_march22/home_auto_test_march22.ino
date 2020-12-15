void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13, 1);   // turn the LED on (HIGH is the voltage level)
delay(1000);                       // wait for a second
digitalWrite(12, 1);    // turn the LED off by making the voltage LOW
delay(1000);
digitalWrite(11, 1);    // turn the LED off by making the voltage LOW
delay(1000);
digitalWrite(13, 0);
digitalWrite(12, 0);
digitalWrite(11, 0);// turn the LED off by making the voltage LOW
delay(1000);
}
