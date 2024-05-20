#include "Booth.h"
#define PRICE_PER_METER 560000

Booth::Booth() {
	_id = "";
	_area = 0;
	_pricePerMeter = PRICE_PER_METER;
}

Booth::Booth(string id, int area) {
	_id = id;
	_area = area;
	_pricePerMeter = PRICE_PER_METER;
}

string Booth::getID() { return _id; }

int Booth::getArea() { return _area; }

int Booth::getPricePerMeter() { return _pricePerMeter; }

int Booth::getAreaPrice() { return _pricePerMeter * _area; }