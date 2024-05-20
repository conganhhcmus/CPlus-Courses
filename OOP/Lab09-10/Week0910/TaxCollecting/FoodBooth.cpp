#include "FoodBooth.h"

FoodBooth::FoodBooth() : Booth() {
	_coldStoragePrice = 0;
}

FoodBooth::FoodBooth(string id, int area, int coldStoragePrice) : Booth(id, area) {
	_coldStoragePrice = coldStoragePrice;
}

string FoodBooth::toString() {
	return "FoodBooth";
}

string FoodBooth::getType() {
	return "Thuc pham";
}

int FoodBooth::rentPrice() {
	return _pricePerMeter * _area + _coldStoragePrice;
}

int FoodBooth::getFee() {
	return _coldStoragePrice;
}