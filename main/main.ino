#ifndef MAIN2_H_INCLUDED
#define MAIN2_H_INCLUDED

#include "maze.h"
#include "movement.h"
#include "globals.h"
#include "distSensors.h"

  int d = -1;
  int centerFound = 0;
void setup() {
  // put your setup code here, to run once:
  setupSensors();
  Maze_T maze = init_maze();
  Movement_T movement = init_movement();
  //int coord1 = 0, coord2 = 0,
}
void loop() {
  // put your main code here, to run repeatedly:
  if (((GetCoord1(movement) == 7) || (GetCoord1(movement) == 8)) && ((GetCoord2(movement) == 7) || (GetCoord2(movement) == 8))) {
  //implement back-trace
    centerFound = 1;
    WillYouPleaseReturnForGodsSake();
  }
  if (centerFound = 0){
    d = getDirection(maze, GetCoord1(), GetCoord2());
    moved(d);
    updatePosition(maze, GetCoord1(), GetCoord2());
  }

  if (centerFound = 1){
        WillYouPleaseReturnForGodsSake();
  }
}

void WillYouPleaseReturnForGodsSake(){
  StackArray <int> x_stack_new;
  StackArray <int> y_stack_new;
  
    while ((GetCoord1() != 0)&&(GetCoord2() != 0)){
        x_stack_new.push(GetCoord1());
        x_stack_new.push(GetCoord2());
        d = ReturnToOtherCheckpoint(maze, GetCoord1(), GetCoord2());
        moved(d);
    }

    maze->x_stack = x_stack_new;
    maze->y_stack = y_stack_new;
}


#endif // MAIN2_H_INCLUDED
