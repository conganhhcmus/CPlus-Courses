#include "BubbleSort.h"

template <class T>
// An optimized version of Bubble Sort
void bubbleSort(vector<T>& data, int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				swap(data[j], data[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
}


template <class T>
vector<T> BubbleSort<T>::sort(vector<T> data) {
	// clone data
	vector<T> result;
	for (auto e : data) {
		result.push_back(e);
	}
	bubbleSort(result, result.size());
	return result;
}