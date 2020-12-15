#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);   //defining lcd pins

const int dataIN = 2; //IR sensor INPUT
const int motor = 11; // motor driver PWM
const int acc = 5; // Accuracy of output
const int N = 2; // No. of arms/reference points
int pwm = 0;

unsigned long prevmillis; // To store time
unsigned long duration; // To store time difference
unsigned long lcdrefresh; // To store time for LCD refresh

int setrpm;
int rpm; // RPM value

boolean currentstate; // Current state of IR input scan
boolean prevstate; // State of IR sensor in previous scan

void setup()
{
  pinMode(dataIN,INPUT);
  lcd.begin(16,2);     
  prevmillis = 0;
  prevstate = LOW; 
}

void loop()
{
 // Measure Actual RPM 
 currentstate = digitalRead(dataIN); // Read IR sensor state
 if( prevstate != currentstate) // If there is change in input
   {
     if( currentstate == HIGH ) // If input changes only from LOW to HIGH
       {
         duration = ( micros() - prevmillis )*N; // Time difference between revolution in microsecond
         prevmillis = micros(); // store time for next revolution calculation
         rpm = (60000000/duration); // rpm = (1/ time millis)*1000*1000*60;
       }
   }
  prevstate = currentstate; // store this scan (prev scan) data for next scan
  
  // Measure RPM required
  setrpm = map(analogRead(5), 0, 1023, 0, 8000); // Read set value from analog pin 5 (0 & 8000 min. amd max. rpm)
                                    
  // Change PWM accordingly
  if( rpm > (setrpm*(1+(acc/100))) )   // If current RPM > required
   {
    pwm = pwm-1;     // Decrease PWM
    if(pwm = -1) {pwm = 0;}
    analogWrite(motor,pwm); 
   }
  
  if( rpm < (setrpm*(1-(acc/100))) )   // If current RPM < required
   {
    pwm = pwm+1;     // Increase PWM
    if(pwm = 256) { pwm = 255; }
    analogWrite(motor,pwm); 
   } 
  
  // LCD Display
  if( ( millis()-lcdrefresh ) >= 100 )
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Set RPM = ");
      lcd.print(setrpm);
      lcd.setCursor(0,1);
      lcd.print("RPM = ");
      lcd.print(rpm); 
      if(pwm == 255 )
       { lcd.print(" Max!"); }  // If PWM = 255 ie. max value. Speed will not increase beyond that
      lcdrefresh = millis();   
    }

}

