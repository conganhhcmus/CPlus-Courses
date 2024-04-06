#include "iostream"
#include "cstdlib"
#include "RandomApp.h"

using namespace std;
int main(int argc, char* argv[])
{
	RandomApp* randomApp = new RandomApp();

	// load data from csv
	randomApp->loadRandomListFromCSV();

	// load config
	randomApp->loadConfiguartionFromFile();

	// init probability
	randomApp->recalculateProbability();

	// load menu
	bool isRunning = true;
	while (isRunning) {
		int option = 0;
		system("cls");
		cout << "Welcome to Random App!" << endl;
		cout << "1. Print all random list" << endl;
		cout << "2. Get random item from list" << endl;
		cout << "Other. Exit!" << endl;
		cout << "Please choose option: ";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			randomApp->printAllRandomList();
			break;
		}
		case 2:
		{
			RandomItem* item = randomApp->getRandomItem();
			if (item == nullptr) {
				cout << "No selected item because one of them:" << endl;
				cout << "- Random list is empty" << endl;
				cout << "- Probability of all items is 0 % " << endl;
			}
			else {
				// print selected item 
				item->displayItem();

				// remove item from list because item can only be selected once
				randomApp->removeItemFromRandomList(item);

				// recalculate probability because random list has been changed
				randomApp->recalculateProbability();
			}

			break;
		}
		default: {
			isRunning = false;
			break;
		}
		}
		system("pause");
	}

	delete randomApp;
	return 0;
}