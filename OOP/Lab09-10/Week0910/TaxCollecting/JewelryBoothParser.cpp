#include "JewelryBoothParser.h"
#include "JewelryBotth.h"

Object* JewelryBoothParser::parse(string data) {
	string tplId = "ID=";
	string tplArea = "Area=";
	string tplSecurityFee = "SecurityFee=";
	size_t startId = data.find(tplId);
	size_t startArea = data.find(tplArea);
	size_t startSecurityFee = data.find(tplSecurityFee);
	string id = data.substr(startId + tplId.length(), data.find_first_of(",") - tplId.length());
	int area = stoi(data.substr(startArea + tplArea.length(), startSecurityFee));
	int securityFee = stoi(data.substr(startSecurityFee + tplSecurityFee.length()));;
	return new JewelryBooth(id, area, securityFee);
}

string JewelryBoothParser::parsedObjectName() {
	return "Jewelry";
}