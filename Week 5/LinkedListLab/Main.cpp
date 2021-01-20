#include <iostream>
#include <string>

#include "ListNode.h"

using namespace std;


ListNode * AddNewNode(ListNode *aTop, int aItem)
{
	return new ListNode(aItem, aTop);
}

void main()
{
	//Do something

	ListNode one(1);
	ListNode two(2, &one);
	ListNode three(3, &two);

	ListNode *lTop = &three;

	while (lTop != NULL)
	{
		cout << "Value " << lTop->GetItem() << endl;
		lTop = lTop->GetNext();
	}

	cout << endl << endl << endl;
	lTop = NULL;
	ListNode *lTemp = NULL;

	lTop = AddNewNode(lTop, 4);
	lTop = AddNewNode(lTop, 5);
	lTop = AddNewNode(lTop, 6);
	lTop = AddNewNode(lTop, 7);
	lTop = AddNewNode(lTop, 8);
	lTop = AddNewNode(lTop, 9);
	lTop = AddNewNode(lTop, 10);

	while (lTop != NULL)
	{
		cout << "Value " << lTop->GetItem() << endl;

		lTemp = lTop;

		lTop = lTop->GetNext();

		delete lTemp;
	}

	system("pause");
	return;
}