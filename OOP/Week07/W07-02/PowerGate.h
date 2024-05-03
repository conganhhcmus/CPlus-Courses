#pragma once
#include "Gate.h"

class PowerGate : public Gate {
public:
	PowerGate();
	PowerGate(float power);
	~PowerGate();
	bool passGate(Player player) override;
};