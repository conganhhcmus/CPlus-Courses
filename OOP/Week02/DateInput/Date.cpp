#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Date::getDay() {
	return _day;
}

int Date::getMonth() {
	return _month;
}

int Date::getYear() {
	return _year;
}

void Date::setDay(int value) {
	_day = value;
}

void Date::setMonth(int value) {
	_month = value;
}

void Date::setYear(int value) {
	_year = value;
}


Date::Date() {
	_day = 1;
	_month = 1;
	_year = 1;
}

// Week02: Use input() function
// Week03: Use DateKeyboardProvider.next()
void Date::input() {
	cout << "Nhap ngay: ";
	cin >> _day;
	cout << "Nhap thang: ";
	cin >> _month;
	cout << "Nhap nam: ";
	cin >> _year;
}

// Week02: use "output" function and inside this function access directly to the console using cout
// Week03: use toString()
// Week04: use Converter
void Date::output() {
	cout << "DD/MM/YYY: " << setw(2) << setfill('0') << _day << "/" 
		<< setw(2) << setfill('0')  << _month << "/"
		<< setw(2) << setfill('0')  << _year;
}