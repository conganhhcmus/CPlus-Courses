#pragma once
#include "iostream"

using namespace std;

class RandomItem {
private:
	string _MSSV;
	int _count;
	float _probability;
	int _distance;

public:
	// constructor
	RandomItem();
	RandomItem(string, int);
	// destructor
	~RandomItem();
	// getter & setter
	string getMSSV();
	int getCount();
	int getDistance();
	void setDistance(int);
	float getProbability();
	void setProbability(float);
	// function
	void displayItem();
};