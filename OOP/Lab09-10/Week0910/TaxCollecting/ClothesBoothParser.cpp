#include "ClothesBoothParser.h"
#include "ClothesBooth.h"

Object* ClothesBoothParser::parse(string data) {
	string tplId = "ID=";
	string tplArea = "Area=";
	size_t startId = data.find(tplId);
	size_t startArea = data.find(tplArea);
	string id = data.substr(startId + tplId.length(), data.find_first_of(",") - tplId.length());
	int area = stoi(data.substr(startArea + tplArea.length()));

	return new ClothesBooth(id, area);
}

string ClothesBoothParser::parsedObjectName() {
	return "Clothes";
}
