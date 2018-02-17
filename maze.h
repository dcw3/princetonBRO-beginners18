/*
This module manages the maze navigation.
*/

// Link to documentation of stack array: https://playground.arduino.cc/Code/StackArray
// ToDo: implement backtrace, make algorithm more efficient, make stack more efficient, build case where everythign is zero


#import "distSensors.h"
#import "StackArray.h"
#import "globals.h"

#define MAZE_SIZE 16

struct Node {
	int visited = 0;
}

typedef struct Node *Node_T;

struct Maze {
	Node_T nodes[MAZE_SIZE][MAZE_SIZE];
	// stack of path taken
	StackArray <int> x_stack;
	StackArray <int> y_stack;
	// TODO: install/import Arduino stack library -> Done!
}

typedef struct Maze *Maze_T;

// initializations
MAZE_T init() {
	// ???
	// do we need to init the nodes inside Maze?
}

void updateMaze(Maze_T maze) {
	// maze->nodes[coord_1][coord_2].northWall = 1;
	// skip for now, not needed
}

void updatePosition(Maze_T maze, int coord_1, int coord_2) {
	// update nodes to make current position visited
	maze->nodes[coord_1][coord_2].visited = 1;
	// Update stack to make the path traceable
	x_stack.push(coord_1);
	y_stack.push(coord_2);
}

int getDirection(Maze_T maze, int coord_1, int coord_2) {
	// TODO: write code for this -> DONE

    // Stores the possibilities for each maze
    int getDirection[4] = {0,0,0,0};

	// Assumption: robot starts from bottom right part of maze
		// check if north has been visited
		if (maze->nodes[coord_1][coord_2 + 1].visited == 0){
                if (!detectWall(NORTH)) {getDirection[NORTH] = 1;}
		}

		// check if south has been visited
		if (maze->nodes[coord_1][coord_2 - 1].visited == 0){
                if (!detectWall(SOUTH)) {getDirection[SOUTH] = 1;}
		}

		// check if east has been visited
		if (maze->nodes[coord_1 + 1][coord_2].visited == 0){
                if (!detectWall(EAST)) {getDirection[EAST] = 1;}
		}

		// check if west has been visited
		if (maze->nodes[coord_1 - 1][coord_2].visited == 0){
                if (!detectWall(WEST)) {getDirection[WEST] = 1;}
		}

		// Intelligent turn ->
        if ((coord_2 < 8){
            if (getDirection[NORTH] == 1) {return NORTH;}
            if ((coord1 < 8) && (getDirection[EAST] == 1)){return EAST;}
            if (getDirection[SOUTH] == 1) {return SOUTH;}
            if ((getDirection[WEST] == 1)) {return WEST;}
        }

        if ((coord_2 >= 8) {
            if (getDirection[SOUTH] == 1) {return SOUTH;}
            if ((coord1 >= 8) && (getDirection[WEST] == 1)){return WEST;}
            if (getDirection[NORTH] == 1) {return NORTH;}
            if ((getDirection[EAST] == 1)) {return EAST;}
        }

        // Implements back-trace
        int a = x_stack.pop();
        int b = y_stack.pop();

        // assert(a == coord_1);
        // assert(b == coord_2);

        int x = coord_1 - x_stack.pop();
        int y = coord_2 - y_stack.pop();

        switch(x){
            case 1:
                return WEST;
            case -1:
                return EAST;
        }

        switch(y){
            case 1:
                return SOUTH;
            case -1:
                return NORTH;
        }
}
