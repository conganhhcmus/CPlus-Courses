#pragma once
#include "Object.h"

class Booth : public Object {
protected:
	string _id;
	int _area;
	int _pricePerMeter;
public:
	Booth();
	Booth(string, int);
	string getID();
	int getArea();
	int getPricePerMeter();
	int getAreaPrice();
	virtual string getType() = 0;
	virtual int rentPrice() = 0;
	virtual int getFee() = 0;
};