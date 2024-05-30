#pragma once
#include "Object.h"
#include "vector"

using namespace std;

class IValueConverter : public Object {
public:
	virtual string convert(Object*) = 0;
	virtual string convert(vector<Object*>) = 0;
};