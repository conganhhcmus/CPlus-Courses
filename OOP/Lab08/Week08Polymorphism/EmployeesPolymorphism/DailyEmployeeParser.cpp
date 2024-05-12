#include "DailyEmployeeParser.h"
#include "DailyEmployee.h"

Object* DailyEmployeeParser::parse(string data) {
	string tplDayCount = "dayCount=";
	string tplPaymentPerDay = "paymentPerDay=";
	size_t startPosDayCount = data.find(tplDayCount);
	size_t startPosPaymentPerDay = data.find(tplPaymentPerDay);
	auto dayCount = stoi(data.substr(startPosDayCount + tplDayCount.length(), startPosPaymentPerDay));
	auto paymentPerDay = stoi(data.substr(startPosPaymentPerDay + tplPaymentPerDay.length()));
	return new DailyEmployee(dayCount, paymentPerDay);
}

string DailyEmployeeParser::parsedObjectName() {
	return "DailyEmployee";
}