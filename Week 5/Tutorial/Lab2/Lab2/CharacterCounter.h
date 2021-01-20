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

	//Changed in lab5 (From char* str to unsigned char aCharacter)
	void count(unsigned char str);

	friend ostream& operator<<(std::ostream& aOStream, const CharacterCounter& aCharacterCounter);

	int operator[](unsigned char aCharacter) const;
};