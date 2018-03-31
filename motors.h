/*
This module is used to interface with the motors.

NOTE: this class doesn't have a struct. If data/values needs to be stored
then we'll need to add a struct, as is done in DistSensors.h
*/

// globals includes the 4 integer directions

#ifndef MOTORS_FILE
#define MOTORS_FILE

#include "globals.h"

// double is power: should be between -1 and 1
// (1 being max power, -1 being max power in the opposite direction)
void setMotor(int direction, double power) 
{
	int speed = (int)
	if (direction == NORTH)
	{
		moveRightLeft(0, true);
		moveForwardBackward(255, true);

	}
	else if (direction == SOUTH)
	{
		moveRightLeft(0, true);
		moveForwardBackward(255, false);
	}
	else if (direction == EAST)
	{
		moveForwardBackward(0, true);
		moveRightLeft(255, true);
	}
	else if (direction == WEST)
	{
		moveForwardBackward(0, true);
		moveRigthLeft(255, false);
	}
}

// any initialization that's needed
void init() 
{

}

// reset anything that needs to be reset?
reset() 
{

}

void moveForwardBackward(int speed, boolean reverse)
{
    analogWrite(enablePin1, 255); 
    digitalWrite(in1Pin, !reverse);
    digitalWrite(in2Pin, reverse);
}

void moveRightLeft(int speed, int reverse)
{
	analogWrite(enablePin2, 255); 
	digitalWrite(in3Pin, !reverse); 
    digitalWrite(in4Pin, reverse); 
}

#endif
