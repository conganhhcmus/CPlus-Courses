#include "Circle.h"
#include "sstream"
#include "format"

using namespace std;

#define PI 3.1416

Circle::Circle() { _radius = 0; }

Circle::Circle(double radius) { _radius = radius; }

double Circle::area() {
	return PI * _radius * _radius;
}

double Circle::perimeter() {
	return 2 * PI * _radius;
}

string Circle::toString() {
	stringstream ss;
	ss << format("Circle r={}", _radius);
	return ss.str();
}