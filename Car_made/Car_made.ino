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
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int RECV_PIN = 10; // IR Receiver - Arduino Pin Number 8
int pwmPin = 9; 
int pwmValue;
IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup() {
  myservo.attach(4);  // attaches the servo on pin 4 to the servo object
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode( pwmPin, OUTPUT); 
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(12, OUTPUT); 
  pwmValue = 0; // Starts the program with turned off motor
}
 
void loop() {
  
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
        ; // % Duty Cycle | Max Speed
        }
    if (results.value == 4048) { // ...... Button
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        pwmValue = 255
        ; // % Duty Cycle | Max Speed
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
        myservo.write(130); 
        
        delay(50); 
    
        
     }

   if (results.value == 2576 ) // Turn to left
    {
        myservo.write(50); 
        
        delay(50); 
        
        
    }

    
    if (results.value == 21225 ) 
     {
        digitalWrite(11,HIGH);
     }
    
        

     if (results.value == 4841 )
     {
        
        digitalWrite(11,LOW);
        
     }

     if (results.value == 12345)
     {
       digitalWrite(8,LOW);
       digitalWrite(7,LOW);
       myservo.write(90); 
       pwmValue = 0
       ;
     }
     
     
  Serial.print(pwmValue);
  Serial.print(" ");
  Serial.println(results.value, DEC);
   
  irrecv.resume(); // Receive the next value
  }
  
}
