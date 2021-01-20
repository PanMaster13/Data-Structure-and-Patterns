#include "SortedCharacterCounterIterator.h"

//Sorting will be done in the constructor
SortedCharacterCounterIterator::SortedCharacterCounterIterator(CharacterCounter& aCounter)
{
	int i, j, max_index; //Values used for sorting algorithm
	FrequencyMap temp; //Value used for swapping part in sorting algorithm
	fIndex = 0;

	for (int x = 0; x < 256; x++)
	{
		fMaps[x] = FrequencyMap(x, aCounter[x]);
	}

	//Sorting algorithm (Selection Sort)
	for (i = 0; i < 256-1; i++)
	{
		max_index = i;

		for (j = i + 1; j < 256; j++)
		{
			if (fMaps[j].getFrequency() > fMaps[max_index].getFrequency())
			{
				max_index = j;
			}
		}
		//Swapping of Values
		temp = fMaps[max_index];
		fMaps[max_index] = fMaps[i];
		fMaps[i] = temp;
	}

	for (int x = 0; x < 256; x++)
	{
		if (fMaps[x].getFrequency() > 0)
		{
			fIndex = x;
			break;
		}
	}
}

SortedCharacterCounterIterator::SortedCharacterCounterIterator(const SortedCharacterCounterIterator& aCounterIt, int aIndex)
{
	fIndex = aIndex;

	for (int i = 0; i < 256; i++)
	{fMaps[i] = aCounterIt.fMaps[i];}
}

const FrequencyMap& SortedCharacterCounterIterator::operator*() const
{
	return fMaps[fIndex];
}

SortedCharacterCounterIterator& SortedCharacterCounterIterator::operator++()
{
	fIndex++;
	while (fMaps[fIndex].getFrequency() == 0)
	{fIndex++;}

	return *this;
}

SortedCharacterCounterIterator SortedCharacterCounterIterator::operator++(int)
{
	SortedCharacterCounterIterator temp = *this;

	++(*this);

	return temp;
}

bool SortedCharacterCounterIterator::operator==(const SortedCharacterCounterIterator& aOther) const
{
	return (fIndex == aOther.fIndex);
}

bool SortedCharacterCounterIterator::operator!=(const SortedCharacterCounterIterator& aOther) const
{
	return !(fIndex == aOther.fIndex);
}

SortedCharacterCounterIterator SortedCharacterCounterIterator::begin() const
{
	for (int i = 0; i < 256; i++)
	{
		if (fMaps[i].getFrequency() > 0)
			return SortedCharacterCounterIterator(*this, i);
	}

	return *this;
}

SortedCharacterCounterIterator SortedCharacterCounterIterator::end() const
{
	return SortedCharacterCounterIterator(*this, 256);
}