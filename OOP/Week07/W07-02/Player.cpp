#include "Player.h"

Player::Player() {
	playerName = "";
	money = wisdom = power = 0;
}

Player::Player(string playerName, float money, float wisdom, float power) {
	this->playerName = playerName;
	this->money = money;
	this->wisdom = wisdom;
	this->power = power;
}

Player::~Player() {
}

float Player::getMoney() {
	return money;
}

float Player::getPower() {
	return power;
}
float Player::getWisdom() {
	return wisdom;
}
void Player::setMoney(float money) {
	this->money = money;
}
void Player::setPower(float power) {
	this->power = power;
}
void Player::setWisdom(float wisdom) {
	this->wisdom = wisdom;
}

string Player::printInfo() {
	stringstream ss;
	ss << "Name: " << playerName
		<< "\tMoney: " << money
		<< "\tWisdom: " << wisdom
		<< "\tPower: " << power;
	return ss.str();
}