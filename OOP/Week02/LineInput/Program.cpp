#include <iostream>
#include "Line.h"

using namespace std;

int main()
{
	cout << "Nhap xuat Line" << endl << endl;

	cout << "Nhap vao toa do cua Line." << endl;
	Line a;
	a.input();

	cout << "Toa do cua Line vua nhap la: ";
	a.output();
}