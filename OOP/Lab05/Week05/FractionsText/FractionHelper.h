#pragma once

#include "sstream"
#include "string"
#include "vector"
#include <iomanip>
#include "Fraction.h"

using namespace std;

string showData(vector<Fraction> data);

string showLowestTerm(vector<Fraction> data);

string showDecimal(vector<Fraction> data);

string showPercentage(vector<Fraction> data);
