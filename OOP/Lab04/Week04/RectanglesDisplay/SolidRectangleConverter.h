#pragma once
#include "string"
#include "sstream"
#include "Rectangle.h"

using namespace std;

class SolidRectangleConverter {
private:
    string _character;
public:
    SolidRectangleConverter(string);
    string convert(Rectangle info);
};
