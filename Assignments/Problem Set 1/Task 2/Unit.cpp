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
