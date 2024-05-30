#include "EmployeeParser.h"
#include "Employee.h"
#include "WorkshopParser.h"
#include "DateParser.h"

Object* EmployeeParser::parse(vector<string> data) {
	auto workshopParser = WorkshopParser();
	auto dateParser = DateParser();
	string employeeData = data[0];
	string workshopData = data[1];

	string tplName = "Name=";
	string tplEmail = "Email=";
	string tplStartDate = "StartDate=";
	size_t startName = employeeData.find(tplName);
	size_t startEmail = employeeData.find(tplEmail);
	size_t startStartDate = employeeData.find(tplStartDate);

	string name = employeeData.substr(startName + tplName.length(), startEmail - startName - tplEmail.length() - 1);
	string email = employeeData.substr(startEmail + tplEmail.length(), startStartDate - startEmail - tplEmail.length() - 2);
	string startDate = employeeData.substr(startStartDate + tplStartDate.length());
	auto date = dynamic_cast<Date*> (dateParser.parse(startDate));
	auto workshop = dynamic_cast<Workshop*>(workshopParser.parse(workshopData));

	return new Employee(name, email, date, workshop);
}
