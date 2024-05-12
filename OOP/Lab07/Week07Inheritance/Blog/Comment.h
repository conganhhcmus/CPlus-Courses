#pragma once
#include "string"

using namespace std;

class Comment {
private:
	string _author;
	string _content;
public:
	Comment();
	Comment(string author, string content);
	string author();
	string content();
};