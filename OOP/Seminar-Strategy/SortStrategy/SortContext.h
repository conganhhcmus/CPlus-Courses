#pragma once
#include "SortStrategy.h"

template <class T>
class SortContext {
private:
	SortStrategy<T>* _strategy;
public:
	void setSortStrategy(SortStrategy<T>*);
	vector<T> sort(vector<T>);
};