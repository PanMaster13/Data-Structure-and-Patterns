#include <iostream>
#include "DoublyLinkedNode.h"
#include <string>

using namespace std;

#define ARRAYSIZE 20

// Sorting Function.
template <class DataType>
void sorting(DataType *arr)
{
	int i, j;
	DataType temp;

	for (i = 0; i < ARRAYSIZE; i++)
	{
		for (j = i + 1; j < ARRAYSIZE; j++)
		{
			if (arr[i].compare(arr[j]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void makeDoublyLinkedList(string *arr)
{
	typedef DoublyLinkedNode<string>::Node StringNode;

	StringNode node1(arr[0]);
	StringNode node2(arr[1]);
	StringNode node3(arr[2]);
	StringNode node4(arr[3]);
	StringNode node5(arr[4]);
	StringNode node6(arr[5]);
	StringNode node7(arr[6]);
	StringNode node8(arr[7]);
	StringNode node9(arr[8]);
	StringNode node10(arr[9]);
	StringNode node11(arr[10]);
	StringNode node12(arr[11]);
	StringNode node13(arr[12]);
	StringNode node14(arr[13]);
	StringNode node15(arr[14]);
	StringNode node16(arr[15]);
	StringNode node17(arr[16]);
	StringNode node18(arr[17]);
	StringNode node19(arr[18]);
	StringNode node20(arr[19]);

	node1.append(node20);
	node1.append(node19);
	node1.append(node18);
	node1.append(node17);
	node1.append(node16);
	node1.append(node15);
	node1.append(node14);
	node1.append(node13);
	node1.append(node12);
	node1.append(node11);
	node1.append(node10);
	node1.append(node9);
	node1.append(node8);
	node1.append(node7);
	node1.append(node6);
	node1.append(node5);
	node1.append(node4);
	node1.append(node3);
	node1.append(node2);

	cout << "Prev    Current    Next" << endl;
	for (const StringNode* pn = &node1; pn != &StringNode::NIL; pn = pn->getNext())
	{
		cout << "(";
		if (pn->getPrevious() != &StringNode::NIL)
			cout << pn->getPrevious()->getValue();
		else
			cout << "<NULL>";
		cout << ",    " << pn->getValue() << ",    ";
		if (pn->getNext() != &StringNode::NIL)
			cout << pn->getNext()->getValue();
		else
			cout << "<NULL>";
		cout << ")" << endl;
	}
}

int main()
{
	string lData[ARRAYSIZE] = { "Emma", "Zack", "Wade", "Liam", "Kyle", "Mason", "Fiona", "Sam", "Ava", "Mike", "Diana", "Paul", "Ryan", "Aidan", "Beth", "Noel", "Tina", "Harry", "Cyril", "Jean" };

	cout << "All Nodes Without Sorting: " << endl;
	makeDoublyLinkedList(lData);
	
	sorting<string>(lData);

	cout << endl << "All Nodes after Sorting: " << endl;
	makeDoublyLinkedList(lData);

	system("pause");
	return 0;
}