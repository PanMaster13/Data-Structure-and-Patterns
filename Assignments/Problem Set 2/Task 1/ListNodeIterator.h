#pragma once
#include "ListNodeTemplate.h"

template<class T>
class ListNodeIterator
{
private:
	ListNode<T>* fNode;

public:
	typedef ListNodeIterator<T> Iterator;
	ListNodeIterator(ListNode<T>* aNode);
	const T& operator*() const;
	Iterator& operator++();
	Iterator operator++(int);
	bool operator==(const Iterator& aOther) const;
	bool operator!=(const Iterator& aOther) const;
	Iterator end();
};

//Implementation done here due to template class reasons

template<class T>
ListNodeIterator<T>::ListNodeIterator(ListNode<T>* aNode)
{
	fNode = aNode;
}

template<class T>
const T & ListNodeIterator<T>::operator*() const
{
	return fNode->fData;
}

template<class T>
typename ListNodeIterator<T>::Iterator & ListNodeIterator<T>::operator++()
{
	fNode = fNode->fNext;

	return (*this);
}

template<class T>
typename ListNodeIterator<T>::Iterator ListNodeIterator<T>::operator++(int)
{
	ListNode<T> temp = fNode;
	++(*this);

	return temp;
}

template<class T>
bool ListNodeIterator<T>::operator==(const Iterator & aOther) const
{
	return (fNode == aOther.fNode);
}

template<class T>
bool ListNodeIterator<T>::operator!=(const Iterator & aOther) const
{
	return !(fNode == aOther.fNode);
}

template<class T>
typename ListNodeIterator<T>::Iterator ListNodeIterator<T>::end()
{
	return (nullptr); //The end of an iterator is a null value
}
