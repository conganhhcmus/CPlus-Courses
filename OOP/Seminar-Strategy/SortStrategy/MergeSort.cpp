#include "MergeSort.h"

template <class T>
void merge(vector<T>& data, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays  
	vector<T> L, R;

	// Copy data to temp arrays L[] and R[]  
	for (int i = 0; i < n1; i++)
		L.push_back(data[l + i]);
	for (int j = 0; j < n2; j++)
		R.push_back(data[m + 1 + j]);

	// Merge the temp arrays back into arr[l..r] 

	// Initial index of first subarray 
	int i = 0;

	// Initial index of second subarray 
	int j = 0;

	// Initial index of merged subarray 
	int k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			data[k] = L[i];
			i++;
		}
		else
		{
			data[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of 
	// L[], if there are any  
	while (i < n1)
	{
		data[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of 
	// R[], if there are any  
	while (j < n2)
	{
		data[k] = R[j];
		j++;
		k++;
	}
}

template <class T>
// l is for left index and r is  
// right index of the sub-array 
// of arr to be sorted */ 
void mergeSort(vector<T>& data, int l, int r)
{
	if (l < r)
	{

		// Same as (l+r)/2, but avoids  
		// overflow for large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(data, l, m);
		mergeSort(data, m + 1, r);

		merge(data, l, m, r);
	}
}

template <class T>
vector<T> MergeSort<T>::sort(vector<T> data) {
	// clone data
	vector<T> result;
	for (auto e : data) {
		result.push_back(e);
	}

	mergeSort(result, 0, result.size() - 1);

	return result;
}
