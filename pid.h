/*
This module creates PID loop objects.
*/

#include "globals.h"

struct PID {
	//
	double kP ,kI, kD;
	double integral;
	double setPoint;
	double prevMeasure;
	// TODO: add flag to detect first update?
};

typedef struct PID *PID_T;
// return a PID loop object
PID_T init(double kP, double kI, double kD) {
	PID *p;
	p->kP = kP;
	p->kI = kI;
	p->kD = kD;
	return p;
};

// reset prevMeasure, setPoint, integral
void reset(PID_T pid) {
	pid->integral = 0;// TODO
	pid->setPoint = 0;
	pid->prevMeasure = 0;
}

// update PID_T 
double update(PID_T pid, double val, double dt) {
	double error = pid->setPoint - val;

	//deriv = currentMeasure - prevMeasure;
}

// return PID value
getVal(PID_T pid) {
	// TODO: return PID value
}

