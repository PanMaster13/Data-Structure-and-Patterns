#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
	Time theTime(6, 0, 0);
	theTime.showTime();
	theTime.setMinute(30);
	theTime.showTime();
	
	Time newTime;
	cout << "Enter a time:" << endl;
	cin >> newTime;
	cout << "This is the new time you've defined:	";
	cout << newTime;

	system("pause");
	return 0;
}
