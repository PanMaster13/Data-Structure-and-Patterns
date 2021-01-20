#pragma once
#include <iostream>
#include <string>
#include "Entity.h"
#include "Visitor.h"

using namespace std;

int main()
{
	//First, set up all your handles.
	Position pos;
	Entity* One = nullptr;
	Visitor* V = nullptr;

	//Then, begin instantiation your Entity objects.
	pos.x = 10;
	pos.y = 10;
	One = new Soldier("Mr.X", 100, 10, pos);

	//Depending on what you want to do, apply the appropriate Visitors.
	V = new VisitorReport();
	One->accept(*V);
	delete V; 
	V = nullptr;

	V = new VisitorAttacked(20);
	One->accept(*V);
	delete V;
	V = nullptr;

	V = new VisitorReport();
	One->accept(*V);
	delete V;
	V = nullptr;

	//My implementation
	V = new VisitorChangeName("Dio");
	One->accept(*V);
	delete V;
	V = nullptr;

	V = new VisitorReport();
	One->accept(*V);
	delete V;
	V = nullptr;

	V = new VisitorAttacked(80);
	One->accept(*V);
	delete V;
	V = nullptr;

	V = new VisitorReport();
	One->accept(*V);
	delete V;
	V = nullptr;

	//When you are all done, remember to release memory.
	if(One!= nullptr)
		delete One;
	if (V != nullptr)
		delete V;

	//Goodbye
	system("pause");
	return 0;
}