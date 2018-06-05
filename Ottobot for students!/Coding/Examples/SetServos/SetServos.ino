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

//---------------------------------------------------------
//-- First step: Configure the pins where the servos are attached
/*
         ---------------
        |     O   O     |
        |---------------|
  YR 3==> |               | <== YL 2
         ---------------
            ||     ||
  RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/
#define PIN_YL 2 //servo[0]
#define PIN_YR 3 //servo[1]
#define PIN_RL 4 //servo[2]
#define PIN_RR 5 //servo[3]

///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//

///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup() {
  //Set the servo pins

  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true);
  Otto.home();

  Serial.begin(9600);
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////

int shake_leg1[4] = {90, 90, 58, 35};
int shake_leg2[4] = {90, 90, 58, 120};
int shake_leg3[4] = {90, 90, 58, 60};

void loop() {

  if(Serial.available()){
    int a = Serial.readStringUntil(',').toInt();
    int b = Serial.readStringUntil(',').toInt();
    int c = Serial.readStringUntil(',').toInt();
    int d = Serial.readStringUntil(',').toInt();



      while(Serial.available()){
        Serial.read();
      }
    
    int asdf[4] = {a, b, c, d};
    
    Otto._moveServos(10, asdf);

    for(int i = 0; i < 4; i++){
      Serial.print(asdf[i]);
      Serial.print(',');
      Serial.println();
      Serial.println();
    }
  }

  
// 1 - Right Leg (small = inward)
// 2 - Left Leg (small = outward)
// 3 - Right foot (small = upward)
// 4 - Left foot (small = downward)

}


