#include "NumberFormatInfo.h"

string NumberFormatInfo::currencyDecimalSeparator() {
	return _currencyDecimalSeparator;
}

string NumberFormatInfo::currencySymbol() {
	return _currencySymbol;
}

int NumberFormatInfo::currencyPositive() {
	return _currencyPositive;
}

string NumberFormatInfo::currencyPositiveFormat() {
	return _currencyPositiveFormat;
}

string NumberFormatInfo::toString() {
	return "NumberFormatInfo";
}

NumberFormatInfo::NumberFormatInfo(
	string currencyDecimalSeparator,
	string currencySymbol,
	int currencyPositive,
	string currencyPositiveFormat) {
	_currencyDecimalSeparator = currencyDecimalSeparator;
	_currencySymbol = currencySymbol;
	_currencyPositive = currencyPositive;
	_currencyPositiveFormat = currencyPositiveFormat;
}

NumberFormatInfo::NumberFormatInfo() {
	_currencyDecimalSeparator = ",";
	_currencySymbol = "$";
	_currencyPositive = 0;			// 0		1		2		3
	_currencyPositiveFormat = "$n"; // "$n"		"n$"	"$ n"	"n $"
}