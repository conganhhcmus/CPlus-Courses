#include "Student.h"
#include <iostream>

using namespace std;

string Student::getID() {
	return _id;
}

string Student::getFullName() {
	return _fullName;
}

string Student::getAddress() {
	return _address;
}

string Student::getEmail() {
	return _email;
}

Date* Student::getDOB() {
	return _dob;
}

void Student::setID(string value) {
	_id = value;
}

void Student::setFullName(string value) {
	_fullName = value;
}

void Student::setAddress(string value) {
	_address = value;
}

void Student::setEmail(string value) {
	_email = value;
}

void Student::setDOB(Date* value) {
	_dob = value;
}

Student::Student() {
	_id = _fullName = _address = _email = "";
	_dob = new Date();
}

// Week02: Use input() function
// Week03: Use StudentKeyboardProvider.next()
void Student::input() {
	cout << "Nhap ID: ";
	getline(cin, _id);
	cout << "Nhap FullName: ";
	getline(cin, _fullName);
	cout << "Nhap Address: ";
	getline(cin, _address);
	cout << "Nhap Email: ";
	getline(cin, _email);
	cout << "Nhap DOB: ";
	_dob->input();
}

// Week02: use "output" function and inside this function access directly to the console using cout
// Week03: use toString()
// Week04: use Converter
void Student::output() {
	cout << "ID: " << _id << endl
		<< "FullName: " << _fullName << endl
		<< "Address: " << _address << endl
		<< "Email: " << _email << endl
		<< "DBO: ";
	_dob->output();
}