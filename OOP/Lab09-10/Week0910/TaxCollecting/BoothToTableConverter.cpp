#include "BoothToTableConverter.h"
#include "sstream"
#include <iomanip>
#include "Booth.h"
#include "IntegerToCurrencyConverter.h"
#include "Integer.h"

BoothToTableConverter::BoothToRowConverter::BoothToRowConverter(vector<int> columnSizes) {
	for (int columnSize : columnSizes) {
		this->_columnSizes.push_back(columnSize);
	}
}

string BoothToTableConverter::BoothToRowConverter::convert(Object* object) {
	stringstream ss;
	NumberFormatInfo numberFormatWithoutSymbol = NumberFormatInfo(".", "", 0, "n $");
	NumberFormatInfo numberFormat = NumberFormatInfo(".", "d", 0, "n $");
	auto integerConverter = IntegerToCurrencyConverter(numberFormat);
	auto integerConverterWithoutSymbol = IntegerToCurrencyConverter(numberFormatWithoutSymbol);

	auto booth = dynamic_cast<Booth*>(object);
	auto rentPrice = new Integer(booth->rentPrice());
	auto pricePerMeter = new Integer(booth->getPricePerMeter());
	auto areaPrice = new Integer(booth->getAreaPrice());
	auto fee = new Integer(booth->getFee());

	ss << setw(_columnSizes[1]) << left << booth->getID() << " | ";
	ss << setw(_columnSizes[2]) << left << booth->getType() << " | ";
	ss << setw(_columnSizes[3]) << left << booth->getArea() << " | ";
	ss << setw(_columnSizes[4]) << left << integerConverterWithoutSymbol.convert(pricePerMeter) << " | ";
	ss << setw(_columnSizes[4]) << left << integerConverterWithoutSymbol.convert(areaPrice) << " | ";
	ss << setw(_columnSizes[5]) << left << integerConverterWithoutSymbol.convert(fee) << " | ";
	ss << setw(_columnSizes[6]) << left << integerConverter.convert(rentPrice);

	return ss.str();
}

BoothToTableConverter::BoothToTableConverter(vector<string>headers, vector<int> columnSizes) {
	for (string header : headers) {
		_headers.push_back(header);
	}

	for (int columnSize : columnSizes) {
		_columnSizes.push_back(columnSize);
	}
}

string BoothToTableConverter::convert(vector<Object*> objects) {
	stringstream ss;
	int length = 0;
	for (int i = 0; i < _headers.size(); i++) {
		ss << setw(_columnSizes[i]) << left << _headers[i];
		length += _columnSizes[i];
		if (i < _headers.size() - 1) ss << " | ";
	}

	ss << endl << setfill('-') << setw(length + _columnSizes.size() + 1) << "" << endl << setfill(' ');

	for (int i = 0; i < objects.size(); i++) {
		auto row = BoothToRowConverter(_columnSizes);
		ss << setw(_columnSizes[0]) << left << i + 1 << " | " << row.convert(objects[i]) << endl;
	}

	return ss.str();
}

string BoothToTableConverter::convert(Object* object) {
	stringstream ss;
	int length = 0;
	for (int i = 0; i < _headers.size(); i++) {
		ss << setw(_columnSizes[i]) << left << _headers[i];
		length += _columnSizes[i];
		if (i < _headers.size() - 1) ss << " | ";
	}

	ss << endl << setfill('-') << setw(length + _columnSizes.size() + 1) << "" << endl << setfill(' ');

	auto row = BoothToRowConverter(_columnSizes);
	ss << setw(_columnSizes[0]) << left << 1 << " | " << row.convert(object) << endl;

	return ss.str();
}

string BoothToTableConverter::toString() {
	return "BoothToTableConverter";
}