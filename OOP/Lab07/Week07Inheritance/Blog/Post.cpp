#include "Post.h"

Post::Post() {}

Post::Post(string author, string title, string content)
	: _author(author), _title(title), _content(content) {}

string Post::toString() {
	stringstream ss;
	ss << format("Author: {}\nTitle: {}\nContent: {}\n", _author, _title, _content);
	return ss.str();
}