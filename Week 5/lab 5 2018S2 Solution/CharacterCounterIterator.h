#pragma once

#include "CharacterCounter.h"
#include "FrequencyMap.h"

class CharacterCounterIterator {
private:
	FrequencyMap fMaps[256];
	int fIndex;

public:
	CharacterCounterIterator(CharacterCounter& aCounter);
	CharacterCounterIterator(const CharacterCounterIterator& aCounterIt, int aIndex);
	// return current frequency map
	const FrequencyMap& operator*() const;
	CharacterCounterIterator& operator++(); // prefix
	CharacterCounterIterator operator++(int); // postfix (extra unused argument)
	bool operator==(const CharacterCounterIterator& aOther) const;
	bool operator!=(const CharacterCounterIterator& aOther) const;
	CharacterCounterIterator begin() const;
	CharacterCounterIterator end() const;
};