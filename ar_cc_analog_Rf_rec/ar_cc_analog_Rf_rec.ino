#include <VirtualWire.h>
#include <Servo.h>
int ledPin = 13;
Servo myservo;  // create servo object to control a servo
int val;    // variable to read the value from the analog pin
// Sensors 
int Sensor1Data;

// RF Transmission container
char Sensor1CharMsg[4]; 

void setup() {
 myservo.attach(5);  // attaches the servo on pin 9 to the servo object
 Serial.begin(9600);
 
 // sets the digital pin as output
 pinMode(ledPin, OUTPUT);      
   
   // VirtualWire 
   // Initialise the IO and ISR
   // Required for DR3100
   vw_set_ptt_inverted(true); 
   // Bits per sec
   vw_setup(2000);   
   
   // Start the receiver PLL running
   vw_rx_start();       

} // END void setup

void loop(){
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;
   
   // Non-blocking
   if (vw_get_message(buf, &buflen)) 
   {
  int i;
       // Turn on a light to show received good message 
       digitalWrite(13, true); 
  
       // Message with a good checksum received, dump it. 
       for (i = 0; i < buflen; i++)
  {            
         // Fill Sensor1CharMsg Char array with corresponding 
         // chars from buffer.   
         Sensor1CharMsg[i] = char(buf[i]);
  }
       
       // Convert Sensor1CharMsg Char array to integer
       Sensor1Data = atoi(Sensor1CharMsg);
       
       // DEBUG 
       Serial.print("Sensor 1: ");
       Serial.println(Sensor1Data);

       val = Sensor1Data;            // reads the value of the potentiometer (value between 0 and 1023)
       val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
       
       // END DEBUG
       
       // Clear Sensor1CharMsg char array for coming messages
       // This needs to be done otherwise problems will occur
       // when the incoming messages has less digits than the
       // one before. 
       for (i = 0; i < 4; i++)
       {
         Sensor1CharMsg[i] = 0;
       }
       
       // Turn off light to and await next message 
       digitalWrite(13, false);
   }
}
