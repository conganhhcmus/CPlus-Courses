#pragma once
#include "Booth.h"

class FoodBooth : public Booth {
private:
	int _coldStoragePrice;
public:
	FoodBooth();
	FoodBooth(string, int, int);
	string toString() override;
	int rentPrice() override;
	int getFee() override;
	string getType() override;
};