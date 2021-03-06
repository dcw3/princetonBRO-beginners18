/*
This module is used to interface with the distance sensors.
*/
#ifndef DISTSENSORS_FILE
#define DISTSENSORS_FILE

#include "VL6180X.h"
#include "globals.h"

// pins connected to VL6180 GPIO used to hold sensor in reset (to be redefined after final wiring)
#define NORTH_SHUTDOWN 13
#define EAST_SHUTDOWN 12
#define WEST_SHUTDOWN 8
//#define SOUTH_SHUTDOWN 8

// threshold distance for detectWall (mm)
double const WALL = 70;

// initializes sensor
void initSensor(VL6180X* sensor) {
	delay(20);
	(*sensor).init();
	(*sensor).configureDefault();
	(*sensor).setTimeout(500);
}

// sensors
VL6180X sensorNorth;
VL6180X sensorSouth;
VL6180X sensorWest;
VL6180X sensorEast;

void setupSensors() {
	// shutdown pins
	pinMode(NORTH_SHUTDOWN, OUTPUT);
	pinMode(WEST_SHUTDOWN, OUTPUT);
	pinMode(EAST_SHUTDOWN, OUTPUT);
  //pinMode(SOUTH_SHUTDOWN, OUTPUT);

	// hold each sensor in shutdown initially
	digitalWrite(NORTH_SHUTDOWN, LOW);
	digitalWrite(WEST_SHUTDOWN, LOW);
	digitalWrite(EAST_SHUTDOWN, LOW);
  //digitalWrite(SOUTH_SHUTDOWN, LOW);
	delay(10);

	digitalWrite(NORTH_SHUTDOWN, HIGH);
	digitalWrite(WEST_SHUTDOWN, HIGH);
	digitalWrite(EAST_SHUTDOWN, HIGH);
  //digitalWrite(SOUTH_SHUTDOWN, HIGH);

	digitalWrite(NORTH_SHUTDOWN, LOW);
	digitalWrite(WEST_SHUTDOWN, LOW);
	digitalWrite(EAST_SHUTDOWN, LOW);
  //digitalWrite(SOUTH_SHUTDOWN, HIGH);
  
	// wake sensors and change address one by one
	sensorSouth.setAddress(0x23);
	delay(20);
 
	digitalWrite(WEST_SHUTDOWN, HIGH);
	delay(20);
	sensorWest.setAddress(0x25);
 
	digitalWrite(EAST_SHUTDOWN, HIGH);
	delay(20);
	sensorEast.setAddress(0x27);
  
	digitalWrite(NORTH_SHUTDOWN, HIGH); // NORTH maintains default address
	delay(20);

	// init all sensors
	initSensor(&sensorNorth);
	initSensor(&sensorSouth);
	initSensor(&sensorWest);
	initSensor(&sensorEast);
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
