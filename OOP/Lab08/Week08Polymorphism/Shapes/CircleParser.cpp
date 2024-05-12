#include "CircleParser.h"
#include "Circle.h"

Object* CircleParser::parse(string data) {
	string tpl = "r=";
	size_t startPos = data.find(tpl);
	double radius = stod(data.substr(startPos + tpl.length()));
	return new Circle(radius);
}

string CircleParser::parsedObjectName() {
	return "Circle";
}