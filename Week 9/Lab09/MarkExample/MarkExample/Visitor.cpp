#include "Visitor.h"
#include "Entity.h"

void Visitor::Visit(Entity& E)	
{}
void Visitor::Visit(Soldier& S) 
{}

void VisitorReport::Visit(Entity& E)	
{	
	E.Talk();	
}
void VisitorReport::Visit(Soldier& S)	
{	
	S.Talk();	
}


VisitorAttacked::VisitorAttacked(int adamage)
{
	fdamage = adamage;
}

void VisitorAttacked::Visit(Entity& E) 
{ 
	cout << "Damage " << E.GetName() <<": " << fdamage << endl;
	E.Damaged(fdamage);
}
void VisitorAttacked::Visit(Soldier& S) 
{ 
	cout << "Damage " << S.GetName() << ": " << fdamage << endl;
	S.Damaged(fdamage);
}

//My implementation
VisitorChangeName::VisitorChangeName(string _newName)
{
	newName = _newName;
}

void VisitorChangeName::Visit(Entity& E)
{
	E.SetName(newName);
	cout << "Entity's new name is " << newName << endl;
}

void VisitorChangeName::Visit(Soldier& S)
{
	S.SetName(newName);
	cout << "Soldier's new name is " << newName << endl;
}