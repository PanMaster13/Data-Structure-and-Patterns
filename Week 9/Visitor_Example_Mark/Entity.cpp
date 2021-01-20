#include "Entity.h"
#include "Visitor.h"

/*********************************************************************************/
/*Structure's Element Base Class AKA Interface Implementation*/
/*********************************************************************************/
Entity::Entity()
{
	fname = "";
	fhealth = 0;
	fdamage = 0;
	fpos.x = 0;
	fpos.y = 0;
}

Entity::Entity(string name, int health, int damage, Position pos)
{
	fname = name;
	fhealth = health;
	fdamage = damage;
	fpos = pos;
}

Entity::~Entity()					
{}

void Entity::SetName(string name)	
{	fname = name;	}

string Entity::GetName()			
{	return fname;	}

void Entity::Talk()
{
	cout << "Entity:" << fname;
	cout << " , H:" << fhealth;
	cout << ", D:" << fdamage;
	cout << ", Pos:(" << fpos.x;
	cout << "," << fpos.y << ")\n";
}

void Entity::Damaged(int adamage) 
{ fhealth -= adamage; }

void Entity::accept(Visitor& v)
{	
	v.Visit(*this);	
}


/*********************************************************************************/
/*Structure's Concrete Element AKA Derived Class Implementation*/
/*********************************************************************************/
Soldier::Soldier()
{
	fname = "";
	fhealth = 0;
	fdamage = 0;
	fpos.x = 0;
	fpos.y = 0;
}

Soldier::Soldier(string name, int health, int damage, Position pos)
{
	fname = name;
	fhealth = health;
	fdamage = damage;
	fpos = pos;
}

Soldier::~Soldier()					
{}

void Soldier::SetName(string name)	
{ fname = name;		}

string Soldier::GetName()			
{ return fname;		}

void Soldier::Talk()
{
	cout << "Soldier:" << fname;
	cout << " , H:" << fhealth;
	cout << ", D:" << fdamage;
	cout << ", Pos:(" << fpos.x;
	cout << "," << fpos.y << ")\n";
}

void Soldier::Damaged(int adamage)	
{ fhealth -= adamage;	}

void Soldier::accept(Visitor& v)	
{	v.Visit(*this);	}