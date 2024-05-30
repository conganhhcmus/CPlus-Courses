#include "iostream"
#include "vector"
#include "Employee.h"
#include "EmployeeParser.h"
#include "Utils.h"
#include "WorkshopSponsorToTableConverter.h"

using namespace Utils;

vector<Object*> getAllRequest(vector<string> lines) {
	vector<Object*> result;
	vector<string> data;
	auto parser = EmployeeParser();

	for (string line : lines) {
		if (line.length() == 0) {
			result.push_back(parser.parse(data));
			data.clear();
		}
		else {
			data.push_back(line);
		}
	}
	result.push_back(parser.parse(data));

	return result;
}


WorkshopSponsorToTableConverter setupTableDisplay(vector<Sponsorship*> sponsorship) {
	vector<string> headers = { "STT", "Nhan vien", "Tham nien", "Ten workshop", "Chi phi", "Ho tro", "Thanh tien" };
	vector<int> columnSizes = { 3, 20, 10, 30, 10, 10, 10 };
	return WorkshopSponsorToTableConverter(headers, columnSizes, sponsorship);
}

int main() {
	const string filename = "May2024Proposals.txt";
	auto lines = String::getAllLineFromFile(filename);
	auto requests = getAllRequest(lines);
	vector<Sponsorship*> sponsorship = vector<Sponsorship*>{
		new Sponsorship("Fresher", 0, 1, 50),
		new Sponsorship("Junior", 1, 2, 75),
		new Sponsorship("Senior", 2, 0, 100)
	};
	auto tableDisplay = setupTableDisplay(sponsorship);

	cout << "Chuong trinh tai tro workshop cho nhan vien 05/2024" << endl;
	cout << "Dang doc cac de nghi tu tap tin " << filename << endl;
	cout << "Tim thay " << requests.size() << " de nghi ho tro chi phi tham gia workshop" << endl;
	cout << tableDisplay.convert(requests) << endl;
	cout << "Tong tien tai tro: $" << WorkshopSponsorToTableConverter::total << endl;
	return 0;
}