#pragma once
#include <iostream>

using namespace std;

class CharacterCounter
{
private:
	int fCharTotal;
	int fCharCounts[256];

public:
	CharacterCounter();

	void count(unsigned char str);

	friend ostream& operator<<(ostream& aOstream, const CharacterCounter& aCharacterCounter);

	int operator[](unsigned char aCharacter) const;
};