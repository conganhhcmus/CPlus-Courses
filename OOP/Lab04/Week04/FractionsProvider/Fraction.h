#pragma once
#include <string>  
#include <iostream> 
#include <sstream>  

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

public:
	Fraction();
	Fraction(int, int);
	~Fraction();
	string toString();
};