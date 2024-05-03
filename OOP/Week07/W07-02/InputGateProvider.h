#pragma once
#include "Gate.h"
#include "iostream"


using namespace std;

enum GateType
{
	POWER = 0,
	ACADEMIC = 1,
	BUSINESS = 2
};

class InputGateProvider {
public:
	static Gate* inputGate(GateType type);
};