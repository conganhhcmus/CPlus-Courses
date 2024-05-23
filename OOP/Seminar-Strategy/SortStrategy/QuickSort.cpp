#include "QuickSort.h"

template <class T>
T partition(vector<T>& data, int start, int end)
{
	T pivot = data[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (data[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(data[pivotIndex], data[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (data[i] <= pivot) {
			i++;
		}

		while (data[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(data[i++], data[j--]);
		}
	}

	return pivotIndex;
}

template <class T>
void quickSort(vector<T>& data, int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(data, start, end);

	// Sorting the left part
	quickSort(data, start, p - 1);

	// Sorting the right part
	quickSort(data, p + 1, end);
}

template <class T>
vector<T> QuickSort<T>::sort(vector<T> data) {
	// clone data
	vector<T> result;
	for (auto e : data) {
		result.push_back(e);
	}

	quickSort(result, 0, result.size() - 1);
	return result;
}