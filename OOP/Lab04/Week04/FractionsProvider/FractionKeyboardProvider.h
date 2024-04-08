#pragma once
#include "Result.h"
#include "Fraction.h"
#include "RandomInteger.h"
#include "DynamicArray.h"

class FractionKeyboardProvider {
public:
	static Result<Fraction> next();
};