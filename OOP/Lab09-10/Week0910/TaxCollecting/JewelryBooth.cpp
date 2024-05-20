#include "JewelryBotth.h"

JewelryBooth::JewelryBooth() : Booth() {
	_securityFee = 0;
}

JewelryBooth::JewelryBooth(string id, int area, int securityFee) : Booth(id, area) {
	_securityFee = securityFee;
}

string JewelryBooth::toString() {
	return "JewelryBooth";
}

int JewelryBooth::rentPrice() {
	return _pricePerMeter * _area + _securityFee;
}

int JewelryBooth::getFee() {
	return _securityFee;
}

string JewelryBooth::getType() {
	return "Da qui";
}