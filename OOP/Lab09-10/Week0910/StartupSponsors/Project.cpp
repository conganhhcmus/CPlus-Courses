#include "Project.h"

Project::Project() { _name = ""; }

Project::Project(string name) : _name(name) {}

string Project::getName() { return _name; }