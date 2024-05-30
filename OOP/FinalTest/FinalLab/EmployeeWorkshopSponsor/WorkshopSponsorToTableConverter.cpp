#include "WorkshopSponsorToTableConverter.h"
#include "sstream"
#include <iomanip>
#include "Employee.h"
#include "format"


float WorkshopSponsorToTableConverter::total = 0;

WorkshopSponsorToTableConverter::WorkshopSponsorToRowConverter::WorkshopSponsorToRowConverter(vector<int> columnSizes, vector<Sponsorship*> sponsorship) {
	for (int columnSize : columnSizes) {
		this->_columnSizes.push_back(columnSize);
	}
	for (auto sponsor : sponsorship) {
		this->_sponsorship.push_back(sponsor);
	}

}

Sponsorship* WorkshopSponsorToTableConverter::findSponsorship(Object* object) {
	auto employee = dynamic_cast<Employee*>(object);
	Date* today = new Date(30, 05, 2024);

	int diffYear = today->getYear() - employee->getStartDate()->getYear();
	diffYear += today->getMonth() > employee->getStartDate()->getMonth() ? 1 : 0;
	diffYear += today->getMonth() < employee->getStartDate()->getMonth() ? -1 : 0;

	for (auto sponsor : _sponsorship) {
		if (diffYear >= sponsor->getMinYear() && (diffYear < sponsor->getMaxYear() || sponsor->getMaxYear() == 0)) {
			return sponsor;
		}
	}
	return nullptr;
}

Sponsorship* WorkshopSponsorToTableConverter::WorkshopSponsorToRowConverter::findSponsorship(Object* object) {
	auto employee = dynamic_cast<Employee*>(object);
	Date* today = new Date(30, 05, 2024);

	int diffYear = today->getYear() - employee->getStartDate()->getYear();
	diffYear += today->getMonth() > employee->getStartDate()->getMonth() ? 1 : 0;
	diffYear += today->getMonth() < employee->getStartDate()->getMonth() ? -1 : 0;

	for (auto sponsor : _sponsorship) {
		if (diffYear >= sponsor->getMinYear() && (diffYear < sponsor->getMaxYear() || sponsor->getMaxYear() == 0)) {
			return sponsor;
		}
	}
	return nullptr;
}


string WorkshopSponsorToTableConverter::WorkshopSponsorToRowConverter::convert(Object* object) {
	stringstream ss;

	auto employee = dynamic_cast<Employee*>(object);
	auto sponsorship = dynamic_cast<Sponsorship*>(findSponsorship(object));

	ss << setw(_columnSizes[1]) << left << employee->getName() << " | ";
	ss << setw(_columnSizes[2]) << left << sponsorship->getName() << " | ";
	ss << setw(_columnSizes[3]) << left << employee->getWorkshop()->getName() << " | ";
	ss << setw(_columnSizes[4]) << left << format("${}", ceil(employee->getWorkshop()->getExpense() * 100.0) / 100.0) << " | ";
	ss << setw(_columnSizes[5]) << left << format("{}%", sponsorship->getPercent()) << " | ";
	ss << setw(_columnSizes[6]) << left << format("${}", ceil((100 - sponsorship->getPercent()) / 100.0 * employee->getWorkshop()->getExpense() * 100.0) / 100.0);

	total += (100 - sponsorship->getPercent()) / 100.0 * employee->getWorkshop()->getExpense();

	return ss.str();
}

WorkshopSponsorToTableConverter::WorkshopSponsorToTableConverter(vector<string>headers, vector<int> columnSizes, vector<Sponsorship*> sponsorship) {
	for (string header : headers) {
		_headers.push_back(header);
	}

	for (int columnSize : columnSizes) {
		_columnSizes.push_back(columnSize);
	}

	for (auto sponsor : sponsorship) {
		this->_sponsorship.push_back(sponsor);
	}
}

string WorkshopSponsorToTableConverter::convert(vector<Object*> objects) {
	stringstream ss;
	int length = 0;
	for (int i = 0; i < _headers.size(); i++) {
		ss << setw(_columnSizes[i]) << left << _headers[i];
		length += _columnSizes[i];
		if (i < _headers.size() - 1) ss << " | ";
	}

	ss << endl << setfill('-') << setw(length + _columnSizes.size() + 1) << "" << endl << setfill(' ');

	for (int i = 0; i < objects.size(); i++) {
		auto row = WorkshopSponsorToRowConverter(_columnSizes, _sponsorship);
		ss << setw(_columnSizes[0]) << left << i + 1 << " | " << row.convert(objects[i]) << endl;
	}

	return ss.str();
}

string WorkshopSponsorToTableConverter::convert(Object* object) {
	stringstream ss;
	int length = 0;
	for (int i = 0; i < _headers.size(); i++) {
		ss << setw(_columnSizes[i]) << left << _headers[i];
		length += _columnSizes[i];
		if (i < _headers.size() - 1) ss << " | ";
	}

	ss << endl << setfill('-') << setw(length + _columnSizes.size() + 1) << "" << endl << setfill(' ');

	auto row = WorkshopSponsorToRowConverter(_columnSizes, _sponsorship);
	ss << setw(_columnSizes[0]) << left << 1 << " | " << row.convert(object) << endl;

	return ss.str();
}

string WorkshopSponsorToTableConverter::toString() {
	return "WorkshopSponsorToTableConverter";
}