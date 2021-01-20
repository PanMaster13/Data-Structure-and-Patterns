#include "CharacterCounter.h"
#include <iostream>
using namespace std;

CharacterCounter::CharacterCounter(void)
{
	fTotalNumberOfCharacters = 0;
	for (int i = 0; i < 256; i++)
	{
		fCharacterCounts[i] = 0;
	}
}

void CharacterCounter::count(unsigned char aCharacter)
{
	fCharacterCounts[aCharacter]++;
	fTotalNumberOfCharacters++;
}

std::ostream& operator<<(std::ostream& aOStream, const CharacterCounter& aCharacterCounter)
{
	for (int i = 0; i < 256; i++)
	{
		if (aCharacterCounter.fCharacterCounts[i] > 0)
		{
			aOStream << (unsigned char)i << ":\t" << aCharacterCounter.fCharacterCounts[i] << endl;

		}

	}

	return aOStream;
}

int CharacterCounter::operator[](unsigned char aCharacter) const
{
	return fCharacterCounts[aCharacter];
}