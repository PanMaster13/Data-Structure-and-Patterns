#include <iostream>
#include "Animal.h"
#include "Aerosmith.h"
#include "Zipperman.h"

using namespace std;

int main()
{
	Aerosmith aerosmith1;
	Zipperman zipperman1;

	Animal *animal1 = &aerosmith1;
	Animal *animal2 = &zipperman1;

	cout << "Using Direct calls: " << endl;

	aerosmith1.howMove();
	aerosmith1.howCall();
	zipperman1.howMove();
	zipperman1.howCall();

	cout << "\nUsing Animal pointers: " << endl;

	animal1->howMove();
	animal1->howCall();
	animal2->howMove();
	animal2->howCall();

	system("pause");
	return 0;
}