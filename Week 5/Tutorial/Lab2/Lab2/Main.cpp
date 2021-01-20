#include "CharacterCounter.h"
#include "CharacterCounterIterator.h"
#include <iostream>
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
		cerr << "Cannot open input fie: " << inputFilename << endl;
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
		cerr << "Cannot open output file: " << outputFilename << endl;
		lOutput.close();
		return 3;
	}
	else
	{
		lOutput << lCounter;
		lOutput.close();

		//Testing the iterator
		cout << "The frequencies: " << endl;
		for (CharacterCounterIterator iter(lCounter); iter != iter.end(); iter++)
		{
			cout << (*iter).getCharacter() << ": " << (*iter).getFrequency() << endl;
		}

	}

	system("pause");
	return 0;
}