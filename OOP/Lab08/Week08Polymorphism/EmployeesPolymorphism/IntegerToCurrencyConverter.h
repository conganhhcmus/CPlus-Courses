#pragma once
#include "IValueConverter.h"

class IntegerToCurrencyConverter : public IValueConverter {
public:
	string convert(Object*) override;
	string toString() override;
};