#include "iostream"
#include "ParserFactory.h"
#include "FoodBoothParser.h"
#include "ClothesBoothParser.h"
#include "JewelryBoothParser.h"
#include "Singleton.h"
#include "Singleton.cpp" // if not add a cpp file, the program gets an error when building
#include "Utils.h"
#include "BoothToTableConverter.h"
#include "IntegerToCurrencyConverter.h"
#include "Integer.h"
#include <algorithm>
#include "Booth.h"

using namespace Utils;

void setupDI(ParserFactory& factory) { // Add Dependency Injection
	factory.registerWith(new FoodBoothParser());
	factory.registerWith(new ClothesBoothParser());
	factory.registerWith(new JewelryBoothParser());
}

BoothToTableConverter setupTableDisplay() {
	vector<string> headers = { "STT", "Ma sap", "Loai", "Dien tich", "Tien / m2", "Tien mat bang", "Phi khac", "Tong cong" };
	vector<int> columnSizes = { 3, 6, 15, 15, 15, 15, 15, 15 };
	return BoothToTableConverter(headers, columnSizes);
}

vector<Object*> getAllBooth(vector<string> lines, ParserFactory factory) {
	vector<Object*> result;

	for (string line : lines) {// Food ID=A724, Area=78, ColdStorage=3000000
		int splitPosition = line.find_first_of(" ");
		string type = line.substr(0, splitPosition); // type = "Food"
		IParsable* parser = factory.create(type);

		// data = "ID=A724, Area=78, ColdStorage=3000000",
		string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
		result.push_back(parser->parse(data));
	}

	return result;
}

bool compareBoothObject(Object* a, Object* b) {
	auto boothA = dynamic_cast<Booth*>(a);
	auto boothB = dynamic_cast<Booth*>(b);

	return boothA->rentPrice() < boothB->rentPrice();
}

vector<Object*> sortAllBooth(vector<Object*> objects) {
	vector<Object*> result;
	sort(objects.begin(), objects.end(), compareBoothObject);

	for (auto object : objects) {
		result.push_back(object);
	}

	return result;
}

int getTotalRentPrice(vector<Object*> objects) {
	int result = 0;

	for (auto object : objects) {
		auto booth = dynamic_cast<Booth*>(object);
		result += booth->rentPrice();
	}
	return result;
}

int main() {
	auto factory = Singleton<ParserFactory>::getInstance();
	setupDI(factory);
	string filename = "RentMay24.txt";
	auto lines = String::getAllLineFromFile(filename);
	auto booths = getAllBooth(lines, factory);
	auto boothTableConverter = setupTableDisplay();
	auto numberFormat = NumberFormatInfo(".", "d", 3, "n $");
	auto currencyConverter = IntegerToCurrencyConverter(numberFormat);
	auto totalRentPrice = new Integer(getTotalRentPrice(booths));
	booths = sortAllBooth(booths);

	cout << "Bao cao thu tien thue mat bang cho Ben Thanh " << endl;
	cout << "Thang: 05/2024" << endl << endl;
	cout << boothTableConverter.convert(booths) << endl;
	cout << "Tong tien thue mat bang thu trong thang: " << currencyConverter.convert(totalRentPrice) << endl;

	return 0;
}