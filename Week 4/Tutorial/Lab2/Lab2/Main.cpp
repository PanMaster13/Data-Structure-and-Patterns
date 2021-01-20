#include <iostream>
#include <fstream>
#include <string>
#include "CharacterCounter.h"
using namespace std;

int main()
{
	CharacterCounter lCounter;
	fstream myFile;
	string sentence;

	myFile.open("CCinput.txt"); //Opening the file

	//Checking if file is opened successfully or not
	if (myFile.fail())
	{
		cout << "Error, desired file not found!" << endl;
		system("pause");
		return 2;
	}
	getline(myFile, sentence);
	cout << "The file input reads: " << sentence << endl;

	//Closes the file
	myFile.close();

	//Converts string into char array
	char c_sentence[50];
	strcpy_s(c_sentence, sentence.c_str());

	lCounter.count(c_sentence);
	cout << lCounter;

	//Output file
	ofstream outputFile;
	outputFile.open("outputFile.txt");
	if (outputFile.fail())
	{
		cout << "Error, desired file not found!" << endl;
		system("pause");
		return 3;
	}
	outputFile << lCounter;
	
	outputFile.close();

	system("pause");
	return 0;
}