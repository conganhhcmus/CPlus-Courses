#pragma once
#include "string"

using namespace std;

class Sponsorship {
private:
	string _name;
	int _minYear;
	int _maxYear;
	int _percent;
public:
	Sponsorship(string, int, int, int);
	string getName();
	int getMinYear();
	int getMaxYear();
	int getPercent();
};