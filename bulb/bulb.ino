

int phase1 = 2;
int phase2 = 3;
int phase3 = 4;
int led = 12;

unsigned long stepLength = 80000;
int minStepLength = 800;
int steps = 5;

void setup() {
  pinMode(led, OUTPUT);  
  pinMode(phase1, OUTPUT);
  pinMode(phase2, OUTPUT);
  pinMode(phase3, OUTPUT);
  digitalWrite(led, LOW); 
}

void loop() {
  switchStep(1);
  switchStep(2); 
  switchStep(3);
  
  if(stepLength > minStepLength)
  {
    stepLength = stepLength - steps;
  } else {
    // set the minimum pulse length
    stepLength=minStepLength;
  }
  
  Serial.print(stepLength);
  
  if (stepLength < 79950) {
    digitalWrite(led, HIGH);   // second gear
    steps = 1000;
  }
   
  if (stepLength < 10000) {
    digitalWrite(led, LOW);      // third gear
    steps = 100;
  }

  if (stepLength < 7000) {
    digitalWrite(led, HIGH);      // fourth gear
    steps = 5;
  }

  if (stepLength < 5000) {
    digitalWrite(led, HIGH);      // fourth gear
    steps = 2;
  }

  if (stepLength < 3000) {
    digitalWrite(led, HIGH);      // fourth gear
    steps = 1;
  }

  if (stepLength <1500) {
    digitalWrite(led, HIGH);      // fourth gear
    steps = 1/2;
   
  }

  if (stepLength < 0000) {
    digitalWrite(led, HIGH);      // fourth gear
    steps = 0.5;
  }
}


void switchStep(int stage)
{
  switch(stage)
  {
  case 1:
    digitalWrite(phase1, 0 );
    digitalWrite(phase2, 1 );
    digitalWrite(phase3, 1 );
    myDelay(stepLength);
    break;
    
  case 2:
    digitalWrite(phase1, 1 );
    digitalWrite(phase2, 0 );
    digitalWrite(phase3, 1 );
    myDelay(stepLength);
    break;
    
  default:
    digitalWrite(phase1, 1 );
    digitalWrite(phase2, 1 );
    digitalWrite(phase3, 0 );
    myDelay(stepLength);
    break;
  }  


}

void myDelay(unsigned long p) {
if (p > 16380) {
  delay (p/1000);
  } else {
  delayMicroseconds(p);
  }
}
