//----------------------------------------------------------------
// Code to put all 4 servos in home position (90 degrees)
//-----------------------------------------------------------------
#include <Servo.h>
#include <EEPROM.h>
#include <Otto.h>
#include <Oscillator.h>
#include "MaxMatrix.h"
#include <US.h>
#include <BatReader.h>
Otto Otto;  //This is Otto!


#define PIN_YL 2 //servo[0]
#define PIN_YR 3 //servo[1]
#define PIN_RL 4 //servo[2]
#define PIN_RR 5 //servo[3]

void setup() {
  //Set the servo pins
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true);
  Otto.home();

  Serial.begin(9600);
}

// 1 - Right Leg (small = inward)
// 2 - Left Leg (small = outward)
// 3 - Right foot (small = upward)
// 4 - Left foot (small = downward)

int step1[4] = {90, 90, 90, 90};


void loop() {
  Otto._moveServos(300, step1);
  //Write your code here!

  
  
  //Remember, the first number in the () is the time in milliseconds
  //and the second word is the step you want to set!


  delay(1000);
}



