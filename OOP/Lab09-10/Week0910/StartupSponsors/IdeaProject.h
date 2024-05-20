#pragma once
#include "Project.h"

class IdeaProject : public Project {
private:
	int _devMonth;
public:
	IdeaProject();
	IdeaProject(string, int);
	string toString() override;
	string getType() override;
	string getInfo() override;
	int sponsorshipMoney() override;
};