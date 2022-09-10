#include "Cell.h"
Cell::Cell()
{

//constructor

}



//returns the state of the cell in the positiong giving by the parameters (coordinates)
int Cell::getCellState(int xPosition, int yPosition)
{
	x = xPosition;
	y = yPosition;

	return stateInPosition[x][y];
}

//initializes the cell 
void Cell:: initializeState(int size)
{

	//creates a 2d array to store the state of the array according to its coordinates
	stateInPosition = new int* [size];
	for (int i = 0; i < size; i++)
		stateInPosition[i] = new int[size];


}



// 3 methods to return a state for a comparison
int Cell::returnEmpty()
{
	return empty;
}

int Cell::returnTree()
{
	return tree;
}

int Cell::returnBurning()
{
	return burning;
}



//sets the state of a cell in specific coordinates
int Cell::setCellState(int state, int Xpos,int Ypos)
{
	
	x = Xpos;
	y = Ypos;
	stateInPosition[x][y] = state;

	return stateInPosition[x][y];
}



//sets a cell to burn in specific coordinates 
int Cell::setCellOnFire(int xPosition, int yPosition)
{
	x = xPosition;
	y = yPosition;
	
	stateInPosition[x][y] = burning;
	return stateInPosition[x][y];

}



//set the state of a cell to empty in specific coordinates
int Cell::setCellEmpty(int xPosition, int yPosition) //makes the cell empty at the spot xpositon, yposition
{
	x = xPosition;
	y = yPosition;

	stateInPosition[x][y] = empty;
	return stateInPosition[x][y];

}

//set the state of a cell to tree in specific coordinates
int Cell::setCellTree(int xPosition, int yPosition) //adds a tree at the spot xpositon, yposition
{
	x = xPosition;
	y = yPosition;
	stateInPosition[x][y] = tree;
	return stateInPosition[x][y];

}


// for the output on the console
char Cell::output(int state)
{
	if (state == tree)
	{
		stateOutput = '@';
	}
	else if (state == burning)
	{
		stateOutput = '!';
	}

	else
	{
		stateOutput = '#';
	}
	return stateOutput;
}


Cell::~Cell()
{
}