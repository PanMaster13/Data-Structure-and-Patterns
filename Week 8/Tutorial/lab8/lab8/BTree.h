#pragma once
#include <stdexcept>
#include "TreeVisitor.h"

template<class T>
class BTree {
private:
	const T* fKey;
	BTree <T>* fLeft;
	BTree <T>* fRight;
	BTree() :fKey((T*)0) //Shortcut way of fKey = (T*)0; inside constructor
	{
		fLeft = &NIL;
		fRight = &NIL;
	}
public:
	static BTree<T> NIL;

	BTree(const T& aKey) : fKey(&aKey) 
	{
		fLeft = &NIL;
		fRight = &NIL;
	}

	~BTree() 
	{
		if (fLeft != &NIL)
			delete fLeft;
		if (fRight != &NIL)
			delete fRight;
	}

	bool isEmpty() const
	{
		return this == &NIL;
	}

	const T& key() const 
	{
		if (isEmpty())
			throw std::domain_error("Empty BTree");
		return *fKey;
	}

	BTree& left() const 
	{
		if (isEmpty())
			throw std::domain_error("Empty BTree");
		return *fLeft;
	}

	BTree& right() const 
	{
		if (isEmpty())
			throw std::domain_error("Empty BTree");
		return *fRight;
	}

	void attachLeft(BTree<T>* aBTree) 
	{
		if (isEmpty())
			throw std::domain_error("Empty BTree");
		if (fLeft != &NIL)
			throw std::domain_error("Non-empty sub tree");
		fLeft = new BTree<T>(*aBTree);//makes allocation on heap
	}

	void attachRight(BTree<T>* aBTree) 
	{
		if (isEmpty())
			throw std::domain_error("Empty BTree");
		if (fRight != &NIL)
			throw std::domain_error("Non-empty sub tree");
		fRight = new BTree<T>(*aBTree);//makes allocation on heap
	}

	BTree* detachLeft() 
	{
		if (isEmpty())
			throw std::domain_error("Empty BTree");
		BTree<T>& Result = *fLeft; //changed to pointer variable
		fLeft = &NIL;
		return &Result;
	}

	BTree* detachRight() 
	{
		if (isEmpty())
			throw std::domain_error("Empty BTree");
		BTree<T>& Result = *fRight; //changed to pointer variable
		fRight = &NIL;
		return &Result;
	}

	void transverseDepthFirst(const TreeVisitor<T>& aVisitor) const 
	{
		if (!isEmpty()) 
		{
			aVisitor.preVisit(key());
			left().transverseDepthFirst(aVisitor);
			aVisitor.inVisit(key());
			right().transverseDepthFirst(aVisitor);
			aVisitor.postVisit(key());
		}
	}
};

template<class T>
BTree<T> BTree<T>::NIL;