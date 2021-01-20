#pragma once

class ListNode
{
private:
	int item;
	ListNode * next;

public:
	ListNode();
	ListNode(int n);
	ListNode(int n, ListNode * ptr);

	int getItem();
	void setItem(int n);

	ListNode* getNext();
	void setNext(ListNode * p);
};