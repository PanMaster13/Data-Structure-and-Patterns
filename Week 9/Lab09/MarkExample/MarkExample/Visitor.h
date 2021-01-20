#pragma once
#include <iostream>
#include <string>
using namespace std;

//Forward Declarations
class Entity;
class Soldier;

//The Visitor Interface
class Visitor
{
public:
	virtual void Visit(Entity& E);
	virtual void Visit(Soldier& S);
};

//Example Concrete Visitor Class: VisitorReport
//Pokes the element to talk about itself.
class VisitorReport : public Visitor
{
public:
	virtual void Visit(Entity& E);
	virtual void Visit(Soldier& S);
};

//Example Concrete Visitor Class: VisitorAttacked
//Incur an amount of damage to the element.
class VisitorAttacked : public Visitor
{
private:
	int fdamage;
public:
	VisitorAttacked(int adamage);
	virtual void Visit(Entity& E);
	virtual void Visit(Soldier& S);
};

//My implementation
class VisitorChangeName : public Visitor
{
private:
	string newName;
public:
	VisitorChangeName(string _newName);
	virtual void Visit(Entity& E);
	virtual void Visit(Soldier& S);
};