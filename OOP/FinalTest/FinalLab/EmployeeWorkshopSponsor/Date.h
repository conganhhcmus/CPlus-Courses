#pragma once
#include "Object.h"

class Date: public Object {
private:
	int _day;
	int _month;
	int _year;
public:
	Date(int, int, int);
	int getDay();
	int getMonth();
	int getYear();
	string toString() override;

};
