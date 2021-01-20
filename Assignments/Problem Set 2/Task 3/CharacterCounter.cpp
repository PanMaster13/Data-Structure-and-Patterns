#include "CharacterCounter.h"
#include <iostream>

using namespace std;

CharacterCounter::CharacterCounter()
{
	fCharTotal = 0;
	for (int x = 0; x < 256; x++)
	{
		fCharCounts[x] = 0;
	}
}

void CharacterCounter::count(unsigned char str)
{
	fCharCounts[str]++;
	fCharTotal++;
}

ostream& operator<<(std::ostream& aOStream, const CharacterCounter& aCharacterCounter)
{
	for (int x = 0; x < 256; x++)
	{
		if (aCharacterCounter.fCharCounts[x] != 0)
		{
			aOStream << (unsigned char)x << ":	" << aCharacterCounter.fCharCounts[x] << endl;
		}
	}
	aOStream << "Total Number of Characters: " << aCharacterCounter.fCharTotal << endl;
	return aOStream;
}

int CharacterCounter::operator[](unsigned char aCharacter) const
{
	return fCharCounts[aCharacter];
}