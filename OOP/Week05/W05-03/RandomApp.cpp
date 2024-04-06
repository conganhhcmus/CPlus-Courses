#include "RandomApp.h"

RandomApp::RandomApp() {
	_flagCount = 0;
}

RandomApp::~RandomApp() {
	// release all item in List
	for (int i = 0; i < _randomList.size(); i++) {
		delete _randomList[i];
	}
}


static RandomItem* CreateRandomItem(vector<string> row) {
	string MSSV = row[0];
	int count = stoi(row[1]);

	return new RandomItem(MSSV, count);
}

static float createRandomNumber() {
	int min = 0, max = 10000; // 00.00 -> 100.00%
	int res = rand() % (max - min + 1) + min;

	return res / 100.00;
}

void RandomApp::loadRandomListFromCSV() {
	int count = 0;
	const string path = "data.csv";
	fstream fin;
	fin.open(path, ios::in);
	vector<string> row;
	string line, word;
	while (fin >> line) {
		row.clear();

		stringstream ss(line);

		while (getline(ss, word, ';')) {
			row.push_back(word);
		}

		count++;
		_randomList.push_back(CreateRandomItem(row));
	}
	if (count == 0) cout << "Record not found\n";

	fin.close();
}


void RandomApp::loadConfiguartionFromFile() {
	int count = 0;
	const string path = "config.txt";
	fstream fin;
	fin.open(path, ios::in);
	vector<string> row;
	row.clear();

	string line, temp;
	while (fin >> line) {
		row.push_back(line);
		count++;
	}
	if (count == 0) cout << "Config not found\n";
	else {
		int initRandom = stoi(row[0]);
		srand(initRandom >= 0 ? initRandom : time(0));
		_flagCount = stoi(row[1]);

	}
	fin.close();
}

void RandomApp::recalculateProbability() {
	if (_randomList.size() <= 0) return;

	int totalDistance = 0;
	int maxCount = 0;
	int totalCount = 0;
	// get max count
	for (int i = 0; i < _randomList.size(); i++) {
		if (maxCount < _randomList[i]->getCount()) {
			maxCount = _randomList[i]->getCount();
		}
		totalCount += _randomList[i]->getCount();
	}

	int flagCount = _flagCount >= 0 ? _flagCount : maxCount + (totalCount / _randomList.size());
	// calculate distance
	for (int i = 0; i < _randomList.size(); i++) {
		int distance = flagCount - _randomList[i]->getCount();
		distance = distance >= 0 ? distance : 0; // if distance is negative, reset to zero

		_randomList[i]->setDistance(distance);
		totalDistance += distance;
	}

	// calculate probability
	for (int i = 0; i < _randomList.size(); i++) {
		float probability = totalDistance > 0 ? (_randomList[i]->getDistance() * 100.0) / totalDistance : 0;
		_randomList[i]->setProbability(probability);
	}
}

RandomItem* RandomApp::getRandomItem() {
	float randomNumber = createRandomNumber();

	for (int i = 0; i < _randomList.size(); i++) {
		randomNumber -= _randomList[i]->getProbability();
		if (randomNumber < 0) return _randomList[i];
	}

	return nullptr;
}

void RandomApp::removeItemFromRandomList(RandomItem* item) {
	int position = -1;

	// find position
	for (int i = 0; i < _randomList.size(); i++) {
		if (_randomList[i]->getMSSV() == item->getMSSV()) {
			position = i;
			break;
		}
	}

	if (position >= 0) {
		_randomList.erase(next(_randomList.begin(), position));
	}
}

void RandomApp::printAllRandomList() {
	cout << "--- All Random List ---" << endl;
	for (int i = 0; i < _randomList.size(); i++) {
		_randomList[i]->displayItem();
	}
}