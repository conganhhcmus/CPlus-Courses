#pragma once
#include "Booth.h"

class JewelryBooth : public Booth {
private:
	int _securityFee;
public:
	JewelryBooth();
	JewelryBooth(string, int, int);
	string toString() override;
	int rentPrice() override;
	int getFee() override;
	string getType() override;
};