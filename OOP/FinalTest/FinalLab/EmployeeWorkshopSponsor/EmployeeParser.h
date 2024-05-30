#pragma once
#include "Object.h"
#include "vector"

using namespace std;

class EmployeeParser {
public:
	Object* parse(vector<string>);
};
