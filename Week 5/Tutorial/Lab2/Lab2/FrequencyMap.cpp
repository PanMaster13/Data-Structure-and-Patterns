#include "FrequencyMap.h"

FrequencyMap::FrequencyMap()
{}

FrequencyMap::FrequencyMap(char aChar, int aFrequency)
{
	fChar = aChar;
	fFrequency = aFrequency;
}

char FrequencyMap::getCharacter() const
{return fChar;}

int FrequencyMap::getFrequency() const
{return fFrequency;}