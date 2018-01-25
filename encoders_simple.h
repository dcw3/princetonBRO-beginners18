/*
This module interfaces with the encoders.
*/

#include "globals.h"
#include "pololu/encoders.h"

const double rev_per_click = 1.0/12.0; // Seems small but listed here: https://www.pololu.com/product/3081/resources
const double circumference_left = 48; // in meters TODO: Get right value
const double circumference_up = 48; // in meters TODO: Get right value
const char forwardAPin = PD1;
const char forwardBPin = PD2;
const char leftAPin = PD3;
const char leftBPin = PD4;
int numCalls;
double northDirection;
double eastDirection;

void init() {
  encoders_init(forwardAPin, forwardBPin, leftAPin, leftBPin);
    numCalls = 0;
    northDirection = 0;
    eastDirection = 0;
}

// anything needed during reset
void reset() {
  encoders_get_counts_and_reset_m1();
    encoders_get_counts_and_reset_m2();
}

// return distance traveled since init occurred... This might be a mess right now.
double getCumulDist(int direction) {
    if (numCalls % 50 == 0) {
        northDirection = (rev_per_click * encoders_get_counts_and_reset_m1() * circumference_up);
        eastDirection = (rev_per_click * encoders_get_counts_and_reset_m2() * circumference_left);
    }
    numCalls++;
  switch(direction) {
   case NORTH  :
       return (northDirection + (rev_per_click * encoders_get_counts_m1() * circumference_up));

    case EAST  :
      return (eastDirection + (rev_per_click * encoders_get_counts_m2() * circumference_left));
    }
}