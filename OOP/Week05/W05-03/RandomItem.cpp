#include "RandomItem.h"

RandomItem::RandomItem() {
	_MSSV = "";
	_count = 0;
	_probability = 0.0;
	_distance = 0;
}

RandomItem::RandomItem(string MSSV, int count) {
	_MSSV = MSSV;
	_count = count;
	_probability = 0;
	_distance = 0;
}

RandomItem::~RandomItem() {

}

void RandomItem::displayItem() {
	cout << "MSSV: " << _MSSV << "\tCount: " << _count << "\tProbability: " << _probability << "%" << endl;
}

void RandomItem::setProbability(float probability) {
	_probability = probability;
}

int RandomItem::getCount() {
	return _count;
}

void RandomItem::setDistance(int distance) {
	_distance = distance;
}

int RandomItem::getDistance() {
	return _distance;
}

float RandomItem::getProbability() {
	return _probability;
}

string RandomItem::getMSSV() {
	return _MSSV;
}