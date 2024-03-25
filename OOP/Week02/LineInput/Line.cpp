#include "Line.h"
#include <iostream>
using namespace std;

int Line::getX1() {
	return _x1;
}

int Line::getX2() {
	return _x2;
}

int Line::getY1() {
	return _y1;
}

int Line::getY2() {
	return _y2;
}

void Line::setX1(int value) {
	_x1 = value;
}

void Line::setX2(int value) {
	_x2 = value;
}

void Line::setY1(int value) {
	_y1 = value;
}

void Line::setY2(int value) {
	_y2 = value;
}

Line::Line() {
	_x1 = 0;
	_x2 = 0;
	_y1 = 0;
	_y2 = 0;
}

// Week02: Use input() function
// Week03: Use LineKeyboardProvider.next()
void Line::input() {
	cout << "Nhap toa do X1: ";
	cin >> _x1;
	cout << "Nhap toa do X2: ";
	cin >> _x2;

	cout << "Nhap toa do Y1: ";
	cin >> _y1;
	cout << "Nhap toa do Y2: ";
	cin >> _y2;
}

// Week02: use "output" function and inside this function access directly to the console using cout
// Week03: use toString()
// Week04: use Converter
void Line::output() {
	cout << "X1: " << _x1 << " X2: " << _x2 << " Y1: " << _y1 << " Y2: " << _y2;
}