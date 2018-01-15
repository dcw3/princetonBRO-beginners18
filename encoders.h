/*
This module interfaces with the encoders.
*/

#include "globals.h"

// struct holds the # of encoders clicks seen so far
// NOTE: feel free to change these data values: they may
// not be the right way to interface this. These are just an example.
struct Encoders {
	int n_clicks_north = 0;
	int n_clicks_east = 0;
	int n_clicks_south = 0;
	int n_clicks_west = 0;
	double meters_per_click = 0.001; // TODO: correct this value!
	// add other data if needed
}

// this is just a pointer to the Encoders struct
// used for passing Encoders to/from functions
typedef struct Encoders *Encoders_T;

// whatever initialization is needed
Encoders_T init() {
	// TODO
}

// anything needed during reset
void reset(Encoders_T) {
	// TODO
	// Example: Encoders_T->n_clicks = 0?
}

// return distance traveled since init occurred
double getCumulDist(int direction) {
	// TODO
}
