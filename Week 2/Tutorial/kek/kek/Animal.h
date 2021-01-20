#pragma once
#include <iostream>

using namespace std;

class Animal 
{
protected:
	int numberOfLegs = 0;

public:
	virtual void howMove();
	virtual void howCall() = 0;
};
