#pragma once
#include "vector"
#include "string"
#include "sstream"
#include "University.h"
#include <algorithm> 
#include "iomanip"

using namespace std;

vector<University> getTop10(vector<University> data);

string showData(vector<University> data, string delimer);