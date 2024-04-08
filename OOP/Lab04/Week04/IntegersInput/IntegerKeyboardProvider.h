#pragma once
#include "DynamicArray.h"
#include "Result.h";
#include "RandomInteger.h"

class IntegerKeyboardProvider {
public:
	static Result<int> next();
	static Result<int> next(int min, int max);
};