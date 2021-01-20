#pragma once

template<class DataType>
class DoublyLinkedNode
{
public:
	typedef DoublyLinkedNode<DataType> Node;

private:
	DataType fValue;
	Node* fNext;
	Node* fPrevious;

	DoublyLinkedNode()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
	}

public:
	static Node NIL;

	DoublyLinkedNode(const DataType& aValue);

	void prepend(Node& aNode);
	void append(Node& aNode);
	void remove();

	const DataType getValue() const;
	const Node* getNext() const;
	const Node* getPrevious() const;
};

template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;



template<class DataType>
DoublyLinkedNode<DataType>::DoublyLinkedNode(const DataType& aValue)
{
	fValue = aValue;
	fNext = &NIL;
	fPrevious = &NIL;
}

template<class DataType>
void DoublyLinkedNode<DataType>::prepend(Node& aNode)
{
	//make this the forward pointer of aNode
	aNode.fNext = this;

	if (fPrevious != &NIL)
	{
		aNode.fPrevious = fPrevious;
		fPrevious->fNext = &aNode;
	}

	fPrevious = &aNode;
}

template<class DataType>
void DoublyLinkedNode<DataType>::append(Node& aNode)
{
	//Make this the backward pointer of aNode
	aNode.fPrevious = this;

	if (fNext != &NIL) // make this's forward pointer aNode's
	{
		aNode.fNext = fNext;

		fNext->fPrevious = &aNode; //pointer
	}

	fNext = &aNode;
}

template<class DataType>
void DoublyLinkedNode<DataType>::remove()
{
	if (fNext == &NIL)
	{
		fPrevious->fNext = &NIL;
	}
	else if (fPrevious == &NIL)
	{
		fNext->fPrevious = &NIL;
	}
	else
	{
		fPrevious->fNext = fNext;
		fNext->fPrevious = fPrevious;
	}

	//delete this; only if created in the heap
}

template<class DataType>
const DataType DoublyLinkedNode<DataType>::getValue() const 
{
	return fValue;
}

template<class DataType>
const DoublyLinkedNode<DataType>* DoublyLinkedNode<DataType>::getNext() const
{
	return fNext;
}

template<class DataType>
const DoublyLinkedNode<DataType>* DoublyLinkedNode<DataType>::getPrevious() const
{
	return fPrevious;
}