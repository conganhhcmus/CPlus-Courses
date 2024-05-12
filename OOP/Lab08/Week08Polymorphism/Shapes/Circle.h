#pragma once
#include "IShape.h"

class Circle : public IShape {
private:
	double _radius;
public:
	Circle();
	Circle(double);
	double area() override;
	double perimeter() override;
	string toString() override;
};