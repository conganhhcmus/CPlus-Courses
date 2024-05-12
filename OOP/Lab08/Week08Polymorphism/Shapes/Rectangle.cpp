#include "Rectangle.h"
#include "sstream"
#include "format"

using namespace std;

Rectangle::Rectangle() { _width = _height = 0; }

Rectangle::Rectangle(double width, double height) { _width = width; _height = height; }

double Rectangle::area() {
	return _width * _height;
}

double Rectangle::perimeter() {
	return 2 * (_width + _height);
}

string Rectangle::toString() {
	stringstream ss;
	ss << format("Rectangle w={}, h={}", _width, _height);
	return ss.str();
}