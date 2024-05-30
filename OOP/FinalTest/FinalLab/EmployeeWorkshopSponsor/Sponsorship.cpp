#include "Sponsorship.h"

Sponsorship::Sponsorship(string name, int minYear, int maxYear, int percent) {
	_name = name;
	_minYear = minYear;
	_maxYear = maxYear;
	_percent = percent;
}

string Sponsorship::getName() {
	return _name;
}

int Sponsorship::getMinYear() {
	return _minYear;
}

int Sponsorship::getMaxYear() {
	return _maxYear;
}

int Sponsorship::getPercent() {
	return _percent;
}