#include"Grid.h"


int main()
{

	ForestGrid* forest = new ForestGrid;
	Cell emptyCell;
	char key;
	bool leave = false;

	cout << "Press Any Key to start the simulation or L to leave:";
	key=getchar();
	cout << endl << endl;

	if (toupper(key) == 'L')
	{
		leave = true;
	}
	//initializes the grid according to the ForestGrid method
	forest->initializeGrid(emptyCell);
	cout << endl; 
	while (leave== false)
	{
		forest->nextState();
		
		cout << "Press Any Key to continue the simulation or L to leave:";
		key = getchar();
		if (toupper(key) == 'L' || forest->returnBurningTrees() == false)
		{
			leave = true;
		}
		forest->spreadFire();
		
	}
	cout << endl << endl;
	cout << "End of simulation";
	cout << endl << endl;
	
	


	
}