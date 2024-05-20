#include "IdeaProject.h"
#include "sstream";

#define DEVELOPMENT_FUNDING 2200

IdeaProject::IdeaProject() : Project() { _devMonth = 0; }

IdeaProject::IdeaProject(string name, int devMonth) : Project(name), _devMonth(devMonth) {}

string IdeaProject::toString() {
	return "IdeaProject";
}

string IdeaProject::getType() {
	return "Y tuong";
}

string IdeaProject::getInfo() {
	stringstream ss;
	ss << "Phat trien: " << _devMonth << " thang";
	return ss.str();
}

int IdeaProject::sponsorshipMoney() {
	return _devMonth * DEVELOPMENT_FUNDING;
}