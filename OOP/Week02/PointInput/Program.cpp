#include <iostream>
#include "Point2D.h"

using namespace std;

int main()
{
	cout << "Nhap xuat Point 2D" << endl << endl;

	cout << "Nhap vao mot toa do X,Y cua Point 2D." << endl;
	Point2D a;
	a.input();

	cout << "Toa do cua Point 2D vua nhap la: ";
	a.output();
}