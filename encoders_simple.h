/*
This module interfaces with the encoders.
 This is written in C++ as it works with the Arduino an is also much easier to work with.
*/

#ifndef ENCODERS_SIMPLE_FILE
#define ENCODERS_SIMPLE_FILE

#include "globals.h"
#include "Encoder.h"

//const double PI = 3.1415926536;
const double rev_per_click = 1.0/12.0; // Confirmed correct
const double circumference_left = 48*3.1415926536; // in mm
const double circumference_up = 38*3.1415926536; // in mm
const int forwardAPin = 2;
const int forwardBPin = 4;
const int leftAPin = 3;
const int leftBPin = 8;

Encoder upDisp(forwardAPin, forwardBPin);
Encoder leftDisp(leftAPin, leftBPin);

// No initiate function necessary. Use reset to set encoders back to zero.

// anything needed during reset
void reset() {
    upDisp = Encoder(forwardAPin, forwardBPin);
    leftDisp = Encoder(leftAPin, leftBPin);
}

// return distance traveled since init occurred. This can work as a coordinate system. Returns distance in meters.
double getCumulDist(int direction) {
  switch(direction) {
   case NORTH  :
       return (rev_per_click * upDisp.read() * circumference_up);

    case EAST  :
      return (rev_per_click * leftDisp.read() * circumference_left);

      case SOUTH  :
          return -(rev_per_click * upDisp.read() * circumference_up);

      case WEST  :
          return -(rev_per_click * leftDisp.read() * circumference_left);
    }
    return 1.0/0.0;
}

#endif
