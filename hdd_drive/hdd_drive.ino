int phase1 = 2;
int phase2 = 3;
int phase3 = 4;
int x=50;
void setup() {
  // put your setup code here, to run once:
  pinMode(phase1, OUTPUT);
  pinMode(phase2, OUTPUT);
  pinMode(phase3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(phase1, HIGH);
    digitalWrite(phase2, LOW);
    digitalWrite(phase3, LOW);

    delay(x);

    digitalWrite(phase1, LOW);
    digitalWrite(phase2, HIGH);
    digitalWrite(phase3, LOW);

    delay(x);

    digitalWrite(phase1, LOW);
    digitalWrite(phase2, LOW);
    digitalWrite(phase3, HIGH);

    delay(x);
}
