#pragma once
#include "Booth.h"

class ClothesBooth : public Booth {
public:
	ClothesBooth();
	ClothesBooth(string, int);
	string toString() override;
	int rentPrice() override;
	int getFee() override;
	string getType() override;
};