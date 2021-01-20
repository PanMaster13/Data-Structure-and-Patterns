#include <iostream>
#include <fstream>
#include <string>
#include "Caesar.h"

using namespace std;

Caesar::Caesar()
{
	for (int i = 0; i < 26; i++)
	{
		fCharFreqBefore[i] = 0;
		fCharFreqAfter[i] = 0;
	}
}

void Caesar::shiftByFour(ifstream& aInput, ofstream& aOutput)
{
	string inputTextLine = "";
	string outputTextLine = "";
	bool isLowerCase = false;
	char c;


	cout << endl << "Before Caesar Shift";
	cout << endl << "------------------" << endl;
	//Getline returns true until there is no stuff in file, then returns false thus closing the while loop
	while (getline(aInput, inputTextLine))
	{
		cout << inputTextLine << endl;
		for (int x = 0; x < inputTextLine.length(); x++)
		{
			c = inputTextLine[x];

			//Is alphabat
			if (isalpha(c))
			{
				//Is lower case
				if (islower(c))
				{
					isLowerCase = true;
				}

				//Changes character to upper case
				c = toupper(c);
				fCharFreqBefore[(c - 'A')]++;

				//Formula from pdf file
				c = 'A' + ((c - 'A' + 4) % 26);

				fCharFreqAfter[(c - 'A')]++;

				if (isLowerCase)
				{
					//Changes to lower case
					c = tolower(c);
					isLowerCase = false;
				}
			}
			outputTextLine += c;
		}
		outputTextLine += "\n";
	}

	cout << endl << "After Caesar Shift";
	cout << endl << "------------------" << endl;
	cout << outputTextLine << endl;
	aOutput << outputTextLine;
}

ostream& operator<<(ostream& aOStream, const Caesar& aObject)
{
	aOStream << "Character Frequency Counter (before, after)" << endl;

	for (int i = 0; i < 26; i++)
	{
		aOStream << (unsigned char)(i + 'A') << ":" << aObject.fCharFreqBefore[i] << ", " << aObject.fCharFreqAfter[i] << endl;
	}

	return aOStream;
}