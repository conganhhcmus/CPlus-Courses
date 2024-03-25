#include "Point2D.h"
#include <iostream>
using namespace std;

int Point2D::getX() {
	return _x;
}

int Point2D::getY() {
	return _y;
}

void Point2D::setX(int value) {
	_x = value;
}

void Point2D::setY(int value) {
	_y = value;
}

Point2D::Point2D() {
	_x = 0;
	_y = 0;
}

// Week02: Use input() function
// Week03: Use Point2DKeyboardProvider.next()
void Point2D::input() {
	cout << "Nhap toa do X: ";
	cin >> _x;
	cout << "Nhap toa do Y: ";
	cin >> _y;
}

// Week02: use "output" function and inside this function access directly to the console using cout
// Week03: use toString()
// Week04: use Converter
void Point2D::output() {
	cout << "X: " << _x << " Y: " << _y;
}