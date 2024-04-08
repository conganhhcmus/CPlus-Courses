#include "RandomInteger.h"

RandomInteger::RandomInteger() {
	srand(time(0));
}

int RandomInteger::next() {
	return rand() % (DEFAULT_MAX_VALUE + 1);
}

int RandomInteger::next(int max) {
	return this->next() % max;
}

int RandomInteger::next(int left, int right) {
	return this->next() % (right - left + 1) + left;
}