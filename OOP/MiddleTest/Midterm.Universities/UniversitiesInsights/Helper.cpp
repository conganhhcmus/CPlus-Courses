#include "Helper.h"
#include <iostream>

class comma_numpunct : public std::numpunct<char>
{
protected:
	virtual char do_thousands_sep() const
	{
		return ',';
	}

	virtual std::string do_grouping() const
	{
		return "\03";
	}
};

bool compareUniversity(University u1, University u2)
{
	return (u1.getFee() > u2.getFee());
}

string convertCurrency(int number) {
	locale comma_locale(std::locale(), new comma_numpunct());

	stringstream ss;
	ss.imbue(comma_locale);
	ss << "$ " << setprecision(2) << number;
	return ss.str();
}

vector<University> getTop10(vector<University> data) {
	vector<University> result;
	sort(data.begin(), data.end(), compareUniversity);
	int length = 10;
	if (data.size() < 10) length = data.size();

	for (int i = 0;i < length;i++) {
		result.push_back(data[i]);
	}
	return result;
}

string showData(vector<University> data, string delimer) {
	stringstream ss;
	ss << "|" << setw(10) << "STT" << "|"
		<< setw(40) << "Ten truong" << "|"
		<< setw(20) << "Hoc phi" << "|" << endl;
	ss << "------------------------------------------------------------------------" << endl;
	for (int i = 0;i < data.size();i++) {
		ss << "|" << setw(10) << i + 1 << "|"
			<< setw(40) << data[i].getName() << "|"
			<< setw(20) << convertCurrency(data[i].getFee()) << "|" << endl;
	}
	return ss.str();
}