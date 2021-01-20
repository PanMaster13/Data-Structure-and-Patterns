#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
	int hours, minutes, seconds;

public:
	Time(int h, int m, int s);

	Time(int h, int m);

	//default constructor
	Time();

	void setTime(int h, int m, int s);

	void setHours(int h);
	void setMinutes(int m);
	void setSeconds(int s);

	int getHours() const;
	int getMinutes() const;

	int getSeconds() const;

	void showTime();

	//friend method that returns input stream
	friend istream& operator>>(istream& aIstream, Time& aTime);
	//friend method that returns output stream
	friend ostream& operator<<(ostream& aOstream, Time& aTime);
};



