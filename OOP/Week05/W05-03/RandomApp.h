#pragma once
#include "RandomItem.h"
#include "vector"
#include "fstream"
#include "iostream"
#include "string"
#include "sstream"
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomApp {
private:
	vector<RandomItem*> _randomList;
	int _flagCount;

public:
	RandomApp();
	~RandomApp();
	void loadRandomListFromCSV();
	void loadConfiguartionFromFile();
	RandomItem* getRandomItem();
	void removeItemFromRandomList(RandomItem*);
	void recalculateProbability();
	void printAllRandomList();
};