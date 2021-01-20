#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
	Time theTime(6, 0, 0);
	theTime.showTime();
	theTime.setMinutes(30);
	theTime.showTime();
	
	Time newTime; //empty Time
	cout << "Enter a time:" << endl;
	cin >> newTime;
	cout << "This is the time that you have defined: ";
	cout << newTime;

	return 0;
}








