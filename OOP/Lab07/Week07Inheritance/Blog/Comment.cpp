#include "Comment.h"

Comment::Comment() { _author = ""; _content = ""; }

Comment::Comment(string author, string content) : _author(author), _content(content) {}

string Comment::author() { return _author; }

string Comment::content() { return _content; }