#include "MVPProject.h"
#include "sstream"

#define RUNNING_PRODUCT_FUNDING 930
#define MARKETING_PRODUCT_FUNDING 500

MVPProject::MVPProject() : Project() { _runMonth = 0; _marketingMonth = 0; }

MVPProject::MVPProject(string name, int runMonth, int marketingMonth) : Project(name), _runMonth(runMonth), _marketingMonth(marketingMonth) {}

string MVPProject::toString() {
	return "MVPProject";
}

string MVPProject::getType() {
	return "San pham";
}

string MVPProject::getInfo() {
	stringstream ss;
	ss << "Van hanh: " << _runMonth << " thang. Marketing: " << _marketingMonth << " thang";
	return ss.str();
}

int MVPProject::sponsorshipMoney() {
	return _runMonth * RUNNING_PRODUCT_FUNDING + _marketingMonth * MARKETING_PRODUCT_FUNDING;
}