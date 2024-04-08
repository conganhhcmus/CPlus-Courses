#pragma once
#include "string"

using namespace std;

class Student {
public:
    string _id;
    string _fullname;
    string _email;
public:
    Student();
    Student(string id, string fullname, string email);
};