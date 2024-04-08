#include "FractionKeyboardProvider.h"

Result<Fraction> FractionKeyboardProvider::next() {
	string input;
	int numerator, denominator;
	do {
		cin >> input;
		string delimiter = "/";
		numerator = stoi(input.substr(0, input.find(delimiter)));
		denominator = stoi(input.substr(input.find(delimiter) + delimiter.length(), input.length()));
	} while (denominator == 0);

	Fraction fraction = Fraction(numerator, denominator);
	Result<Fraction> result = Result<Fraction>();
	result.data = fraction;
	result.success = true;
	result.errorCode = 0;
	result.message = "Success";

	return result;
}