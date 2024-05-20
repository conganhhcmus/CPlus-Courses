#pragma once
#include "IValueConverter.h"

class ProjectToTableConverter : public IValueConverter {
private:
	vector<string> _headers;
	vector<int> _columnSizes;

public:
	ProjectToTableConverter(vector<string> headers, vector<int> columnSizes);
	string convert(vector<Object*> objects) override;
	string convert(Object* object) override;
	string toString() override;

private: // Inner class
	class ProjectToRowConverter {
	private:
		vector<int> _columnSizes;
	public:
		ProjectToRowConverter(vector<int> columnSizes);
		string convert(Object* object);
	};
};