#pragma once
#include "Gate.h"

class BusinessGate : public Gate {
private:
	float cost;
	int num;
public:
	BusinessGate();
	BusinessGate(float cost, int num);
	~BusinessGate();

	bool passGate(Player* player) override;
	string printGateInfo() override;
};
