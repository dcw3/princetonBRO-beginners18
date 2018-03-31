/*
This module is used to interface with the distance sensors.
*/
#ifndef DISTSENSORS_FILE
#define DISTSENSORS_FILE

#include "VL6180X.h"
#include "globals.h"
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
void initSensor(VL6180X* sensor) {
	(*sensor).init();
	(*sensor).configureDefault();
	(*sensor).setTimeout(500);
}

// sensors
VL6180X sensorNorth;
VL6180X sensorSouth;
VL6180X sensorWest;
VL6180X sensorEast;

// pointers
VL6180X *ptrSensorNorth = &sensorNorth;
VL6180X *ptrSensorSouth = &sensorSouth;
VL6180X *ptrSensorWest = &sensorWest;
VL6180X *ptrSensorEast = &sensorEast;

void setupSensors() {
	// shutdown pins
	pinMode(NORTH_SHUTDOWN, OUTPUT);
	pinMode(WEST_SHUTDOWN, OUTPUT);
	pinMode(EAST_SHUTDOWN, OUTPUT);

	 // hold each sensor in shutdown initially
	digitalWrite(NORTH_SHUTDOWN, LOW);
	digitalWrite(WEST_SHUTDOWN, LOW);
	digitalWrite(EAST_SHUTDOWN, LOW);
	delay(10);

	// wake sensors and change address one by one
	(*ptrSensorSouth).setAddress(0x25); // SOUTH is the first to change - doesnt need to be in reset
	delay(10);
	digitalWrite(WEST_SHUTDOWN, HIGH);
	(*ptrSensorWest).setAddress(0x25);
	delay(10);
	digitalWrite(EAST_SHUTDOWN, HIGH);
	(*ptrSensorEast).setAddress(0x27);
	delay(10);
	digitalWrite(NORTH_SHUTDOWN, HIGH); // NORTH maintains default address

	// init all sensors
	initSensor(ptrSensorNorth);
	initSensor(ptrSensorSouth);
	initSensor(ptrSensorWest);
	initSensor(ptrSensorEast);
}

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

// return 1 if there is a wall, 0 if there is not a wall
int detectWall(int direction) {
	if (getDist(direction) <= WALL) { return 1; }
	else { return 0; }
}

#endif
