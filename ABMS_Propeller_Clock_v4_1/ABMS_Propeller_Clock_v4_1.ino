  /*
#####################################################################################
#   File:               ABMS_Propeller_Clock_v4.ino
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


int timer = 210;    
int sensorPin = 3;
int State = 0;         
int lastState = 0;     




//Character's Matrix Array....
boolean space[]={0,0,0,0,0,0,0,0}; // just one column space between the letters
boolean _[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //no letter, blank space

//ASCII 5x7 alphabet letters uppercase
boolean A[] = {0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,1,0};
boolean B[] = {0,1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,1,1,1,0};
boolean C[] = {0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0};
boolean D[] = {0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0};
boolean E[] = {0,1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1};
boolean F[] = {0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1};
boolean G[] = {0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,1,1,1,0,1,0};
boolean H[] = {0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1};
boolean I[] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0};
boolean J[] = {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1};
boolean K[] = {0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1};
boolean L[] = {0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0};
boolean M[] = {0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1};
boolean N[] = {0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1};
boolean O[] = {0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0};
boolean P[] = {0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0};
boolean Q[] = {0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,1,1,0};
boolean R[] = {0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0};
boolean S[] = {0,1,0,0,0,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,0,0,1};
boolean T[] = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1};
boolean U[] = {0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1};
boolean V[] = {0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1};
boolean W[] = {0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1};
boolean X[] = {0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,1};
boolean Y[] = {0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1};
boolean Z[] = {0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,1};

//ASCII 5x7 alphabet letters lowercase
boolean a[] = {0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,0,0,0};
boolean b[] = {0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0};
boolean c[] = {0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0};
boolean d[] = {0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1};
boolean e[] = {0,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1,1,0,0,0};
boolean f[] = {0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0};
boolean g[] = {0,0,0,0,1,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,1,1,1,1,0};
boolean h[] = {0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0};
boolean i[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
boolean j[] = {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0};
boolean k[] = {0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0};
boolean l[] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
boolean m[] = {0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0};
boolean n[] = {0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0};
boolean o[] = {0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0};
boolean p[] = {0,1,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0};
boolean q[] = {0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0};
boolean r[] = {0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0};
boolean s[] = {0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0};
boolean t[] = {0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0};
boolean u[] = {0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0};
boolean v[] = {0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0};
boolean w[] = {0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0};
boolean x[] = {0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0};
boolean y[] = {0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0};
boolean z[] = {0,1,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,1,0,0};

//ASCII 5x7 alphabet numbers
boolean _0[] = {0,0,1,1,1,1,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,1,1,1,1,0};
boolean _1[] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
boolean _2[] = {0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,0}; 
boolean _3[] = {0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,0,1};
boolean _4[] = {0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0};
boolean _5[] = {0,0,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,1};
boolean _6[] = {0,0,1,1,1,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,0,0,0};
boolean _7[] = {0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1};
boolean _8[] = {0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0};
boolean _9[] = {0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,1,1,1,0};


//ASCII 5x7 alphabet symbols
boolean _exclamation[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //!
boolean _quotation[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0}; //"
boolean _number[] = {0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0}; //#
boolean _dollar[] = {0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0}; //$
boolean _percent[] = {0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,1,1,0,0,0,1,0}; //%
boolean _ampersand[] = {0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0}; //&
boolean _apostrophe[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //'
boolean _openparentheses[] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0}; //(
boolean _closeparentheses[] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0}; //)
boolean _asterisk[] = {0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0}; //*
boolean _plus[] = {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0}; //+
boolean _comma[] = {0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //,
boolean _hyphen[] = {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0}; //-
boolean _period[] = {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //.
boolean _slash[] = {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0}; ///
boolean _colon[] = {0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //:
boolean _semicolon[] = {0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //;
boolean _lessthan[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1}; //<
boolean _equal[] = {0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0}; //=
boolean _greatherthan[] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0}; //>
boolean _question[] = {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0}; //?
boolean _leftbrakets[] = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0}; //[
boolean _backslash[] = {0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0}; //\
boolean _rightbrakets[] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //]
boolean _caret[] = {0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0}; //^
boolean _underline[] = {0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0}; //_
boolean _leftgbrace[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0}; //{
boolean _stroke[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //|
boolean _rightbrace[] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0}; //}
boolean _tilde[] = {0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0}; //~ 
boolean _ellipses[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}; //... 
boolean _craseaccent[] = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //`
boolean _graveaccent[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1}; //´
boolean _different[] = {0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1}; //!=
boolean _at[] = {0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,0}; //@
boolean _up[] = {0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0};
boolean _down[] = {0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0};
boolean _left[] = {0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
boolean _right[] = {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0};
boolean _diveded[] = {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
boolean _omega[] = {0,1,0,1,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,1,0,1,1,0,0,0};
boolean _pi[] = {0,1,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0};
boolean _sum[] = {0,1,1,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};
boolean _grade[] = {0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
boolean _alpha[] = {0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,1,1,0,0};
boolean _betha[] = {0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0};
boolean _deltha[] = {0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0};
boolean _tetha[] = {0,0,1,1,1,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0};
boolean _phi[] = {0,1,0,1,1,1,0,0,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1,1,0,1};
boolean _Epson[] = {0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0};
boolean _rho[] = {0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0};
boolean _mu[] = {0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1};
boolean _circle[] = {0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0};
boolean _sphere[] = {0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0};
boolean _square[] = {0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1};
boolean _block[] = {0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1};
boolean _diamond[] = {0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0};
boolean _celcius[] = {0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0};
boolean _farenheight[] = {0,0,0,0,0,0,1,1,0,1,1,1,1,0,1,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0};
boolean _error[] = {0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0};
boolean _musicnote[] = {0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0};
boolean _squareroot[] = {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0};

//some emojis
boolean _smile[] = {0,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0};
boolean _sad[] = {0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0};
boolean _cry[] = {0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,0,0,0};
boolean _plane[] = {0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0};
boolean _heart[] = {0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0};
boolean _solidheart[] = {0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0};


int _m;

void setup() {
  Serial.begin(9600);
  for (int Pin = 4; Pin <=13; Pin++) {
    pinMode(Pin, OUTPUT);
  }
  pinMode(sensorPin, INPUT);
}

void loop(){
  State = digitalRead(sensorPin);
  if (State != lastState){
    if (State == HIGH){
      delayMicroseconds(10000);
      //put your message here, it will write a charater a time
      WriteLetter(_heart);
      WriteLetter1Width(space);
      WriteLetter(_solidheart);
      WriteLetter1Width(space);
      WriteLetter(_heart);
      WriteLetter1Width(space);
      WriteLetter(_);
      WriteLetter(I);
      WriteLetter1Width(space);
      WriteLetter(S);
      WriteLetter1Width(space);
      WriteLetter(H);
      WriteLetter1Width(space);
      WriteLetter(A);
      WriteLetter1Width(space);
      WriteLetter(N);
      WriteLetter(_);
      WriteLetter(_2);
      WriteLetter1Width(space);
      WriteLetter(_0);
      WriteLetter1Width(space);
      WriteLetter(_1);
      WriteLetter1Width(space);
      WriteLetter(_7);
      WriteLetter(_);
      WriteLetter(_heart);
      WriteLetter1Width(space);
      WriteLetter(_solidheart);
      WriteLetter1Width(space);
      WriteLetter(_heart);
      WriteLetter1Width(space);
      WriteLetter(_);
    }
    lastState = State;
  }
}

void WriteLetter(boolean letter[]){
  _m=0;
  //write 5 colunms
  for (int n=0; n<=4; n++){
    //write for 8 pins
    for (int Pin = 5; Pin <=12; Pin++) {
      //Serial.print(letter[m]);
      digitalWrite(Pin, letter[_m]);
      digitalWrite(4,HIGH);
      digitalWrite(13,HIGH);
      _m=_m+1;
    }
    delayMicroseconds(timer);
  }
}

void WriteLetter1Width(boolean letter[]){
  _m=0;
  for (int Pin = 5; Pin <=12; Pin++) {
    digitalWrite(Pin, space[_m]);
    digitalWrite(4,HIGH);
    digitalWrite(13,HIGH);
    _m=_m+1;
  }
  delayMicroseconds(timer);
}

void WriteLetter2Width(boolean letter[]){
  _m=0;
  for (int n=0; n<=1; n++){
    for (int Pin = 5; Pin <=12; Pin++) {
      digitalWrite(Pin, letter[_m]);
      digitalWrite(4,HIGH);
      digitalWrite(13,HIGH);
      _m=_m+1;
    }
    delayMicroseconds(timer);
  }
}
  

