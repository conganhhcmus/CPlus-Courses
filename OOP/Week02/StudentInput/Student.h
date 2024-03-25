#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Student {
private:
	string _id;
	string _fullName;
	string _address;
	string _email;
	Date* _dob;

public:
	string getID();
	string getFullName();
	string getAddress();
	string getEmail();
	Date* getDOB();

	void setID(string value);
	void setFullName(string value);
	void setAddress(string value);
	void setEmail(string value);
	void setDOB(Date* value);

public:
	Student();
public:
	void input();
	void output();
};