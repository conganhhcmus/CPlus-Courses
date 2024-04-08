#include "HollowRectangleConverter.h"

HollowRectangleConverter::HollowRectangleConverter(string character) {
	this->_character = character;
}


string HollowRectangleConverter::convert(Rectangle info) {
	stringstream output;
	for (int i = 0; i < info.getWidth(); i++) {
		for (int j = 0; j < info.getHeight(); j++) {
			if (i == 0 || i == (info.getWidth() - 1) || j == 0 || j == (info.getHeight() - 1)) output << _character;
			else output << " ";
		}
		output << endl;
	}
	return output.str();
}