#include "RectangleParser.h"
#include "Rectangle.h"

Object* RectangleParser::parse(string data) {
	string tplW = "w=", tplH = "h=";
	size_t startPosW = data.find(tplW);
	size_t startPosH = data.find(tplH);
	double width = stod(data.substr(startPosW + tplW.length(), startPosH));
	double height = stod(data.substr(startPosH + tplW.length()));
	return new Rectangle(width, height);
}

string RectangleParser::parsedObjectName() {
	return "Rectangle";
}