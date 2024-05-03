#include "BusinessGate.h"

BusinessGate::BusinessGate() : Gate() {
	this->type = "Business Gate";
	this->guardName = "Merchant";
}

BusinessGate::BusinessGate(float cost, int num) : Gate() {
	this->cost = cost;
	this->num = num;
	this->money = cost * num;
	this->type = "Business Gate";
	this->guardName = "Merchant";
}

BusinessGate::~BusinessGate() {
}

bool BusinessGate::passGate(Player player) {
	float playerMoney = player.getMoney();
	if (playerMoney < money) return false;

	player.setMoney(playerMoney - money);
	return true;
}