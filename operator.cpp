#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int minute;
	void correctMinute();
public:
	Time();
	Time(const int hour_, const int minute_);
	void show();
};

void Time::correctMinute() {
	hour += minute / 60;
	minute %= 60;
}

Time::Time() {
	minute = 0;
	hour = 0;
}

Time::Time(const int hour_, const int minute_) {
	if (minute < 60) {
		minute = minute_;
		hour = hour_;
	}
	else {
		minute = hour_ * 60 + minute_;
		hour = 0;
		correctMinute();
	}
}

void Time::show() {
	cout << "Time: " << hour << " hour(s) " << ", " << minute << " minute(s) " << endl;
}

int main() {
	Time t1, t2;
	t1 = Time(2, 40);
	t2 = Time(2, 70);

	t1.show();
	t2.show();
}
