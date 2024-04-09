#include "FractionsTextProvider.h"

vector<Fraction> FractionsTextProvider::read(string filename) {
	vector<Fraction> result;
	string info;
	ifstream inputfile(filename);

	while (getline(inputfile, info)) {
		try {
			Fraction value = Fraction::parse(info);
			result.push_back(value);
		}
		catch (...) {
			cout << "Fraction: " << info << " is invalid!" << endl;
		}
	}

	return result;
}
