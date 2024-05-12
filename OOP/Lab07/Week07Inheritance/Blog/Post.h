#pragma once
#include "string"
#include "sstream"
#include "format"

using namespace std;

class Post {
protected:
	string _author;
	string _title;
	string _content;
public:
	Post();
	Post(string author, string title, string content);
	string toString();
};