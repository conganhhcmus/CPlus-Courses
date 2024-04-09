#pragma once
#include "string"
#include "vector"
#include "iostream"
#include "fstream"
#include "Integer.h"

using namespace std;

class IntegersTextProvider {
public:
	static vector<int> read(string filename);
};