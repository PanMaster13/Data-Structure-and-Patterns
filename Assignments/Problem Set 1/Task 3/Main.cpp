#include <iostream>
#include <string>
#include "Unit.h"
#include "UnitCat.h"
#include "GameState.h"
using namespace std;

//This is a Main loop
int main()
{
	//Creation of Unit object "Drone" via overloaded Constructor
	Unit Drone("Player 1", LAND, 0001, 0, 0, 100, 100, 50, 50, 30, 30, ACTIVE);

	//This outputs text in the console window
	cout << "Program Start" << endl;

	//Usage of "PingStatus" function
	Drone.PingStatus();

	//Usage of Insertion Operator
	cin >> Drone;

	//Usage of Extraction Operator
	cout << Drone;

	//This pauses the console window while waiting for any input
	system("pause");

	//This ends the program
	return 0;
}