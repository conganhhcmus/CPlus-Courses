#include "iostream";
#include "FractionKeyboardProvider.h"

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
	DynamicArray<Result<Fraction>> fractionArray = DynamicArray<Result<Fraction>>();
	int n = randomInteger.next(10, 20);
	cout << "Please enter " << n << " fractions from the keyboard" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Fraction " << i + 1 << ": ";
		Result<Fraction> input = FractionKeyboardProvider::next();
		fractionArray.addItem(input);
	}

	cout << "All entered fractions: :";
	for (int i = 0; i < fractionArray.getSize(); i++) {
		cout << fractionArray.getItem(i).data.toString() << " ";
	}
	return 0;
}

#include "RandomInteger.cpp"
#include "DynamicArray.cpp"
#include "Result.cpp"