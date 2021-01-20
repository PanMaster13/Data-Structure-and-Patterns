#pragma once

template <class T>
class TemplateLinkedList
{
private:
	T value;
	TemplateLinkedList *next;

public:
	TemplateLinkedList();
	TemplateLinkedList(T n);
	TemplateLinkedList(T n, TemplateLinkedList *ptr);

	T getValue();
	void setValue(T n);

	TemplateLinkedList *getNext();
	void setNext(TemplateLinkedList *p);
};

// Implementation

template <class T>
TemplateLinkedList<T>::TemplateLinkedList()
{
	value = nullptr;
	next = nullptr;
}

template <class T>
TemplateLinkedList<T>::TemplateLinkedList(T n)
{
	value = n;
	next = nullptr;
}

template <class T>
TemplateLinkedList<T>::TemplateLinkedList(T n, TemplateLinkedList *ptr)
{
	value = n;
	next = ptr;
}

template <class T>
T TemplateLinkedList<T>::getValue()
{
	return value;
}

template <class T>
void TemplateLinkedList<T>::setValue(T n)
{
	value = n;
}

template <class T>
TemplateLinkedList<T>* TemplateLinkedList<T>::getNext()
{
	return next;
}

template <class T>
void TemplateLinkedList<T>::setNext(TemplateLinkedList<T> *p)
{
	next = p;
}
