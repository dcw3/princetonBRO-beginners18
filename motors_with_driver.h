/*
This module is used to interface with the motors.

NOTE: Hasn't been tested yet. But it does compile.

*/

// globals includes the 4 integer directions
#include "globals.h"

const float batteryVoltage = 7.4;
const float goodVoltage = 5.0; // Good speed for robot voltage
int maxPower = 0;
const int LUDICROUS_SPEED = 255; // Max power, too fast for normal movement.

const int motorAPinA = 6; // Fix these when wiring robot. Must be pins with ~ by them (support PWM).
const int motorAPinB = 7;
const int motorBPinA = 8;
const int motorBPinB = 9;

const int scaleA = 1; // Motors not same speed? Change these to scale them. Must be less than one.
const int scaleB = 1;

// Make it easier
void northMove(double power) {
    power = power * scaleA;
    if (power < 0) {
        analogWrite(motorAPinA, 0);
        analogWrite(motorAPinB, (int)(power * maxPower * -1));
    } else {
        analogWrite(motorAPinA, (int)(power * maxPower));
        analogWrite(motorAPinB, 0);
    }
}

void eastMove(double power) {
    power = power * scaleB;
    if (power < 0) {
        analogWrite(motorBPinA, 0);
        analogWrite(motorBPinB, (int)(power * maxPower * -1));
    } else {
        analogWrite(motorBPinA, (int)(power * maxPower));
        analogWrite(motorBPinB, 0);
    }
}

// double is power: should be between -1 and 1
// (1 being max power, -1 being max power in the opposite direction)
void setMotor(int direction, double power) {
    switch (direction) {
        case NORTH : northMove(power); return;
        case SOUTH : northMove(power * -1); return;
        case EAST :  eastMove(power); return;
        case WEST :  eastMove(power * -1); return;
    }
}

// Goes max speed. May not be good for motors, depending on battery voltage.
void turbo(int direction) {
    setMotor(direction, LUDICROUS_SPEED / maxPower);
}

// any initialization that's needed
void init() {
    maxPower = (int) (LUDICROUS_SPEED * goodVoltage/batteryVoltage); // Probably could be done above but ¯\_(ツ)_/¯
    pinMode(motorAPinA, OUTPUT);
    pinMode(motorAPinB, OUTPUT);
    pinMode(motorBPinA, OUTPUT);
    pinMode(motorBPinB, OUTPUT);
}

// reset anything that needs to be reset - Turns off motors.
void reset() {
    analogWrite(motorAPinA, 0);
    analogWrite(motorAPinB, 0);
    analogWrite(motorBPinA, 0);
    analogWrite(motorBPinB, 0);
}
