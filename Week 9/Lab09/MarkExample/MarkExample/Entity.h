#pragma once
#include <iostream>
#include <string>
using namespace std;

//Utility struct for Entity Position
struct Position
{	int x, y;	};

//Forward Declaration
class Visitor;

//Data Structure's Element Interface.
class Entity
{
protected:
	string fname;
	int fhealth;
	int fdamage;
	Position fpos;

public:
	Entity();
	Entity(string name, int health, int damage, Position pos);
	~Entity();

	virtual void SetName(string name);
	virtual string GetName();
	virtual void Talk();
	virtual void Damaged(int adamage);

	//Required for Visitor Pattern to work.
	virtual void accept(Visitor& v);
};


//Example Concrete Element - derived from the Entity base class.
class Soldier : public Entity
{
public:
	Soldier();
	Soldier(string name, int health, int damage, Position pos);
	~Soldier();

	void SetName(string name);
	string GetName();
	void Talk();
	virtual void Damaged(int adamage);

	//Remember to implement this.
	void accept(Visitor& v);
};