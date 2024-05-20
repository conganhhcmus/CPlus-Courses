#include "FoodBoothParser.h"
#include "FoodBooth.h"

Object* FoodBoothParser::parse(string data) {
	string tplId = "ID=";
	string tplArea = "Area=";
	string tplColdStorage = "ColdStorage=";
	size_t startId = data.find(tplId);
	size_t startArea = data.find(tplArea);
	size_t startColdStorage = data.find(tplColdStorage);
	string id = data.substr(startId + tplId.length(), data.find_first_of(",") - tplId.length());
	int area = stoi(data.substr(startArea + tplArea.length(), startColdStorage));
	int coldStoragePrice = stoi(data.substr(startColdStorage + tplColdStorage.length()));;

	return new FoodBooth(id, area, coldStoragePrice);
}

string FoodBoothParser::parsedObjectName() {
	return "Food";
}