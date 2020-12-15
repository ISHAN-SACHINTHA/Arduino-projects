int incomingByte = 0; // for incoming serial data

void setup() 

{ 

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps 


pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
 


} 

void loop() 

{

// send data only when you receive data: 

if (Serial.available() > 0) 

{ // read the incoming byte: 

incomingByte = Serial.read();

// say what you got: 

Serial.print("I received: "); 

Serial.println(incomingByte, DEC); 

} 

if (incomingByte==48) 

  digitalWrite(8, LOW);
  digitalWrite(7, LOW); 
  analogWrite (9, 0);
  
if (incomingByte==49) 
 
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW); 
  analogWrite (9, 50);
  
if (incomingByte==50) 
 
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW); 
  analogWrite (9, 100);

if (incomingByte==51) 
 
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW); 
  analogWrite (9, 100);

if (incomingByte==52) 
 
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW); 
  analogWrite (9, 200);

}

