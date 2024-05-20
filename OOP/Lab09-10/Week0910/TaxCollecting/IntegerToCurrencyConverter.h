#pragma once
#include "IValueConverter.h"
#include "NumberFormatInfo.h"

class IntegerToCurrencyConverter : public IValueConverter {
private:
	NumberFormatInfo _numberFormat;
public:
	IntegerToCurrencyConverter(NumberFormatInfo);
	string convert(Object*) override;
	string convert(vector<Object*>) override;
	string toString() override;
};