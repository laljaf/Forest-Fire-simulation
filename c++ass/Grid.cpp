#include "Grid.h"
#include <time.h>

ForestGrid::ForestGrid()
{
	//defines sizee
	size=gridHeight*gridWidth;

	//defining a 2d array to store data for the update
	copy = new int* [gridWidth];
	for (int i = 0; i < gridWidth; i++)
	{
		copy[i] = new int[gridWidth];
		
	}
	
	// creats an damp area of random size that doesn't exceed a quarter of the grid
	randomDamp = rand()%(size/4);

	//creates an array for the coordinates for the damp part of the grid
	dampXcoo = new int[randomDamp];
	dampYcoo = new int[randomDamp];
	for (int i = 0; i < randomDamp; i++)
	{
		//randomises the damp area coordinates
		xDamp = rand() % (gridWidth - 1) + 1;
		yDamp = rand() % (gridHeight - 1) + 1;
		dampXcoo[i] = xDamp;
		dampYcoo[i] = yDamp;

	}
	
}



void ForestGrid::initializeGrid(Cell emptyCell)

{
	// initialise the cell using an int parameter to define the size of the array for the cell
	emptyCell.initializeState(size);

	//shallow copying the data of the cell into a cell already declared 
	cell = emptyCell;
	
	//Sets random coordinates that aren't close to the boundary layer for the fire to start

	srand(time(NULL));

	
    xF = rand() % (gridWidth-2) + 2;
	yF = rand() % (gridHeight-2) + 2;

	for (y = 0; y < gridHeight; y++)
	{
		for (x = 0; x < gridWidth; x++)

		{
		
			//1-cell thick perimeter boundary layer of empty cells
			if ((y == 0) || (y == gridHeight - 1))
				cell.setCellEmpty(x, y);

            else if ((x == 0) || (x == gridWidth - 1))
             	cell.setCellEmpty(x, y);

			

			//sets the random cell on fire
			else if ((x == xF) && (y == yF))
               cell.setCellOnFire(x, y);
			
			//sets the rest of the grid with trees
			else
            	cell.setCellTree(x, y);

			// copies every state with its coordinate in a 2d array where it's stored
			copy[x][y] = cell.getCellState(x,y);

			//calls the output method(Cell class) and uses the copy array as a parameter for the output
			cout <<cell.output(copy[x][y]);

		}
		cout << endl;
	}
	cout << endl; cout << endl;

}

//method that returns whether there are still trees bruning or not 
bool ForestGrid:: returnBurningTrees()
{
	return burningTrees;
}


//method to define the new state of the cells
int ForestGrid::nextState()
{
	//boolean used to check 
	burningTrees = false;

	for (y = 0; y < gridHeight; y++)
	{
		for (x = 0; x < gridWidth; x++)

		{
			
			//1-cell thick perimeter boundary layer of empty cells
			if ((y == 0) || (y == gridHeight - 1))
			   newState = cell.getCellState(x,y);
            
			else if ((x == 0) || (x == gridWidth - 1))
             	newState = cell.getCellState(x,y);

			// sets up the rest of the grid
			else 
			{
				//a random probability for a tree to catch fire
				Probability = rand() % 100;

				// makes the probability smaller if x and y are equal to the coordinates of the damp area
				for (int i = 0; i < randomDamp; i++)
				{
					if ((x == dampXcoo[i]) && (y == dampYcoo[i]))
					{
						Probability = Probability / 2;
					}
                }
				
				//for an empty state the getCellstate returns a 0, for a tree state it returns a 1 for a burning state it returns a  5, this number is then used to define the type of
				//cells surrounding the main cell 
				neighboursCount = cell.getCellState(x+1, y) + cell.getCellState(x-1, y) + cell.getCellState(x, y+1) + cell.getCellState(x, y-1);

				
				//if neighbours count > 4 it means that at least one of the surrounding trees is burning and for an area to burn there have to be a tree there
				if (cell.getCellState(x, y) == cell.returnTree() && (neighboursCount > 4))
			
				{
					
					//50% probability for a tree to catch fire
					if (Probability >= 50)
					{
						newState = cell.returnBurning();
						burningTrees = true; //set up to true every time a tree is burning 
						
					}
					
					else if ((neighboursCount >= 10) && Probability >= 45) // if surrounded by 2 fires (2*5=10) 55% probability for a tree to catch fire
					{
						newState = cell.returnBurning();
						burningTrees = true;

					}
						else if ((neighboursCount >= 15) && Probability >= 40)  // if surrounded by 3 fires (3*5=15) 60% probability for a tree to catch fire
					{
						newState = cell.returnBurning();
						burningTrees = true;
					}
						else	if ((neighboursCount == 20) && Probability >= 30) // if surrounded by fire (4*5=20) 70% probability for a tree to catch fire
					{
						newState = cell.returnBurning();
						burningTrees = true;
					}
							
							
						
							else  //in the other case the cell stays the same
								newState= cell.getCellState(x,y);

					
				
				}

				else if (cell.getCellState(x, y) ==  cell.returnBurning()) //if the cell was burning previously it turns into an empty cell
				{
					
					newState = cell.returnEmpty();
					
				}

				else if ((neighboursCount >= 2) && (cell.getCellState(x, y) == cell.returnEmpty())&& Probability > 70) // if empty but surrounded by at least two trees then there's 30% probability a tree will spawn there
				{
					newState = cell.returnTree();
				}


				else  //in the other case the cell stays the same
					newState = cell.getCellState(x,y);
			}

			//stores the newState (update) in a 2d array copy[][] by copying it
			copy[x][y] = newState;
		}

	}cout << endl; cout << endl;
	return newState;
}


//method to output the state of the cells after the update
void ForestGrid::spreadFire()
{
	
	for (y = 0; y < gridHeight; y++)
	{
		for (x = 0; x < gridWidth; x++)

		{
			// takes in the data stored in the 2d array copy and puts it in a new array for the output
			cell.setCellState(copy[x][y],x,y) ;

			//outputs this new 2d array with the data from the copy[][] array
			cout << cell.output(copy[x][y]);
		}
		cout << endl;
	}
	cout << endl; cout << endl;
}




ForestGrid::~ForestGrid()
{
}