#pragma once
#include "Gate.h"

class AcademicGate : public Gate {
public:
	AcademicGate();
	AcademicGate(float wisdom);
	~AcademicGate();
	bool passGate(Player* player) override;
	string printGateInfo() override;
};
