#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal() 
{
	cout << "Animal Constructor" << endl;
}

void Animal::callName()
{
	cout << "My name is Animal" << endl;
}

void Animal::callSound()
{
	cout << "Your next line is, ..." << endl;
}

Animal::~Animal()
{
	cout << "Animal Deconstructor" << endl;
}