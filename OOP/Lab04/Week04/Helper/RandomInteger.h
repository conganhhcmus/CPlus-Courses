#pragma once

#include "iostream"
#include "random"

using namespace std;

const int DEFAULT_MAX_VALUE = 65535;

class RandomInteger {
public:
	RandomInteger();
public:
	int next(); // [0, 65535]
	int next(int max); // [0, max-1]
	int next(int left, int right); // [left, right]
};