#include "Gate.h"

Gate::Gate() {
	money = power = wisdom = 0;
	guardName = "";
	type = "Gate";
}

Gate::~Gate() {
}

bool Gate::passGate(Player* player) {
	return true;
}

string Gate::printGateInfo() {
	stringstream ss;
	ss << "Money: " << money
		<< "\tPower: " << power
		<< "\tWisdom: " << wisdom;
	return ss.str();
}