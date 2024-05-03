#pragma once
#include "Gate.h"

enum GateType
{
	POWER = 0,
	ACADEMIC = 1,
	BUSINESS = 2
};

class GateFactory {
public:
	static Gate* createGate(GateType type);
};