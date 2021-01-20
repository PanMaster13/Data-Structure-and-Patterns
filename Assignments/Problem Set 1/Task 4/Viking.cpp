#include <iostream>
#include "Viking.h"
using namespace std;

//Overloaded Constructor
Viking::Viking(string Owner, UnitCat UnitCat, int ID, int PositionX, int PositionY, int MaxHP, int CurrentHP, int MaxShield, int CurrentShield, int MaxEnergy, int CurrentEnergy, GameState GameState)
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

Viking::~Viking()
{}