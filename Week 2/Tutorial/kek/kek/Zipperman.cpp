#include <iostream>
#include "Zipperman.h"
using namespace std;

void Zipperman::howMove()
{
	numberOfLegs = 2;
	cout << "This Zipperman moves on " << numberOfLegs << " legs." << endl;
}
void Zipperman::howCall()
{
	cout << "The Zipperman goes ariariariariariariari!" << endl;
}