#pragma once
#include "Employee.h"

class DailyEmployee : public Employee {
private:
	int _dayCount;
	int _paymentPerDay;

public:
	DailyEmployee();
	DailyEmployee(int, int);
	int salary() override;
	string toString() override;
};