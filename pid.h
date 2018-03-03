/*
This module creates PID loop objects.
*/

#include "globals.h"

struct PID {
	double kP ,kI, kD;
	double integral;
	double setPoint;
	//double prevMeasure;
	double derivative;
	double prevError;
	bool isFirstUpdate;
	// TODO: add flag to detect first update?
};

typedef struct PID *PID_T;
// return a PID loop object
PID_T init(double kP, double kI, double kD) {
	struct PID *p;
	p->kP = kP;
	p->kI = kI;
	p->kD = kD;
	p->integral = 0;// TODO
	p->setPoint = 0;
	p->derivative = 0;
	p->prevError = 0;
	p->isFirstUpdate = true;
	return p;
};

// reset prevMeasure, setPoint, integral
void reset(PID_T pid) {
	pid->integral = 0;// TODO
	pid->setPoint = 0;
	pid->derivative = 0;
	pid->prevError = 0;
}

// update PID_T 
//double update(PID_T pid, double val, double dt) {
void update(PID_T pid, double val, double dt) {
	double error = pid->setPoint - val;
	pid->integral = pid->integral + error * dt;
	pid->derivative = (error - pid->prevError) / dt;
	pid->prevError = error;
	pid->isFirstUpdate = false;
	//deriv = currentMeasure - prevMeasure;
}

// return PID value
double getVal(PID_T pid) {
	return (pid->kP * pid->prevError) + (pid->kI * pid->integral) + (pid->derivative * pid->kD);
	// TODO: return PID value
}

