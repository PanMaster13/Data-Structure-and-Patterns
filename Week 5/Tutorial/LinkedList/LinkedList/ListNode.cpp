#include "ListNode.h"

ListNode::ListNode()
{
	item = 0;
	next = nullptr;
}

ListNode::ListNode(int n)
{
	item = n;
	next = nullptr;
}

ListNode::ListNode(int n, ListNode * p)
{
	item = n;
	next = p;
}

int ListNode::getItem()
{
	return item;
}

void ListNode::setItem(int n)
{
	item = n;
}

ListNode * ListNode::getNext()
{
	return next;
}

void ListNode::setNext(ListNode * p)
{
	next = p;
}

