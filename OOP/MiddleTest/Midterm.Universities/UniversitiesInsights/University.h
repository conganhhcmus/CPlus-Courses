#pragma once
#include "string"
#include "sstream"

using namespace std;

class University {
private:
	string _name;
	int _fee;

public:
	University(string, int);
	string getName();
	int getFee();
};