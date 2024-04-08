#pragma once
#include "vector"
#include "string"
#include "sstream"
#include <iomanip>
#include "Student.h"

using namespace std;

class StudentsToTableConverter {
private:
    vector<string> _headers;
    vector<int> _columnSizes;
public:
    StudentsToTableConverter();
    StudentsToTableConverter(vector<string> headers, vector<int> columnSizes);
    string convert(vector<Student> students);

private: // Inner class
    class StudentToRowConverter {
    private:
        vector<int> _columnSizes;
    public:
        StudentToRowConverter();
        StudentToRowConverter(vector<int> columnSizes);
        string convert(Student student);
    };
};