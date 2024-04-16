#include "UniversitiesProvider.h"

University CreateUniversityItem(vector<string> row) {
	string name = row[0];
	string feeStr = row[1].substr(2, row[1].length() - 3);
	int pos = feeStr.find(',');
	int fee = stoi(feeStr.erase(pos, 1));

	return University(name, fee);
}

vector<University> UniversitiesProvider::read(string filename) {
	vector<University> result;
	int count = 0;
	fstream fin;
	fin.open(filename, ios::in);
	vector<string> row;
	string line, word;
	while (getline(fin,line)) {
		row.clear();

		stringstream ss(line);

		while (getline(ss, word, ';')) {
			row.push_back(word);
		}

		if (count > 0) result.push_back(CreateUniversityItem(row));
		count++;
	}
	if (count == 0) cout << "Record not found\n";

	fin.close();
	return result;
}

