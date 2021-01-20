#pragma once
#include <iostream>
#include <string>
#include "UnitCat.h"
#include "GameState.h"
#include "Unit.h"

using namespace std;

class Thor : public Unit
{
//Since it inherits the Unit class, it also has its attributes
public:
	//Overloaded Constructor
	Thor(string Owner, UnitCat UnitCat, int ID, int PositionX, int PositionY, int MaxHP, int CurrentHP, int MaxShield, int CurrentShield, int MaxEnergy, int CurrentEnergy, GameState GameState);

	void iniThorAtk();

	//Destructor
	~Thor();
};