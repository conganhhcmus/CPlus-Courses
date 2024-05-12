#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
	double _width;
	double _height;
public:
	Rectangle();
	Rectangle(double, double);
	double area() override;
	double perimeter() override;
	string toString() override;
};