#include "iostream"
#include "sstream"
#include "SortContext.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

template <class T>
string displayArray(vector<T> data) {
	stringstream ss;
	for (auto e : data) {
		ss << e << " ";
	}
	return ss.str();
}

void sortInteger() {
	cout << " ----- Sort Integer -----" << endl;
	vector<int> data = vector<int>{ 6, 2, 1, 14, 5, 30, 7, 10, 20 };
	SortContext<int> sortContext = SortContext<int>();
	cout << "Init Array Value: " << displayArray(data) << endl;;

	// set BubbleSort strategy for sort by Bubble Sort Algorithm 
	sortContext.setSortStrategy(new BubbleSort<int>());
	vector<int> bubbleSort = sortContext.sort(data);
	cout << "Sort by BubbleSort: " << displayArray(bubbleSort) << endl;

	// set MergeSort strategy for sort by Merge Sort Algorithm 
	sortContext.setSortStrategy(new MergeSort<int>());
	vector<int> mergeSort = sortContext.sort(data);
	cout << "Sort by MergeSort: " << displayArray(mergeSort) << endl;

	// set QuickSort strategy for sort by Quick Sort Algorithm 
	sortContext.setSortStrategy(new QuickSort<int>());
	vector<int> quickSort = sortContext.sort(data);
	cout << "Sort by QuickSort: " << displayArray(quickSort) << endl;
}

void sortChar() {
	cout << " ----- Sort Char -----" << endl;
	vector<char> data = vector<char>{ 'x','b','y','k','j','a' };
	SortContext<char> sortContext = SortContext<char>();
	cout << "Init Array Value: " << displayArray(data) << endl;;

	// set BubbleSort strategy for sort by Bubble Sort Algorithm 
	sortContext.setSortStrategy(new BubbleSort<char>());
	vector<char> bubbleSort = sortContext.sort(data);
	cout << "Sort by BubbleSort: " << displayArray(bubbleSort) << endl;

	// set MergeSort strategy for sort by Merge Sort Algorithm 
	sortContext.setSortStrategy(new MergeSort<char>());
	vector<char> mergeSort = sortContext.sort(data);
	cout << "Sort by MergeSort: " << displayArray(mergeSort) << endl;

	// set QuickSort strategy for sort by Quick Sort Algorithm 
	sortContext.setSortStrategy(new QuickSort<char>());
	vector<char> quickSort = sortContext.sort(data);
	cout << "Sort by QuickSort: " << displayArray(quickSort) << endl;
}

int main() {
	sortInteger();
	sortChar();
	return 0;
}

// if don't include cpp files below, it has LNK2019 error when building on Windows version ARM (Windows on macOS chip M1)
#include "SortContext.cpp"
#include "BubbleSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"