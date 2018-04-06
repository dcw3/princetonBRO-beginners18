/*
This module is used to interface with the distance sensors.
*/
#ifndef DISTSENSORS_FILE_2
#define DISTSENSORS_FILE_2

#include "globals.h"
const int WALL = 168;
const int trigPinNorth = 2;
const int echoPinNorth = 4;
const int trigPinSouth = 7;
const int echoPinSouth = 8;
const int trigPinWest = -1;
const int echoPinWest = -1;
const int trigPinEast = -1;
const int echoPinEast = -1;
int duration, distance;

double findDist(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * .0343 / 2;
  return distance;
}
// Return the distance reading from the given direction
double getDist(int direction) {
	switch (direction) {
	case NORTH:
		return findDist(trigPinNorth, echoPinNorth);
	case SOUTH:
		return findDist(trigPinSouth, echoPinSouth);
	case WEST:
		return findDist(trigPinWest, echoPinWest);
	case EAST:
		return findDist(trigPinEast, echoPinEast);
	}
}
// return 1 if there is a wall, 0 if there is not a wall
int detectWall(int direction) {
	if (getDist(direction) <= WALL) { return 1; }
	else { return 0; }
}

#endif
