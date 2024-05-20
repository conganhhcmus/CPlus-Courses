#include "ClothesBooth.h"

ClothesBooth::ClothesBooth() : Booth() {}

ClothesBooth::ClothesBooth(string id, int area) : Booth(id, area) {}

string ClothesBooth::toString() {
	return "ClothesBooth";
}

int ClothesBooth::rentPrice() {
	return _pricePerMeter * _area;
}

int ClothesBooth::getFee() { return 0; }

string ClothesBooth::getType() {
	return "Quan ao";
}