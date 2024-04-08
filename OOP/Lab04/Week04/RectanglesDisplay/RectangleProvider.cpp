#include "RectangleProvider.h"

vector<Rectangle> RectangleProvider::getAll() {
	return { // Hard code at this week is enough
		Rectangle(3, 4),
		Rectangle(4, 5),
		Rectangle(4, 8)
	};
}