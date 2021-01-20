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

void CharacterCounter::count(char *str)
{
	for (int x = 0; x < 256; x++)
	{
		for (int y = 0; y < 50; y++)
		{
			if (((unsigned char)x == str[y]) && ((unsigned char)x != NULL)) //To not count the NULL character in ASCII
			{
				fCharTotal++;
				fCharCounts[x]++;
			}
		}
	}
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