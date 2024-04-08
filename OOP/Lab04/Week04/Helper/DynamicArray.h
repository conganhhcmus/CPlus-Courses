#pragma once

#include <iostream>
#include "vector"
#include <algorithm>

using namespace std;

template <class T>
class DynamicArray {
private:
	vector<T> array;

public:
	void sortArray(bool (*compare)(T a, T b));
	void addItem(T item);
	void removeItem(int position);
	vector<T> getArray();
	int getSize();
	T getItem(int index);
};