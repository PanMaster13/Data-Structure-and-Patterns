#include <iostream>
#include <fstream>
#include <string>
#include "Caesar.h"

using namespace std;

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	Caesar julius;
	
	inputFile.open("CaesarInput.txt");
	outputFile.open("CaesarOutput.txt");

	//Error checking
	if (inputFile.fail())
	{
		cout << "Input file can't be opened!" << endl;
		system("pause");
		return 1;
	}

	//Error checking
	if (outputFile.fail())
	{
		cout << "Output file can't be opened!" << endl;
		system("pause");
		return 2;
	}
	
	julius.shiftByFour(inputFile, outputFile);

	cout << julius;

	inputFile.close();
	outputFile.close();

	system("pause");
	return 0;
}