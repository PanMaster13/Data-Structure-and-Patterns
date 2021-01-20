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
	SortedCharacterCounterIterator operator++(int);

	bool operator==(const SortedCharacterCounterIterator& aOther) const;
	bool operator!=(const SortedCharacterCounterIterator& aOther) const;

	SortedCharacterCounterIterator begin() const;
	SortedCharacterCounterIterator end() const;
};