#include <iostream>
#include "DoublyLinkedNode.h"

using namespace std;

#define ARRAYSIZE 12

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
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void makeDoublyLinkedList(double *arr) 
{
	typedef DoublyLinkedNode<double>::Node DoubleNode;

	DoubleNode node1(arr[0]);
	DoubleNode node2(arr[1]);
	DoubleNode node3(arr[2]);
	DoubleNode node4(arr[3]);
	DoubleNode node5(arr[4]);
	DoubleNode node6(arr[5]);
	DoubleNode node7(arr[6]);
	DoubleNode node8(arr[7]);
	DoubleNode node9(arr[8]);
	DoubleNode node10(arr[9]);
	DoubleNode node11(arr[10]);
	DoubleNode node12(arr[11]);

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
	for (const DoubleNode* pn = &node1; pn != &DoubleNode::NIL; pn = pn->getNext())
	{
		cout << "(";
		if (pn->getPrevious() != &DoubleNode::NIL)
			cout << pn->getPrevious()->getValue();
		else
			cout << "<NULL>";
		cout << ",    " << pn->getValue() << ",    ";
		if (pn->getNext() != &DoubleNode::NIL)
			cout << pn->getNext()->getValue();
		else
			cout << "<NULL>";
		cout << ")" << endl;
	}
}

int main()
{
	double lData[ARRAYSIZE] = { 37.3, 20.6, 138.9, 70.0, 55.9, 25.9, 144.4, 66.9, 112.6, 106.7, 134.2, 129.5 };

	cout << "All Nodes Without Sorting: " << endl;
	makeDoublyLinkedList(lData);

	sorting(lData);
	cout << endl;

	makeDoublyLinkedList(lData);

	system("pause");
	return 0;
}