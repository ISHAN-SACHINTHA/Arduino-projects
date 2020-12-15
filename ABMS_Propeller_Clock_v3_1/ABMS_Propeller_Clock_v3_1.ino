  /*
#####################################################################################
#   File:               ABMS_Propeller_Clock_v3_1.ino
#   Processor:          Arduino UNO, MEGA ou Teensy++ 2.0      
#   Language:           Wiring / C /Processing /Fritzing / Arduino IDE          
#           
#   Objectives:         To demonstrating the Persistence Of Vision (POV) effect by creating
#                       a LED gadget showing rotative messages  
#                     
#   Behavior:           By sinchronized rotating the LEDs will show a message
#                       using POV
#                           
#
#     
#   Author:                 Marcelo Moraes 
#   Date:                   27/12/16  
#   place:                  Brazil, Sorocaba City 
#         
#####################################################################################
 
  This project contains public domain code.
  The modification is allowed without notice.
  
 */
  
  // defining the ASCII alphabet characters from the font.h library
  #include "font.h"
  
  
  // define the Arduino LED pins
  const int LEDpins[] = {13,12,11,10,9,8,7,6,5,4}; //only 8 pins, 
                                            //pins 2 and 11 is for the inner and outter ring
  
  int rows = 8;		        // Total LEDs in a row
  const int charHeight = 8;
  const int charWidth = 5;
  
  const int _povDelay =10 ; //persistence of vision need 1/10 of second
  const int _delay = 260; //delay for letters
  
  // sensor setup
  const int sensorPin = 3;  // define the Arduino sensor pin
                             // the sensor is a Reed Switch with pull down resistor 
                             // connected to the +5Vdc
                             
  int sensVal;  // variable to store the value coming from the sensor (not used)
  
  int i;
  int State = 0;
  int lastState = 0;
  int message = 0;
 
  //put your message here
  char textString[] =  " ! @ # $ % ^ & * ! @ # $ % ^ ";
  char textString1[] = "       I'm POV Display       ";
  char textString2[] = "   I use 10 LEDs to display  ";
  char textString3[] = "     Characters on air       ";
  char textString4[] = "    I use wireless power     ";
  char textString5[] = "        transmission         ";
  char textString6[] = " I made by #Ishan Saachintha ";
  char textString7[] = "   For Technology Faculty    ";




  String tmpStr = textString;
  
  unsigned long previousMillis = 0;
  
  const long interval = 3000;
void setup(){
  //reed switch sensor pin connected at pin 12 and is an input
  pinMode(sensorPin,INPUT);
  // all other pins are outputs (2,3,4,5,6,7,8,9,10,11)
  // the stick has 10 LEDs (8 for letters and 2 for the inner and outter ring)
  for (i = 0; i <=11; i++){
    pinMode(LEDpins[i],OUTPUT);    
  }

  //digitalWrite(2,HIGH);
  //digitalWrite(11,HIGH);
  
}//end of setup

  
void loop(){

  unsigned long currentMillis = millis();

 
 
  

  currentMillis = millis();

  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    
    message = message+1;
    
    if (message == 1){
      tmpStr = textString1;
  }

  if (message == 2){
      tmpStr = textString2;
  }

  if (message == 3){
      tmpStr = textString3;
  }

  if (message == 4){
      tmpStr = textString4;
  }
  if (message == 5){
      tmpStr = textString5;
  }
  if (message == 6){
      tmpStr = textString6;
  }
  if (message == 7){
      tmpStr = textString7;
  }

  if (message == 7 ){
    message = 0;
  }
    
  }

 
  int strLen = tmpStr.length();

  digitalWrite(4,HIGH);
  //digitalWrite(10,HIGH);
  digitalWrite(13,HIGH);
  
  State = digitalRead(sensorPin); //get the sensor state
  if(State != lastState){//if sensor state changed
    if(State == HIGH){//if sensor state is high
      delayMicroseconds(_povDelay); //POV delay 1/10 of second
      //writes the message
      for (int k=strLen-1; k>-1; k--){
        printNormalLetter(tmpStr[k]);
      }
    }
    lastState = State;
  }
  //delayMicroseconds(_povDelay); //POV delay 1/10 of second
}//end of main loop
  

//normal and forwards printted letters  
void printNormalLetter(char ch){
  // make sure the character is within the alphabet bounds (defined by the font.h file)
  // if it's not, make it a blank character
  if (ch < 32 || ch > 126){
    ch = 32;
  }
  // subtract the space character (converts the ASCII number to the font index number)
  ch -= 32;
  // step through each byte of the character array
  for (int i=charWidth-1; i>-1; i--) {//width = 5 so i=4 to 0
    byte b = font[ch][i];
    for (int j=0; j<charHeight; j++) {//height = 8 so j=0 to 7
      digitalWrite(LEDpins[j+1], bitRead(b, 7-j));
    }
    delayMicroseconds(_delay);
  }
  //clear the LEDs
  for (i = 0; i < rows; i++){
    digitalWrite(LEDpins[i+1] , LOW);
  }
  // space between letters
  delayMicroseconds(_delay);
}  

//inverted (flipped) and backwards printed letters
void printInvertedLetter(char ch){
  // make sure the character is within the alphabet bounds (defined by the font.h file)
  // if it's not, make it a blank character
  if (ch < 32 || ch > 126){
    ch = 32;
  }
  // subtract the space character (converts the ASCII number to the font index number)
  ch -= 32;
  // step through each byte of the character array
  for (int i=0; i<charWidth; i++) {
    byte b = font[ch][i];
    for (int j=0; j<charHeight; j++) {
       digitalWrite(LEDpins[j+1], bitRead(b, 7-j));
     }
     delayMicroseconds(_delay);
   }
   //clear the LEDs
   for (i = 0; i < rows; i++){
    digitalWrite(LEDpins[i+1] , LOW);
   }
   // space between letters
   delayMicroseconds(_delay);
}
