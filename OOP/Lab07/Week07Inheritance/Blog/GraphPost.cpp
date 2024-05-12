#include "GraphPost.h"

GraphPost::GraphPost() : Post() {
	_likes = 0;
}

GraphPost::GraphPost(string author, string title, string content, int likes, vector<Comment> comments) : Post(author, title, content) {
	_likes = likes;
	for (auto& comment : comments) {
		_comments.push_back(comment);
	}
}

string GraphPost::toString() {
	stringstream ss;
	ss << Post::toString();
	ss << format("\nLikes: {}\nComments: {}\n", _likes, _comments.size());

	for (auto& comment : _comments)
	{
		ss << format("- {}: {}\n", comment.author(), comment.content());
	}
	return ss.str();
}