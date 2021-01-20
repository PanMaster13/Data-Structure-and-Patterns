#pragma once
template <class T>

class ListNode
{
public:
	T fData;
	ListNode * fNext;
	ListNode(const T& aData, ListNode * aNext = (ListNode*)0)
	{
		fData = aData;
		fNext = aNext;
	}
};