// JB: all of my comments will start with "JB:", all other comments are from test codes.

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

//JB: Naming the buttons, telling it which pin it is in, and making a variable to track each button's state
const int Button2 = 2;
int Button2State = 0;
const int Button3 = 3;
int Button3State = 0;
const int Button4 = 4;
int Button4State = 0;
const int Button5 = 5;
int Button5State = 0;
const int Button6 = 6;
int Button6State = 0;
const int Button7 = 7;
int Button7State = 0;
const int Button8 = 8;
int Button8State = 0;
const int Button9 = 9;
int Button9State = 0;
const int Button10 = 10;
int Button10State = 0;


int G0State = 0; //JB:Creating state tracking variables for each gate, each gate will be opened in the setup code so that when it is powered on the state variables will all be 0 and the gates will all be opened 
int G1State = 0;
int G2State = 0;
int G3State = 0;
int G4State = 0;
int G5State = 0;
int G6State = 0;
int G7State = 0;
int G8State = 0;
int G9State = 0;
int G10State = 0;
int G11State = 0;
int G12State = 0;
int G13State = 0;
int G14State = 0;
int G15State = 0;

//JB: Creating 32 functions to be called later in the actual loop. 1 for each gate to open and 1 for each to close, checks the state to see if it actually needs to move it, updates the state if moved.
void OpenG0(){
  if (G0State == 1){
  pwm.setPWM(0,0,360);
  G0State = 0;} 
}

void OpenG1(){
  if (G1State == 1){
  pwm.setPWM(1,0,355);
  G1State = 0;} 
}

void OpenG2(){
  if (G2State == 1){
  pwm.setPWM(2,0,365);
  G2State = 0;} 
}

void OpenG3(){
  if (G3State == 1){
  pwm.setPWM(3,0,340);
  G3State = 0;} 
}

void OpenG4(){
  if (G4State == 1){
  pwm.setPWM(4,0,350);
  G4State = 0;} 
}

void OpenG5(){
  if (G5State == 1){
  pwm.setPWM(5,0,365);
  G5State = 0;} 
}

void OpenG6(){
  if (G6State == 1){
  pwm.setPWM(6,0,365);
  G6State = 0;} 
}

void OpenG7(){
  if (G7State == 1){
  pwm.setPWM(7,0,356);
  G7State = 0;}
}

void OpenG8(){
  if (G8State == 1){
  pwm.setPWM(8,0,370);
  G8State = 0;} 
}

void OpenG9(){
  if (G9State == 1){
  pwm.setPWM(9,0,340);
  G9State = 0;} 
}

void OpenG10(){
  if (G10State == 1){
  pwm.setPWM(10,0,360);
  G10State = 0;} 
}

void OpenG11(){
  if (G11State == 1){
  pwm.setPWM(11,0,330);
  G11State = 0;} 
}

void OpenG12(){
  if (G12State == 1){
  pwm.setPWM(12,0,345);
  G12State = 0;} 
}

void OpenG13(){
  if (G13State == 1){
  pwm.setPWM(13,0,350);
  G13State = 0;} 
}

void OpenG14(){
  if (G14State == 1){
  pwm.setPWM(14,0,365);
  G14State = 0;} 
}

void OpenG15(){
  if (G15State == 1){
  pwm.setPWM(15,0,335);
  G15State = 0;} 
}

//JB: staring the close gate loops now
void CloseG0(){
  if (G0State == 0){
  pwm.setPWM(0,0,170);
  G0State = 1;} 
}

void CloseG1(){
  if (G1State == 0){
  pwm.setPWM(1,0,165);
  G1State = 1;} 
}

void CloseG2(){
  if (G2State == 0){
  pwm.setPWM(2,0,170);
  G2State = 1;} 
}

void CloseG3(){
  if (G3State == 0){
  pwm.setPWM(3,0,155);
  G3State = 1;} 
}

void CloseG4(){
  if (G4State == 0){
  pwm.setPWM(4,0,160);
  G4State = 1;} 
}

void CloseG5(){
  if (G5State == 0){
  pwm.setPWM(5,0,170);
  G5State = 1;} 
}

void CloseG6(){
  if (G6State == 0){
  pwm.setPWM(6,0,160);
  G6State = 1;} 
}

void CloseG7(){
  if (G7State == 0){
  pwm.setPWM(7,0,160);
  G7State = 1;} 
}

void CloseG8(){
  if (G8State == 0){
  pwm.setPWM(8,0,185);
  G8State = 1;} 
}

void CloseG9(){
  if (G9State == 0){
  pwm.setPWM(9,0,150);
  G9State = 1;} 
}

void CloseG10(){
  if (G10State == 0){
  pwm.setPWM(10,0,165);
  G10State = 1;} 
}

void CloseG11(){
  if (G11State == 0){
  pwm.setPWM(11,0,155);
  G11State = 1;} 
}

void CloseG12(){
  if (G12State == 0){
  pwm.setPWM(12,0,160);
  G12State = 1;} 
}

void CloseG13(){
  if (G13State == 0){
  pwm.setPWM(13,0,150);
  G13State = 1;} 
}

void CloseG14(){
  if (G14State == 0){
  pwm.setPWM(14,0,170);
  G14State = 1;} 
}

