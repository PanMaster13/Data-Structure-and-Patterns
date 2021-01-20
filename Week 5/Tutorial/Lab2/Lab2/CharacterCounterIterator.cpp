#include "CharacterCounterIterator.h"

CharacterCounterIterator::CharacterCounterIterator(CharacterCounter& aCounter)
{
	fIndex = 0;

	//Initialise elements in the frequencymap array fMaps
	for (int i = 0; i < 256; i++)
	{
		fMaps[i] = FrequencyMap(i, aCounter[i]);
	}

	for (int i = 0; i < 256; i++)
	{
		if (fMaps[i].getFrequency() > 0)
		{
			fIndex = i; //Save the position of the first character with non-zero count
			break;
		}
	}
}

CharacterCounterIterator::CharacterCounterIterator(const CharacterCounterIterator &aObj)
{
	for (int i = 0; i < 256; i++)
	{
		fMaps[i] = aObj.fMaps[i];
	}
	fIndex = aObj.fIndex;
}

CharacterCounterIterator::CharacterCounterIterator(const CharacterCounterIterator &aObj, int aIndex)
{
	fIndex = aIndex;
	for (int i = 0; i < 256; i++)
	{
		fMaps[i] = aObj.fMaps[i];
	}
}

const FrequencyMap& CharacterCounterIterator::operator*() const
{
	return fMaps[fIndex];
}

CharacterCounterIterator & CharacterCounterIterator::operator++()
{
	fIndex++;
	while (fMaps[fIndex].getFrequency() == 0)
	{
		fIndex++;
	}

	return *this; //Return itself
}

CharacterCounterIterator CharacterCounterIterator::operator++(int)
{
	CharacterCounterIterator temp = *this;

	++(*this); //This refers to itself

	return temp;
}

bool CharacterCounterIterator::operator==(const CharacterCounterIterator & aOther) const
{
	return (fIndex == aOther.fIndex); //If statement inside return statement (True or False)
}

bool CharacterCounterIterator::operator!=(const CharacterCounterIterator & aOther) const
{
	return !(*this == aOther); //If statement inside return statement (True or False)
}

CharacterCounterIterator CharacterCounterIterator::begin() const
{
	for (int i = 0; i < 256; i++)
	{
		if (fMaps[i].getFrequency() > 0)
			return CharacterCounterIterator(*this, i);
	}

	return *this;
}

CharacterCounterIterator CharacterCounterIterator::end() const
{
	return CharacterCounterIterator(*this, 256);
}

