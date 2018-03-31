#ifndef MOVEMENT_FILE
#define MOVEMENT_FILE

#import "globals.h"
#import "maze.h"
#import "pid.h"
#import "motors.h"
#import "encoders_simple.h"
#import "distSensors.h"


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



void moved(int direction, encoders_simple encoder1, double move_value){
    PID_T pid1 = init(1,2,3); // Needs to be changed
    StopWatch sw_millis;
    sw_millis.start();
    double prevTime = sw_millis.(); currentTime=0;
    double final_dist = encoder1->getCumulDist(direction) + move_value;

    // This loop MOVES the robot
    while (final_dist - encoder1->getCumulDist(direction) != 0){
        // assume we imported time already
        currentTime = sw_millis.elapsed()
        // Call setPoint, update (where they currently are, how long it has been since the previous measurement), getVal() -> the power to the motor
        pid1->setPoint(pid1, final_dist);
        pid1->update(pid1,-(final_dist - move_value) + encoder1->getCumulDist(direction), currentTime-prevTime);
        // Pass getVal() to motors
        setMotor(direction,getVal(pid1));
        prevTime = currentTime;
    }
    pid1->reset()
}

void calibrate(DistSensors_T dist, encoders_simple encoder1){
    double value = one_square / 2 ;
    if (dist->detectWall(NORTH) = 1){
        double correction = dist.getDist(NORTH) - value
        // Change the position of the robot and the encoders
        if (correction < 0) {
                encoder1->Rewrite(correction, NORTH)
                moved(SOUTH, encoder1, -correction);
            }
        if (correction > 0) {
                encoder1->Rewrite(correction, SOUTH)
                moved(NORTH, encoder1, correction);
        }

    if (dist->detectWall(SOUTH) = 1){
        double correction = dist.getDist(SOUTH) - value
        // Change the position of the robot and the encoders
        if (correction < 0) {
                encoder1->Rewrite(correction, SOUTH)
                moved(NORTH, encoder1, -correction);
            }
        if (correction > 0) {
                encoder1->Rewrite(correction, NORTH)
                moved(SOUTH, encoder1, correction);
        }

    if (dist->detectWall(WEST) = 1){
        double correction = dist.getDist(WEST) - value
        // Change the position of the robot and the encoders
        if (correction < 0) {
                encoder1->Rewrite(correction, WEST)
                moved(EAST, encoder1, -correction);
            }
        if (correction > 0) {
                encoder1->Rewrite(correction, EAST)
                moved(WEST, encoder1, correction);
        }

    if (dist->detectWall(EAST) = 1){
        double correction = dist.getDist(EAST) - value
        // Change the position of the robot and the encoders
        if (correction < 0) {
                encoder1->Rewrite(correction, EAST)
                moved(WEST, encoder1, -correction);
            }
        if (correction > 0) {
                encoder1->Rewrite(correction, WEST)
                moved(EAST, encoder1, correction);
        }

    }

}

int GetCoord1(){
    return ((int)(getCumulDist(NORTH)-getCumulDist(SOUTH))/one_square);
}

int GetCoord2(){
    return ((int)(getCumulDist(EAST)-getCumulDist(WEST))/one_square);
}

#endif
