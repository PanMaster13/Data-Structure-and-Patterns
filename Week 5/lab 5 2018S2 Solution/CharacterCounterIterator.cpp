#include "CharacterCounterIterator.h"
#include "FrequencyMap.h"
#include <iostream>
using namespace std;

CharacterCounterIterator::CharacterCounterIterator(CharacterCounter& aCounter)
{
	fIndex = 0;
	for (int i = fIndex; i< 256; i++)
	{
		fMaps[i] = FrequencyMap(i, aCounter[i]);
	}
	for (int i = 0; i < 256; i++)
	{
		if (fMaps[i].getFrequency() > 0)
		{
			fIndex = i;//position the iterator at the first character with non-zero count.
			break;
		}
	}
}
CharacterCounterIterator::CharacterCounterIterator(const CharacterCounterIterator& aCounterIt, int aIndex)
{
	for (int i = aIndex; i< 256; i++)
	{
		fMaps[i] = aCounterIt.fMaps[i];
	}
	fIndex = aIndex;
}

// return current frequency map
const FrequencyMap& CharacterCounterIterator:: operator*() const
{
	return fMaps[fIndex];
}
CharacterCounterIterator& CharacterCounterIterator:: operator++() // prefix
{
	fIndex++;
	while (fMaps[fIndex].getFrequency() == 0)
		fIndex++;

	return *this;
}
CharacterCounterIterator CharacterCounterIterator:: operator++(int) // postfix (extra unused argument)
{
	CharacterCounterIterator temp = *this;
	++(*this);
	return temp;
}

bool CharacterCounterIterator:: operator==(const CharacterCounterIterator& aOther) const
{
	return (fIndex == aOther.fIndex);
}
bool CharacterCounterIterator:: operator!=(const CharacterCounterIterator& aOther) const
{
	return !(*this == aOther);
}
CharacterCounterIterator CharacterCounterIterator::begin() const
{
	for (int i = 0; i<256; i++)
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





