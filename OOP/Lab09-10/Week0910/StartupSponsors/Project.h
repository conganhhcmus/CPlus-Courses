#pragma once
#include "Object.h"

class Project : public Object {
protected:
	string _name;
public:
	Project();
	Project(string);
	string getName();
	virtual string getType() = 0;
	virtual string getInfo() = 0;
	virtual int sponsorshipMoney() = 0;
};