#include <iostream>
#include "Aerosmith.h"
using namespace std;

void Aerosmith::howMove()
{
	numberOfLegs = 0;
	cout << "This Aerosmith moves on " << numberOfLegs << " legs!" << endl;
}

void Aerosmith::howCall()
{
	cout << "The Aerosmith goes Pew Pew Pew!" << endl;
}