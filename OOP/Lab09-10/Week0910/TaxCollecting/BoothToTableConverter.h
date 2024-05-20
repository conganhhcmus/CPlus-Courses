#pragma once
#include "IValueConverter.h"

class BoothToTableConverter : public IValueConverter {
private:
	vector<string> _headers;
	vector<int> _columnSizes;

public:
	BoothToTableConverter(vector<string> headers, vector<int> columnSizes);
	string convert(vector<Object*> objects) override;
	string convert(Object* object) override;
	string toString() override;

private: // Inner class
	class BoothToRowConverter {
	private:
		vector<int> _columnSizes;
	public:
		BoothToRowConverter(vector<int> columnSizes);
		string convert(Object* object);
	};
};