#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "IntegersTextProvider.h"
#include "NumberHelper.h"

using namespace std;

int main(int argc, char* argv[])
{
	string filename = "input.txt";
	cout << "Working with integer arrays from text files" << endl;
	cout << "Reading data from " << filename << endl;
	vector<int> data = IntegersTextProvider::read(filename);
	cout << "Expected to find " << data.size() << " numbers." << endl << endl;

	cout << "Found " << data.size() << " numbers" << showData(data, " ") << endl;
	auto oddNumbers = getOddNumber(data);
	cout << "Found " << oddNumbers.size() << " odd numbers" << showData(oddNumbers, ", ") << endl;
	auto evenNumbers = getEvenNumber(data);
	cout << "Found " << evenNumbers.size() << " even numbers" << showData(evenNumbers, ", ") << endl;
	auto palindromicNumbers = getPalindromicNumber(data);
	cout << "Found " << palindromicNumbers.size() << " palindromic numbers" << showData(palindromicNumbers, ", ") << endl;
	auto primeNumbers = getPrimeNumber(data);
	cout << "Found " << primeNumbers.size() << " prime numbers: " << showData(primeNumbers, ", ") << endl;
	auto squareNumbers = getSquareNumber(data);
	cout << "Found " << squareNumbers.size() << " square numbers" << showData(squareNumbers, ", ") << endl;
	auto perfectNumbers = getPerfectNumber(data);
	cout << "Found " << perfectNumbers.size() << " perfect numbers" << showData(perfectNumbers, ", ") << endl;

	cout << "Minimum value : " << getMinimumNumber(data) << endl;
	cout << "Maximum value : " << getMaximumNumber(data) << endl;
	cout << "Average value : " << getAverageNumber(data) << endl;
	cout << "Sum of all numbers : " << getSumAllNumber(data) << endl;

	cout << endl << "Program is exiting. Press enter to quit..." << endl;
	getchar();
	return 0;
}