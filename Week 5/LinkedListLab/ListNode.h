#pragma once
template <class T>
class ListNode
{
private:
	T item;
	ListNode *next;

public:
	ListNode()
	{
		item = 0;
		next = NULL;
	}

	ListNode(int n)
	{
		item = n;
		next = NULL;
	}

	ListNode(int n, ListNode *p)
	{
		item = n;
		next = p;
	}

	int GetItem()
	{
		return item;
	}

	void SetItem(int n)
	{
		item = n;
	}

	ListNode* GetNext()
	{
		return next;
	}

	void SetNext(ListNode *p)
	{
		next = p;
	}

	
};