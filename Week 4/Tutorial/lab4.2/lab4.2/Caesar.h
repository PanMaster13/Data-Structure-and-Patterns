#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Caesar
{
private:
	int fCharFreqBefore[26];
	int fCharFreqAfter[26];

public:
	Caesar();

	void shiftByFour(ifstream& aInput, ofstream& aOutput);

	friend ostream& operator<<(ostream& aOStream, const Caesar& aObject);
};