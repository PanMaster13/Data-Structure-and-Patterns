#pragma once
#include <iostream>
#include <string>
#include "UnitCat.h"
#include "GameState.h"

using namespace std;

class Unit
{
protected:
	string fOwner;
	UnitCat fUnitCat;
	int fID;
	int fPosition[2];
	int fMaxHP;
	int fCurrentHP;
	int fMaxShield;
	int fCurrentShield;
	int fMaxEnergy;
	int fCurrentEnergy;
	GameState fGameState;
	string fMessage;

public:
	//Default Constructor
	Unit();

	//Overloaded Constructor
	Unit(string Owner, UnitCat UnitCat, int ID, int PositionX, int PositionY, int MaxHP, int CurrentHP, int MaxShield, int CurrentShield, int MaxEnergy, int CurrentEnergy, GameState GameState);
	
	//Getter and Setter for fOwner
	string getOwner();
	void setOwner(string value);

	//Getter and Setter for fUnitCat
	UnitCat getUnitCat();
	void setUnitCat(UnitCat value);

	//Getter and Setter for fID
	int getID();
	void setID(int value);

	//Getter and Setter for fPosition
	int getPosition(int index);
	void setPosition(int index, int value);

	//Getter and Setter for fMaxHP
	int getMaxHP();
	void setMaxHP(int value);

	//Getter and Setter for fCurrentHP
	int getCurrentHP();
	void setCurrentHP(int value);

	//Getter and Setter for fMaxShield
	int getMaxShield();
	void setMaxShield(int value);

	//Getter and Setter for fCurrentShield
	int getCurrentShield();
	void setCurrentShield(int value);

	//Getter and Setter for fMaxEnergy
	int getMaxEnergy();
	void setMaxEnergy(int value);

	//Getter and Setter for fCurrentEnergy
	int getCurrentEnergy();
	void setCurrentEnergy(int value);

	//Getter and Setter for fGameState
	GameState getGameState();
	void setGameState(GameState value);

	//Deconstructor
	~Unit();

	//Friend overload of Insertion Operator
	friend istream& operator>>(istream& aIstream, Unit& aUnit);

	//Friend overload of Extraction Operator
	friend ostream& operator<<(ostream& aOstream, Unit& aUnit);

	void PingStatus();
};