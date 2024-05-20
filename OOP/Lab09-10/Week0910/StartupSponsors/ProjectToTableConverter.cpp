#include "ProjectToTableConverter.h"
#include "sstream"
#include <iomanip>
#include "Project.h"
#include "IntegerToCurrencyConverter.h"
#include "Integer.h"

ProjectToTableConverter::ProjectToRowConverter::ProjectToRowConverter(vector<int> columnSizes) {
	for (int columnSize : columnSizes) {
		this->_columnSizes.push_back(columnSize);
	}
}

string ProjectToTableConverter::ProjectToRowConverter::convert(Object* object) {
	stringstream ss;
	IntegerToCurrencyConverter integerConverter;

	auto project = dynamic_cast<Project*>(object);
	auto sponsorShipMoney = new Integer(project->sponsorshipMoney());

	ss << setw(_columnSizes[1]) << left << project->getType() << " | ";
	ss << setw(_columnSizes[2]) << left << project->getName() << " | ";
	ss << setw(_columnSizes[3]) << left << project->getInfo() << " | ";
	ss << setw(_columnSizes[4]) << left << integerConverter.convert(sponsorShipMoney);

	return ss.str();
}

ProjectToTableConverter::ProjectToTableConverter(vector<string>headers, vector<int> columnSizes) {
	for (string header : headers) {
		_headers.push_back(header);
	}

	for (int columnSize : columnSizes) {
		_columnSizes.push_back(columnSize);
	}
}

string ProjectToTableConverter::convert(vector<Object*> objects) {
	stringstream ss;
	int length = 0;
	for (int i = 0; i < _headers.size(); i++) {
		ss << setw(_columnSizes[i]) << left << _headers[i];
		length += _columnSizes[i];
		if (i < _headers.size() - 1) ss << " | ";
	}

	ss << endl << setfill('-') << setw(length + _columnSizes.size() + 1) << "" << endl << setfill(' ');

	for (int i = 0; i < objects.size(); i++) {
		auto row = ProjectToRowConverter(_columnSizes);
		ss << setw(_columnSizes[0]) << left << i + 1 << " | " << row.convert(objects[i]) << endl;
	}

	return ss.str();
}

string ProjectToTableConverter::convert(Object* object) {
	stringstream ss;
	int length = 0;
	for (int i = 0; i < _headers.size(); i++) {
		ss << setw(_columnSizes[i]) << left << _headers[i];
		length += _columnSizes[i];
		if (i < _headers.size() - 1) ss << " | ";
	}

	ss << endl << setfill('-') << setw(length + _columnSizes.size() + 1) << "" << endl << setfill(' ');

	auto row = ProjectToRowConverter(_columnSizes);
	ss << setw(_columnSizes[0]) << left << 1 << " | " << row.convert(object) << endl;

	return ss.str();
}

string ProjectToTableConverter::toString() {
	return "ProjectToTableConverter";
}