#pragma once
#include "string"
#include "vector"
#include "iostream"
#include "fstream"
#include "University.h"

using namespace std;

class UniversitiesProvider {
public:
	static vector<University> read(string filename);
};