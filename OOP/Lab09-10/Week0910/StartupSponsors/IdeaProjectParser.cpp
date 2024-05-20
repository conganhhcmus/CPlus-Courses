#include "IdeaProjectParser.h"
#include "IdeaProject.h"

Object* IdeaProjectParser::parse(string data) {
	string tplDevMonth = "DevMonths=";
	size_t startDevMonth = data.find(tplDevMonth);
	string name = data.substr(0, data.find(", "));
	int devMonth = stoi(data.substr(startDevMonth + tplDevMonth.length()));
	return new IdeaProject(name, devMonth);
}

string IdeaProjectParser::parsedObjectName() {
	return "Idea";
}