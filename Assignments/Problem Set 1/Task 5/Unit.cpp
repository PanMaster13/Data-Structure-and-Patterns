#include <iostream>
#include "Unit.h"
using namespace std;

//Default Constructor
Unit::Unit()
{}

//Overloaded Constructor
Unit::Unit(string Owner, UnitCat UnitCat, int ID, int PositionX, int PositionY, int MaxHP, int CurrentHP, int MaxShield, int CurrentShield, int MaxEnergy, int CurrentEnergy, GameState GameState)
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

//Getter for fOwner
string Unit::getOwner()
{return fOwner;}

//Setter for fOwner
void Unit::setOwner(string value)
{fOwner = value;}

//Getter for fUnitCat
UnitCat Unit::getUnitCat()
{return fUnitCat;}

//Setter for fUnitCat
void Unit::setUnitCat(UnitCat value)
{fUnitCat = value;}

//Getter for fID
int Unit::getID()
{return fID;}

//Setter for fID
void Unit::setID(int value)
{fID = value;}

//Getter for fPosition
int Unit::getPosition(int index)
{return fPosition[index];}

//Setter for fPosition
void Unit::setPosition(int index, int value)
{fPosition[index] = value;}

//Getter for fMaxHP
int Unit::getMaxHP()
{return fMaxHP;}

//Setter for fMaxHP
void Unit::setMaxHP(int value)
{fMaxHP = value;}

//Getter for fCurrentHP
int Unit::getCurrentHP()
{return fCurrentHP;}

//Setter for fCurrentHP
void Unit::setCurrentHP(int value)
{fCurrentHP = value;}

//Getter for fMaxShield
int Unit::getMaxShield()
{return fMaxShield;}

//Setter for fMaxShield
void Unit::setMaxShield(int value)
{fMaxShield = value;}

//Getter for fCurrentShield
int Unit::getCurrentShield()
{return fCurrentShield;}

//Setter for fCurrentShield
void Unit::setCurrentShield(int value)
{fCurrentShield = value;}

//Getter for fMaxEnergy
int Unit::getMaxEnergy()
{return fMaxEnergy;}

//Setter for fMaxEnergy
void Unit::setMaxEnergy(int value)
{fMaxEnergy = value;}

//Getter for fCurrentEnergy
int Unit::getCurrentEnergy()
{return fCurrentEnergy;}

//Setter for fCurrentEnergy
void Unit::setCurrentEnergy(int value)
{fCurrentEnergy = value;}

//Getter for fGameState
GameState Unit::getGameState()
{return fGameState;}

//Setter for fGameState
void Unit::setGameState(GameState value)
{fGameState = value;}

//Deconstructor
Unit::~Unit()
{}

//Friend overload of Insertion Operator
istream& operator>>(istream& aIstream, Unit& aUnit)
{
	int input1; //Getting input on heal, damage or move option
	int input2; //Getting amount on heal, damage or movement

	cout << "\nSelect number to do perfrom actions on the unit" << endl;
	cout << "1. Heal unit	2. Damage unit	3. Move unit \nInput:";
	cin >> input1;

	if (input1 == 1)
	{
		cout << "Heal amount to unit:";
		cin >> input2;
		aUnit.fCurrentHP = aUnit.fCurrentHP + input2; //Increases the unit's HP

		//Checking if HP has gone over the maximum capacity
		if (aUnit.fCurrentHP > aUnit.fMaxHP)
		{
			cout << "\nThe unit's HP is at maximum capacity!" << endl;
			aUnit.fCurrentHP = aUnit.fMaxHP; //Sets current HP to match maximum HP
		}
	}

	else if (input1 == 2)
	{
		cout << "Damage amount to unit:";
		cin >> input2;

		//This is executed when shield is more than 0 (not broken)
		if (aUnit.fCurrentShield > 0)
		{ 
			aUnit.fCurrentShield = aUnit.fCurrentShield - input2; //Reduces the unit's shield

			//This is executed the moment the unit's shield goes below or is 0 (shield breaks)
			if (aUnit.fCurrentShield < 0) 
			{
				aUnit.fCurrentHP = aUnit.fCurrentHP + aUnit.fCurrentShield; //Reduces HP based on the damage amount remained
				aUnit.fCurrentShield = 0; //Sets shield to 0 (indicating its broken)
				cout << "\nThe unit's shield has been broken! OH NO!" << endl;
			}
		}

		//Only runs once shield is broken
		else
		{
			aUnit.fCurrentHP = aUnit.fCurrentHP - input2; //Reduces the unit's HP

			//This is executed when the unit's HP goes below 0 (the unit dies)
			if (aUnit.fCurrentHP <= 0)
			{
				cout << "\nThe unit has ceased to exist. This program will now terminate." << endl; //The program will end when the unit's HP is below 0
			}
		}
		
	}

	else if (input1 == 3)
	{
		cout << "Movement in X-axis:"; 
		cin >> input2;
		aUnit.fPosition[0] = aUnit.fPosition[0] + input2; //Adjusts the position of the unit in the X-axis

		cout << "Movement in Y-axis:";
		cin >> input2;
		aUnit.fPosition[1] = aUnit.fPosition[1] + input2; //Adjusts the position of the unit in the Y-axis
	}
	return aIstream;
}

//Friend overload of Extration Operator
ostream& operator<<(ostream& aOstream, Unit& aUnit)
{
	aOstream << aUnit.fMessage << endl;
	return aOstream;
}

//Prints out status of the Unit object
void Unit::PingStatus()
{
	cout << "ID:" << fID << " Owner:" << fOwner << " Position: X=" << fPosition[0] << " Y=" << fPosition[1] << " HP:" << fCurrentHP << " Shield:" << fCurrentShield << " Energy:" << fCurrentEnergy << endl;
}
