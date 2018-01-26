/*
This module is used to interface with the distance sensors.
*/

#include "globals.h"

// used as the initial distance offsets
double const INIT_N_OFFSET = 0;
double const INIT_E_OFFSET = 0;
double const INIT_S_OFFSET = 0;
double const INIT_W_OFFSET = 0;

// max distance for detectWall
// what should this be? or should this be 0
double const WALL = 10;

// this struct holds the offsets needed for each offset
// feel free to add other stuff to this struct as well
struct DistSensors {
	double northOffset = INIT_N_OFFSET;
	double eastOffset = INIT_E_OFFSET;
	double southOffset = INIT_S_OFFSET;
	double westOffset = INIT_W_OFFSET;
};
// this is just a pointer to the DistSensors struct
// used for passing DistSensors to/from functions
typedef struct DistSensors *DistSensors_T;

// Return the distance reading from the given direction
double getDist(DistSensors_T sensors, int direction) {
	switch (direction) {
	case NORTH:
		return *sensors.northOffset;
	case SOUTH:
		return *sensors.southhOffset;
	case WEST:
		return *sensors.westOffset;
	case EAST:
		return *sensors.eastOffset;
	}
}

// Calibrate the distance sensor by updating that offset
// probably not used yet: will be used in the init() function later
void calibrate(DistSensors_T sensors, double currentDist, int direction) {
	switch (direction) {
	case NORTH:
		*sensors.northOffset = currentDist;
	case SOUTH:
		*sensors.southOffset = currentDist;
	case WEST:
		*sensors.westOffset = currentDist;
	case EAST:
		*sensors.eastOffset = currentDist;
	}
}

// initialization: return a DistSensors object
DistSensors_T init() {
	// TODO
}

// reset the DistSensors object
// this may be empty but it's included just in case we do need it
void reset(DistSensors_T) {
	// TODO
}

// return 1 if there is a wall, 0 if there is not a wall
int detectWall(int direction) {
	if (getDist(init, direction) <= WALL) return 1;
	return 0;
}
