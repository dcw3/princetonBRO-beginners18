/*
This module interfaces with the encoders.
*/

#include "globals.h"
#include "pololu/encoders.h"

// struct holds the # of encoders clicks seen so far
struct Encoders {
  int n_clicks_north = 0;
  int n_clicks_east = 0;
  int n_clicks_south = 0;
  int n_clicks_west = 0;
  double rev_per_click = 1.0/48.0;
  double cirumference = 48; // in meters TODO: Get right value
};

const int forwardAPin = 1;
const int forwardBPin = 2;
const int leftAPin = 1;
const int leftBPin = 2;

// this is just a pointer to the Encoders struct
// used for passing Encoders to/from functions
typedef struct Encoders *Encoders_T;

void init() {
  // TODO
  //encoders_init(forwardAPin, forwardBPin, leftAPin, leftBPin);
  encoders_init('a', 'b', 'c', 'd');
}

// anything needed during reset
void reset() {
  // TODO
  // Example: Encoders_T->n_clicks = 0?
}

// return distance traveled since init occurred... This might be a mess right now.
double getCumulDist(int direction) {
  // TODO
  int clicks = 0;
  switch(direction) {

   case NORTH  :
      clicks = n_clicks_north;
      break;
  
   case SOUTH  :
      clicks = n_clicks_south;
      break;

    case EAST  :
      clicks = n_clicks_east;
      break;

    case WEST  :
      clicks = n_clicks_west;
      break;
    }
    return (Encoders.rev_per_click * clicks * Encoders.cirumference);
}