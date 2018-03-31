#ifndef MOVEMENT_FILE
#define MOVEMENT_FILE

#import "globals.h"
#import "maze.h"
#import "pid.h"
#import "motors.h"



	// Distance moved in each direction
struct movement(){
	double total = 0;
	// constant, will include tolerance
	double one_square = 12;
}


void reset(double value_for_one_square){
	struct movement *m1;
	m1->total = 0;
	m1->one_square = value_for_one_square;
}


void Useless_move(int direction, double dt){

    double final_dist = getCumulDist(direction) + one_square;
    dt1 = 0;
    while (final_dist - getCumulDist(direction) != 0){
        dt1 = dt1 + dt
        // Call setPoint, update (where they currently are, how long it has been since the previous measurement), getVal() -> the power to the motor
        setPoint(final_dist);
        update(getCumulDist(direction), dt1);
        // Pass getVal() to motors
        setMotor(direction,getVal());
    }

}

void moved(int direction){
    PID_T pid1 = init(1,2,3); // Needs to be changed
    StopWatch sw_millis;
    sw_millis.start();
    double prevTime = sw_millis.(); currentTime=0;
    double final_dist = getCumulDist(direction) + one_square;

    // This loop MOVES the robot
    while (final_dist - getCumulDist(direction) != 0){
        // assume we imported time already
        currentTime = sw_millis.elapsed()
        // Call setPoint, update (where they currently are, how long it has been since the previous measurement), getVal() -> the power to the motor
        setPoint(pid1, final_dist);
        update(pid1,getCumulDist(direction), currentTime-prevTime);
        // Pass getVal() to motors
        setMotor(direction,getVal(pid1));
        prevTime = currentTime;
    }
    pid1->reset()
}

int GetCoord1(){
    return ((int)(getCumulDist(NORTH)-getCumulDist(SOUTH))/one_square);
}

int GetCoord2(){
    return ((int)(getCumulDist(EAST)-getCumulDist(WEST))/one_square);
}

#endif
