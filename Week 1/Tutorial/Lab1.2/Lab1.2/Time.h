#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int hours;
	int minutes;
	int seconds;

public:
	Time(int h, int m, int s);
	Time(int h, int m);
	Time();

	void setTime(int h, int m, int s);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	void showTime();

	friend istream& operator>>(istream& aIstream, Time& aTime);
	friend ostream& operator<<(ostream& aOstream, Time& aTime);
};