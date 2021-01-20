#include <iostream>
#include "SimpleString.h"

using namespace std;

int main()
{
	//Test 1: Normal Testing of instantiating objects on Stack.
	SimpleString s1;

	s1 + 'A';
	cout << "s1 content is " << *s1 << endl;
	s1 + ' ';
	s1 + 'L';
	s1 + 'M';
	s1 + 'A';
	s1 + 'O';
	cout << "s1 content is " << *s1 << endl;

	//Test 2: Being risky with StrCpy (strcpy VS strcpy_s)
	SimpleString s2(s1);
	s2 + '@';
	cout << "s2 content is " << *s2 << endl;

	//Test 3: Creating object on the Heap
	SimpleString *s3 = new SimpleString();
	*s3 + 'D';
	cout << "s3 content is " << **s3 << endl;

	//Test 4: Induce errors thanks to implicit copy/shallow copy
	//SimpleString *s4 = s3;

	//Test 5: Perform a proper deep copy
	SimpleString * s4 = s3->Clone();
	*s4 + 'E';
	cout << "s4 content is " << **s4 << endl;

	cout << "s3 content is " << **s3 << endl;

	delete s3;
	delete s4;

	system("pause");
	return 0;
}