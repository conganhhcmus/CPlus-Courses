#include "Fraction.h"

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
}

Fraction::~Fraction() {

}

string Fraction::toString() {
	stringstream buffer;
	int temp = numerator / denominator;

	numerator = numerator % denominator;

	if (temp == 0) {
		if (numerator == 0) {
			buffer << 0;
		}
		else {
			buffer << numerator << "/" << denominator;
		}
	}
	else {
		if (numerator != 0) {
			buffer << temp << " " << numerator << "/" << denominator;
		}
		else {
			buffer << temp;
		}
	}

	return buffer.str();
}