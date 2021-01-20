#include <iostream>
#include "CharacterCounter.h"
using namespace std;

int main()
{
	CharacterCounter lCounter;

	const int arraySize = 50;
	char str[arraySize];

	cout << "All 256 unsigned characters: " << endl;

	for (int i = 0; i < 256; i++)
	{
		cout << (unsigned char)i; //(unsigned char)i is the character sign of number "i" based on ASCII
	}

	cout << "\n" << endl;

	cout << "Enter a string: ";
	cin.getline(str, arraySize);
	cout << "You have entered: " << str << endl;

	lCounter.count(str);

	cout << lCounter;

	system("pause");
	return 0;
}