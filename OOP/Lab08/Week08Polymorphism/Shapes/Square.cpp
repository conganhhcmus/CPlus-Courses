#include "Square.h"
#include "sstream"
#include "format"

using namespace std;

Square::Square() { _a = 0; }

Square::Square(double a) { _a = a; }

double Square::area() {
	return _a * _a;
}

double Square::perimeter() {
	return 4 * _a;
}

string Square::toString() {
	stringstream ss;
	ss << format("Square a={}", _a);
	return ss.str();
}