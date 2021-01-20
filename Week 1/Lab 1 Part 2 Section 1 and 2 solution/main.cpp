#include <iostream>

using namespace std;

class Time
{
private:
	int hours, minutes, seconds;

public:
	Time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}

	Time(int h, int m) {
		hours = h;
		minutes = m;
		seconds = 0;
	}

	//default constructor
	Time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	void setTime(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}

	void setHours(int h) {
		if (h >= 0 && h <= 23)
			hours = h;
		else
			hours = 0;
	}

	void setMinutes(int m) {
		if (m >= 0 && m <= 59)
			minutes = m;
		else
			minutes = 0;
	}

	void setSeconds(int s) {
		if (s >= 0 && s <= 59)
			seconds = s;
		else
			seconds = 0;
	}

	int getHours() const {
		return hours;
	}

	int getMinutes() const {
		return minutes;
	}

	int getSeconds() const {
		return seconds;
	}

	void showTime() {
		cout << hours << ":" << minutes 
			 << ":" << seconds << endl;
	}
};

int main()
{
	Time theTime(6, 0, 0);
	theTime.showTime();
	theTime.setMinutes(30);
	theTime.showTime();
	return 0;
}



