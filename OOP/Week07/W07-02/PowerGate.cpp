#include "PowerGate.h"

PowerGate::PowerGate() :Gate() {
	this->type = "Power Gate";
	this->guardName = "Hero";
}

PowerGate::PowerGate(float power) : Gate() {
	this->power = power;
	this->type = "Power Gate";
	this->guardName = "Hero";
}

PowerGate::~PowerGate() {
}

bool PowerGate::passGate(Player* player) {
	float playerPower = player->getPower();
	if (playerPower < power) return false;

	player->setPower(playerPower - power);
	return true;
}

string PowerGate::printGateInfo() {
	stringstream ss;
	ss << "Type: " << type
		<< "\tGuard by: " << guardName
		<< "\t" << Gate::printGateInfo();
	return ss.str();
}