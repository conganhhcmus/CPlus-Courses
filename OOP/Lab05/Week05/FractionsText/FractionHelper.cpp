#include "FractionHelper.h"


string showData(vector<Fraction> data) {
	stringstream ss;

	for (int i = 0; i < data.size(); i++) {
		ss << data[i].getNumerator() << "/" << data[i].getDenominator();
		if (i < data.size() - 1)  ss << ", ";
	}

	return ss.str();
}

string showLowestTerm(vector<Fraction> data) {
	stringstream ss;

	for (int i = 0; i < data.size(); i++) {
		int temp = 0, numerator = data[i].getNumerator(), denominator = data[i].getDenominator();

		temp = numerator / denominator;
		numerator %= denominator;
		if (temp == 0) {
			if (numerator == 0) ss << 0;
			else ss << data[i].getNumerator() << "/" << data[i].getDenominator();
		}
		else {
			if (numerator == 0) ss << temp;
			else ss << temp << " " << numerator << "/" << denominator;
		}
		
		if (i < data.size() - 1)  ss << ", ";
	}

	return ss.str();
}

string showDecimal(vector<Fraction> data) {
	stringstream ss;

	for (int i = 0; i < data.size(); i++) {
		ss << fixed << setprecision(2) << data[i].getNumerator() * 1.00 / data[i].getDenominator();
		if (i < data.size() - 1)  ss << ", ";
	}

	return ss.str();
}

string showPercentage(vector<Fraction> data) {
	stringstream ss;

	for (int i = 0; i < data.size(); i++) {
		ss << (int)(data[i].getNumerator() * 100.00 / data[i].getDenominator()) << "%";
		if (i < data.size() - 1)  ss << ", ";
	}

	return ss.str();
}