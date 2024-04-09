#include "Integer.h"

int Integer::parse(string info) {
	int num = 0;
	char min = '0', max = '9';
	int n = info.length();

	for (int i = 0; i < n; i++) {
		if (info[i] < min || info[i]> max) throw (info);
		else {
			num = num * 10 + (int(info[i]) - 48);
		}
	}
	return num;
}