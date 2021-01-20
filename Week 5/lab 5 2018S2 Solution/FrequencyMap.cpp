#include "FrequencyMap.h"

FrequencyMap::FrequencyMap(void)
{
	//do nothing
}

FrequencyMap::FrequencyMap(char aChar, int aFrequency)
{
	fChar = aChar;
	fFrequency = aFrequency;
}

char FrequencyMap::getCharacter() const
{
	return fChar;
}

int FrequencyMap::getFrequency() const
{
	return fFrequency;
}