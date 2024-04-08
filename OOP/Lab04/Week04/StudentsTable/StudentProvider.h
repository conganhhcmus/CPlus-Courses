#pragma once
#include "vector"
#include "Student.h"

using namespace std;

class StudentProvider {
public:
    static vector<Student> getAll();
};