#pragma once

enum WeekDay{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};
class Date
{
private:
	WeekDay day;
	int hour, min;

public:
	Date();
	bool operator < (Date);
	~Date();
};

