#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
	cout << "Nhap xuat Student" << endl << endl;

	cout << "Nhap vao thong tin cua Student." << endl;
	Student st;
	st.input();

	cout << "Thong tin cua Student vua nhap la:" << endl;
	st.output();
}