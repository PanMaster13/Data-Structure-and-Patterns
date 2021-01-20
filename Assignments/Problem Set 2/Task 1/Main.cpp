#include <iostream>
#include "ListNodeIterator.h"

using namespace std;

int main()
{
	typedef ListNode<int> IntegerNode;

	IntegerNode One(1);
	IntegerNode Two(2, &One);
	IntegerNode Three(3, &Two);

	for (ListNodeIterator<int> iter(&Three); iter != iter.end(); ++iter)
	{
		cout << "Value: " << *iter << endl;
	}

	system("pause");
	return 0;
}