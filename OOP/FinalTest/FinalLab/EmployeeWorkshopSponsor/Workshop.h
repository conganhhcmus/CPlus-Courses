#pragma once
#include "Object.h"

class Workshop: public Object {
private:
	string _name;
	float _expense;
public:
	Workshop(string, float);
	string getName();
	float getExpense();
	string toString() override;
};