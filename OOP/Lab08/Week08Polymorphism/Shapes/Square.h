#pragma once
#include "IShape.h"

class Square : public IShape {
private:
	double _a;

public:
	Square();
	Square(double);
	double area() override;
	double perimeter() override;
	string toString() override;
};