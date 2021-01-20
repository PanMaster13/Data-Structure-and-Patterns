#include <iostream>
#include "ListNode.h"
#include "TemplateLinkedList.h"
using namespace std;

int main()
{
	//Test with given LinkedList class
	ListNode one(1);
	ListNode two(2, &one);
	ListNode three(3, &two);

	ListNode *lTop = nullptr;
	lTop = &three;

	while (lTop != nullptr)
	{
		cout << "Value " << lTop->getItem() << endl;
		lTop = lTop->getNext();
	}

	cout << endl;

	//Test with custom template LinkedList class
	TemplateLinkedList<double> value1(77.45);
	TemplateLinkedList<double> value2(6.89, &value1);
	TemplateLinkedList<double> value3(145.66, &value2);

	TemplateLinkedList<double> *Null = nullptr;
	Null = &value3;

	while (Null != nullptr)
	{
		cout << "Value " << Null->getValue() << endl;
		Null = Null->getNext();
	}

	system("pause");
	return 0;
}