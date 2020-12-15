/*  
 *  Controlling a DC Fan Speed with a TV Remote
 *  
 *  Modified IRrecvDemo example from Ken Shirriff IRremote Library
 *  Ken Shirriff
 *  http://arcfn.com
 *  
 *  Modified by Dejan Nedelkovski,
 *  www.HowToMechatronics.com 
 *  
 */
 
#include <IRremote.h>
int RECV_PIN = 10; // IR Receiver - Arduino Pin Number 8
int pwmPin = 9; // Arduino Pin Number 7 to the Base of the Transistor
int pwmValue;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define trigPin 13
#define echoPin 11

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode( pwmPin, OUTPUT); 
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(12, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pwmValue = 0; // Starts the program with turned off motor
}
 
void loop() {

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  
  if (irrecv.decode(&results)) 
  {   
    
    analogWrite(pwmPin, pwmValue);
  
    if (results.value == 11497) { // PLAY Button
        digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
        pwmValue = 255; // 100% Duty Cycle | Max Speed
        }
    if (results.value == 24101) { // ...... Button
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        pwmValue = 150
        ; // % Duty Cycle | Max Speed BACKWARD
        }
    if (results.value == 4048) { // ...... Button
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        pwmValue = 255
        ; // % Duty Cycle | Max Speed  BACKWARD
        }
    if (results.value == 2672) { // STOP Button
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
        pwmValue = 0; // 0% Duty Cycke | Turned off
        }
    if (results.value == 752 ) { // FORWARD Button
        if(pwmValue <= 255){ 
         digitalWrite(8, HIGH);
         digitalWrite(7, LOW); 
        pwmValue = pwmValue + 20; // Increases the Duty Cycle of the PWM Signal
        delay(20);     
      }   
    }
    if (results.value == 2800 ) { // BACKWARD Button
      if(pwmValue >= 20){
          digitalWrite(8, HIGH);
          digitalWrite(7, LOW); 
        pwmValue = pwmValue - 50; // Decreases the Duty Cycle of the PWM Signal
        delay(20);    
      }
    }   
   
  if (results.value == 3088 ) // Turn to left
    {
        digitalWrite(4, HIGH);
        digitalWrite(12, LOW);
        
        delay(50); 
    
        
     }

   if (results.value == 2576 ) // Turn to left
    {
        digitalWrite(12, HIGH);
        digitalWrite(4, LOW);
        
        delay(50); 
        
        
    }

    if (results.value == 528 ) // Turn to left
    {
        digitalWrite(12,LOW);
        digitalWrite(4, LOW);    
       
    }

    if (results.value == 16 ) // Turn to left
    {
        digitalWrite(12,LOW);
        digitalWrite(4, HIGH);    

       delay(50);
       
        digitalWrite(12,LOW);
        digitalWrite(4, LOW);
    }

    if (results.value == 1040 ) // Turn to left
    {
        digitalWrite(4,LOW);
        digitalWrite(12, HIGH);    

       delay(50);
       
        digitalWrite(12,LOW);
        digitalWrite(4, LOW);
    }

   
   
  Serial.print(pwmValue);
  Serial.print(" ");
  Serial.println(results.value, DEC);
  Serial.print(" ");
  Serial.print(distance);
   
  irrecv.resume(); // Receive the next value
  }
  if (distance <= 10) 
    {
       digitalWrite(7, HIGH);
       digitalWrite(8, LOW);
    }
   else
   {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
   }
   delay(10);
}
