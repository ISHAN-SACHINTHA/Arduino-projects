
const int red = 10;  // define the red pin
const int yellow = 9;  // define the yellow pin
const int green = 8;  // define the green pin


void setup()
{
  pinMode(red, OUTPUT); // define pin output mode
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

}


void loop()
{
  stage1();
  delay(1000); // 1 sec interval
  stage2();
  delay(1000); // 1 sec interval
  stage3();
  delay(1000); // 1 sec interval
  stage4();
  delay(1000); // 1 sec interval
}


void stage1() // stage 1 light patern
{
  digitalWrite(red, 1);
  digitalWrite(yellow, 0);
  digitalWrite(green, 0);
}



void stage2() // stage 2 light patern
{
  digitalWrite(red, 1);
  digitalWrite(yellow, 1);
  digitalWrite(green, 0);
}



void stage3() // stage 3 light patern
{
  digitalWrite(red, 0);
  digitalWrite(yellow, 0);
  digitalWrite(green, 1);
}


void stage4() // stage 4 light patern
{
  digitalWrite(red, 0);
  digitalWrite(yellow, 1);
  digitalWrite(green, 0);
}
