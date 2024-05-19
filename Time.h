#include<string>
#include<chrono>
#pragma once
const int DAYS_OF_MONTH[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };
const int MONTH[12] = {1,2,3,4,5,6,7,8,9,10,11,12 };

class Time
{
private:
	int day;
	int month;
	int year;
	bool checkValidDate(int day, int month, int year);
	bool isLeapYear(int year);

public:
	Time();
	Time(int day, int month, int year);
	// Getter methods
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	// Setter methods
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);
	
	void getCurrentTime();
	bool isOnTime(Time date) const;
	std::string toString() const;
};

