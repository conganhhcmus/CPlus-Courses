#include "SortContext.h"

template <class T>
void SortContext<T>::setSortStrategy(SortStrategy<T>* strategy) {
	_strategy = strategy;
}

template <class T>
vector<T> SortContext<T>::sort(vector<T> data) {
	return _strategy->sort(data);
}