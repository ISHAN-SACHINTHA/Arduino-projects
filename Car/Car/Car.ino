/*
 Some Sample code of how to use your IR remote
 
 * Lets get started:
 
 The IR sensor's pins are attached to Arduino as so:
 Pin 1 to Vout (pin 11 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

#include <IRremote.h>

int IRpin = 9;  // pin for the IR sensor
int M1_1 = 10;    // 
int M1_2 = 11;    // 
int M2_1 = 12;    // 
int M2_2 = 13;
IRrecv irrecv(IRpin);
decode_results results;



void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(M1_1, OUTPUT);
  pinMode(M1_2, OUTPUT);
  pinMode(M2_1, OUTPUT);
  pinMode(M2_2, OUTPUT);
}

void loop() 
{
   
  if (irrecv.decode(&results)) 
    {
      
      irrecv.resume();   // Receive the next value
    }
  
   if (results.value == 144)  // this is where you put in your IR remote button #
    
     digitalWrite(M1_1,HIGH);
     digitalWrite(M1_2, LOW);
     
  
   if (results.value == 2192)

     digitalWrite(M1_2,HIGH);
     digitalWrite(M1_1, LOW);
      
   if (results.value == 1168)

     digitalWrite(M2_1,HIGH);
     digitalWrite(M2_2, LOW);
     
   if (results.value == 3216) 

     digitalWrite(M2_2,HIGH);
     digitalWrite(M2_1, LOW);
     
}
