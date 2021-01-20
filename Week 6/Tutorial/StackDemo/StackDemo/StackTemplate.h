#pragma once

template <class T>
class StackTemplate
{
private:
	T* fElements;
	int fStackPointer;
	int fStackSize;

public:
	StackTemplate(int aSize);
	~StackTemplate();

	bool isEmpty() const;
	int size() const;
	void push(const T& aItem);
	void pop();
	const T& top() const;
};

template <class T>
StackTemplate<T>::StackTemplate(int aSize)
{
	if (aSize <= 0)
	{
		std::cout << "Illegal stack size." << std::endl;
	}
	else
	{
		fElements = new T[aSize];
		fStackPointer = 0;
		fStackSize = aSize;
	}
}

template <class T>
StackTemplate<T>::~StackTemplate()
{
	delete[] fElements; //Special delete operator for arrays.
}

template <class T>
bool StackTemplate<T>::isEmpty() const
{
	return fStackPointer == 0;
	// Returns 1 for true, 0 for false
}

template <class T>
int StackTemplate<T>::size() const
{
	return fStackSize;
}

template <class T>
void StackTemplate<T>::push(const T& aItem)
{
	if (fStackPointer < fStackSize)
	{
		fElements[fStackPointer++] = aItem;
	}
	else
	{
		std::cout << "Stack is full." << std::endl;
	}
}

template <class T>
void StackTemplate<T>::pop()
{
	if (!isEmpty())
	{
		fStackPointer--;
	}
	else
	{
		std::cout << "Stack is empty." << std::endl;
	}
}

template <class T>
const T& StackTemplate<T>::top() const
{
	if (!isEmpty())
	{
		return fElements[fStackPointer - 1];
	}
	else
	{
		std::cout << "Stack is empty." << std::endl;
	}
}