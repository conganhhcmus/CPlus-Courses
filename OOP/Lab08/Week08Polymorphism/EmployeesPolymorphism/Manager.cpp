#include "Manager.h"
#include "sstream"

using namespace std;

Manager::Manager() { _employeeCount = _paymentPerEmployee = _baseSalary = 0; }

Manager::Manager(int employeeCount, int paymentPerEmployee, int baseSalary) :
	_employeeCount(employeeCount), _paymentPerEmployee(paymentPerEmployee), _baseSalary(baseSalary) {}

int Manager::salary() {
	return _baseSalary + _employeeCount * _paymentPerEmployee;
}

string Manager::toString() {
	stringstream ss;
	ss << "Manager";
	return ss.str();
}