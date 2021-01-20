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
	//Creation of Viking and Thor objects that derived from the Unit Class
	Viking viking1("Player 1", AIR, 0002, 1, 1, 100, 100, 0, 0, 50, 50, PASSIVE);
	Thor thor1("Player 1", LAND, 0003, 5, 1, 250, 250, 0, 0, 75, 75, PASSIVE);

	//This outputs text in the console window
	cout << "Program Start" << endl;

	//Checking Thor object status
	cout << "\nThor 1 Status:" << endl;
	thor1.PingStatus();

	//Using Thor class' special function
	thor1.iniThorAtk();

	//Checking Viking object status
	cout << "\nViking 1 Status:" << endl;
	viking1.PingStatus();
	
	//This pauses the console window while waiting for any input
	system("pause");

	//This ends the program
	return 0;
}