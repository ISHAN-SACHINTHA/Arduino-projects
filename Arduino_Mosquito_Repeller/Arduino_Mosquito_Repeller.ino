int speakerA = 8;
int frequencyA = 31000;
int speakerB = 9;
int frequencyB = 44000;

void setup(){
  pinMode(speakerA, OUTPUT);
  pinMode(speakerB, OUTPUT);
}

void loop(){
  tone(speakerB, frequencyB, 1000);
  delay(10);
  tone(speakerA, frequencyA, 1000);
  delay(10);
 
}
