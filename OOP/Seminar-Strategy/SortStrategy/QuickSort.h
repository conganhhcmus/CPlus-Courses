#pragma once
#include "SortStrategy.h"

template <class T>
class QuickSort : public SortStrategy<T> {
public:
	vector<T> sort(vector<T>) override;
};