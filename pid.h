/*
This module creates PID loop objects.
*/

#include "globals.h"

struct PID {
	double kP = 2, kI = 1, kD = 0.1;
	double integral = 0;
	double setPoint = 0;
	double prevMeasure = 0;
	// TODO: add flag to detect first update?
}

typedef struct PID *PID_T;

// return a PID loop object
PID_T init(double kP, double kI, double kD) {
	// TODO
}

// reset prevMeasure, setPoint, integral
void reset(PID_T pid) {
	// TODO
}

// update PID_T 
double update(PID_T pid, double val, double dt) {
	deriv = currentMeasure - prevMeasure;
}

// return PID value
getVal(PID_T pid) {
	// TODO: return PID value
}

