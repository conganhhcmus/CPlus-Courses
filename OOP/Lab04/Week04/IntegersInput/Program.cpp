#include "iostream";
#include "IntegerKeyboardProvider.h"

using namespace std;

static bool isPrimeNumber(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	RandomInteger randomInteger = RandomInteger();
	DynamicArray<Result<int>> integerArray = DynamicArray<Result<int>>();
	int n = randomInteger.next(10, 20);
	cout << "Please enter " << n << " integers in the range of [20, 100]" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Integer " << i + 1 << ": ";
		Result<int> input = IntegerKeyboardProvider::next(20, 100);
		integerArray.addItem(input);
	}

	vector<int> primeList;
	for (int i = 0; i < integerArray.getSize(); i++) {
		if (isPrimeNumber(integerArray.getItem(i).data)) {
			primeList.push_back(integerArray.getItem(i).data);
		}
	}

	cout << "Found " << primeList.size() << " prime number(s) :";
	for (int i = 0; i < primeList.size(); i++) {
		cout << primeList[i] << " ";
	}
	return 0;
}

#include "RandomInteger.cpp"
#include "DynamicArray.cpp"
#include "Result.cpp"