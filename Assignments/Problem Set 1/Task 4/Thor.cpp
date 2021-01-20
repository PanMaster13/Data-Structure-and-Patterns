#include <iostream>
#include "Thor.h"
using namespace std;

//Overloaded Constructor
Thor::Thor(string Owner, UnitCat UnitCat, int ID, int PositionX, int PositionY, int MaxHP, int CurrentHP, int MaxShield, int CurrentShield, int MaxEnergy, int CurrentEnergy, GameState GameState)
{
	fOwner = Owner;
	fUnitCat = UnitCat;
	fID = ID;
	fPosition[0] = PositionX;
	fPosition[1] = PositionY;
	fMaxHP = MaxHP;
	fCurrentHP = CurrentHP;
	fMaxShield = MaxShield;
	fCurrentShield = CurrentShield;
	fMaxEnergy = MaxEnergy;
	fCurrentEnergy = CurrentEnergy;
	fGameState = GameState;
}

void Thor::iniThorAtk()
{
	cout << "Thor initiated its attack *Pew Pew*" << endl;
}

Thor::~Thor()
{}