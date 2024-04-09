#include "Fraction.h"

Fraction::Fraction() {
	_numerator = 0;
	_denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
	if (denominator == 0) throw ("denominator is zero");
	else {
		_numerator = numerator;
		_denominator = denominator;
	}
}

Fraction::~Fraction() {

}

int Fraction::getNumerator() {
	return _numerator;
}

int Fraction::getDenominator() {
	return _denominator;
}

Fraction Fraction::parse(string info) {
	string delimiter = "/";
	int pos = info.find(delimiter);
	if (pos > 0) {
		string numerator = info.substr(0, pos);
		string denominator = info.substr(pos + delimiter.length(), info.size());
		return Fraction(stoi(numerator), stoi(denominator));
	}
	return Fraction(stoi(info), 1);
}