#include "WorkshopParser.h"
#include "Workshop.h"

Object* WorkshopParser::parse(string data) {
	string tplName = "Name=";
	string tplExpense = "Expense=$";
	size_t startName = data.find(tplName);
	size_t startExpense = data.find(tplExpense);
	string name = data.substr(startName + tplName.length(), startExpense - startName - tplName.length() - 2);
	float expense = stof(data.substr(startExpense + tplExpense.length()));

	return new Workshop(name, expense);
}