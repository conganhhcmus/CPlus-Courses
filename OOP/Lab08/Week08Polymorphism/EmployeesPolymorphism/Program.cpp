#include "iostream"
#include "vector"
#include "ParserFactory.h"
#include "DailyEmployeeParser.h"
#include "ProductEmployeeParser.h"
#include "ManagerParser.h"
#include "Employee.h"
#include "IntegerToCurrencyConverter.h"
#include "Integer.h"
#include "memory";
#include "Singleton.h"
#include "Singleton.cpp" // if not add a cpp file, the program gets an error when building

using namespace std;

void setupDI(ParserFactory& factory) { // Add Dependency Injection
	factory.registerWith(new DailyEmployeeParser());
	factory.registerWith(new ProductEmployeeParser());
	factory.registerWith(new ManagerParser());
}

auto getData() {
	return vector<string> {
		"ProductEmployee productCount=790, paymentPerProduct=20000",
			"DailyEmployee dayCount=20, paymentPerDay=1000000",
			"ProductEmployee productCount=810, paymentPerProduct=19000",
			"ProductEmployee productCount=900, paymentPerProduct=18000",
			"Manager employeeCount=49, paymentPerEmployee=500000, baseSalary=6000000",
			"DailyEmployee dayCount=22, paymentPerDay=1100000",
			"Manager employeeCount=37, paymentPerEmployee=500000, baseSalary=7000000",
			"DailyEmployee dayCount=18, paymentPerDay=1500000",
			"Manager employeeCount=30, paymentPerEmployee=500000, baseSalary=5000000"
	};
}

int main()
{
	auto factory = Singleton<ParserFactory>::getInstance();

	setupDI(factory);

	auto lines = getData();

	vector<auto_ptr<Employee>> employees;

	for (string line : lines) {// "ProductEmployee productCount=790, paymentPerProduct=20000"
		int splitPosition = line.find_first_of(" ");
		string type = line.substr(0, splitPosition); // type = "ProductEmployee" 
		IParsable* parser = factory.create(type);

		// data = "productCount=790, paymentPerProduct=20000",
		string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
		auto_ptr<Employee> employee = auto_ptr<Employee>(dynamic_cast<Employee*>(parser->parse(data)));
		employees.push_back(move(employee));
	}

	IntegerToCurrencyConverter converter;

	for (auto& employee : employees) {
		Integer* value = new Integer(employee->salary());
		cout << employee->toString() << ", salary:"
			<< converter.convert(value) << endl;
	}

	return 0;
}