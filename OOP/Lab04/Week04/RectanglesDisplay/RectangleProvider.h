#pragma once
#include "Rectangle.h"
#include "vector"

using namespace std;

class RectangleProvider {
public:
	static vector<Rectangle> getAll();
};
