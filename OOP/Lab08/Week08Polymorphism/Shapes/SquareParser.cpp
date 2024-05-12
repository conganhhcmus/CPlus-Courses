#include "SquareParser.h"
#include "Square.h"

Object* SquareParser::parse(string data) {
	string tpl = "a=";
	size_t startPos = data.find(tpl);
	double a = stod(data.substr(startPos + tpl.length()));
	return new Square(a);
}

string SquareParser::parsedObjectName() {
	return "Square";
}