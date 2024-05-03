#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "vector"
#include "InputGateProvider.h"
#include "Player.h"

using namespace std;

int main(int argc, char* argv[])
{
	vector<Gate*> gateList;
	string playerName;
	float playerMoney = 0, playerWisdom = 0, playerPower = 0;
	cout << "Enter info of player! " << endl;
	cout << "Player Name: "; cin >> playerName;
	cout << "Player Money: "; cin >> playerMoney;
	cout << "Player Wisdom: "; cin >> playerWisdom;
	cout << "Player Power: "; cin >> playerPower;
	Player* player = new Player(playerName, playerMoney, playerWisdom, playerPower);

	int number;
	system("cls");
	cout << "Enter number of Gate: ";
	cin >> number;
	int type = 0;

	for (int i = 0; i < number; i++) {
		system("cls");
		cout << "Enter the Gate " << i + 1 << endl;
		cout << "Choose type of Gate: " << endl
			<< "0. Power Gate" << endl
			<< "1. Academic Gate" << endl
			<< "2. Business Gate" << endl
			<< "Your choose: ";
		cin >> type;
		gateList.push_back(InputGateProvider::inputGate(GateType(type)));
	}

	stringstream trace;
	bool isSuccess = true;
	for (int i = 0; i < gateList.size(); i++) {
		if (!gateList[i]->passGate(player)) {
			trace << "Don't pass the gate!" << endl
				<< "Gate " << i + 1 << "\tPlayer info: " << player->printInfo() << endl
				<< "\tGate info: " << gateList[i]->printGateInfo() << endl;

			isSuccess = false;
			break;
		}
		trace << "Gate " << i + 1 << "\tPlayer info: " << player->printInfo() << endl
			<< "\tGate info: " << gateList[i]->printGateInfo() << endl << endl;
	}

	cout << "----RESULT OF GAME----" << endl;
	if (isSuccess) {
		cout << "The player successfully rescued the princess!" << endl;
		cout << "The player info after rescued: " << player->printInfo() << endl;
	}
	else {
		cout << "The player did not successfully rescued the princess!" << endl;
	}
	cout << "Trace history:" << endl << trace.str() << endl;

	return 0;
}