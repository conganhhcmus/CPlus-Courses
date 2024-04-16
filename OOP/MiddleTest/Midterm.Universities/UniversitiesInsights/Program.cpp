#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include "UniversitiesProvider.h"
#include "Helper.h"

using namespace std;

int main(int argc, char* argv[])
{
	string filename = "gapminder.csv";
	vector<University> uniersities = UniversitiesProvider::read(filename);

	cout << "Phan tich du lieu cac truong dai hoc 2024" << endl;
	cout << "Top 10 truong co hoc phi cao nhat" << endl << endl;

	cout << showData(getTop10(uniersities), "") << endl;

	return 0;
}