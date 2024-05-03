#include "AcademicGate.h"

AcademicGate::AcademicGate() : Gate() {
	this->type = "Acedemic Gate";
	this->guardName = "Sage";
}

AcademicGate::AcademicGate(float wisdom) : Gate() {
	this->wisdom = wisdom;
	this->type = "Acedemic Gate";
	this->guardName = "Sage";
}

AcademicGate::~AcademicGate() {
}

bool AcademicGate::passGate(Player player) {
	float playerWisdom = player.getWisdom();
	if (playerWisdom < wisdom) return false;
	return true;
}