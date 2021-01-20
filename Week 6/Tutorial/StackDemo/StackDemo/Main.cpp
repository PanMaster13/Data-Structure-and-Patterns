#include <iostream>
#include "StackTemplate.h"

using namespace std;

int main()
{
	StackTemplate<int> stack1(5);

	cout << "Size of stack1: " << stack1.size() << endl;

	cout << "Adding 1" << endl;
	stack1.push(1);
	cout << "Adding 2" << endl;
	stack1.push(2);
	cout << "Adding 3" << endl;
	stack1.push(3);
	cout << "Adding 4" << endl;
	stack1.push(4);
	cout << "Adding 5" << endl;
	stack1.push(5);

	// Should give console output due to max size of stack
	cout << "Adding 6" << endl;
	stack1.push(6);

	cout << "Upmost variable: " << stack1.top() << endl << endl;

	cout << "Removing variable" << endl;
	stack1.pop();
	cout << "Removing variable" << endl;
	stack1.pop();

	cout << "Upmost variable: " << stack1.top() << endl;

	cout << "Removing variable" << endl;
	stack1.pop();
	cout << "Removing variable" << endl;
	stack1.pop();

	cout << "Upmost variable: " << stack1.top() << endl;

	cout << "Removing variable" << endl;
	stack1.pop();
	
	// Should give console output due to pointer going beyong minimum
	cout << "Removing variable" << endl;
	stack1.pop();

	system("pause");
	return 0;
}