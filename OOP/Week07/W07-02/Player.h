#pragma once
#include "string"
#include "sstream"

using namespace std;

class Player {
private:
	string playerName;

	float money;
	float wisdom;
	float power;

public:
	Player();
	Player(string playerName, float money, float wisdom, float power);
	~Player();
	float getMoney();
	float getPower();
	float getWisdom();
	void setMoney(float money);
	void setPower(float power);
	void setWisdom(float wisdom);
	string printInfo();
};