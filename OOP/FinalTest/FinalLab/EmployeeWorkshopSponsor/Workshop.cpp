#include "Workshop.h"

Workshop::Workshop(string name, float expense) {
	_name = name;
	_expense = expense;
}

string Workshop::getName() {
	return _name;
}

float Workshop::getExpense() {
	return _expense;
}

string Workshop::toString() {
	return "Workshop";
}