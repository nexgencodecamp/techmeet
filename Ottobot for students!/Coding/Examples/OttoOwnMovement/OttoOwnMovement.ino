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
  Otto._moveServos(300, step1); //home
  //Write your code here!





  delay(1000);
}

/* all movements:
 *  dir = 1 or -1
 *  first number is repetitions
 *  Otto.jump(1, 1500);
 *  Otto.walk(2, 1000, dir);
 *  Otto.turn(4, 1500, dir);
 *  Otto.bend(1, 1500, dir);
 *  Otto.shakeLeg(1, 1500, dir);
 *  Otto.updown(1, 1500, 15);
 *  Otto.swing(1, 1500, 15);
 *  Otto.tiptoeSwing(1, 1500, 15);
 *  Otto.jitter(1, 1500, 15);
 *  Otto.ascendingTurn(1, 1500, 15);
 *  Otto.moonwalker(4, 1500, 15, dir);
 *  Otto.crusaito(2, 1500, 15, dir);
 *  Otto.flapping(2, 1500, 15, dir);
 */



