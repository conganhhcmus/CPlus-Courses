#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Product {
private:
	string _id;
	string _name;
	float _price;
	Date* _expiryDate;

public:
	string getID();
	string getName();
	float getPrice();
	Date* getExpiryDate();

	void setID(string value);
	void setName(string value);
	void setPrice(float value);
	void setExpiryDate(Date* value);

public:
	Product();
public:
	void input();
	void output();
};