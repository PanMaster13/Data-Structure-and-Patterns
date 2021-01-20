#pragma once
#include <iostream>
#include "TreeVisitor.h"

using namespace std;

template<class T, int N>
class NTree
{
private:
	const T* fKey; // 0 for empty
	NTree <T, N>* fNodes[N]; // N subtrees of degree N
	NTree():fKey((T*)0)
	{
		for (int i = 0; i < N; i++)
		{
			fNodes[i] = &NIL;
		}
	}

public:
	static NTree<T, N> NIL; // sentinel

	NTree(const T& aKey);
	~NTree();

	bool isEmpty() const;
	const T& key() const;

	NTree& operator[](int aIndex) const;
	void attachNtree(int aIndex, NTree<T, N>* aNTree);
	NTree* detachNTree(int aIndex);
	void travereseDepthFirst(const TreeVisitor<T>& aVisitor) const;
};



template<class T, int N>
NTree<T, N>::NTree(const T& aKey) : fKey(&aKey)
{
	for (int i = 0; i < N; i++)
	{
		fNodes[i] = &NIL;
	}
}

template<class T, int N>
NTree<T, N>::~NTree()
{
	for (int i = 0; i < N; i++)
	{
		if (fNodes[i] != &NIL)
		{
			delete fNodes[i];
		}
	}
}

template<class T, int N>
bool NTree<T, N>::isEmpty() const
{
	return this == &NIL;
}

template<class T, int N>
const T& NTree<T, N>::key() const
{
	if (isEmpty())
		throw std::domain_error("Empty NTree");

	return *fKey;
}

template<class T, int N>
NTree<T, N>& NTree<T, N>::operator[](int aIndex) const
{
	if (isEmpty())
		throw std::domain_error("Empty NTree");

	return *fNodes[aIndex];
}

template<class T, int N>
void NTree<T, N>::attachNtree(int aIndex, NTree<T, N>* aNTree)
{
	if (aIndex > N)
		throw std::domain_error("Index doesn't match node size");

	fNodes[aIndex] = new NTree<T, N>(*aNTree);
}

template<class T, int N>
NTree<T, N>* NTree<T, N>::detachNTree(int aIndex)
{
	if (aIndex > N)
		throw std::domain_error("Index doesn't match node size");
	if (isEmpty())
		throw std::domain_error("Empty NTree");

	NTree<T, N>& Result = *fNodes[aIndex];
	fNodes[aIndex] = &NIL;

	return &Result;
}

template<class T, int N>
void NTree<T, N>::travereseDepthFirst(const TreeVisitor<T>& aVisitor) const
{
	if (!isEmpty())
	{
		aVisitor.preVisit(key());
		for (int i = 0; i < N; i++)
		{
			fNodes[i]->travereseDepthFirst(aVisitor);
		}
		aVisitor.postVisit(key());
	}
}

// Sentinel Node
template<class T, int N>
NTree<T, N> NTree<T, N>::NIL;
	