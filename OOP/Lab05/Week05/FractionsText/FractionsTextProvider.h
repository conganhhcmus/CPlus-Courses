#pragma once
#include "vector"
#include "Fraction.h"
#include "string"
#include "iostream"
#include "fstream"

using namespace std;

class FractionsTextProvider {
public:
	static vector<Fraction> read(string filename);
};