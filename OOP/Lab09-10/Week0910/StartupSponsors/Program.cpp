#include "iostream"
#include "ParserFactory.h"
#include "IdeaProjectParser.h"
#include "MVPProjectParser.h"
#include "Singleton.h"
#include "Singleton.cpp" // if not add a cpp file, the program gets an error when building
#include "Utils.h"
#include "Project.h"
#include "ProjectToTableConverter.h"
#include "IntegerToCurrencyConverter.h"
#include "Integer.h"
#include <algorithm>

using namespace Utils;

void setupDI(ParserFactory& factory) { // Add Dependency Injection
	factory.registerWith(new IdeaProjectParser());
	factory.registerWith(new MVPProjectParser());
}

ProjectToTableConverter setupTableDisplay() {
	vector<string> headers = { "STT", "Loai du an", "Ten du an", "Thong tin", "Kinh phi" };
	vector<int> columnSizes = { 3, 20, 20, 40, 20 };
	return ProjectToTableConverter(headers, columnSizes);
}

vector<Object*> getAllProject(vector<string> lines, ParserFactory factory) {
	vector<Object*> result;

	for (string line : lines) {// "Mvp: SmartKey, RunMonths=4, Marketing=5"
		int splitPosition = line.find_first_of(":");
		string type = line.substr(0, splitPosition); // type = "Mvp"
		IParsable* parser = factory.create(type);

		// data = "SmartKey, RunMonths=4, Marketing=5",
		string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
		result.push_back(parser->parse(data));
	}

	return result;
}

bool compareProjectObject(Object* a, Object* b) {
	auto projectA = dynamic_cast<Project*>(a);
	auto projectB = dynamic_cast<Project*>(b);

	return projectA->sponsorshipMoney() < projectB->sponsorshipMoney();
}

vector<Object*> sortAllProject(vector<Object*> objects) {
	vector<Object*> result;
	sort(objects.begin(), objects.end(), compareProjectObject);

	for (auto object : objects) {
		result.push_back(object);
	}

	return result;
}

int getTotalSponsorAmount(vector<Object*> objects) {
	int result = 0;

	for (auto object : objects) {
		auto project = dynamic_cast<Project*>(object);
		result += project->sponsorshipMoney();
	}
	return result;
}

int main() {
	auto factory = Singleton<ParserFactory>::getInstance();
	setupDI(factory);
	string filename = "MayProposals.txt";
	auto lines = String::getAllLineFromFile(filename);
	auto projects = getAllProject(lines, factory);
	auto projectTableConverter = setupTableDisplay();
	auto currencyConverter = IntegerToCurrencyConverter();
	auto totalSponsorAmount = new Integer(getTotalSponsorAmount(projects));
	projects = sortAllProject(projects);

	cout << "Ke hoach tai tro du an startup noi bo cong ty AlphaTech" << endl;
	cout << "Thang: 05/2024" << endl << endl;
	cout << projectTableConverter.convert(projects) << endl;
	cout << "Tong kinh phi tai tro: " << currencyConverter.convert(totalSponsorAmount) << endl;

	return 0;
}