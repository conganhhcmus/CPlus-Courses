#include "Student.h"

Student::Student() {
	_id = _fullname = _email = "";
}

Student::Student(string id, string fullname, string email) {
	_id = id;
	_fullname = fullname;
	_email = email;
}