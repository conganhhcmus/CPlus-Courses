#include "ProductEmployeeParser.h"
#include "ProductEmployee.h"

Object* ProductEmployeeParser::parse(string data) {
	string tplProductCount = "productCount=";
	string tplPaymentPerProduct = "paymentPerProduct=";
	size_t startPosProductCount = data.find(tplProductCount);
	size_t startPosPaymentPerProduct = data.find(tplPaymentPerProduct);
	auto productCount = stoi(data.substr(startPosProductCount + tplProductCount.length(), startPosPaymentPerProduct));
	auto paymentPerProduct = stoi(data.substr(startPosPaymentPerProduct + tplPaymentPerProduct.length()));

	return new ProductEmployee(productCount, paymentPerProduct);
}

string ProductEmployeeParser::parsedObjectName() {
	return "ProductEmployee";
}