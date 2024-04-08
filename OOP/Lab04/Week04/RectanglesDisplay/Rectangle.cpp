#include "Rectangle.h"

Rectangle::Rectangle() {
	_height = 0;
	_width = 0;
}

Rectangle::Rectangle(int width, int heigth) {
	_height = width;
	_width = heigth;
}

Rectangle::~Rectangle() {

}

int Rectangle::getHeight() {
	return _height;
}

int Rectangle::getWidth() {
	return _width;
}



string Rectangle::toString() {
	stringstream output;
	output << "Rectangle Width=" << _width << ", Height=" << _height << endl;
	return output.str();
}