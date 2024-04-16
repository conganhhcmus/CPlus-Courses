#include "University.h"

University::University(string name, int fee) {
	_name = name;
	_fee = fee;
}

string University::getName() {
	return _name;
}

int University::getFee() {
	return _fee;
}