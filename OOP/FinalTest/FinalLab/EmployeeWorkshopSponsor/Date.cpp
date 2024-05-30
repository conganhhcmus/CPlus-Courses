#include "Date.h"


Date::Date(int day, int month, int year) {
	_day = day;
	_month = month;
	_year = year;
}

int Date::getDay() {
	return _day;
}

int Date::getMonth() {
	return _month;
}

int Date::getYear() {
	return _year;
}

string Date::toString() {
	return "Date";
}