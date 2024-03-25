#include "Product.h"
#include <iostream>

using namespace std;

string Product::getID() {
	return _id;
}

string Product::getName() {
	return _name;
}

float Product::getPrice() {
	return _price;
}


Date* Product::getExpiryDate() {
	return _expiryDate;
}

void Product::setID(string value) {
	_id = value;
}

void Product::setName(string value) {
	_name = value;
}

void Product::setPrice(float value) {
	_price = value;
}

void Product::setExpiryDate(Date* value) {
	_expiryDate = value;
}

Product::Product() {
	_id = _name = "";
	_price = 0.0;
	_expiryDate = new Date();
}

// Week02: Use input() function
// Week03: Use ProductKeyboardProvider.next()
void Product::input() {
	cout << "Nhap ID: ";
	getline(cin, _id);
	cout << "Nhap Name: ";
	getline(cin, _name);
	cout << "Nhap Price: ";
	cin >> _price;
	cout << "Nhap Expiry Date: ";
	_expiryDate->input();
}

// Week02: use "output" function and inside this function access directly to the console using cout
// Week03: use toString()
// Week04: use Converter
void Product::output() {
	cout << "ID: " << _id << endl
		<< "Name: " << _name << endl
		<< "Price: " << _price << endl
		<< "Expiry Date: ";
	_expiryDate->output();
}