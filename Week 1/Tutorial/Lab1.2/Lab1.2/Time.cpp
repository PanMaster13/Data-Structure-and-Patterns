#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
	seconds = 0;
}

Time::Time()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

void Time::setTime(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

void Time::setHour(int h)
{
	if (h >= 0 && h <= 23)
	{
		hours = h;
	}

	else
	{
		hours = 0;
	}
}

void Time::setMinute(int m)
{
	if (m >= 0 && m <= 59)
	{
		minutes = m;
	}

	else
	{
		minutes = 0;
	}
}

void Time::setSecond(int s)
{
	if (s >= 0 && s <= 59)
	{
		seconds = s;
	}

	else
	{
		seconds = 0;
	}
}

int Time::getHour() const
{
	return hours;
}

int Time::getMinute() const
{
	return minutes;
}

int Time::getSecond() const
{
	return seconds;
}

void Time::showTime()
{
	cout << hours << ":" << minutes << ":" << seconds << endl;
}

istream& operator>> (istream& istream, Time& time)
{
	istream >> time.hours >> time.minutes >> time.seconds;
	return istream;
}

ostream& operator<< (ostream& ostream, Time& time)
{
	ostream << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
	return ostream;
}