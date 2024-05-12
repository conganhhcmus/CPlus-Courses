#include "ManagerParser.h"
#include "Manager.h"

Object* ManagerParser::parse(string data) {
	string tplEmployeeCount = "employeeCount=";
	string tplPaymentPerEmployee = "paymentPerEmployee=";
	string tplBaseSalary = "baseSalary=";
	size_t startPosEmployeeCount = data.find(tplEmployeeCount);
	size_t startPosPaymentPerEmployee = data.find(tplPaymentPerEmployee);
	size_t startPosBaseSalary = data.find(tplBaseSalary);

	auto employeeCount = stoi(data.substr(startPosEmployeeCount + tplEmployeeCount.length(), startPosPaymentPerEmployee));
	auto paymentPerEmployee = stoi(data.substr(startPosPaymentPerEmployee + tplPaymentPerEmployee.length(), startPosBaseSalary));
	auto baseSalary = stoi(data.substr(startPosBaseSalary + tplBaseSalary.length()));

	return new Manager(employeeCount, paymentPerEmployee, baseSalary);
}

string ManagerParser::parsedObjectName() {
	return "Manager";
}