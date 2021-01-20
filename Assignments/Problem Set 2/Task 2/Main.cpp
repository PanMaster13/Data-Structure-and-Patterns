#include <iostream>
#include "CharacterCounter.h"
#include "SortedCharacterCounterIterator.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
	CharacterCounter lCounter;
	unsigned char lChar;
	
	ifstream lInput;
	string inputFilename = "CCinput.txt";

	lInput.open(inputFilename, ifstream::in);

	if (!lInput.good())
	{
		cout << "Cannot open input file: " << inputFilename << endl;
		return 2;
	}
	else
	{
		while (lInput >> lChar)
		{
			lCounter.count(lChar);
		}
		lInput.close();
	}

	ofstream lOutput;
	string outputFilename = "CCoutput.txt";

	lOutput.open(outputFilename, ofstream::out);

	if (!lOutput.good())
	{
		cout << "Cannot open output file: " << outputFilename << endl;
		lOutput.close();
		return 3;
	}
	else
	{
		lOutput << lCounter;
		lOutput.close();

		cout << "The frequencies: " << endl;
		for (SortedCharacterCounterIterator iter(lCounter); iter != iter.end(); iter++)
		{
			cout << (*iter).getCharacter() << ": " << (*iter).getFrequency() << endl;
		}
	}
	
	system("pause");
	return 0;
}