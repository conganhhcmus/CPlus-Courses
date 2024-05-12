#include "ProductEmployee.h"
#include "sstream"

using namespace std;

ProductEmployee::ProductEmployee() { _productCount = _paymentPerProduct = 0; }

ProductEmployee::ProductEmployee(int productCount, int paymentPerProduct) :
	_productCount(productCount), _paymentPerProduct(paymentPerProduct) {}

int ProductEmployee::salary() {
	return _productCount * _paymentPerProduct;
}

string ProductEmployee::toString() {
	stringstream ss;
	ss << "Product employee";
	return ss.str();
}