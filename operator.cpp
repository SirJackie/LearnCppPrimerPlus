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
	const Time operator +(const Time& tb) const;
	const Time operator -(const Time& tb) const;
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

const Time Time::operator +(const Time& tb) const {
	const Time& ta = *this;
	Time result;

	result.hour = ta.hour + tb.hour;
	result.minute = ta.minute + tb.minute;
	result.correctMinute();

	return result;
}

const Time Time::operator -(const Time& tb) const {
	const Time& ta = *this;
	Time result;

	result.hour = 0;
	result.minute = (ta.hour * 60 + ta.minute) - (tb.hour * 60 + tb.minute);

	result.correctMinute();

	return result;
}

int main() {
	Time t1, t2;
	t1 = Time(2, 50);
	t2 = Time(2, 70);

	t1.show();
	t2.show();

	Time t3 = t1 + t2;
	t3.show();

	Time t4 = t2 - t1;
	t4.show();
}
