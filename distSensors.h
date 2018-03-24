/*
This module is used to interface with the distance sensors.
*/

#include "globals.h"
#include "vl6180x.h/VL6180X.h"
#include <Arduino.h>

// pins connected to VL6180 GPIO used to hold sensor in reset
#define NORTH_SHUTDOWN 10
#define EAST_SHUTDOWN 9
#define WEST_SHUTDOWN 8 

// initial offsets (unused)
const double INIT_N_OFFSET = 0;
const double INIT_S_OFFSET = 0;
const double INIT_E_OFFSET = 0;
const double INIT_W_OFFSET = 0;

// threshold distance for detectWall (mm)
double const WALL = 70;

// initializes sensor
void initSensor(VL6180X sensor) {
	sensor.init();
	sensor.configureDefault();
	sensor.setTimeout(500);
}

// setup
// declaring sensors
VL6180X sensorNorth;
VL6180X sensorSouth;
VL6180X sensorWest;
VL6180X sensorEast;

// shutdown pins
pinMode(NORTH_SHUTDOWN, OUTPUT);
pinMode(SOUTH_SHUTDOWN, OUTPUT);
pinMode(WEST_SHUTDOWN, OUTPUT);
pinMode(EAST_SHUTDOWN, OUTPUT);

// hold each sensor in shutdown initially
digitalWrite(NORTH_SHUTDOWN, LOW);
digitalWrite(WEST_SHUTDOWN, LOW);
digitalWrite(EAST_SHUTDOWN, LOW);
delay(10);

// wake sensors and change address one by one
sensorSouth.setAddress(0x25); // SOUTH is the first to change - doesnt need to be in reset
delay(10);
digitalWrite(WEST_SHUTDOWN, HIGH);
sensorWest.setAddress(0x25);
delay(10);
digitalWrite(EAST_SHUTDOWN, HIGH);
sensorEast.setAddress(0x27);
delay(10);
digitalWrite(NORTH_SHUTDOWN, HIGH); // NORTH maintains default address

// init all sensors
initSensor(sensorNorth);
initSensor(sensorSouth);
initSensor(sensorWest);
initSensor(sensorEast);

// this struct holds the offsets needed for each offset
// feel free to add other stuff to this struct as well
// unused
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
	// TODO (unused)
}

// initialization: return a DistSensors object
DistSensors_T initDistSensor() {
	// TODO (unused)
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
