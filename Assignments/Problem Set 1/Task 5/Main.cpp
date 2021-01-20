#include <iostream>
#include <string>
#include "Unit.h"
#include "UnitCat.h"
#include "GameState.h"
#include "Thor.h"
#include "Viking.h"
using namespace std;

//This is a Main loop
int main()
{
	cout << "Program Start!" << endl;
	Unit unit1("Player 1", LAND, 0001, 1, 1, 100, 100, 50, 50, 50, 50, ACTIVE); //Creation of unit1 via overloaded constructor

	//The loop will keep occuring until the unit dies
	while (unit1.getCurrentHP() > 0)
	{ 
		cout << "\nUnit's current status: " << endl;
		unit1.PingStatus(); //Prints out the unit's current status
		cin >> unit1; //Insertion Operator
	}
	
	//This pauses the console window while waiting for any input
	system("pause");

	//This ends the program
	return 0;
}