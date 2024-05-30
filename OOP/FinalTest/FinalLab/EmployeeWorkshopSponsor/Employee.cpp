#include "Employee.h"

Employee::Employee(string name, string email, Date* startDate, Workshop* workshop) {
	_name = name;
	_email = email;
	_startDate = startDate;
	_workshop = workshop;
}

string Employee::getName() { return _name; }

string Employee::getEmail() { return _email; }

Workshop* Employee::getWorkshop() { return _workshop; }

Date* Employee::getStartDate() { return _startDate; }

string Employee::toString() {
	return "Employee";
}