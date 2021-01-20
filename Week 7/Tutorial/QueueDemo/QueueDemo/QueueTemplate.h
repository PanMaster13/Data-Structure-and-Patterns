#pragma once
#include <list>

using namespace std;

template <class T>
class Queue
{
private:
	list<T> fElements;

public:
	Queue();
	bool isEmpty() const;
	int size() const;
	void enqueue(const T& aElement);
	const T& dequeue();
};

template <class T>
Queue<T>::Queue()
{}

template <class T>
bool Queue<T>::isEmpty() const
{
	
}

template <class T>
int Queue<T>::size() const
{

}

template <class T>
void Queue<T>::enqueue(const T& aElement)
{

}

template <class T>
const T& Queue<T>::dequeue()
{

}