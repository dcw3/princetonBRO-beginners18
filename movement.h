#ifndef MOVEMENT_FILE
#define MOVEMENT_FILE

#include "globals.h"
#include "pid.h"
#include "motors_with_driver.h"
#include "encoders_simple.h"
#include "distSensors.h"
#include "StopWatch.h"


// Distance moved in each direction
struct Movement{
	// constant, will include tolerance
	double one_square = 12;
};

typedef struct Movement *Movement_T;

Movement_T init_movement() {
    Movement_T returnVal = (struct Movement*) malloc(sizeof(struct Movement));
    return returnVal;
}

void reset_movement(Movement_T m, double value_for_one_square){
	m->one_square = value_for_one_square;
}

void moved(int direction, double move_value){
    PID_T pid1 = init_pid(1,2,3); // Needs to be changed
    StopWatch sw_millis; // TODO: add stopwatch
    sw_millis.start();
    double prevTime = sw_millis.value();
    double currentTime=0;
    double final_dist = getCumulDist(direction) + move_value;

    // This loop MOVES the robot
    while (final_dist - getCumulDist(direction) != 0){
        // assume we imported time already
        currentTime = sw_millis.elapsed();
        // Call setPoint, update (where they currently are, how long it has been since the previous measurement), getVal() -> the power to the motor
        setPoint(pid1, final_dist);
        update(pid1,-(final_dist - move_value) + getCumulDist(direction), currentTime-prevTime);
        // Pass getVal() to motors
        setMotor(direction, getVal(pid1));
        prevTime = currentTime;
    }
    reset_pid(pid1);
}

void calibrate(Movement_T m){
    double value = m->one_square / 2;
    if (detectWall(NORTH) == 1){
        double correction = getDist(NORTH) - value;
        // Change the position of the robot and the encoders
        if (correction <= 0) {
            rewrite(correction, NORTH);
            moved(SOUTH, -correction);
        }
        if (correction > 0) {
            rewrite(correction, SOUTH);
            moved(NORTH, correction);
        }
    }

    if (detectWall(SOUTH) == 1){
        double correction = getDist(SOUTH) - value;
        // Change the position of the robot and the encoders
        if (correction <= 0) {
            rewrite(correction, SOUTH);
            moved(NORTH, -correction);
        }
        if (correction > 0) {
                rewrite(correction, NORTH);
                moved(SOUTH, correction);
        }
    }

    if (detectWall(WEST) == 1){
        double correction = getDist(WEST) - value;
        // Change the position of the robot and the encoders
        if (correction <= 0) {
                rewrite(correction, WEST);
                moved(EAST, -correction);
            }
        if (correction > 0) {
                rewrite(correction, EAST);
                moved(WEST, correction);
        }
    }

    if (detectWall(EAST) == 1){
        double correction = getDist(EAST) - value;
        // Change the position of the robot and the encoders
        if (correction <= 0) {
                rewrite(correction, EAST);
                moved(WEST, -correction);
            }
        if (correction > 0) {
                rewrite(correction, WEST);
                moved(EAST, correction);
        }

    }
}

int GetCoord1(Movement_T m){
    return ((int)(getCumulDist(NORTH)-getCumulDist(SOUTH))/m->one_square);
}

int GetCoord2(Movement_T m){
    return ((int)(getCumulDist(EAST)-getCumulDist(WEST))/m->one_square);
}

#endif
