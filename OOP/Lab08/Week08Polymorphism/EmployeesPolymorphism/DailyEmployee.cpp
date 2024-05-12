#include "DailyEmployee.h"
#include "sstream"

using namespace std;

DailyEmployee::DailyEmployee() { _dayCount = _paymentPerDay = 0; }

DailyEmployee::DailyEmployee(int dayCount, int paymentPerDay = 0) :
	_dayCount(dayCount), _paymentPerDay(paymentPerDay) {}

int DailyEmployee::salary() {
	return _dayCount * _paymentPerDay;
}

string DailyEmployee::toString() {
	stringstream ss;
	ss << "Daily employee";
	return ss.str();
}