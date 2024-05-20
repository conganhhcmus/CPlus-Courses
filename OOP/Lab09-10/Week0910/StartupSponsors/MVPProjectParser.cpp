#include "MVPProjectParser.h"
#include "MVPProject.h"

Object* MVPProjectParser::parse(string data) {
	string tplRunMonth = "RunMonths=";
	string tplMarketingMonth = "Marketing=";
	size_t startRunMonth = data.find(tplRunMonth);
	size_t startMarketingMonth = data.find(tplMarketingMonth);
	string name = data.substr(0, data.find(", "));
	int runningMonth = stoi(data.substr(startRunMonth + tplRunMonth.length(), startMarketingMonth - startRunMonth));
	int marketingMonth = stoi(data.substr(startMarketingMonth + tplMarketingMonth.length()));

	return new MVPProject(name, runningMonth, marketingMonth);
}

string MVPProjectParser::parsedObjectName() {
	return "Mvp";
}