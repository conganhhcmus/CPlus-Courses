#pragma once
#include "Player.h"
#include "string"

using namespace std;

class Gate {
protected:
	string guardName;
	string type;
	float money;
	float power;
	float wisdom;
public:
	Gate();
	~Gate();
	virtual bool passGate(Player* player);
	virtual string printGateInfo();
};
