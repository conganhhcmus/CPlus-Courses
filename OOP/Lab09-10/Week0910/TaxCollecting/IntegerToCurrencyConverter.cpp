#include "IntegerToCurrencyConverter.h"
#include "Integer.h"
#include "sstream"
#include "regex"

using namespace std;

string IntegerToCurrencyConverter::convert(Object* object) {
	auto number = dynamic_cast<Integer*>(object);
	int value = number->value();

	stringstream builder;
	int count = 0;

	while (value != 0) {
		int lastDigit = value % 10;
		builder << lastDigit;

		count++;
		value /= 10;

		if (count == 3 && value != 0) {
			builder << _numberFormat.currencyDecimalSeparator();
			count = 0;
		}
	}

	string numberSeparated = builder.str(); // "000,000,1"
	reverse(numberSeparated.begin(), numberSeparated.end());

	if (numberSeparated.length() < 1) {
		numberSeparated = "0";
	}

	string format = _numberFormat.currencyPositiveFormat(); //"$n" ==> "$1,000,000"
	string symbol = _numberFormat.currencySymbol(); // "$"

	// https://stackoverflow.com/questions/17459450/how-to-determine-currency-symbol-position-for-a-culture
	string result = regex_replace(format, regex("n"), numberSeparated);
	result = regex_replace(result, regex("\\$"), symbol);

	return result;
}

string IntegerToCurrencyConverter::convert(vector<Object*> objects) {
	stringstream ss;
	for (auto object : objects) {
		auto number = dynamic_cast<Integer*>(object);
		ss << this->convert(object) << endl;
	}
	return ss.str();
}

string IntegerToCurrencyConverter::toString() {
	return "IntegerToCurrencyConverter";
}

IntegerToCurrencyConverter::IntegerToCurrencyConverter(NumberFormatInfo numberFormat) {
	_numberFormat = numberFormat;
}