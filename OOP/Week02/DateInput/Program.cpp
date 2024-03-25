#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	cout << "Nhap xuat Date" << endl << endl;

	cout << "Nhap vao ngay, thang, nam cua Date." << endl;
	Date a;
	a.input();

	cout << "Ngay, thang, nam cua Date vua nhap la: ";
	a.output();
}