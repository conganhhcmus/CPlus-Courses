#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "FractionsTextProvider.h"
#include "FractionHelper.h"

using namespace std;

int main(int argc, char* argv[])
{
	string filename = "input.txt";
	cout << "Working with fraction arrays from text files" << endl;
	cout << "Reading data from " << filename << endl;
	vector<Fraction> data = FractionsTextProvider::read(filename);
	cout << "Expected to find " << data.size() << " fractions." << endl << endl;

	cout << "Found " << data.size() << " fractions: " << showData(data) << endl;
	cout << "Lowest term: " << showLowestTerm(data) << endl;
	cout << "Decimal: " << showDecimal(data) << endl;
	cout << "Percentage: " << showPercentage(data) << endl;

	cout << endl << "Program is exiting. Press enter to quit..." << endl;
	getchar();
	return 0;
}