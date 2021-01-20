#pragma once
#include <iostream>

using namespace std;

class CharacterCounter
{
private:
	int fCharTotal; //to store the total number of characters in the char array
	int fCharCounts[256]; //We count all 256 byte values

public:
	CharacterCounter();

	void count(char* str);

	friend ostream& operator<<(std::ostream& aOStream, const CharacterCounter& aCharacterCounter);
};