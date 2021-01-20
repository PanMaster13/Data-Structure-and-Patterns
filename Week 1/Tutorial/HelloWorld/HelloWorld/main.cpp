#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	//Simple Printing Stuff
	cout << "Hello World!" << endl;

	//There would be 4 arguements (Check properties in solution)
	cout << "There are " << argc << " arguements" << endl;

	for (int i = 0; i < argc; i++)
	{
		cout << "Arguement " << i << ": " << argv[i] << endl;
	}

	//To prevent the console window from closing automatically
	system("pause");
	return 0;
}