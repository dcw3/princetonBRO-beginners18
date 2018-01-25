/*
This module manages the maze navigation.
*/

#import "globals.h"

#define MAZE_SIZE 16

struct Node {
	int visited = 0;
}

typedef struct Node *Node_T;

struct Maze {
	Node_T nodes[MAZE_SIZE][MAZE_SIZE];
	// stack of path taken
	// TODO: install/import Arduino stack library
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
}

int getDirection(Maze_T maze, int coord_1, int coord_2) {
	// TODO: write code for this -> DONE


	// Assumption: robot starts from bottom right part of maze
		// check if north has been visited
		if (!maze->nodes[coord_1 - 1][coord_2].visited == 1){
                if detectWall(NORTH) {return NORTH;}
		}

		// check if south has been visited
		if (!maze->nodes[coord_1 + 1][coord_2].visited == 1){
                if detectWall(SOUTH) {return SOUTH;}
		}

		// check if east has been visited
		if (!maze->nodes[coord_1][coord_2 + 1].visited == 1){
                if detectWall(EAST) {return EAST;}
		}

		// check if west has been visited
		if (!maze->nodes[coord_1][coord_2 - 1].visited == 1){
                if detectWall(WEST) {return WEST;}
		}


}
