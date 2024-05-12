#pragma once
#include "Post.h"
#include "Comment.h"
#include "vector"

using namespace std;



class GraphPost : public Post {
private:
	int _likes;
	vector<Comment> _comments;

public:
	GraphPost();
	GraphPost(string author, string title, string content, int likes, vector<Comment> comments);
	string toString();
};