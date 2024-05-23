#pragma once
#include "vector"

using namespace std;

template <class  T>
class SortStrategy {
public:
	virtual vector<T> sort(vector<T>) = 0;
};