#pragma once
#include<iostream>
#include<random>

using namespace std;

class Cell
{
public:

	Cell();

	int setCellState(int state, int Xpos, int Ypos);
	
	int getCellState(int x, int y);
	void initializeState(int size);
	char output(int state);

	int setCellOnFire(int xposition, int yPosition);
	int setCellEmpty(int xposition, int yPosition);
	int setCellTree(int xposition, int yPosition);

	int returnTree();
	int returnBurning();
	int returnEmpty();
	~Cell();

private:
	int* cell;
	int x, y;
	int** stateInPosition;
	
	int cellState;

	int size;
	char stateOutput;

	int empty = 0;
	int tree = 1;
	int burning = 5;

	
};

