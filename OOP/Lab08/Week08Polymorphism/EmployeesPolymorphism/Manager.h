#pragma once
#include "Employee.h"

class Manager : public Employee {
private:
	int _employeeCount;
	int _paymentPerEmployee;
	int _baseSalary;

public:
	Manager();
	Manager(int, int, int);
	int salary() override;
	string toString() override;
};