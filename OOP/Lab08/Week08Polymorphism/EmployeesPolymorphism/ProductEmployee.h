#pragma once
#include "Employee.h"

class ProductEmployee : public Employee {
private:
	int _productCount;
	int _paymentPerProduct;

public:
	ProductEmployee();
	ProductEmployee(int, int);
	int salary() override;
	string toString() override;
};