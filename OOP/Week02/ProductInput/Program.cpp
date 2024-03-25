#include <iostream>
#include "Product.h"

using namespace std;

int main()
{
	cout << "Nhap xuat Product" << endl << endl;

	cout << "Nhap vao thong tin cua Product." << endl;
	Product product;
	product.input();

	cout << "Thong tin cua Product vua nhap la:" << endl;
	product.output();
}