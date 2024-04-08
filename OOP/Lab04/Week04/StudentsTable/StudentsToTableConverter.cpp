#include "StudentsToTableConverter.h"

StudentsToTableConverter::StudentsToTableConverter() {
}

StudentsToTableConverter::StudentsToTableConverter(vector<string> headers, vector<int> columnSizes) {
	for (int i = 0; i < headers.size(); i++) {
		_headers.push_back(headers[i]);
	}

	for (int i = 0; i < columnSizes.size(); i++) {
		_columnSizes.push_back(columnSizes[i]);
	}
}

string StudentsToTableConverter::convert(vector<Student> students) {
	stringstream ss;
	int length = 0;
	for (int i = 0; i < _headers.size(); i++) {
		ss << "|" << setw(_columnSizes[i]) << _headers[i];
		length += _columnSizes[i];
	}

	ss << "|" << endl;
	ss << setfill('-') << setw(length + _columnSizes.size() + 1) << setfill(' ') << "" << endl;

	for (int i = 0; i < students.size(); i++) {
		StudentToRowConverter row = StudentToRowConverter(_columnSizes);
		ss << "|" << setw(_columnSizes[0]) << i + 1 << "|" << row.convert(students[i]) << "|" << endl;
	}

	return ss.str();
}

StudentsToTableConverter::StudentToRowConverter::StudentToRowConverter() {

}

StudentsToTableConverter::StudentToRowConverter::StudentToRowConverter(vector<int> columnSizes) {
	for (int i = 0; i < columnSizes.size(); i++) {
		this->_columnSizes.push_back(columnSizes[i]);
	}
}

string StudentsToTableConverter::StudentToRowConverter::convert(Student student) {
	stringstream ss;
	ss << setw(_columnSizes[1]) << student._id << "|";
	ss << setw(_columnSizes[2]) << student._fullname << "|";
	ss << setw(_columnSizes[3]) << student._email;

	return ss.str();
}