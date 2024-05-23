#pragma once
#include "SortStrategy.h"

template <class T>
class MergeSort : public SortStrategy<T> {
public:
	vector<T> sort(vector<T>) override;
};