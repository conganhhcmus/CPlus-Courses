#include "NumberHelper.h"


vector<int> getOddNumber(vector<int> data) {
	vector<int> result;
	for (int i = 0;i < data.size();i++) {
		if (data[i] % 2 == 1) result.push_back(data[i]);
	}
	return result;
}
vector<int> getEvenNumber(vector<int> data) {
	vector<int> result;
	for (int i = 0;i < data.size();i++) {
		if (data[i] % 2 == 0) result.push_back(data[i]);
	}
	return result;
}

bool checkPalindrome(int number)
{
	int reverse = 0;
	int temp = number;
	while (temp != 0) {
		reverse = (reverse * 10) + (temp % 10);
		temp = temp / 10;
	}
	return (reverse == number);
}

vector<int> getPalindromicNumber(vector<int> data) {
	vector<int> result;
	for (int i = 0;i < data.size();i++) {
		if (checkPalindrome(data[i])) result.push_back(data[i]);
	}
	return result;
}


bool isPrimeNumber(int number) {
	for (int i = 2;i <= sqrt(number);i++) {
		if (number % i == 0) return false;
	}
	return true;
}
vector<int> getPrimeNumber(vector<int> data) {
	vector<int> result;
	for (int i = 0;i < data.size();i++) {
		if (isPrimeNumber(data[i])) result.push_back(data[i]);
	}
	return result;
}

bool checkSquareNumber(int number) {
	double sqrtValue = sqrt(number);
	return ceil(sqrtValue) == floor(sqrtValue);
}

vector<int> getSquareNumber(vector<int> data) {
	vector<int> result;
	for (int i = 0;i < data.size();i++) {
		if (checkSquareNumber(data[i])) result.push_back(data[i]);
	}
	return result;
}

bool checkPerfectNumber(int number) {
	int sum = 1;
	for (int i = 2;i * i < number;i++) {
		if (number % i == 0) {
			if (i * i != number) sum += i + number / i;
			else sum += i;
		}
	}
	return sum == number && number != 1;
}

vector<int> getPerfectNumber(vector<int> data) {
	vector<int> result;
	for (int i = 0;i < data.size();i++) {
		if (checkPerfectNumber(data[i])) result.push_back(data[i]);
	}
	return result;
}

int getMaximumNumber(vector<int> data) {
	int max = data.empty() ? 0 : data[0];
	for (int i = 0;i < data.size();i++) {
		if (max < data[i]) max = data[i];
	}
	return max;
}
int getMinimumNumber(vector<int> data) {
	int min = data.empty() ? 0 : data[0];
	for (int i = 0;i < data.size();i++) {
		if (min > data[i]) min = data[i];
	}
	return min;
}
float getAverageNumber(vector<int> data) {
	return (float)getSumAllNumber(data) / (float)data.size();

}
int getSumAllNumber(vector<int> data) {
	int sum = 0;
	for (int i = 0;i < data.size();i++) {
		sum += data[i];
	}
	return sum;
}

string showData(vector<int>data, string delimer) {
	stringstream ss;

	if (!data.empty()) ss << ": ";

	for (int i = 0;i < data.size();i++) {
		ss << data[i];
		if (i < data.size() - 1) ss << delimer;
	}

	return ss.str();
}