#include "Utils.h"
#include "fstream"

using namespace Utils;

vector<string> String::split(string haystack, string needle) {
	vector<string> result;
	int startPos = 0;
	size_t foundPos = haystack.find(needle, startPos);

	while (foundPos != string::npos) {
		int count = foundPos - startPos;
		string token = haystack.substr(startPos, count);
		result.push_back(token);

		startPos = foundPos + needle.length();
		foundPos = haystack.find(needle, startPos);
	}

	// The remaining
	string token = haystack.substr(startPos, haystack.length() - startPos);
	result.push_back(token);

	return result;
}

vector<string> String::getAllLineFromFile(string filename) {
	vector<string> result;
	string line;
	fstream infile(filename);
	while (getline(infile, line)) {
		result.push_back(line);
	}
	return result;
}