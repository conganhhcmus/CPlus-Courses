#include "DynamicArray.h"

template <class T> void DynamicArray<T>::sortArray(bool (*compare)(T a, T b)) {
	sort(array.begin(), array.end(), compare);
}


template <class T> void DynamicArray<T>::addItem(T item) {
	array.push_back(item);
}


template <class T> void DynamicArray<T>::removeItem(int position) {
	array.erase(array.begin() + position);
}

template <class T> vector<T> DynamicArray<T>::getArray() {
	return array;
}

template <class T> int DynamicArray<T>::getSize() {
	return array.size();
}

template <class T> T DynamicArray<T>::getItem(int index) {
	return array[index];
}
