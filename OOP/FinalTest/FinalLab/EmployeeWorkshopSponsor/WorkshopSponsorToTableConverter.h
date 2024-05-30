#pragma once
#include "IValueConverter.h"
#include "Sponsorship.h"

class WorkshopSponsorToTableConverter : public IValueConverter {
private:
	vector<string> _headers;
	vector<int> _columnSizes;
	vector<Sponsorship*> _sponsorship;

public:
	WorkshopSponsorToTableConverter(vector<string> headers, vector<int> columnSizes, vector<Sponsorship*> sponsorship);
	string convert(vector<Object*> objects) override;
	string convert(Object* object) override;
	string toString() override;
	Sponsorship* findSponsorship(Object*);
	static float total;


private: // Inner class
	class WorkshopSponsorToRowConverter {
	private:
		vector<int> _columnSizes;
		vector<Sponsorship*> _sponsorship;

	public:
		WorkshopSponsorToRowConverter(vector<int> columnSizes, vector<Sponsorship*> sponsorship);
		string convert(Object* object);
		Sponsorship* findSponsorship(Object*);
	};
};