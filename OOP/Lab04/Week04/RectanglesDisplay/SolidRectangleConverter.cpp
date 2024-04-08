#include "SolidRectangleConverter.h"

SolidRectangleConverter::SolidRectangleConverter(string character) {
	this->_character = character;
}

string SolidRectangleConverter::convert(Rectangle info) {
	stringstream output;
	for (int i = 0; i < info.getWidth(); i++) {
		for (int j = 0; j < info.getHeight(); j++) {
			output << _character;
		}
		output << endl;
	}
	return output.str();
}