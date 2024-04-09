#include "IntegersTextProvider.h"

vector<int> IntegersTextProvider::read(string filename) {
	vector<int> result;
	string info;
	ifstream inputfile(filename);

	while (getline(inputfile, info)) {
		try {
			int value = Integer::parse(info);
			result.push_back(value);
		}
		catch (...) {
			cout << "Number: " << info << " is invalid!" << endl;
		}
	}

	return result;
}