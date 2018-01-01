/*
This module is used to interface with the distance sensors.
*/

/* Each 'direction' is one of the four sides of the robot. For now, assume that
our robot starts at the south west corner of the maze and begins facing north
(so the center of the maze is to the forward and right) */
int const NORTH = 1;
int const EAST = 2;
int const SOUTH = 3;
int const WEST = 4;

// used as the initial distance offsets
double const INIT_N_OFFSET = 0;
double const INIT_E_OFFSET = 0;
double const INIT_S_OFFSET = 0;
double const INIT_W_OFFSET = 0;

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
	// TODO
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
void reset(DistSensors_T ) {
	// TODO
}

// return 1 if there is a wall, 0 if there is not a wall
int detectWall(int direction) {
	// TODO
}
