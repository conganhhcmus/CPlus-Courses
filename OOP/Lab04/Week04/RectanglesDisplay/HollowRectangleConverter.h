#pragma once
#include "string"
#include "Rectangle.h"

using namespace std;

class HollowRectangleConverter {
private:
	string _character;
public:
	HollowRectangleConverter(string);
	string convert(Rectangle info);
};
