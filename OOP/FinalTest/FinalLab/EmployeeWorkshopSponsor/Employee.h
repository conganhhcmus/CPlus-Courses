#pragma once
#include "string"
#include "Date.h"
#include "Object.h"
#include "Workshop.h"

using namespace std;

class Employee:  public Object {
private:
	string _name;
	string _email;
	Date* _startDate;
	Workshop* _workshop;

public:
	Employee(string, string, Date*, Workshop*);
	string getName();
	string getEmail();
	Date* getStartDate();
	Workshop* getWorkshop();
	string toString() override;
};
