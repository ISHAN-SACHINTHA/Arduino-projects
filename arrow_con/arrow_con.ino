#include <IRremote.h>

IRsend irsend;

// constants won't change. They're used here to
// set pin numbers:
const int UbuttonPin = 12;     // the number of the pushbutton pin
const int DbuttonPin = 11;
const int LbuttonPin = 10;
const int RbuttonPin =  9;

// variables will change:
int UbuttonState = 0;         // variable for reading the pushbutton status
int DbuttonState = 0;
int LbuttonState = 0;
int RbuttonState = 0;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(UbuttonPin, INPUT);
  pinMode(DbuttonPin, INPUT);
  pinMode(LbuttonPin, INPUT);
  pinMode(RbuttonPin, INPUT);
 }

void loop() {
  // read the state of the pushbutton value:
  UbuttonState = digitalRead(UbuttonPin);
  DbuttonState = digitalRead(DbuttonPin);
  LbuttonState = digitalRead(LbuttonPin);
  RbuttonState = digitalRead(RbuttonPin);
  
  if (UbuttonState == HIGH) {
    
    irsend.sendSony(11497,32);
  }
  
   
  if (DbuttonState == HIGH) {
    // turn LED on:
    irsend.sendSony(4048,32);
  } 
  
  
  if (LbuttonState == HIGH) {
  
    // turn LED on:
    irsend.sendSony(3088,32);
  } 
  
  
  if (RbuttonState == HIGH) {
    // turn LED on:
    irsend.sendSony(2576,32);
  } 

  if (UbuttonState == DbuttonState == LbuttonState == RbuttonState){
    
     irsend.sendSony(12345,32);
  }
  
    delay(100);
    
}
