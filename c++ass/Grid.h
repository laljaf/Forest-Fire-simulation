#pragma once
#include<iostream>
#include<random>
#include <string>
#include"Cell.h"


using namespace std;

class ForestGrid : public Cell
{


public:
	ForestGrid();
	void initializeGrid(Cell emptyCell);
	int getState(int xPosition, int yPosition);
	void spreadFire();
	int nextState();
	bool returnBurningTrees();
	


	~ForestGrid();

private:
	int size;

	//grid sizes
	int gridWidth = 21;
	int gridHeight = 21;

	int* dampXcoo;
	int* dampYcoo;
	int xDamp;
	int yDamp;
	int randomDamp;

	int xF;
	int yF;

	int neighboursCount;
	int newState = 0;
	
	
	int x, y;
	int** copy;
	int Probability;
	Cell cell;
	bool burningTrees = true;

	

};

