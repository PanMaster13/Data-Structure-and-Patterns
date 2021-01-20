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

		// Demonstration of bidirectional iterator.
		SortedCharacterCounterIterator iter(lCounter);

		cout << "The frequencies in decending order" << endl;
		cout << "Going from first to last" << endl;

		// Going from first to last.
		for (iter; iter != iter.end(); iter++)
		{
			cout << (*iter).getCharacter() << ": " << (*iter).getFrequency() << endl;
		}

		cout << "Going from last to first" << endl;
		// Because the previous loop ends at nullptr, this is required to redirect to actual last value.
		iter--;

		for (iter; iter != iter.begin(); iter--)
		{
			cout << (*iter).getCharacter() << ": " << (*iter).getFrequency() << endl;
		}
		// The last value is not printed because it is the outcome of iter.begin().
		// So it has to be printed outside the loop.
		cout << (*iter).getCharacter() << ": " << (*iter).getFrequency() << endl;
	}

	system("pause");
	return 0;
}