#pragma once
#include "string"

using namespace std;

class Fraction {
private:
	int _numerator;
	int _denominator;
public:
	int getNumerator();
	int getDenominator();
	Fraction();
	Fraction(int, int);
	~Fraction();
	static Fraction parse(string info);
};