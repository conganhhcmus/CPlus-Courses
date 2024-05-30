#include "DateParser.h"
#include "Date.h"
#include "Utils.h"

using namespace Utils;

Object* DateParser::parse(string data) {
	auto list = String::split(data, "/");
	int day = stoi(list[0]);
	int month = stoi(list[1]);
	int year = stoi(list[2]);
	return new Date(day, month, year);
}