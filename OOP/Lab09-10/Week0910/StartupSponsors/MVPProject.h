#pragma once
#include "Project.h"

class MVPProject : public Project {
private:
	int _runMonth;
	int _marketingMonth;

public:
	MVPProject();
	MVPProject(string, int, int);
	string toString() override;
	string getType() override;
	string getInfo() override;
	int sponsorshipMoney() override;
};