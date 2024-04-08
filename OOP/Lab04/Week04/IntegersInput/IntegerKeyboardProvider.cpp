#include "IntegerKeyboardProvider.h"

Result<int> IntegerKeyboardProvider::next() {
	int num;
	cin >> num;
	
	Result<int> result = Result<int>();
	result.data = num;
	result.success = true;
	result.errorCode = 0;
	result.message = "Success";

	return result;
}

Result<int> IntegerKeyboardProvider::next(int min, int max) {
	int num;
	do {
		cin >> num;
	} while (num < min || num > max);

	Result<int> result = Result<int>();
	result.data = num;
	result.success = true;
	result.errorCode = 0;
	result.message = "Success";

	return result;
}