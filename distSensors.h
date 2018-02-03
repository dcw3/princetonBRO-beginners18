/*
This module is used to interface with the distance sensors.
*/

#include "globals.h"
#include "vl6180x/VL6180X.h"

// threshold distance for detectWall (mm)
double const WALL = 70;

// declaring sensors
VL6180X sensorNorth;
VL6180X sensorSouth;
VL6180X sensorWest;
VL6180X sensorEast;

// initializing sensors
init(sensorNorth);
init(sensorSouth);
init(sensorEast);
init(sensorWest);

// initializes sensor
void init(VL6180X sensor) {
	sensor.init();
	sensor.configureDefault();
	sensor.setTimeout(500);
}

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
double getDist(int direction) {
	switch (direction) {
	case NORTH:
		return sensorNorth.readRangeSingleMillimeters();
	case SOUTH:
		return sensorSouth.readRangeSingleMillimeters();
	case WEST:
		return sensorWest.readRangeSingleMillimeters();
	case EAST:
		return sensorEast.readRangeSingleMillimeters();
	}
}

// Calibrate the distance sensor by updating that offset
// probably not used yet: will be used in the init() function later
void calibrate(DistSensors_T sensors, double currentDist, int direction) {
	// TODO
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
	if (getDist(direction) <= WALL) { return 1; }
	else { return 0; }
}
