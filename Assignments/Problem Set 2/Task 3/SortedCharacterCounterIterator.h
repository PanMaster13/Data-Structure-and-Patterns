#pragma once
#include "CharacterCounter.h"
#include "FrequencyMap.h"

class SortedCharacterCounterIterator
{
private:
	FrequencyMap fMaps[256];
	int fIndex;

public:
	SortedCharacterCounterIterator(CharacterCounter& aCounter);

	SortedCharacterCounterIterator(const SortedCharacterCounterIterator& aCounterIt, int aIndex);

	const FrequencyMap& operator*() const;
	SortedCharacterCounterIterator& operator++();
	SortedCharacterCounterIterator& operator--(); //New Function for Task 3
	SortedCharacterCounterIterator operator++(int);
	SortedCharacterCounterIterator operator--(int); //New Function for Task 3

	bool operator==(const SortedCharacterCounterIterator& aOther) const;
	bool operator!=(const SortedCharacterCounterIterator& aOther) const;

	SortedCharacterCounterIterator begin() const;
	SortedCharacterCounterIterator end() const;
};