void CloseG15(){
  if (G15State == 0){
  pwm.setPWM(15,0,135);
  G15State = 1;} 
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pwm.begin();
pwm.setOscillatorFrequency(27000000);
pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

pinMode (2, INPUT);//JB: Telling it that these pin numbers are inputs and using the built in PULLUP Resistor for a cleaner signal
digitalWrite(2,HIGH);
pinMode (3, INPUT);
digitalWrite(3,HIGH);
pinMode (4, INPUT);
digitalWrite(4,HIGH);
pinMode (5, INPUT);
digitalWrite(5,HIGH);
pinMode (6, INPUT);
digitalWrite(6,HIGH);
pinMode (7, INPUT);
digitalWrite(7,HIGH);
pinMode (8, INPUT);
digitalWrite(8,HIGH);
pinMode (9, INPUT);
digitalWrite(9,HIGH);
pinMode (10, INPUT);
digitalWrite(10,HIGH);

pwm.setPWM(0,0,360); //JB: Opening all of the gates when the system is powered on to make sure all gates and state tracking variables are correct.
pwm.setPWM(1,0,355);
delay(500);
pwm.setPWM(2,0,365);
pwm.setPWM(3,0,340);
delay(500);
pwm.setPWM(4,0,350);
pwm.setPWM(5,0,365);
delay(500);
pwm.setPWM(6,0,365);
pwm.setPWM(7,0,356);
delay(500);
pwm.setPWM(8,0,370);
pwm.setPWM(9,0,340);
delay(500);
pwm.setPWM(10,0,360);
pwm.setPWM(11,0,330);
delay(500);
pwm.setPWM(12,0,345);
pwm.setPWM(13,0,350);
delay(500);
pwm.setPWM(14,0,365);
pwm.setPWM(15,0,335);
delay(500);

delay(10);
}

void loop() {

Button2State=digitalRead(Button2); //JB: Reads the state of button 2
  if (Button2State == LOW){
    OpenG1(); //JB: Calls the function to check if the gate is closed and opens it if it's closed
    CloseG0();
    delay(500);
    digitalWrite(2,HIGH);
    return; //JB: returns to the original loop that is reading the buttons
  }


Button3State=digitalRead(Button3);
  if (Button3State == LOW){
    OpenG8();
    CloseG9();
    delay(500);
    OpenG3();
    CloseG2();
    delay(500);
    OpenG0();
    CloseG1();
    delay(500);
    digitalWrite(3,HIGH);
    return;
    
  }


Button4State=digitalRead(Button4);
  if (Button4State == LOW){
    OpenG12();
    CloseG13();
    delay(500);
    OpenG11();
    CloseG10();
    delay(500);
    OpenG9();
    CloseG8();
    delay(500);
    OpenG3();
    CloseG2();
    delay(500);
    OpenG0();
    CloseG1();
    delay(500);
    digitalWrite(4,HIGH);
    return;
  }


Button5State=digitalRead(Button5);
    if (Button5State == LOW){
    OpenG13();
    CloseG12();
    delay(500);
    OpenG11();
    CloseG10();
    delay(500);
    OpenG9();
    CloseG8();
    delay(500);
    OpenG3();
    CloseG2();
    delay(500);
    OpenG0();
    CloseG1();
    delay(500);
    digitalWrite(5,HIGH);
    return;
  }


Button6State=digitalRead(Button6);
    if (Button6State == LOW){
    OpenG14();
    CloseG15();
    delay(500);
    OpenG10();
    CloseG11();
    delay(500);
    OpenG9();
    CloseG8();
    delay(500);
    OpenG3();
    CloseG2();
    delay(500);
    OpenG0();
    CloseG1();
    delay(500);
    digitalWrite(6,HIGH);
    return;
  }


Button7State=digitalRead(Button7);
    if (Button7State == LOW){
    OpenG15();
    CloseG14();
    delay(500);
    OpenG10();
    CloseG11();
    delay(500);
    OpenG9();
    CloseG8();
    delay(500);
    OpenG3();
    CloseG2();
    delay(500);
    OpenG0();
    CloseG1();
    delay(500);
    digitalWrite(7,HIGH);
    return;
  }


Button8State=digitalRead(Button8);
    if (Button8State == LOW){
    OpenG4();
    CloseG5();
    delay(500);
    OpenG2();
    CloseG3();
    delay(500);
    OpenG0();
    CloseG1();
    delay(500);
    digitalWrite(8,HIGH);
    return;
  }


Button9State=digitalRead(Button9);
    if (Button9State == LOW){
    OpenG6();
    CloseG7();
    delay(500);
    OpenG5();
    CloseG4();
    delay(500);
    OpenG2();
    CloseG3();
    delay(500);
    OpenG0();
    CloseG1();
    delay(500);
    digitalWrite(9,HIGH);
    return;
  }

Button10State=digitalRead(Button10);
    if (Button10State == LOW){
    OpenG7();
    CloseG6();
    delay(500);
    OpenG5();
    CloseG4();
    delay(500);
    OpenG2();
    CloseG3();
    delay(500);
    OpenG0();
    CloseG1();
    delay(500);
    digitalWrite(10,HIGH);
    return;
  }



}
