#include<iostream>
#include"Time.h"
#pragma once


bool Time::checkValidDate(int day, int month, int year) {
	if ((day < 0 || day > 31 )|| (month < 0 || month > 12)) {
		std::cout << "Invalid at 1";
		return false;
	}
	if( (isLeapYear(year)== true) && (month == 2) && (day == 29) ){
		return true;
	}
	else if (DAYS_OF_MONTH[(month-1)] >= day)
	{
		return true;
	}
	else
	{
		std::cout << "Invalid at 2";
		return false;
	}
}
bool Time::isLeapYear(int year){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}
Time::Time() = default;
Time::Time(int day, int month, int year){
	if (checkValidDate(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else {
		std::cout << "Invalid date!" << std::endl;
		exit(1);
	}
}

// Getter methods
int Time::getDay() const { return day; }
int Time::getMonth() const { return month; }
int Time::getYear() const { return year; }

// Setter methods
void Time::setDay(int day) { this->day = day; }
void Time::setMonth(int month) { this->month = month; }
void Time::setYear(int year) { this->year = year; }

bool Time::isOnTime(Time date) const {
	if (date.getYear() == this->year) {	
		if (date.getMonth() == this->month) {
			if (date.getDay() <= this->day) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (date.getMonth() > this->month) {
			return false;
		}
		else {
			return true;
		}
	}
	else if (date.getYear() > this->year) {
		return false;
	}
	else {
		return true;
	}
}

void Time::getCurrentTime() {
	std::time_t currentTime;
	std::time(&currentTime);

	std::tm localTime;
	localtime_s(&localTime, &currentTime);

	this->year = localTime.tm_year + 1900;
	this->month = localTime.tm_mon + 1;
	this->day = localTime.tm_mday;
}
	
std::string Time::toString() const {
	std::string dateFomat = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
	return dateFomat;
}
